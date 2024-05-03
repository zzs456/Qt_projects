#include "dbinstance.h"

#include <QSqlQuery>
#include <QtGlobal>
#include <QDebug>

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
    m_db.setDatabaseName("./MyDataBase.db");
    if(m_db.open()){
        qDebug() << "success";
    }else{
        qDebug() << "failure";
    }
}

DBInstance::~DBInstance()
{
    m_db.close();
}

bool DBInstance::HandleRegister(const char *username, const char *password)
{
    if(username == NULL || password == NULL){
        return false;
    }

    QString data = QString("insert into userInfo(username,password) values(:username,:password)");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":username",username);
    query.bindValue(":password",password);

    return query.exec();
}

bool DBInstance::HandleLogin(const char *username, const char *password)
{
    if(username == NULL || password == NULL){
        return false;
    }
    QString data = QString("select userId from userInfo where username = :username and password = :password");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    query.exec();
    if(query.next()){
        data = QString("update userInfo set isOnline = 1 where username = :username");
        query.prepare(data);
        query.bindValue(":username",username);
        query.exec();
        return true;
    }else{
        return false;
    }
}

bool DBInstance::HandleUserExist(const char *username, const char *password)
{
    if(username == NULL || password == NULL){
        return false;
    }
    QString data = QString("select userId from userInfo where username = :username and password = :password");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    query.exec();
    if(query.next()){
        return true;
    }else{
        return false;
    }
}

void DBInstance::HandleLogout(const char *username)
{
    if(username == NULL) return;
    QString data = QString("update userInfo set isOnline = 0 where username = :username");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":username",username);
    query.exec();
}

bool DBInstance::HandleChangePW(const char *username, const char *password)
{
    if(username == NULL || password == NULL){
        return false;
    }
    QString data = QString("update userInfo set password = :password where username = :username");
    QSqlQuery query;
    query.prepare(data);
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    return query.exec();
}


