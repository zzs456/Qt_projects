#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include "myprotocol.h"

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    ~ChatWidget();
    void setUsername(QString);

    QMessageBox::StandardButton do_AgreeAddUser(PDU*);
    void do_AddUserResult(bool,QString);
    void do_FlushFriend(PDU*);
    void do_PrivateChat(PDU*);
    void do_PrivateUserOffline(bool);
    void do_GroupChat(PDU*,bool);
signals:
    void showOnlineUsersSignal();
    void findUserSignal(QString);
    void addUserSignal(QString);
    void flushFriendSignal();
    void delFriendSignal(QString);
    void privateChatFriendSignal(QString);
    void groupChatSignal(QString);

private slots:
    void on_m_showOnlineUser_clicked();
    void on_m_findUser_clicked();

    void on_m_addFriend_clicked();

    void on_m_flushFriend_clicked();

    void on_m_deleteFriend_clicked();

    void on_m_privateChat_clicked();

    void on_m_sendMsg_clicked();

public slots:
    void do_showOnlineUsers(PDU*);
    void do_FindUser(PDU*);
    void do_AddUser(PDU*);
    void do_DelFriend(PDU*);

private:
    Ui::ChatWidget *ui;
    QString m_strUsername;
    QString m_findUsername;
    QString m_addUsername;
    QString m_privateName;
};

#endif // CHATWIDGET_H
