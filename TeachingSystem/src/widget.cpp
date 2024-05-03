#include "widget.h"
#include "ui_widget.h"
#include "./LoginWidget/dbinstance.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rootWidget)
{
    ui->setupUi(this);

    mainWidget = new MainWidget(this);

    ui->stackedWidget->addWidget(mainWidget);
    ui->stackedWidget->setCurrentIndex(0);

    proAndAlgo = new ProblemAndAlgorithm(this);
    ui->stackedWidget->addWidget(proAndAlgo);

    connect(mainWidget,&MainWidget::quitSignal,this,&Widget::handleQuit);
    connect(mainWidget,&MainWidget::mainWidget_changeMainWidget,this,&Widget::do_mainWidget_changeMainWidget);
    connect(proAndAlgo,&ProblemAndAlgorithm::returnToMainWidget,this,&Widget::do_returnMainWidget);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::MyShow(QString username)
{
    m_strUsername = username;
    mainWidget->setUsername(m_strUsername);
    setWindowTitle(QString("%1").arg(username));
    this->show();
}

void Widget::do_mainWidget_changeMainWidget()
{
    ui->stackedWidget->setCurrentWidget(proAndAlgo);
}

void Widget::do_returnMainWidget()
{
    ui->stackedWidget->setCurrentWidget(mainWidget);
}

void Widget::handleQuit()
{
    DBInstance::GetInstance().HandleLogout(m_strUsername.toStdString().c_str());
    this->close();
}
