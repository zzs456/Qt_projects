#include "bpmainwidget.h"
#include "ui_bpmainwidget.h"

BpMainWidget::BpMainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BpMainWidget)
{
    ui->setupUi(this);

    bpProW = new BpProWidget;
    bpGAW = new GADemoShowWidget;
    bpPSOW = new PSODemoShowWidget;
    bpACOW = new ACODemoShowWidget;

    ui->stackedWidget->addWidget(bpProW);
    ui->stackedWidget->addWidget(bpGAW);
    ui->stackedWidget->addWidget(bpPSOW);
    ui->stackedWidget->addWidget(bpACOW);

    connect(bpProW,&BpProWidget::demoSignal,this,&BpMainWidget::do_DemoSignal);
    connect(bpGAW,&GADemoShowWidget::returnBpMainSignal,this,&BpMainWidget::do_BPMainWidget);
    connect(bpPSOW,&PSODemoShowWidget::returnBPMainSignal,this,&BpMainWidget::do_BPMainWidget);
    connect(bpACOW,&ACODemoShowWidget::returnBPMainSignal,this,&BpMainWidget::do_BPMainWidget);
}

BpMainWidget::~BpMainWidget()
{
    delete ui;
}

void BpMainWidget::do_DemoSignal(const QVector<QPair<int,int>> &things)
{
    if(algoType == 1){
        bpGAW->setProClassId(3);
        bpGAW->initWidget();
        bpGAW->setBpDatas(things);
        bpGAW->initGAObj();
        bpGAW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(bpGAW);
    }else if(algoType == 2){
        bpPSOW->setProClassId(3);
        bpPSOW->initWidget();
        bpPSOW->setBpDatas(things);
        bpPSOW->initPSOObj();
        bpPSOW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(bpPSOW);
    }else if(algoType == 3){
        bpACOW->setProClassId(3);
        bpACOW->initWidget();
        bpACOW->setBpDatas(things);
        bpACOW->initACOObj();
        bpACOW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(bpACOW);
    }
    emit stop_QTreeW();
}

void BpMainWidget::do_BPMainWidget()
{
    ui->stackedWidget->setCurrentWidget(bpProW);
    emit start_QTreeW();
}
