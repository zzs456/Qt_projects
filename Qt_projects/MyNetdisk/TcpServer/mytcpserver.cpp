#include "mytcpserver.h"
#include "dbinstance.h"

#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QTcpSocket>

MyTcpServer::MyTcpServer(QObject *parent)
    : QTcpServer{parent}
{
    init_Config();
    m_TcpSocketList.clear();
}
/*
MyTcpServer::~MyTcpServer()
{
    qDebug() << "销毁";
}
*/
MyTcpServer &MyTcpServer::GetInstance()
{
    static MyTcpServer instance;
    return instance;
}

void MyTcpServer::TcpRunning()
{
    qDebug() << "服务器监听的 IP 地址为: " << m_IP << "\t端口号为: " << m_port;
    this->listen(QHostAddress(m_IP),m_port);
}

void MyTcpServer::resend(const char *username, PDU *pdu)
{
    if(username == NULL || pdu == NULL) return;
    QString targetUsername(username);
    for(int i = 0;i < m_TcpSocketList.size();++ i){
        if((m_TcpSocketList.at(i))->GetUserName() == targetUsername){
            (m_TcpSocketList.at(i))->write((char*)pdu,pdu->PDULength);
            break;
        }
    }
}

void MyTcpServer::init_Config()
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


void MyTcpServer::incomingConnection(qintptr handle)
{
    qDebug() << "新客户端连接";
    MyTcpSocket *newTcpSocket = new MyTcpSocket();
    newTcpSocket->setSocketDescriptor(handle);
    m_TcpSocketList.append(newTcpSocket);
    connect(newTcpSocket,&MyTcpSocket::MyOfflineSignal,this,&MyTcpServer::deleteTcpSocket);
}

void MyTcpServer::deleteTcpSocket(MyTcpSocket * target)
{
    // delete m_TcpSocketList.takeAt(0);
    for(int i = 0;i < m_TcpSocketList.size();++ i){
        if(target == m_TcpSocketList.at(i)){
            qDebug() << target->GetUserName() << "退出登录";
            m_TcpSocketList.removeAt(i);
            target->deleteLater();
            target = nullptr;
            break;
        }
    }
}
