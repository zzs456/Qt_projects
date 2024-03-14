#ifndef WIDGET_H
#define WIDGET_H

#include "logindialog.h"
#include "chatwidget.h"
#include "filewidget.h"

#include <QWidget>
#include <QTcpSocket>
#include <QStackedWidget>
#include <QMessageBox>
#include <QTimer>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    void init_Config();
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString GetUsername() const;

private:
    QString m_IP;       // IP
    quint16 m_port;     // 端口号
    Ui::Widget *ui;
    QTcpSocket m_tcpSocket;     // 连接服务器，和服务器数据交互
    QString m_strUsername;
    QString m_curDir;
    QString m_moveFilePath;
    QString m_selectDestPath;

    QString m_uploadFilePath;
    QString m_saveFilePath;
    QFile m_saveFile;

    bool m_isDownload;
    qint64 m_totalSize;
    qint64 m_recvSize;


    ChatWidget *chatWidget;
    FileWidget *fileWidget;

    QTimer *timer;

    void HandleAgreeAddUser(PDU*);
    void HandleAddUserAgree(PDU*);
    void HandleAddUserRefuse(PDU*);
    void HandleFlushFriend(PDU*);
    void HandlePrivateChat(PDU*);
    void HandlePrivateUserOffline(PDU*);
    void HandleGroupChat(PDU*);
    void HandleCreateDir(PDU*);
    void HandleFlushDir(PDU*);
    void HandleDelDir(PDU*);
    void HandleDelFile(PDU*);
    void HandleRename(PDU*);
    void HandleEnterDir(PDU*);
    void HandleMoveFile(PDU*);
    void HandleUploadFile(PDU*);
    void HandleDownLoadFile(PDU*);
    void HandleShareFileWidgetShow(PDU*);
    void HandleRecvFile(PDU*);
    void HandleShareFileToFriends(PDU*);
signals:
    void RegisterRespondSignal(PDU*);
    void LoginRespondSignal(PDU*);
    void ShowAllOnlineUsersSignal(PDU*);
    void FindUserSignal(PDU*);
    void AddFriendSignal(PDU*);
    void DelFriendSignal(PDU*);

private slots:
    // 连接函数
    void ConSuccess();
    // 注册函数
    void do_Register(QString,QString);
    // 登录函数
    void do_Login(QString,QString);
    // 接受信息
    void recvMsg();
    // 显示窗口
    void do_Show();
    // 显示在线用户
    void do_ShowOnlineUsers();
    // 查找用户
    void do_FindUser(QString);
    // 添加好友
    void do_AddUser(QString);
    // 刷新好友
    void do_FlushFriend();
    // 删除好友
    void do_DelFriend(QString);
    // 私聊好友
    void do_PrivateChat(QString);
    // 私聊信息
    void do_PrivateChatMsg(QString,QString);
    // 群聊信息
    void do_GroupChat(QString);

    // 处理创建文件夹信号
    void do_CreateDir(QString);
    // 处理刷新文件夹信号
    void do_FlushDir();
    // 处理删除文件夹信号
    void do_DelDir(QString);
    // 处理删除文件信号
    void do_DelFile(QString);
    // 处理重命名信号
    void do_Rename(QString,QString);
    // 进入文件夹
    void do_EnterDir(QString);
    // 返回上一级
    void do_ReturnFatherDir();
    // 移动文件
    void do_MoveFile(QString);
    void do_SelectDest(QString);
    // 上传文件
    void do_UploadFile(QString,qint64);
    // 上传文件数据
    void do_UploadFileData();
    // 下载文件
    void do_DownloadFile(QString,QString);
    // 共享分件获取在线好友
    void do_ShareFileConfirm(QString);
    // 共享文件
    void do_ShareFileToFriends(QStringList &,QString);
};
#endif // WIDGET_H
