#include "mwsettingwidget.h"
#include "ui_mwsettingwidget.h"
#include "../LoginWidget/dbinstance.h"

MWSettingWidget::MWSettingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MWSettingWidget)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    ui->m_oldPW_Info->setStyleSheet("color:red");
    ui->m_newPW_Info->setStyleSheet("color:red");
}

MWSettingWidget::~MWSettingWidget()
{
    delete ui;
}

void MWSettingWidget::setUsername(QString username)
{
    m_strUsername = username;
}

void MWSettingWidget::on_m_changePW_clicked()
{
    if(ui->groupBox->isHidden()){
        ui->groupBox->show();
        ui->m_changePW->setText("隐藏");
    }else{
        ui->m_newPW->clear();
        ui->m_oldPW->clear();
        ui->m_newPW_Info->clear();
        ui->m_oldPW_Info->clear();
        ui->groupBox->hide();
        ui->m_changePW->setText("修改密码");
    }
}


void MWSettingWidget::on_m_changeOK_clicked()
{
    QString oldPW = ui->m_oldPW->text();
    QString newPW = ui->m_newPW->text();
    if(oldPW.isEmpty() || newPW.isEmpty()){
        ui->m_newPW_Info->setText("原密码和新密码均不能为空!");
        return;
    }
    bool isUserExist = DBInstance::GetInstance().HandleUserExist(m_strUsername.toStdString().c_str(),oldPW.toStdString().c_str());
    if(isUserExist){
        bool ret = DBInstance::GetInstance().HandleChangePW(m_strUsername.toStdString().c_str(),newPW.toStdString().c_str());
        if(ret){
            ui->m_oldPW_Info->clear();
            ui->m_newPW_Info->setText("修改成功");
        }else{
            ui->m_oldPW_Info->clear();
            ui->m_newPW_Info->setText("修改失败");
        }
    }else{
        ui->m_oldPW_Info->setText("原密码错误!");
        ui->m_newPW_Info->clear();
    }
}


void MWSettingWidget::on_m_changeCancel_clicked()
{
    ui->m_newPW->clear();
    ui->m_oldPW->clear();
    ui->m_newPW_Info->clear();
    ui->m_oldPW_Info->clear();
}

