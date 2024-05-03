#include "funcmainwidget.h"
#include "ui_funcmainwidget.h"

FuncMainWidget::FuncMainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FuncMainWidget)
{
    ui->setupUi(this);
    funcProW = new FunctionProWidget;
    // funcGAW = new FuncGAWidget;
    funcGAW = new GADemoShowWidget;
    funcGAW->setProClassId(1);
    funcPSOW = new PSODemoShowWidget;
    funcPSOW->setProClassId(1);
    funcACOW = new ACODemoShowWidget;
    funcACOW->setProClassId(1);

    ui->stackedWidget->addWidget(funcProW);
    ui->stackedWidget->addWidget(funcGAW);
    ui->stackedWidget->addWidget(funcPSOW);
    ui->stackedWidget->addWidget(funcACOW);

    connect(funcProW,&FunctionProWidget::demoSignal,this,&FuncMainWidget::do_GADemoSignal);
    connect(funcGAW,&GADemoShowWidget::returnFuncMainSignal,this,&FuncMainWidget::do_FuncMainSignal);
    connect(funcPSOW,&PSODemoShowWidget::returnFuncMainSignal,this,&FuncMainWidget::do_FuncMainSignal);
    connect(funcACOW,&ACODemoShowWidget::returnFuncMainSignal,this,&FuncMainWidget::do_FuncMainSignal);
}

FuncMainWidget::~FuncMainWidget()
{
    delete ui;
}

void FuncMainWidget::do_GADemoSignal(int id, int n)
{
    if(algoType == 1){
        funcGAW->setProClassId(1);
        if(id == 0){
            funcGAW->setProId(0);
        }else if(id == 1){
            funcGAW->setProId(1);
        }else if(id == 2){
            funcGAW->setProId(2);
            funcGAW->setFuncSphereN(n);
        }
        funcGAW->initWidget();
        funcGAW->initGAObj();
        funcGAW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(funcGAW);
    }else if(algoType == 2){
        funcPSOW->setProClassId(1);
        if(id == 0){
            funcPSOW->setProId(0);
        }else if(id == 1){
            funcPSOW->setProId(1);
        }else{
            funcPSOW->setProId(2);
            funcPSOW->setFuncSphereN(n);
        }
        funcPSOW->initWidget();
        funcPSOW->initPSOObj();
        funcPSOW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(funcPSOW);
    }else if(algoType == 3){
        funcACOW->setProClassId(1);
        if(id == 0){
            funcACOW->setProId(0);
        }else if(id == 1){
            funcACOW->setProId(1);
        }else{
            funcACOW->setProId(2);
            funcACOW->setFuncSphereN(n);
        }
        funcACOW->initWidget();
        funcACOW->initACOObj();
        funcACOW->paintProPlot();
        ui->stackedWidget->setCurrentWidget(funcACOW);
    }
    emit stop_QTreeW();
}

void FuncMainWidget::do_FuncMainSignal()
{
    ui->stackedWidget->setCurrentWidget(funcProW);
    emit start_QTreeW();
}
