#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "privatechat.h"

#include <QInputDialog>
#include <QMessageBox>

ChatWidget::ChatWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    ui->onlineUsers->hide();
    setMinimumSize(QSize(600, 600));
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

void ChatWidget::setUsername(QString username)
{
    m_strUsername = username;
}

void ChatWidget::on_m_showOnlineUser_clicked()
{
    if(ui->onlineUsers->isHidden()){
        ui->onlineUsers->show();
        emit showOnlineUsersSignal();
    }else{
        ui->onlineUsers->hide();
    }
}

void ChatWidget::do_showOnlineUsers(PDU *pdu)
{
    if(pdu == NULL) return;
    ui->m_onlineUserList->clear();
    char caTemp[32];
    int userNums = pdu->MsgLength / 32;
    for(int i = 0;i < userNums;++ i){
        memcpy(caTemp,(char*)(pdu->msg)+i*32,32);
        ui->m_onlineUserList->addItem(QString(caTemp));
    }
}

void ChatWidget::do_FindUser(PDU *pdu)
{
    if(pdu == NULL) return;
    QString showString = "";
    if(strcmp(pdu->caData,FINDUSER_NOT_EXIST) == 0){
        showString = QString("用户 %1 不存在").arg(m_findUsername);
    }else if(strcmp(pdu->caData,FINDUSER_ONLINE) == 0){
        showString = QString("用户 %1 在线").arg(m_findUsername);
    }else{
        showString = QString("用户 %1 不在线").arg(m_findUsername);
    }
    QMessageBox::about(this,"查找结果",showString);
}

void ChatWidget::do_AddUser(PDU *pdu)
{
    if(strcmp(pdu->caData,ADDFRIEND_UNKNOWN_ERROR) == 0){
        QMessageBox::critical(this,"添加好友","未知错误");
    }else if(strcmp(pdu->caData,ADDFRIEND_SELF) == 0){
        QMessageBox::warning(this,"添加好友","请选择其他用户");
    }else if(strcmp(pdu->caData,ADDFRIEND_REPEAT) == 0){
        QMessageBox::warning(this,"添加好友","已经是好友关系");
    }else{
        QMessageBox::information(this,"添加好友",QString("用户 %1 不在线").arg(m_addUsername));
    }
}

void ChatWidget::do_DelFriend(PDU *pdu)
{
    if(strcmp(pdu->caData,DELFRIEND_SUCCESS) == 0){
        QMessageBox::about(this,"删除好友","删除好友成功");
    }else{
        QMessageBox::about(this,"删除好友","删除好友失败");
    }
}

QMessageBox::StandardButton ChatWidget::do_AgreeAddUser(PDU *pdu)
{
    char requestUser[32];
    strncpy(requestUser,pdu->caData,32);
    QMessageBox::StandardButton ret;
    ret = QMessageBox::question(this,"申请好友",QString("用户 %1 申请添加您为好友").arg(QString(requestUser)));
    return ret;
}

void ChatWidget::do_AddUserResult(bool isOk,QString username)
{
    if(isOk){
        QMessageBox::information(this,"添加好友",QString("用户 %1 同意了您的好友申请").arg(username));
    }else{
        QMessageBox::information(this,"添加好友",QString("用户 %1 拒绝了您的好友申请").arg(username));
    }
}

void ChatWidget::do_FlushFriend(PDU *pdu)
{
    if(pdu == NULL) return;
    ui->m_friendList->clear();
    char temp[32];
    uint userNums = (pdu->MsgLength) / 32;
    for(int i = 0;i < userNums;++ i){
        memcpy(temp,(char*)(pdu->msg)+i*32,32);
        ui->m_friendList->addItem(QString(temp));
    }
}

void ChatWidget::do_PrivateChat(PDU *pdu)
{
    char sendName[32];
    char chatName[32];
    strncpy(sendName,pdu->caData,32);
    strncpy(chatName,pdu->caData+32,32);
    if(PrivateChat::GetInstance().isHidden()){
        PrivateChat::GetInstance().show();
        PrivateChat::GetInstance().setSendName(chatName);
        PrivateChat::GetInstance().setRecvName(sendName);
    }
    QString msg(pdu->msg);
    PrivateChat::GetInstance().updateMsgs(false,msg);
}

void ChatWidget::do_PrivateUserOffline(bool isOnline)
{
    if(isOnline){
        if(PrivateChat::GetInstance().isHidden()){
            PrivateChat::GetInstance().show();
            PrivateChat::GetInstance().setSendName(m_strUsername);
            PrivateChat::GetInstance().setRecvName(m_privateName);
        }
    }else{
        QMessageBox::warning(this,"私聊","好友不在线");
    }
}

void ChatWidget::do_GroupChat(PDU *pdu,bool isSelf)
{
    if(isSelf){
        QString data = QString::fromUtf8(pdu->msg);
        ui->m_showMsgs->append(QString("you say: %1").arg(data));
    }else{
        char sendName[32];
        memcpy(sendName,pdu->caData,32);
        QString newLine = QString(sendName) + " says: ";
        QString msg = QString::fromUtf8(pdu->msg);
        newLine += msg;
        ui->m_showMsgs->append(newLine);
    }
}

void ChatWidget::on_m_findUser_clicked()
{
    bool ok = false;
    QString username = QInputDialog::getText(this,"查找","用户名: ",QLineEdit::Normal,"",&ok);
    if(ok){
        if(username.isEmpty()){
            QMessageBox::warning(this,"提示","请输入用户名");
        }else{
            m_findUsername = username;
            emit findUserSignal(username);
        }
    }
}


void ChatWidget::on_m_addFriend_clicked()
{
    QListWidgetItem *currentItem = ui->m_onlineUserList->currentItem();
    if(currentItem){
        m_addUsername = currentItem->text();
        emit addUserSignal(m_addUsername);
    }else{
        QMessageBox::warning(this,"添加好友","请选择要添加的好友");
    }
}


void ChatWidget::on_m_flushFriend_clicked()
{
    emit flushFriendSignal();
}


void ChatWidget::on_m_deleteFriend_clicked()
{
    QListWidgetItem *currentItem = ui->m_friendList->currentItem();
    if(currentItem){
        emit delFriendSignal(currentItem->text());
    }else{
        QMessageBox::warning(this,"删除好友","请选择要删除的好友");
    }
}


void ChatWidget::on_m_privateChat_clicked()
{
    QListWidgetItem *currentItem = ui->m_friendList->currentItem();
    if(currentItem){
        m_privateName = currentItem->text();
        emit privateChatFriendSignal(currentItem->text());
    }else{
        QMessageBox::warning(this,"私聊","请选择要私聊的好友");
    }
}


void ChatWidget::on_m_sendMsg_clicked()
{
    QString msg = ui->m_lineMsg->text();
    if(!msg.isEmpty()){
        emit groupChatSignal(msg);
    }else{
        QMessageBox::warning(this,"群聊","群聊信息不能为空");
    }
}

