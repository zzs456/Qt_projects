#include <QCoreApplication>
#include "mytcpserver.h"
#include "mytcpsocket.h"
#include "dbinstance.h"

#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DBInstance::GetInstance().Init_DB();
    MyTcpServer::GetInstance().TcpRunning();

    return a.exec();
}
