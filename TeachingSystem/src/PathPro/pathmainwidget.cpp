#include "pathmainwidget.h"
#include "ui_pathmainwidget.h"

#include <QRandomGenerator>

PathMainWidget::PathMainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PathMainWidget)
{
    ui->setupUi(this);
    pathProW = new PathProWidget;
    pathGAW = new GADemoShowWidget;
    pathACOW = new ACODemoShowWidget;

    ui->stackedWidget->addWidget(pathProW);
    ui->stackedWidget->addWidget(pathGAW);
    ui->stackedWidget->addWidget(pathACOW);

    connect(pathProW,&PathProWidget::demoSignal,this,&PathMainWidget::do_DemoSignal);
    connect(pathGAW,&GADemoShowWidget::returnPathMainSignal,this,&PathMainWidget::do_PathMainWidget);
    connect(pathACOW,&ACODemoShowWidget::returnPathMainSignal,this,&PathMainWidget::do_PathMainWidget);
}

PathMainWidget::~PathMainWidget()
{
    delete ui;
}

void PathMainWidget::do_DemoSignal(const QVector<QVector<int>> &maps)
{
    if(algoType == 1){
        pathGAW->setProClassId(2);
        pathGAW->initWidget();
        pathGAW->setPathDatas(maps);
        pathGAW->initGAObj();
        pathGAW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(pathGAW);
    }else if(algoType == 3){
        pathACOW->setProClassId(2);
        pathACOW->initWidget();
        pathACOW->setPathDatas(maps);
        pathACOW->initACOObj();
        pathACOW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(pathACOW);
    }
    emit stop_QTreeW();
}

void PathMainWidget::do_PathMainWidget()
{
    ui->stackedWidget->setCurrentWidget(pathProW);
    emit start_QTreeW();
}
