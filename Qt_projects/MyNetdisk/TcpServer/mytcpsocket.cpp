#include "mytcpsocket.h"
#include "dbinstance.h"
#include "mytcpserver.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>

// MyTcpSocket::MyTcpSocket(QObject *parent)
//     : QTcpSocket{parent}
// {
//     connect(this,&MyTcpSocket::readyRead,this,&MyTcpSocket::recvMsg);
//     connect(this,&MyTcpSocket::disconnected,this,&MyTcpSocket::Offline);
//     // connect(this,&MyTcpSocket::OfflineSignal,&MyTcpServer::GetInstance(),&MyTcpServer::deleteTcpSocket);
// }

MyTcpSocket::MyTcpSocket()
{
    m_isUpload = false;
    m_totalSize = 0;
    m_recvSize = 0;
    timer = new QTimer;
    connect(this,&MyTcpSocket::readyRead,this,&MyTcpSocket::recvMsg);
    connect(this,&MyTcpSocket::disconnected,this,&MyTcpSocket::Offline);
    connect(timer,&QTimer::timeout,this,&MyTcpSocket::sendFileToClient);
}

void MyTcpSocket::DoRegisterRequest(PDU * pdu)
{
    char caUsername[32];
    char caPassword[32];
    strncpy(caUsername,pdu->caData,32);         // 用户名
    strncpy(caPassword,pdu->caData+32,32);      // 密码
    bool ret = DBInstance::GetInstance().HandleRegister(caUsername,caPassword);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_REGISTER_RESPOND;
    if(ret){
        strcpy(respdu->caData,REGISTER_OK);
        // 创建初始文件夹
        QDir initUserDir;
        QString data(QString("./usersFile/%1").arg(QString(caUsername)));
        if(!initUserDir.exists()){
            initUserDir.mkdir(data);
        }
    }else{
        strcpy(respdu->caData,REGISTER_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoLoginRequest(PDU *pdu)
{
    char caUsername[32];
    char caPassword[32];
    strncpy(caUsername,pdu->caData,32);         // 用户名
    strncpy(caPassword,pdu->caData+32,32);      // 密码
    int ret = DBInstance::GetInstance().HandleLogin(caUsername,caPassword);
    qDebug() << ret;
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_LOGIN_RESPOND;
    if(ret == -1){
        strcpy(respdu->caData,LOGIN_FAIL);
    }else if(ret == 0){
        strcpy(respdu->caData,LOGIN_OK);
        m_strUsername = QString(caUsername);
        // 创建初始文件夹
        QDir initUserDir;
        QString data(QString("./usersFile/%1").arg(QString(caUsername)));
        if(!initUserDir.exists(data)){
            initUserDir.mkdir(data);
        }
    }else{
        strcpy(respdu->caData,LOGIN_REPEAT);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoShowAllOnlineUsersRequest()
{
    QStringList users = DBInstance::GetInstance().HandleAllOnlineUsers();
    const int fixedSize = 32;
    uint msgLength = fixedSize * users.size();
    PDU *respdu = mkPDU(msgLength);
    respdu->MsgType = MSGTYPE_ALL_ONLINEUSRES_RESPOND;
    for(int i = 0;i < users.size();++ i){
        memcpy((char*)(respdu->msg)+i*32,users.at(i).toStdString().c_str(),users.at(i).size());
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoFindUserRequest(PDU *pdu)
{
    QString username(pdu->caData);
    qDebug() << "查询用户 " << username;
    int ret = DBInstance::GetInstance().HandleFindUser(username.toStdString().c_str());
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_FINDUSER_RESPOND;
    if(ret == -1){
        strcpy(respdu->caData,FINDUSER_NOT_EXIST);
    }else if(ret == 0){
        strcpy(respdu->caData,FINDUSER_OFFONLINE);
    }else{
        strcpy(respdu->caData,FINDUSER_ONLINE);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoAddFriendRequest(PDU *pdu)
{
    char requestUsername[32];
    char targetUsername[32];
    strncpy(requestUsername,pdu->caData,32);
    strncpy(targetUsername,pdu->caData+32,32);
    int ret = DBInstance::GetInstance().HandleAddFriend(requestUsername,targetUsername);
    PDU *respdu = NULL;
    if(ret == -1){
        respdu = mkPDU(0);
        respdu->MsgType = MSGTYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData,ADDFRIEND_UNKNOWN_ERROR);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
    }else if(ret == 0){
        respdu = mkPDU(0);
        respdu->MsgType = MSGTYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData,ADDFRIEND_SELF);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
    }else if(ret == 1){
        respdu = mkPDU(0);
        respdu->MsgType = MSGTYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData,ADDFRIEND_REPEAT);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
    }else if(ret == 2){
        MyTcpServer::GetInstance().resend(targetUsername,pdu);
    }else{
        respdu = mkPDU(0);
        respdu->MsgType = MSGTYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData,ADDFRIEND_OFFLINE);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
    }
}

void MyTcpSocket::DoAddUserRelation(PDU *pdu)
{
    char requestUsername[32];
    char targetUsername[32];
    strncpy(requestUsername,pdu->caData,32);
    strncpy(targetUsername,pdu->caData+32,32);
    DBInstance::GetInstance().HandleAddUserRelation(requestUsername,targetUsername);
    MyTcpServer::GetInstance().resend(requestUsername,pdu);
}

void MyTcpSocket::DoRefuseUserRelation(PDU *pdu)
{
    char requestUsername[32];
    strncpy(requestUsername,pdu->caData,32);
    MyTcpServer::GetInstance().resend(requestUsername,pdu);
}

void MyTcpSocket::DoFlushFriendRequest(PDU *pdu)
{
    char requestUsername[32];
    strncpy(requestUsername,pdu->caData,32);
    QStringList users = DBInstance::GetInstance().HandleFlushFriend(requestUsername);
    const int fixedSize = 32;
    uint msgLength = fixedSize * users.size();
    PDU *respdu = mkPDU(msgLength);
    respdu->MsgType = MSGTYPE_FLUSHFRIEND_RESPOND;
    for(int i = 0;i < users.size();++ i){
        memcpy((char*)(respdu->msg)+i*32,users.at(i).toStdString().c_str(),users.at(i).size());
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoDelFriendRequest(PDU *pdu)
{
    char requestUser[32];
    char targetUser[32];
    memcpy(requestUser,pdu->caData,32);
    memcpy(targetUser,pdu->caData+32,32);
    bool ret = DBInstance::GetInstance().HandleDelRelation(requestUser,targetUser);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_DELFRIEND_RESPOND;
    if(ret){
        strcpy(respdu->caData,DELFRIEND_SUCCESS);
    }else{
        strcpy(respdu->caData,DELFRIEND_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoPrivateChatRequest(PDU *pdu)
{
    char chatName[32];
    memcpy(chatName,pdu->caData+32,32);
    bool ret = DBInstance::GetInstance().HandleUserIsOnline(chatName);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_PRIVATECHAT_RESPOND;
    if(ret){
        strcpy(respdu->caData,PRIVATECHAT_SUCCESS);
    }else{
        strcpy(respdu->caData,PRIVATECHAT_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoPrivateChatMsg(PDU *pdu)
{
    char chatName[32];
    memcpy(chatName,pdu->caData+32,32);
    bool ret = DBInstance::GetInstance().HandleUserIsOnline(chatName);
    if(ret){
        MyTcpServer::GetInstance().resend(chatName,pdu);
        return;
    }else{
        PDU *respdu = mkPDU(0);
        respdu->MsgType = MSGTYPE_PRIVATECHAT_RESPOND;
        strcpy(respdu->caData,PRIVATECHAT_FAIL);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
    }
}

void MyTcpSocket::DoGroupChat(PDU *pdu)
{
    char sendName[32];
    memcpy(sendName,pdu->caData,32);
    QStringList users = DBInstance::GetInstance().HandleAllOnlineUsers();
    for(int i = 0;i < users.size();++ i){
        if(strcmp(sendName,users.at(i).toStdString().c_str()) == 0){
            MyTcpServer::GetInstance().resend(sendName,pdu);
            continue;
        }
        bool isFriend = DBInstance::GetInstance().HandleUserIsFriend(sendName,users.at(i).toStdString().c_str());
        if(isFriend){
            MyTcpServer::GetInstance().resend(users.at(i).toStdString().c_str(),pdu);
        }
    }
}

void MyTcpSocket::DoCreateDir(PDU *pdu)
{
    char username[32];
    char newDir[32];
    strncpy(username,pdu->caData,32);
    strncpy(newDir,pdu->caData+32,32);
    QString curPath((char*)(pdu->msg));
    QString path = QString("%1/%2").arg(curPath).arg(newDir);
    qDebug() << path;
    QDir dir;
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_CREATEDIR_RESPOND;
    if(dir.exists(path)){
        strcpy(respdu->caData,CREATEDIR_FAIL);
    }else{
        dir.mkdir(path);
        strcpy(respdu->caData,CREATEDIR_SUCCESS);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoFlushDir(PDU *pdu)
{
    char username[32];
    strncpy(username,pdu->caData,32);
    QString curPath((char*)(pdu->msg));
    QString path = QString("%1").arg(curPath);
    QDir dir(path);
    QFileInfoList rets = dir.entryInfoList();
    int nums = rets.size() - 2;
    PDU *respdu = mkPDU(sizeof(FileInfo) * nums);
    respdu->MsgType = MSGTYPE_FLUSHDIR_RESPOND;
    FileInfo* fileInfo = NULL;
    QString fileName;
    for(int i = 2;i < rets.size();++ i){
        fileInfo = (FileInfo*)(respdu->msg)+(i-2);
        fileName = rets.at(i).fileName();
        memcpy(fileInfo->fileName,fileName.toStdString().c_str(),fileName.size());
        if(rets.at(i).isDir()){
            fileInfo->fileType = 0;
        }else if(rets.at(i).isFile()){
            fileInfo->fileType = 1;
        }
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoDelDir(PDU *pdu)
{
    char username[32];
    char delDir[32];
    strncpy(username,pdu->caData,32);
    strncpy(delDir,pdu->caData+32,32);
    QString curPath((char*)(pdu->msg));
    QString path = QString("%1/%2").arg(curPath).arg(delDir);
    // qDebug() << path;
    QFileInfo fileInfo(path);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_DELDIR_RESPND;
    if(fileInfo.isDir()){
        QDir dir(path);
        dir.removeRecursively();
        strcpy(respdu->caData,DELDIR_SUCCESS);
    }else{
        strcpy(respdu->caData,DELDIR_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoDelFile(PDU *pdu)
{
    char username[32];
    char delFile[32];
    strncpy(username,pdu->caData,32);
    strncpy(delFile,pdu->caData+32,32);
    QString curPath((char*)(pdu->msg));
    QString path = QString("%1/%2").arg(curPath).arg(delFile);
    // qDebug() << path;
    QFileInfo fileInfo(path);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_DELFILE_RESPND;
    if(fileInfo.isFile()){
        QFile file(path);
        file.remove();
        strcpy(respdu->caData,DELFILE_SUCCESS);
    }else{
        strcpy(respdu->caData,DELFILE_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoRename(PDU *pdu)
{
    char oldName[32];
    char newName[32];
    strncpy(oldName,pdu->caData,32);
    strncpy(newName,pdu->caData+32,32);
    QString curPath((char*)(pdu->msg));
    QString oldPath = QString("%1/%2").arg(curPath).arg(oldName);
    QString newPath = QString("%1/%2").arg(curPath).arg(newName);
    QFileInfo fileInfo(oldPath);
    QDir dir;
    QFile file(oldPath);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_RENAME_RESPOND;
    bool ret = true;
    if(fileInfo.isDir()){
        ret = dir.rename(oldPath,newPath);
    }else{
        ret = file.rename(newPath);
    }
    if(ret){
        strcpy(respdu->caData,RENAME_SUCCESS);
    }else{
        strcpy(respdu->caData,RENAME_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoEnterDir(PDU *pdu)
{
    char dirName[32];
    strncpy(dirName,pdu->caData,32);
    QString curPath((char*)(pdu->msg));
    QString dirPath = QString("%1/%2").arg(curPath).arg(dirName);
    QFileInfo fileInfo(dirPath);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_ENTERDIR_RESPOND;
    if(fileInfo.isDir()){
        strncpy(respdu->caData,dirName,32);
        strcpy(respdu->caData+32,ENTERDIR_SUCCESS);
    }else{
        strncpy(respdu->caData,dirName,32);
        strcpy(respdu->caData+32,ENTERDIR_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoMoveFile(PDU *pdu)
{
    int srcLen;
    int destLen;
    sscanf(pdu->caData,"%d %d",&srcLen,&destLen);
    QByteArray srcData(pdu->msg, srcLen);
    QByteArray destData(pdu->msg + srcLen + 1, destLen);

    QString srcFilePath = QString::fromUtf8(srcData);
    QString destDirPath = QString::fromUtf8(destData);
    QFileInfo srcFileInfo(srcFilePath);
    QFileInfo destDirInfo(destDirPath);
    PDU *respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_MOVEFILE_RESPOND;
    if(srcFileInfo.isFile()){
        if(destDirInfo.isDir()){
            int lastIndex = srcFilePath.lastIndexOf("/");
            QString srcFile = srcFilePath.right(srcFilePath.size() - lastIndex-1);
            QString newPath = destDirPath + "/" + srcFile;
            // qDebug() << srcFilePath << "\t" << newPath;
            QFile::rename(srcFilePath,newPath);
            strcpy(respdu->caData,MOVEFILE_SUCCESS);
        }else{
            strcpy(respdu->caData,DESTDIR_FAIL);
        }
    }else{
        strcpy(respdu->caData,MOVEFILE_FAIL);
    }
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoUploadFile(PDU *pdu)
{
    char fileName[32] = { '\0' };
    qint64 fileSize = 0;
    sscanf(pdu->caData,"%s %lld",fileName,&fileSize);
    QString destDir(pdu->msg);
    QString strPath = QString("%1/%2").arg(destDir).arg(fileName);
    m_destFile.setFileName(strPath);
    if(m_destFile.open(QIODevice::WriteOnly)){
        m_isUpload = true;
        m_totalSize = fileSize;
        m_recvSize = 0;
    }
}

void MyTcpSocket::DoDownloadFile(PDU *pdu)
{
    char fileName[32];
    strncpy(fileName,pdu->caData,32);
    QString dirPath(pdu->msg);
    QString filePath = dirPath + "/" + QString(fileName);
    PDU* respdu = mkPDU(32);
    respdu->MsgType = MSGTYPE_DOWNLOADFILE_RESPOND;
    QFileInfo file(filePath);
    if(file.isDir()){
        memcpy(respdu->msg,DOWNLOADFILE_FAIL_DIR,32);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
        return;
    }else{
        sprintf(respdu->caData,"%s %lld",fileName,file.size());
        memcpy(respdu->msg,DOWNLOADFILE_START,32);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
        m_downloadFile.setFileName(filePath);
        timer->start(1000);
    }
}

void MyTcpSocket::DoShareFile(PDU *pdu)
{
    char fileName[32];
    strncpy(fileName,pdu->caData,32);
    QString dirPath(pdu->msg);
    QString filePath = dirPath + "/" + QString(fileName);
    QFileInfo file(filePath);
    if(file.isDir()){
        PDU* respdu = mkPDU(0);
        respdu->MsgType = MSGTYPE_SHAREFILE_RESPOND;
        strcpy(respdu->caData,SHAREFILE_DIR_FAIL);
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
        return;
    }else{
        char sendName[32];
        strncpy(sendName,pdu->caData+32,32);
        QStringList users = DBInstance::GetInstance().HandleOnlineFriends(sendName);
        int userNums = users.size();
        PDU* respdu = mkPDU(userNums*32);
        respdu->MsgType = MSGTYPE_SHAREFILE_RESPOND;
        strcpy(respdu->caData,SHAREFILE_DIR_SUCCESS);
        for(int i = 0;i < userNums;++ i){
            strncpy((char*)(respdu->msg+32*i),users.at(i).toStdString().c_str(),users.at(i).size());
        }
        this->write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
    }
}

void MyTcpSocket::DoShareFileToFriends(PDU *pdu)
{
    char sendName[32];
    int userNums;
    sscanf(pdu->caData,"%s %d",sendName,&userNums);
    PDU *respdu = mkPDU(pdu->MsgLength-userNums*32);
    respdu->MsgType = MSGTYPE_RECVFILEFROMFRIEND_REQUEST;
    memcpy(respdu->msg,pdu->msg+32*userNums,pdu->MsgLength-userNums*32);
    strncpy(respdu->caData,sendName,32);
    char recvName[32];
    for(int i = 0;i < userNums;++ i){
        strncpy(recvName,(char*)(pdu->msg+32*i),32);
        MyTcpServer::GetInstance().resend(recvName,respdu);
    }
    free(respdu);
    respdu = NULL;
    respdu = mkPDU(0);
    respdu->MsgType = MSGTYPE_SHAREFILETOFRIEND_RESPOND;
    strcpy(respdu->caData,SHAREFILE_SUCCESS);
    this->write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void MyTcpSocket::DoHandleCopyShareFile(PDU *pdu)
{
    char recvName[32];
    strncpy(recvName,pdu->caData,32);
    QString filePath(pdu->msg);
    int index = filePath.lastIndexOf('/');
    QString fileName = filePath.right(filePath.size()-index-1);
    QString newPath = "./usersFile/" + QString(recvName) + "/" + fileName;

    qDebug() << filePath << "\t" << newPath;

    QFile::copy(filePath,newPath);
}

QString MyTcpSocket::GetUserName() const
{
    return this->m_strUsername;
}

void MyTcpSocket::recvMsg()
{
    if(!m_isUpload){
        qDebug() << this->bytesAvailable();
        uint PDULength = 0;
        this->read((char*)&PDULength,sizeof(uint));
        uint MsgLength = PDULength - sizeof(PDU);
        PDU *pdu = mkPDU(MsgLength);
        this->read((char*)pdu+sizeof(uint),PDULength-sizeof(uint));
        switch (pdu->MsgType) {
        case MSGTYPE_REGISTER_REQUEST:
            DoRegisterRequest(pdu);
            break;
        case MSGTYPE_LOGIN_REQUEST:
            DoLoginRequest(pdu);
            break;
        case MSGTYPE_ALL_ONLINEUSRES_REQUEST:
            DoShowAllOnlineUsersRequest();
            break;
        case MSGTYPE_FINDUSER_REQUEST:
            DoFindUserRequest(pdu);
            break;
        case MSGTYPE_ADD_FRIEND_REQUEST:
            DoAddFriendRequest(pdu);
            break;
        case MSGTYPE_AGREE_ADDFRIEND:
            DoAddUserRelation(pdu);
            break;
        case MSGTYPE_REFUSE_ADDFRIEND:
            DoRefuseUserRelation(pdu);
            break;
        case MSGTYPE_FLUSHFRIEND_REQUEST:
            DoFlushFriendRequest(pdu);
            break;
        case MSGTYPE_DELFRIEND_REQUEST:
            DoDelFriendRequest(pdu);
            break;
        case MSGTYPE_PRIVATECHAT_REQUEST:
            DoPrivateChatRequest(pdu);
            break;
        case MSGTYPE_PRIVATECHAT_SENDMSG:
            DoPrivateChatMsg(pdu);
            break;
        case MSGTYPE_GROUPCHAT_REQUEST:
            DoGroupChat(pdu);
            break;

        case MSGTYPE_CREATEDIR_REQUEST:
            DoCreateDir(pdu);
            break;
        case MSGTYPE_FLUSHDIR_REQUEST:
            DoFlushDir(pdu);
            break;
        case MSGTYPE_DELDIR_REQUEST:
            DoDelDir(pdu);
            break;
        case MSGTYPE_DELFILE_REQUEST:
            DoDelFile(pdu);
            break;
        case MSGTYPE_RENAME_REQUEST:
            DoRename(pdu);
            break;
        case MSGTYPE_ENTERDIR_REQUEST:
            DoEnterDir(pdu);
            break;
        case MSGTYPE_MOVEFILE_REQUEST:
            DoMoveFile(pdu);
            break;
        case MSGTYPE_UPLOADFILE_REQUEST:
            DoUploadFile(pdu);
            break;
        case MSGTYPE_DOWNLOADFILE_REQUEST:
            DoDownloadFile(pdu);
            break;
        case MSGTYPE_SHAREFILE_REQUEST:
            DoShareFile(pdu);
            break;
        case MSGTYPE_SHAREFILETOFRIEND_REQUEST:
            DoShareFileToFriends(pdu);
            break;
        case MSGTYPE_RECVFILEFROMFRIEND_RESPOND:
            DoHandleCopyShareFile(pdu);
            break;
        default:
            break;
        }
        free(pdu);
        pdu = NULL;
    }else{
        QByteArray buff = readAll();
        m_destFile.write(buff);
        PDU *respdu = NULL;
        respdu = mkPDU(0);
        respdu->MsgType = MSGTYPE_UPLOADFILE_RESPOND;
        m_recvSize += buff.size();
        if(m_totalSize == m_recvSize){
            m_destFile.close();
            m_isUpload = false;
            strcpy(respdu->caData,UPLOADFILE_SUCCESS);
            this->write((char*)(respdu),respdu->PDULength);
            free(respdu);
            respdu = NULL;
        }else if(m_totalSize < m_recvSize){
            m_destFile.close();
            m_isUpload = false;
            strcpy(respdu->caData,UPLOADFILE_FAIL);
            write((char*)(respdu),respdu->PDULength);
            free(respdu);
            respdu = NULL;
        }
    }
}

void MyTcpSocket::Offline()
{
    DBInstance::GetInstance().HandleLogout(m_strUsername.toStdString().c_str());
    emit MyOfflineSignal(this);
}

void MyTcpSocket::sendFileToClient()
{
    timer->stop();
    m_downloadFile.open(QIODevice::ReadOnly);
    char *pData = new char[4096];
    qint64 ret = 0;
    while(true){
        ret = m_downloadFile.read(pData,4096);
        if(ret > 0 && ret <= 4096){
            this->write(pData,ret);
        }else if(ret == 0){
            m_downloadFile.close();
            break;
        }else if(ret < 0){
            m_downloadFile.close();
            break;
        }
    }
    delete []pData;
    pData = NULL;
}
