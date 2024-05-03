#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(300,150);
}

LoginDialog &LoginDialog::GetInstance()
{
    static LoginDialog instance;
    return instance;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_registerButton_clicked()
{
    QString strUsername = ui->username->text();
    QString strPassword = ui->password->text();
    if(strUsername.isEmpty() || strPassword.isEmpty()){
        QMessageBox::warning(this,"注册","用户名或密码不能为空!");
    }else{
        emit RegisterSignal(strUsername,strPassword);
    }
}


void LoginDialog::on_loginButton_clicked()
{
    QString strUsername = ui->username->text();
    QString strPassword = ui->password->text();
    if(strUsername.isEmpty() || strPassword.isEmpty()){
        QMessageBox::warning(this,"登录","用户名或密码不能为空!");
    }else{
        emit LoginSignal(strUsername,strPassword);
    }
}

void LoginDialog::DoRegisterRespond(PDU *pdu)
{
    qDebug() << pdu->caData;
    if(strcmp(pdu->caData,REGISTER_OK) == 0){
        QMessageBox::information(this,"注册","注册成功!");
    }else if(strcmp(pdu->caData,REGISTER_FAIL) == 0){
        QMessageBox::warning(this,"注册","注册失败,用户名已被注册!");
    }
}

void LoginDialog::DoLoginRespond(PDU *pdu)
{
    qDebug() << pdu->caData;
    if(strcmp(pdu->caData,LOGIN_FAIL) == 0){
        QMessageBox::warning(this,"登录","用户名或密码有误!");
    }else if(strcmp(pdu->caData,LOGIN_REPEAT) == 0){
        QMessageBox::warning(this,"登录","该用户已登录!");
    }else{
        if(QMessageBox::information(this,"登录","登录成功",QMessageBox::Ok) == QMessageBox::Ok){
            emit UpdateShow();
        }
    }
}

