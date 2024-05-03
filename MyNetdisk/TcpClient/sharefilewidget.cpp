#include "sharefilewidget.h"
#include "ui_sharefilewidget.h"
#include "myprotocol.h"

#include <QCheckBox>
#include <QMessageBox>

ShareFileWidget::ShareFileWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ShareFileWidget)
{
    ui->setupUi(this);
}

ShareFileWidget::~ShareFileWidget()
{
    delete ui;
}

void ShareFileWidget::HandleShareFileWidgetShow(PDU *pdu)
{
    ui->m_onlineFriend->clear();
    char userName[32];
    const int eachSize = 32;
    int nums = pdu->MsgLength / eachSize;
    QString temp;
    for(int i = 0;i < nums;++ i){
        strncpy(userName,(char*)(pdu->msg+32*i),32);
        temp = QString(userName);
        qDebug() << temp;
        QListWidgetItem *item = new QListWidgetItem;
        QCheckBox *checkBox = new QCheckBox(temp);
        ui->m_onlineFriend->addItem(item);
        ui->m_onlineFriend->setItemWidget(item,checkBox);
    }
    this->show();
}

void ShareFileWidget::on_m_selectAll_clicked()
{
    for(int i = 0;i < ui->m_onlineFriend->count();++ i){
        QListWidgetItem *item = ui->m_onlineFriend->item(i);
        QCheckBox *checkBox = static_cast<QCheckBox*>(ui->m_onlineFriend->itemWidget(item));
        if(!checkBox->isChecked()){
            checkBox->setChecked(true);
        }
    }
}


void ShareFileWidget::on_m_cancelAll_clicked()
{
    for(int i = 0;i < ui->m_onlineFriend->count();++ i){
        QListWidgetItem *item = ui->m_onlineFriend->item(i);
        QCheckBox *checkBox = static_cast<QCheckBox*>(ui->m_onlineFriend->itemWidget(item));
        if(checkBox->isChecked()){
            checkBox->setChecked(false);
        }
    }
}


void ShareFileWidget::on_m_ok_clicked()
{
    QStringList recvUsers;
    recvUsers.clear();
    for(int i = 0;i < ui->m_onlineFriend->count();++ i){
        QListWidgetItem *item = ui->m_onlineFriend->item(i);
        QCheckBox *checkBox = static_cast<QCheckBox*>(ui->m_onlineFriend->itemWidget(item));
        if(checkBox->isChecked()){
            recvUsers.append(checkBox->text());
        }
    }
    if(!recvUsers.isEmpty()){
        emit ShareFileToFriends(recvUsers);
    }else{
        QMessageBox::warning(this,"分享文件","请选择至少一名好友");
    }
}


void ShareFileWidget::on_m_cancel_clicked()
{
    for(int i = 0;i < ui->m_onlineFriend->count();++ i){
        QListWidgetItem *item = ui->m_onlineFriend->item(i);
        QCheckBox *checkBox = static_cast<QCheckBox*>(ui->m_onlineFriend->itemWidget(item));
        if(checkBox->isChecked()){
            checkBox->setChecked(false);
        }
    }
    this->hide();
}

