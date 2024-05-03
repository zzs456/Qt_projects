#include "tspmainwidget.h"
#include "ui_tspmainwidget.h"

TSPMainWidget::TSPMainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TSPMainWidget)
{
    ui->setupUi(this);
    tspProW = new TSPProWidget;
    tspGAW = new GADemoShowWidget;
    tspPSOW = new PSODemoShowWidget;
    tspACOW = new ACODemoShowWidget;

    ui->stackedWidget->addWidget(tspProW);
    ui->stackedWidget->addWidget(tspGAW);
    ui->stackedWidget->addWidget(tspPSOW);
    ui->stackedWidget->addWidget(tspACOW);

    connect(tspProW,&TSPProWidget::demoSignal,this,&TSPMainWidget::do_DemoSignal);
    connect(tspGAW,&GADemoShowWidget::returnTspMainSignal,this,&TSPMainWidget::do_TSPMainWidget);
    connect(tspPSOW,&PSODemoShowWidget::returnTspMainSignal,this,&TSPMainWidget::do_TSPMainWidget);
    connect(tspACOW,&ACODemoShowWidget::returnTspMainSignal,this,&TSPMainWidget::do_TSPMainWidget);
}

TSPMainWidget::~TSPMainWidget()
{
    delete ui;
}

void TSPMainWidget::do_DemoSignal(const QVector<QPair<int,int>> &points)
{
    if(algoType == 1){
        tspGAW->setProClassId(4);
        tspGAW->initWidget();
        tspGAW->setTspDatas(points);
        tspGAW->initGAObj();
        tspGAW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(tspGAW);
    }else if(algoType == 2){
        tspPSOW->setProClassId(4);
        tspPSOW->initWidget();
        tspPSOW->setTspDatas(points);
        tspPSOW->initPSOObj();
        tspPSOW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(tspPSOW);
    }else if(algoType == 3){
        tspACOW->setProClassId(4);
        tspACOW->initWidget();
        tspACOW->setTspDatas(points);
        tspACOW->initACOObj();
        tspACOW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(tspACOW);
    }
    emit stop_QTreeW();
}

void TSPMainWidget::do_TSPMainWidget()
{
    ui->stackedWidget->setCurrentWidget(tspProW);
    emit start_QTreeW();
}
