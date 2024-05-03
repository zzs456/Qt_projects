#include "widget.h"
#include "ui_widget.h"
#include "logindialog.h"
#include "myprotocol.h"
#include "privatechat.h"

#include <QFile>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    init_Config();

    setMinimumSize(QSize(800, 600));
    setWindowState(Qt::WindowMaximized);


    timer = new QTimer;
    m_isDownload = false;

    connect(timer,&QTimer::timeout,this,&Widget::do_UploadFileData);

    m_tcpSocket.connectToHost(QHostAddress(m_IP),m_port);
    connect(&m_tcpSocket,&QTcpSocket::connected,this,&Widget::ConSuccess);

    connect(&m_tcpSocket,&QTcpSocket::readyRead,this,&Widget::recvMsg);

    // 注册信号与处理注册
    connect(&LoginDialog::GetInstance(),&LoginDialog::RegisterSignal,this,&Widget::do_Register);
    // 登录信号与处理注册
    connect(&LoginDialog::GetInstance(),&LoginDialog::LoginSignal,this,&Widget::do_Login);

    // 处理注册请求的回复
    connect(this,&Widget::RegisterRespondSignal,&LoginDialog::GetInstance(),&LoginDialog::DoRegisterRespond);
    // 处理登录请求的回复
    connect(this,&Widget::LoginRespondSignal,&LoginDialog::GetInstance(),&LoginDialog::DoLoginRespond);

    // 显示该窗口
    connect(&LoginDialog::GetInstance(),&LoginDialog::UpdateShow,this,&Widget::do_Show);

    // connect(&m_tcpSocket,&QTcpSocket::disconnected,[this](){ qDebug() << "失败"; });

    ui->listWidget->setCurrentRow(0);
    chatWidget = new ChatWidget;
    chatWidget->setUsername(m_strUsername);
    fileWidget = new FileWidget;

    ui->stackedWidget->addWidget(chatWidget);
    ui->stackedWidget->addWidget(fileWidget);

    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->listWidget,&QListWidget::currentRowChanged,ui->stackedWidget,&QStackedWidget::setCurrentIndex);

    // 在线用户
    connect(chatWidget,&ChatWidget::showOnlineUsersSignal,this,&Widget::do_ShowOnlineUsers);
    connect(this,&Widget::ShowAllOnlineUsersSignal,chatWidget,&ChatWidget::do_showOnlineUsers);

    // 查找用户
    connect(chatWidget,&ChatWidget::findUserSignal,this,&Widget::do_FindUser);
    connect(this,&Widget::FindUserSignal,chatWidget,&ChatWidget::do_FindUser);

    // 添加好友
    connect(chatWidget,&ChatWidget::addUserSignal,this,&Widget::do_AddUser);
    connect(this,&Widget::AddFriendSignal,chatWidget,&ChatWidget::do_AddUser);
    // connect(this,&Widget::AgreeAddFriendSignal,chatWidget,&ChatWidget::do_AgreeAddUser);

    // 刷新好友
    connect(chatWidget,&ChatWidget::flushFriendSignal,this,&Widget::do_FlushFriend);

    // 删除好友
    connect(chatWidget,&ChatWidget::delFriendSignal,this,&Widget::do_DelFriend);
    connect(this,&Widget::DelFriendSignal,chatWidget,&ChatWidget::do_DelFriend);

    // 私聊信息
    connect(chatWidget,&ChatWidget::privateChatFriendSignal,this,&Widget::do_PrivateChat);
    connect(&PrivateChat::GetInstance(),&PrivateChat::SendPrivateChatMsg,this,&Widget::do_PrivateChatMsg);

    // 群聊
    connect(chatWidget,&ChatWidget::groupChatSignal,this,&Widget::do_GroupChat);

    // 创建文件夹
    connect(fileWidget,&FileWidget::CreateDirSignal,this,&Widget::do_CreateDir);

    // 刷新文件夹
    connect(fileWidget,&FileWidget::FlushDirSignal,this,&Widget::do_FlushDir);

    // 删除文件夹
    connect(fileWidget,&FileWidget::DelDirSignal,this,&Widget::do_DelDir);

    // 删除文件
    connect(fileWidget,&FileWidget::DelFileSignal,this,&Widget::do_DelFile);

    // 重命名操作
    connect(fileWidget,&FileWidget::RenameSignal,this,&Widget::do_Rename);

    // 进入文件夹
    connect(fileWidget,&FileWidget::EnterDir,this,&Widget::do_EnterDir);

    // 返回上一级目录
    connect(fileWidget,&FileWidget::ReturnFatherDir,this,&Widget::do_ReturnFatherDir);

    // 移动文件
    connect(fileWidget,&FileWidget::MoveFileSignal,this,&Widget::do_MoveFile);
    connect(fileWidget,&FileWidget::SelectDestFileSignal,this,&Widget::do_SelectDest);

    // 上传文件
    connect(fileWidget,&FileWidget::UploadFileSignal,this,&Widget::do_UploadFile);

    // 下载文件
    connect(fileWidget,&FileWidget::DownloadFileSignal,this,&Widget::do_DownloadFile);

    // 分享文件
    connect(fileWidget,&FileWidget::ShareFileSignal,this,&Widget::do_ShareFileConfirm);
    connect(fileWidget,&FileWidget::ShareFileToFriendsSignal,this,&Widget::do_ShareFileToFriends);
}



