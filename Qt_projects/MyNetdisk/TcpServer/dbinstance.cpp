#include "dbinstance.h"
#include <QDebug>
#include <QSqlQuery>
#include <QtGlobal>

DBInstance &DBInstance::GetInstance()
{
    static DBInstance instance;
    return instance;
}

DBInstance::DBInstance(QObject *parent)
    : QObject{parent}
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

void DBInstance::Init_DB()
{
    m_db.setHostName("localhost");
    m_db.setDatabaseName("./MyNetdisk.db");
    if(m_db.open()){
        qDebug() << "success";
    }else{
        qDebug() << "failure";
    }
}

bool DBInstance::HandleRegister(const char *username, const char *password)
{
    if(username == NULL || password == NULL){
        return false;
    }
    QString data = QString("insert into userInfo(username,password) values(\'%1\',\'%2\')").arg(QString(username)).arg(QString(password));
    QSqlQuery query;
    return query.exec(data);
}

int DBInstance::HandleLogin(const char *username, const char *password)
{
    if(username == NULL || password == NULL){
        return false;
    }
    QString data = QString("select * from userInfo where username = \'%1\' and password = \'%2\'").arg(QString(username)).arg(QString(password));
    qDebug() << data;
    QSqlQuery query;
    query.exec(data);
    if(query.next()){
        int isOnline = query.value(3).toString().toInt();
        // qDebug() << isOnline;
        int ret = isOnline;
        if(isOnline == 0){
            data = QString("update userInfo set isOnline = 1 where username = \'%1\'").arg(QString(username));
            query.exec(data);
        }
        return ret;
    }else{
        return -1;
    }
}

bool DBInstance::HandleLogout(const char * username)
{
    QString data = QString("update userInfo set isOnline = 0 where username = \'%1\'").arg(QString(username));
    QSqlQuery query;
    return query.exec(data);
}

QStringList DBInstance::HandleAllOnlineUsers()
{
    QString data = QString("select username from userInfo where isOnline = 1");
    QSqlQuery query;
    query.exec(data);
    QStringList result;
    result.clear();
    while(query.next()){
        result.append(query.value(0).toString());
    }
    return result;
}

int DBInstance::HandleFindUser(const char *username)
{
    QString data("select isOnline from userInfo where username = :username");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":username",QString(username));
    query.exec();
    if(query.next()){
        int isOnline = query.value(0).toString().toInt();
        return isOnline;
    }else{
        return -1;
    }
}

int DBInstance::HandleGetUserId(const char * username)
{
    QString data("select userId from userInfo where username = :username");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":username",username);
    query.exec();
    if(query.next()){
        int ret = query.value(0).toString().toInt();
        return ret;
    }else{
        return -1;
    }
}

QString DBInstance::HandleGetUsername(int id)
{
    QString data("select username from userInfo where userId = :id");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":id",id);
    query.exec();
    if(query.next()){
        QString ret = query.value(0).toString();
        return ret;
    }else{
        return "";
    }
}

int DBInstance::HandleAddFriend(const char *src, const char *target)
{
    int srcId = HandleGetUserId(src);
    int targetId = HandleGetUserId(target);
    if(srcId == -1 || targetId == -1){
        return -1;
    }else if(srcId == targetId){
        return 0;
    }else{
        int minId = qMin(srcId,targetId);
        int maxId = qMax(srcId,targetId);
        QString data("select * from userRelation where minUserId = :minId and maxUserId = :maxId");
        QSqlQuery query;
        query.prepare(data);
        query.bindValue(":minId",minId);
        query.bindValue(":maxId",maxId);
        query.exec();
        if(query.next()){
            // 已经是好友关系
            return 1;
        }else{
            // 非好友关系
            data = QString("select isOnline from userInfo where userId = :targetId");
            query.prepare(data);
            query.bindValue(":targetId",targetId);
            query.exec();
            query.next();
            int ret = query.value(0).toInt();
            if(ret){
                // 要添加的人在线
                return 2;
            }else{
                // 要添加的人不在线
                return 3;
            }
        }
    }
}

