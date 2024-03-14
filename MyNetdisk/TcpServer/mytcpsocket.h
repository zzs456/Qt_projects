#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "myprotocol.h"

// #include <QObject>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>
#include <QFile>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    // explicit MyTcpSocket(QObject *parent = nullptr);
    MyTcpSocket();
    QString GetUserName() const;
    void DoRegisterRequest(PDU *);
    void DoLoginRequest(PDU *);
    void DoShowAllOnlineUsersRequest();
    void DoFindUserRequest(PDU *);
    void DoAddFriendRequest(PDU *);
    void DoAddUserRelation(PDU*);
    void DoRefuseUserRelation(PDU*);
    void DoFlushFriendRequest(PDU*);
    void DoDelFriendRequest(PDU*);
    void DoPrivateChatRequest(PDU*);
    void DoPrivateChatMsg(PDU*);
    void DoGroupChat(PDU *);

    void DoCreateDir(PDU*);
    void DoFlushDir(PDU*);
    void DoDelDir(PDU*);
    void DoDelFile(PDU*);
    void DoRename(PDU*);
    void DoEnterDir(PDU*);
    void DoMoveFile(PDU*);
    void DoUploadFile(PDU*);
    void DoDownloadFile(PDU*);
    void DoShareFile(PDU*);
    void DoShareFileToFriends(PDU*);
    void DoHandleCopyShareFile(PDU*);
private slots:
    void recvMsg();
    void Offline();
    void sendFileToClient();
signals:
    void MyOfflineSignal(MyTcpSocket*);
private:
    QString m_strUsername;
    bool m_isUpload;
    qint64 m_totalSize;
    qint64 m_recvSize;
    QFile m_destFile;
    QTimer *timer;
    QFile m_downloadFile;
};

#endif // MYTCPSOCKET_H
