#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H

#include <QWidget>

namespace Ui {
class PrivateChat;
}

class PrivateChat : public QWidget
{
    Q_OBJECT
public:
    PrivateChat(PrivateChat&) = delete;
    PrivateChat& operator=(PrivateChat&) = delete;
    static PrivateChat& GetInstance();
    void setSendName(QString);
    void setRecvName(QString);
    ~PrivateChat();
    void updateMsgs(bool,QString);
private slots:
    void on_m_privateSend_clicked();

signals:
    void SendPrivateChatMsg(QString,QString);

private:
    explicit PrivateChat(QWidget *parent = nullptr);

private:
    Ui::PrivateChat *ui;
    QString m_sendName;
    QString m_recvName;
};

#endif // PRIVATECHAT_H
