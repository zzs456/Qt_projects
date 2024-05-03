#include "logindialog.h"
#include "ui_logindialog.h"
#include "dbinstance.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    setFixedSize(360,240);
    setTipsColor();

    ui->stackedWidget->setCurrentIndex(0);
    connect(this,&LoginDialog::changeStackedWidget,ui->stackedWidget,&QStackedWidget::setCurrentIndex);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}



void LoginDialog::on_m_loginButton_clicked()
{
    QString username = ui->m_luser->text();
    if(username.isEmpty()){
        clearLTips();
        ui->m_luserTip->setText("账号不能为空!");
        return;
    }
    QString password = ui->m_lpw->text();
    if(password.isEmpty()){
        clearLTips();
        ui->m_lpwTip->setText("密码不能为空!");
        return;
    }
    // 注册
    bool isLoOk = DBInstance::GetInstance().HandleLogin(username.toStdString().c_str(),password.toStdString().c_str());
    if(isLoOk){
        clearLText();
        clearLTips();
        emit loginSuccess(username);
        this->close();
    }else{
        clearLTips();
        ui->m_lpwTip->setText("账号或密码错误!");
    }

}


void LoginDialog::on_m_registerButton_clicked()
{
    clearLTips();
    clearLText();
    emit changeStackedWidget(1);
    setWindowTitle("注册");
}


void LoginDialog::on_m_confirmRegister_clicked()
{
    QString username = ui->m_ruser->text();
    if(username.isEmpty()){
        clearRTips();
        ui->m_ruserTip->setText("账号不能为空!");
        return;
    }
    QString password = ui->m_rpw->text();
    if(password.isEmpty()){
        clearRTips();
        ui->m_rpwTip->setText("密码不能为空!");
        return;
    }
    QString rewrite_pw = ui->m_rewrite->text();
    if(rewrite_pw.isEmpty()){
        clearRTips();
        ui->m_rewriteTip->setText("确认密码不能为空!");
        return;
    }
    if(password != rewrite_pw){
        clearRTips();
        ui->m_rewriteTip->setText("两次密码不一致!");
        return;
    }
    // 注册
    bool isReOk = DBInstance::GetInstance().HandleRegister(username.toStdString().c_str(),password.toStdString().c_str());
    if(isReOk){
        clearRText();
        clearRTips();
        ui->m_rewriteTip->setText("注册成功!");
    }else{
        clearRTips();
        ui->m_ruserTip->setText("账号已被注册!");
    }
}

void LoginDialog::clearRTips()
{
    ui->m_ruserTip->clear();
    ui->m_rpwTip->clear();
    ui->m_rewriteTip->clear();
}

void LoginDialog::clearRText()
{
    ui->m_ruser->clear();
    ui->m_rpw->clear();
    ui->m_rewrite->clear();
}

void LoginDialog::setTipsColor()
{
    ui->m_luserTip->setStyleSheet("color:red;");
    ui->m_lpwTip->setStyleSheet("color:red;");
    ui->m_ruserTip->setStyleSheet("color:red;");
    ui->m_rpwTip->setStyleSheet("color:red;");
    ui->m_rewriteTip->setStyleSheet("color:red;");
}


void LoginDialog::on_m_returnLogin_clicked()
{
    clearRText();
    clearRTips();
    emit changeStackedWidget(0);
    setWindowTitle("登录");
}

void LoginDialog::clearLTips()
{
    ui->m_luserTip->clear();
    ui->m_lpwTip->clear();
}

void LoginDialog::clearLText()
{
    ui->m_luser->clear();
    ui->m_lpw->clear();
}