void DBInstance::HandleAddUserRelation(const char *srcName, const char *targetName)
{
    if(srcName == NULL || targetName == NULL){ return; }
    int srcId = HandleGetUserId(srcName);
    int targetId = HandleGetUserId(targetName);
    if(srcId == -1 || targetId == -1){
        return;
    }else{
        int minId = qMin(srcId,targetId);
        int maxId = qMax(srcId,targetId);
        QString data("insert into userRelation (minUserId,maxUserId) values (:minId,:maxId)");
        QSqlQuery query;
        query.prepare(data);
        query.bindValue(":minId",minId);
        query.bindValue(":maxId",maxId);
        query.exec();
    }
}

QStringList DBInstance::HandleFlushFriend(const char *username)
{
    QStringList ret;
    ret.clear();
    if(username == NULL){
        return ret;
    }
    int userId = HandleGetUserId(username);
    if(userId == -1){
        return ret;
    }
    QString data("select maxUserId from userRelation where minUserId = :userId");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":userId",userId);
    query.exec();
    while(query.next()){
        int id = query.value(0).toInt();
        QString tempStr = HandleGetUsername(id);
        ret.append(tempStr);
    }
    data = QString("select minUserId from userRelation where maxUserId = :userId");
    query.prepare(data);
    query.bindValue(":userId",userId);
    query.exec();
    while(query.next()){
        int id = query.value(0).toInt();
        QString tempStr = HandleGetUsername(id);
        ret.append(tempStr);
    }
    return ret;
}

bool DBInstance::HandleDelRelation(const char *srcName, const char *targetName)
{
    if(srcName == NULL || targetName == NULL){ return false; }
    int srcId = HandleGetUserId(srcName);
    int targetId = HandleGetUserId(targetName);
    if(srcId == -1 || targetId == -1){
        return false;
    }else{
        int minId = qMin(srcId,targetId);
        int maxId = qMax(srcId,targetId);
        QString data("delete from userRelation where minUserId = :minId and maxUserId = :maxId");
        QSqlQuery query;
        query.prepare(data);
        query.bindValue(":minId",minId);
        query.bindValue(":maxId",maxId);
        return query.exec();
    }
}

bool DBInstance::HandleUserIsOnline(const char *destName)
{
    if(destName == NULL) return false;
    QString data("select isOnline from userInfo where username = :destName");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":destName",destName);
    query.exec();
    query.next();
    int ret = query.value(0).toInt();
    return ret;
}

bool DBInstance::HandleUserIsFriend(const char *srcName, const char *targetName)
{
    if(srcName == NULL || targetName == NULL){ return false; }
    int srcId = HandleGetUserId(srcName);
    int targetId = HandleGetUserId(targetName);
    if(srcId == -1 || targetId == -1){
        return false;
    }else{
        int minId = qMin(srcId,targetId);
        int maxId = qMax(srcId,targetId);
        QString data("select * from userRelation where minUserId = :minId and maxUserId = :maxId");
        QSqlQuery query;
        query.prepare(data);
        query.bindValue(":minId",minId);
        query.bindValue(":maxId",maxId);
        query.exec();
        return query.next();
    }
}

QStringList DBInstance::HandleOnlineFriends(const char *sendName)
{
    QStringList onlineUsers;
    onlineUsers.clear();
    onlineUsers = HandleAllOnlineUsers();
    QStringList ret;
    ret.clear();
    for(int i = 0;i < onlineUsers.size();++ i){
        QString checkUser = onlineUsers.at(i);
        bool isFriend = HandleUserIsFriend(sendName,checkUser.toStdString().c_str());
        if(isFriend){
            ret.append(checkUser);
        }
    }
    return ret;
}

DBInstance::~DBInstance()
{
    m_db.close();
}
