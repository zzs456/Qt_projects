#include "mymessagebox.h"
#include "ui_mymessagebox.h"

#include <QPixmap>
#include <QSize>
#include <QFont>

MyMessageBox::MyMessageBox(MyMessageBoxType m_type, QString text,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyMessageBox)
{
    ui->setupUi(this);
    setFixedSize(400,200);
    Init(m_type,text);
    setWindowTitle("提示信息");
}

MyMessageBox::~MyMessageBox()
{
    delete ui;
}

void MyMessageBox::Init(MyMessageBoxType type, QString text)
{
    switch (type) {
    case MyMessageBoxType_Question:
        setQuestion(text);
        break;
    case MyMessageBoxType_Success:
        setSuccess(text);
        break;
    case MyMessageBoxType_Fail:
        setFail(text);
        break;
    case MyMessageBoxType_Info:
        setInfo(text);
        break;
    default:
        break;
    }
}

void MyMessageBox::setQuestion(QString text)
{
    ui->myMB_picLabel->setFixedSize(QSize(48,48));
    ui->myMB_picLabel->setPixmap(QPixmap(":/myMB_pngs/res/myMB_pngs/question.png"));
    ui->myMB_textLabel->setFont(QFont("Microsoft YaHei", 16, QFont::Normal));
    ui->myMB_textLabel->setText(text);
}

void MyMessageBox::setSuccess(QString text)
{
    ui->myMB_picLabel->setFixedSize(QSize(48,48));
    ui->myMB_picLabel->setPixmap(QPixmap(":/myMB_pngs/res/myMB_pngs/success.png"));
    ui->myMB_textLabel->setFont(QFont("Microsoft YaHei", 16, QFont::Normal));
    ui->myMB_textLabel->setText(text);
    ui->myMB_Cancel->hide();
}

void MyMessageBox::setFail(QString text)
{
    ui->myMB_picLabel->setFixedSize(QSize(48,48));
    ui->myMB_picLabel->setPixmap(QPixmap(":/myMB_pngs/res/myMB_pngs/fail.png"));
    ui->myMB_textLabel->setFont(QFont("Microsoft YaHei", 16, QFont::Normal));
    ui->myMB_textLabel->setText(text);
}

void MyMessageBox::setInfo(QString text)
{
    ui->myMB_picLabel->setFixedSize(QSize(48,48));
    ui->myMB_picLabel->setPixmap(QPixmap(":/myMB_pngs/res/myMB_pngs/info.png"));
    ui->myMB_textLabel->setFont(QFont("Microsoft YaHei", 16, QFont::Normal));
    ui->myMB_textLabel->setText(text);
    ui->myMB_Cancel->hide();
}

void MyMessageBox::on_myMB_OK_clicked(){
    this->accept();
}


void MyMessageBox::on_myMB_Cancel_clicked()
{
    this->close();
}

