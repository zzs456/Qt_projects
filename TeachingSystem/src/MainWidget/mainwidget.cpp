#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "../MyComponents/mymessagebox.h"
#include "../LoginWidget/dbinstance.h"

#include <QSize>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QFont>
#include <QMessageBox>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setMWListWidget();
    setMWStackedWidget();
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,2);

    connect(ui->mw_listWidget,&QListWidget::currentRowChanged,this,&MainWidget::do_mwListWidgetChange);
    connect(mwHomeWidget,&MWHomeWidget::mwHome_changeMainWidget,this,&MainWidget::do_mwHome_changeMainWidgetSignal);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::setUsername(QString username)
{
    m_strUsername = username;
    mwSettingWidget->setUsername(m_strUsername);
}

void MainWidget::setMWListWidget()
{
    ui->mw_listWidget->setIconSize(QSize(32,32));
    QListWidgetItem *homeWidgetItem = new QListWidgetItem(ui->mw_listWidget);
    homeWidgetItem->setIcon(QIcon(":/icon/res/icons/homepage_icon.bmp"));
    homeWidgetItem->setText("主页");
    QListWidgetItem *settingWidgetItem = new QListWidgetItem(ui->mw_listWidget);
    settingWidgetItem->setIcon(QIcon(":/icon/res/icons/setting_icon.bmp"));
    settingWidgetItem->setText("设置");
    QListWidgetItem *helpWidgetItem = new QListWidgetItem(ui->mw_listWidget);
    helpWidgetItem->setIcon(QIcon(":/icon/res/icons/help_icon.bmp"));
    helpWidgetItem->setText("帮助");
    QListWidgetItem *quitItem = new QListWidgetItem(ui->mw_listWidget);
    quitItem->setIcon(QIcon(":/icon/res/icons/quit_icon.bmp"));
    quitItem->setText("退出登录");

    ui->mw_listWidget->setCurrentRow(0);

    ui->mw_listWidget->setFont(QFont("Microsoft YaHei", 16, QFont::Normal));
    ui->mw_listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->mw_listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->mw_listWidget->setStyleSheet("QListWidget{border:none;}"
                                     "QListWidget::item{height:60px;}");
}

void MainWidget::setMWStackedWidget()
{
    mwHelpWidget = new MWHelpWidget;
    mwHomeWidget = new MWHomeWidget;
    mwSettingWidget = new MWSettingWidget;
    ui->stackedWidget->addWidget(mwHomeWidget);
    ui->stackedWidget->addWidget(mwSettingWidget);
    ui->stackedWidget->addWidget(mwHelpWidget);
}

void MainWidget::do_mwListWidgetChange(int index)
{
    if(index != 3){
        ui->stackedWidget->setCurrentIndex(index);
    }else{
        MyMessageBox isquitBox(MyMessageBoxType_Question,"您确定要退出登录吗?",nullptr);
        int ret = isquitBox.exec();
        if(ret == QMessageBox::Accepted){
            emit quitSignal();
        }else{
            return;
        }
    }
}

void MainWidget::do_mwHome_changeMainWidgetSignal()
{
    emit mainWidget_changeMainWidget();
}
