#include "privatechat.h"
#include "ui_privatechat.h"

#include <QMessageBox>

PrivateChat::PrivateChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PrivateChat)
{
    ui->setupUi(this);
}

PrivateChat &PrivateChat::GetInstance()
{
    static PrivateChat instance;
    return instance;
}

void PrivateChat::setSendName(QString username)
{
    m_sendName = username;
}

void PrivateChat::setRecvName(QString username)
{
    m_recvName = username;
    this->setWindowTitle(username);
}

PrivateChat::~PrivateChat()
{
    delete ui;
}

void PrivateChat::updateMsgs(bool isSender, QString msg)
{
    QString lineTxt = "";
    if(isSender){
        lineTxt = "you say: ";
    }else{
        lineTxt = m_recvName + " says: ";
    }
    lineTxt += msg;
    ui->m_privateMsgs->append(lineTxt);
}

void PrivateChat::on_m_privateSend_clicked()
{
    QString msg = ui->m_privateLineMsg->text();
    ui->m_privateLineMsg->clear();
    if(!msg.isEmpty()){
        updateMsgs(true,msg);
        emit SendPrivateChatMsg(m_recvName,msg);
    }else{
        QMessageBox::warning(this,"发送信息","发送信息不能为空");
    }
}