void Widget::init_Config()
{
    QFile configFile(":/config/Network.config");
    bool flag = configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    if(flag){
        qDebug() << "配置文件打开成功!";
        QByteArray contentData = configFile.readAll();
        QString contentStr = contentData.toStdString().c_str();
        configFile.close();
        qDebug() << contentStr;
        QStringList strList = contentStr.split("\n");
        qDebug() << strList.size();
        this->m_IP = strList[0];
        this->m_port = strList[1].toUShort();
        qDebug() << this->m_IP << "\t" << this->m_port;
    }else{
        qDebug() << "配置文件打开失败!";
    }
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::GetUsername() const
{
    return m_strUsername;
}

void Widget::HandleAgreeAddUser(PDU *pdu)
{
    QMessageBox::StandardButton ret = chatWidget->do_AgreeAddUser(pdu);
    PDU *respdu = mkPDU(0);
    memcpy(respdu->caData,pdu->caData,64);
    if(ret == QMessageBox::Yes){
        respdu->MsgType = MSGTYPE_AGREE_ADDFRIEND;
    }else{
        respdu->MsgType = MSGTYPE_REFUSE_ADDFRIEND;
    }
    m_tcpSocket.write((char*)respdu,respdu->PDULength);
    free(respdu);
    respdu = NULL;
}

void Widget::HandleAddUserAgree(PDU *pdu)
{
    char targetUsername[32];
    strncpy(targetUsername,pdu->caData+32,32);
    chatWidget->do_AddUserResult(true,QString(targetUsername));
}

void Widget::HandleAddUserRefuse(PDU *pdu)
{
    char targetUsername[32];
    strncpy(targetUsername,pdu->caData+32,32);
    chatWidget->do_AddUserResult(false,QString(targetUsername));
}

void Widget::HandleFlushFriend(PDU *pdu)
{
    chatWidget->do_FlushFriend(pdu);
}

void Widget::HandlePrivateChat(PDU *pdu)
{
    chatWidget->do_PrivateChat(pdu);
}

void Widget::HandlePrivateUserOffline(PDU *pdu)
{
    if(strcmp(pdu->caData,PRIVATECHAT_SUCCESS) == 0){
        chatWidget->do_PrivateUserOffline(true);
    }else{
        chatWidget->do_PrivateUserOffline(false);
    }
}

void Widget::HandleGroupChat(PDU *pdu)
{
    char sendName[32];
    memcpy(sendName,pdu->caData,32);
    if(strcmp(sendName,m_strUsername.toStdString().c_str()) == 0){
        chatWidget->do_GroupChat(pdu,true);
    }else{
        chatWidget->do_GroupChat(pdu,false);
    }
}

void Widget::HandleCreateDir(PDU *pdu)
{
    qDebug() << pdu->caData;
    char ret[32];
    strncpy(ret,pdu->caData,32);
    if(strcmp(ret,CREATEDIR_SUCCESS) == 0){
        fileWidget->HandleCreateDirRespond(true);
    }else{
        fileWidget->HandleCreateDirRespond(false);
    }
}

void Widget::HandleFlushDir(PDU *pdu)
{
    fileWidget->HandleFlushDirRespond(pdu);
}

void Widget::HandleDelDir(PDU *pdu)
{
    char ret[32];
    strncpy(ret,pdu->caData,32);
    if(strcmp(ret,DELDIR_SUCCESS) == 0){
        fileWidget->HandleDelDirRespond(true);
    }else{
        fileWidget->HandleDelDirRespond(false);
    }
}

void Widget::HandleDelFile(PDU *pdu)
{
    char ret[32];
    strncpy(ret,pdu->caData,32);
    if(strcmp(ret,DELFILE_SUCCESS) == 0){
        fileWidget->HandleDelFileRespond(true);
    }else{
        fileWidget->HandleDelFileRespond(false);
    }
}

void Widget::HandleRename(PDU *pdu)
{
    char ret[32];
    strncpy(ret,pdu->caData,32);
    if(strcmp(ret,RENAME_SUCCESS) == 0){
        fileWidget->HandleRenameRespond(true);
    }else{
        fileWidget->HandleRenameRespond(false);
    }
}

void Widget::HandleEnterDir(PDU *pdu)
{
    char dirName[32];
    char enterRes[32];
    strncpy(dirName,pdu->caData,32);
    strncpy(enterRes,pdu->caData+32,32);

    if(strcmp(enterRes,ENTERDIR_SUCCESS) == 0){
        m_curDir += QString("/%1").arg(dirName);
        this->do_FlushDir();
    }
}

void Widget::HandleMoveFile(PDU *pdu)
{
    char moveRet[32];
    strncpy(moveRet,pdu->caData,32);
    if(strcmp(moveRet,MOVEFILE_SUCCESS) == 0){
        fileWidget->HandleMoveFileRespond(0);
    }else if(strcmp(moveRet,MOVEFILE_FAIL) == 0){
        fileWidget->HandleMoveFileRespond(1);
    }else{
        fileWidget->HandleMoveFileRespond(2);
    }
}

void Widget::HandleUploadFile(PDU *pdu)
{
    char uploadRet[32];
    strncpy(uploadRet,pdu->caData,32);
    if(strcmp(uploadRet,UPLOADFILE_SUCCESS) == 0){
        fileWidget->HandleUploadFileRespond(true);
    }else{
        fileWidget->HandleUploadFileRespond(false);
    }
}

void Widget::HandleDownLoadFile(PDU *pdu)
{
    char downloadRet[32];
    strncpy(downloadRet,pdu->msg,32);
    if(strcmp(downloadRet,DOWNLOADFILE_FAIL_DIR) == 0){
        QMessageBox::warning(this,"下载文件","请选择文件进行下载");
        return;
    }else{
        char fileName[32];
        qint64 fileSize;
        sscanf(pdu->caData,"%s %lld",fileName,&fileSize);
        m_totalSize = fileSize;
        m_recvSize = 0;
        m_isDownload = true;
        m_saveFile.setFileName(m_saveFilePath);
        if(!m_saveFile.open(QIODevice::WriteOnly)){
            QMessageBox::warning(this,"下载文件","获得保存文件路径失败");
        }
    }
}

void Widget::HandleShareFileWidgetShow(PDU *pdu)
{
    fileWidget->HandleShareFileWidgetShow(pdu);
}

void Widget::HandleRecvFile(PDU *pdu)
{
    char sendName[32];
    strncpy(sendName,pdu->caData,32);
    QString filePath(pdu->msg);
    int lastIndex = filePath.lastIndexOf('/');
    QString fileName = filePath.right(filePath.size()-lastIndex-1);
    QString str = QString("%1 向你发送文件 %2,是否接收?").arg(QString(sendName)).arg(QString(fileName));
    int ret = QMessageBox::question(this,"分享文件",str);
    if(ret == QMessageBox::Yes){
        PDU *respdu = mkPDU(pdu->MsgLength);
        respdu->MsgType = MSGTYPE_RECVFILEFROMFRIEND_RESPOND;
        strncpy(respdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
        memcpy(respdu->msg,pdu->msg,pdu->MsgLength);
        m_tcpSocket.write((char*)respdu,respdu->PDULength);
        free(respdu);
        respdu = NULL;
    }else{
        return;
    }
}

void Widget::HandleShareFileToFriends(PDU *pdu)
{
    char ret[32];
    strncpy(ret,pdu->caData,32);
    if(strcmp(ret,SHAREFILE_SUCCESS) == 0){
        QMessageBox::about(this,"分享文件","分享文件成功");
    }
}


void Widget::ConSuccess()
{
    qDebug() << "连接成功!";
}

void Widget::do_Register(QString username, QString password)
{
    // 创建 PDU 对象
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_REGISTER_REQUEST;
    strncpy(pdu->caData,username.toStdString().c_str(),32);
    strncpy(pdu->caData+32,password.toStdString().c_str(),32);
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_Login(QString username, QString password)
{
    // 创建 PDU 对象
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_LOGIN_REQUEST;
    strncpy(pdu->caData,username.toStdString().c_str(),32);
    strncpy(pdu->caData+32,password.toStdString().c_str(),32);
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    m_strUsername = username;
    m_curDir = "./usersFile/"+m_strUsername;
    free(pdu);
    pdu = NULL;
}

void Widget::recvMsg()
{
    if(!m_isDownload){
        qDebug() << m_tcpSocket.bytesAvailable();
        uint si = m_tcpSocket.bytesAvailable();
        uint PDULength = 0;
        m_tcpSocket.read((char*)&PDULength,sizeof(uint));
        uint MsgLength = PDULength - sizeof(PDU);
        PDU *pdu = mkPDU(MsgLength);
        m_tcpSocket.read((char*)pdu+sizeof(uint),PDULength-sizeof(uint));
        // qDebug() << PDULength << "\t" << pdu->MsgLength;
        // char msg[1024];
        // m_tcpSocket.read(msg,si-PDULength);
        // qDebug() << msg;
        switch (pdu->MsgType) {
        case MSGTYPE_REGISTER_RESPOND:
            emit RegisterRespondSignal(pdu);
            break;
        case MSGTYPE_LOGIN_RESPOND:
            emit LoginRespondSignal(pdu);
            break;
        case MSGTYPE_ALL_ONLINEUSRES_RESPOND:
            emit ShowAllOnlineUsersSignal(pdu);
            break;
        case MSGTYPE_FINDUSER_RESPOND:
            emit FindUserSignal(pdu);
            break;
        case MSGTYPE_ADD_FRIEND_REQUEST:
            // emit AgreeAddFriendSignal(pdu);
            HandleAgreeAddUser(pdu);
            break;
        case MSGTYPE_ADD_FRIEND_RESPOND:
            emit AddFriendSignal(pdu);
            break;
        case MSGTYPE_AGREE_ADDFRIEND:
            HandleAddUserAgree(pdu);
            break;
        case MSGTYPE_REFUSE_ADDFRIEND:
            HandleAddUserRefuse(pdu);
            break;
        case MSGTYPE_FLUSHFRIEND_RESPOND:
            HandleFlushFriend(pdu);
            break;
        case MSGTYPE_DELFRIEND_RESPOND:
            emit DelFriendSignal(pdu);
            break;
        case MSGTYPE_PRIVATECHAT_REQUEST:
            HandlePrivateChat(pdu);
            break;
        case MSGTYPE_PRIVATECHAT_RESPOND:
            HandlePrivateUserOffline(pdu);
            break;
        case MSGTYPE_PRIVATECHAT_SENDMSG:
            HandlePrivateChat(pdu);
            break;
        case MSGTYPE_GROUPCHAT_REQUEST:
            HandleGroupChat(pdu);
            break;
        case MSGTYPE_CREATEDIR_RESPOND:
            HandleCreateDir(pdu);
            break;
        case MSGTYPE_FLUSHDIR_RESPOND:
            HandleFlushDir(pdu);
            break;
        case MSGTYPE_DELDIR_RESPND:
            HandleDelDir(pdu);
            break;
        case MSGTYPE_DELFILE_RESPND:
            HandleDelFile(pdu);
            break;
        case MSGTYPE_RENAME_RESPOND:
            HandleRename(pdu);
            break;
        case MSGTYPE_ENTERDIR_RESPOND:
            HandleEnterDir(pdu);
            break;
        case MSGTYPE_MOVEFILE_RESPOND:
            HandleMoveFile(pdu);
            break;
        case MSGTYPE_UPLOADFILE_RESPOND:
            HandleUploadFile(pdu);
            break;
        case MSGTYPE_DOWNLOADFILE_RESPOND:
            HandleDownLoadFile(pdu);
            break;
        case MSGTYPE_SHAREFILE_RESPOND:
            HandleShareFileWidgetShow(pdu);
            break;
        case MSGTYPE_RECVFILEFROMFRIEND_REQUEST:
            HandleRecvFile(pdu);
            break;
        case MSGTYPE_SHAREFILETOFRIEND_RESPOND:
            HandleShareFileToFriends(pdu);
            break;
        default:
            break;
        }
        free(pdu);
        pdu = NULL;
    }else{
        QByteArray buffer = m_tcpSocket.readAll();
        m_saveFile.write(buffer);
        m_recvSize += buffer.size();
        if(m_totalSize == m_recvSize){
            m_saveFile.close();
            m_totalSize = 0;
            m_recvSize = 0;
            m_isDownload = false;
            QMessageBox::information(this,"下载文件","下载文件成功");
        }else if(m_totalSize < m_recvSize){
            m_saveFile.close();
            m_totalSize = 0;
            m_recvSize = 0;
            m_isDownload = false;
            QMessageBox::critical(this,"下载文件","下载文件失败");
        }
    }

}

void Widget::do_Show()
{
    LoginDialog::GetInstance().close();
    this->show();
    this->setWindowTitle(m_strUsername);

    this->do_FlushDir();
}

void Widget::do_ShowOnlineUsers()
{
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_ALL_ONLINEUSRES_REQUEST;
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_FindUser(QString username)
{
    if(username.isEmpty()){
        return;
    }
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_FINDUSER_REQUEST;
    strncpy(pdu->caData,username.toStdString().c_str(),username.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_AddUser(QString username)
{
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_ADD_FRIEND_REQUEST;
    strncpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    strncpy(pdu->caData+32,username.toStdString().c_str(),username.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_FlushFriend()
{
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_FLUSHFRIEND_REQUEST;
    strncpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_DelFriend(QString strDelUser)
{
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_DELFRIEND_REQUEST;
    strncpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    strncpy(pdu->caData+32,strDelUser.toStdString().c_str(),strDelUser.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_PrivateChat(QString targetName)
{
    PDU *pdu = mkPDU(0);
    pdu->MsgType = MSGTYPE_PRIVATECHAT_REQUEST;
    strncpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    strncpy(pdu->caData+32,targetName.toStdString().c_str(),targetName.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_PrivateChatMsg(QString chatName, QString msg)
{
    QByteArray utf8msg = msg.toUtf8();
    PDU *pdu = mkPDU(utf8msg.size()+1);
    pdu->MsgType = MSGTYPE_PRIVATECHAT_SENDMSG;
    memcpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    memcpy(pdu->caData+32,chatName.toStdString().c_str(),chatName.size());
    strcpy((char*)(pdu->msg),utf8msg.data());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_GroupChat(QString msg)
{
    QByteArray utf8msg = msg.toUtf8();
    PDU *pdu = mkPDU(utf8msg.size()+1);
    pdu->MsgType = MSGTYPE_GROUPCHAT_REQUEST;
    memcpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    strcpy((char*)(pdu->msg),utf8msg.data());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_CreateDir(QString newDir)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    pdu->MsgType = MSGTYPE_CREATEDIR_REQUEST;
    memcpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    memcpy(pdu->caData+32,newDir.toStdString().c_str(),newDir.size());
    strcpy((char*)(pdu->msg),m_curDir.toStdString().c_str());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_FlushDir()
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    pdu->MsgType = MSGTYPE_FLUSHDIR_REQUEST;
    memcpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    strcpy((char*)(pdu->msg),m_curDir.toStdString().c_str());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_DelDir(QString dirName)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    pdu->MsgType = MSGTYPE_DELDIR_REQUEST;
    memcpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    memcpy(pdu->caData+32,dirName.toStdString().c_str(),dirName.size());
    strcpy((char*)(pdu->msg),m_curDir.toStdString().c_str());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_DelFile(QString fileName)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    pdu->MsgType = MSGTYPE_DELFILE_REQUEST;
    memcpy(pdu->caData,m_strUsername.toStdString().c_str(),m_strUsername.size());
    memcpy(pdu->caData+32,fileName.toStdString().c_str(),fileName.size());
    strcpy((char*)(pdu->msg),m_curDir.toStdString().c_str());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_Rename(QString oldName, QString newName)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    pdu->MsgType = MSGTYPE_RENAME_REQUEST;
    memcpy(pdu->caData,oldName.toStdString().c_str(),oldName.size());
    memcpy(pdu->caData+32,newName.toStdString().c_str(),newName.size());
    strcpy((char*)(pdu->msg),m_curDir.toStdString().c_str());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_EnterDir(QString dirName)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    pdu->MsgType = MSGTYPE_ENTERDIR_REQUEST;
    memcpy(pdu->caData,dirName.toStdString().c_str(),dirName.size());
    strcpy((char*)(pdu->msg),m_curDir.toStdString().c_str());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_ReturnFatherDir()
{
    QString strRootPath = "./usersFile/" + m_strUsername;
    if(strRootPath == m_curDir){
        fileWidget->HandleReturn();
    }else{
        int lastIndex = m_curDir.lastIndexOf('/');
        m_curDir.remove(lastIndex,m_curDir.length() - lastIndex);
        this->do_FlushDir();
    }
}

void Widget::do_MoveFile(QString fileName)
{
    m_moveFilePath.clear();
    m_moveFilePath = m_curDir + "/" + fileName;
}

void Widget::do_SelectDest(QString destName)
{
    if(destName.isEmpty()){
        m_selectDestPath.clear();
        m_selectDestPath = m_curDir;
    }else{
        m_selectDestPath.clear();
        m_selectDestPath = m_curDir + "/" + destName;
    }
    PDU *pdu = mkPDU(m_selectDestPath.size()+m_moveFilePath.size()+2);
    pdu->MsgType = MSGTYPE_MOVEFILE_REQUEST;
    sprintf(pdu->caData,"%d %d",m_moveFilePath.size(),m_selectDestPath.size());
    strcpy((char*)(pdu->msg),m_moveFilePath.toStdString().c_str());
    strcpy((char*)(pdu->msg)+m_moveFilePath.size()+1,m_selectDestPath.toStdString().c_str());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_UploadFile(QString fileName, qint64 fileSize)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    m_uploadFilePath = fileName;
    pdu->MsgType = MSGTYPE_UPLOADFILE_REQUEST;
    int lastIndex = fileName.lastIndexOf('/');
    QString fileN = fileName.right(fileName.size()-lastIndex-1);
    sprintf(pdu->caData,"%s %lld",fileN.toStdString().c_str(),fileSize);
    strncpy((char*)pdu->msg,m_curDir.toStdString().c_str(),m_curDir.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
    timer->start(1000);
}

void Widget::do_UploadFileData()
{
    timer->stop();
    QFile file(m_uploadFilePath);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"上传文件","打开文件失败");
        return;
    }
    char *buffer = new char[4096];
    qint64 ret = 0;
    while(true){
        ret = file.read(buffer,4096);
        if(ret > 0 && ret <= 4096){
            m_tcpSocket.write(buffer,ret);
        }else if(ret == 0){
            break;
        }else{
            QMessageBox::warning(this,"上传文件","上传文件失败");
            break;
        }
    }
    file.close();
    delete []buffer;
    buffer = NULL;
}

void Widget::do_DownloadFile(QString downloadFile, QString saveFile)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    m_saveFilePath = saveFile;
    pdu->MsgType = MSGTYPE_DOWNLOADFILE_REQUEST;
    memcpy(pdu->caData,downloadFile.toStdString().c_str(),downloadFile.size());
    strncpy((char*)pdu->msg,m_curDir.toStdString().c_str(),m_curDir.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_ShareFileConfirm(QString fileName)
{
    PDU *pdu = mkPDU(m_curDir.size()+1);
    pdu->MsgType = MSGTYPE_SHAREFILE_REQUEST;
    strncpy(pdu->caData,fileName.toStdString().c_str(),fileName.size());
    strncpy(pdu->caData+32,m_strUsername.toStdString().c_str(),m_strUsername.size());
    strncpy((char*)pdu->msg,m_curDir.toStdString().c_str(),m_curDir.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}

void Widget::do_ShareFileToFriends(QStringList &users, QString shareFile)
{
    QString sendFile = m_curDir + "/" + shareFile;
    PDU* pdu = mkPDU(users.size()*32+sendFile.size()+1);
    pdu->MsgType = MSGTYPE_SHAREFILETOFRIEND_REQUEST;
    sprintf(pdu->caData,"%s %d",m_strUsername.toStdString().c_str(),users.size());
    for(int i = 0;i < users.size();++ i){
        strncpy((char*)(pdu->msg+32*i),users.at(i).toStdString().c_str(),users.at(i).size());
    }
    strncpy((char*)(pdu->msg+32*users.size()),sendFile.toStdString().c_str(),sendFile.size());
    m_tcpSocket.write((char*)pdu,pdu->PDULength);
    free(pdu);
    pdu = NULL;
}
