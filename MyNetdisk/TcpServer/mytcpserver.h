#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include "mytcpsocket.h"

#include <QObject>
#include <QTcpServer>
#include <QList>

class MyTcpServer : public QTcpServer
{
public:
    static MyTcpServer& GetInstance();
    void TcpRunning();
    void resend(const char*,PDU*);

    MyTcpServer(MyTcpServer&) = delete;
    MyTcpServer& operator=(MyTcpServer&) = delete;

private:
    QString m_IP;       // IP
    quint16 m_port;     // 端口号
    void init_Config();
    explicit MyTcpServer(QObject *parent = nullptr);
    // ~MyTcpServer();
    QList<MyTcpSocket*> m_TcpSocketList;

    // QTcpServer interface
protected:
    virtual void incomingConnection(qintptr handle) override;
public slots:
    void deleteTcpSocket(MyTcpSocket*);
};

#endif // MYTCPSERVER_H
