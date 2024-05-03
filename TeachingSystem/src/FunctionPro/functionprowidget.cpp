#include "functionprowidget.h"
#include "ui_functionprowidget.h"

FunctionProWidget::FunctionProWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FunctionProWidget)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,3);
    initFuncProWidget();
    QTreeWidgetItem *temp = ui->functions_treeWidget->topLevelItem(0);
    ui->functions_treeWidget->setCurrentItem(temp);
    ui->func_stackedWidget->setCurrentWidget(ui->GA_IntroW);
    ui->startDemo->setEnabled(false);
}

FunctionProWidget::~FunctionProWidget()
{
    delete ui;
}

void FunctionProWidget::initFuncProWidget()
{
    ui->powerFuncName->setText("f(x) = x^2");
    ui->powerFuncAccu->setText("0.001");
    ui->powerFuncDomain->setText("[0,6]");
    paintPowerFunc();
    ui->trigoFuncName->setText("f(x) = xcos(4x)+xsin(20x)+2");
    ui->trigoFuncAccu->setText("0.001");
    ui->trigoFuncDomain->setText("[0,1]");
    paintTrigoFunc();
    ui->sphereFuncName->setText("f(x) = &sum; <sub>i</sub><sup>n</sup><sub>=1</sub> x<sub>i</sub><sup>2</sup>");
    ui->sphereFuncAccu->setText("0.001");
    ui->sphereFuncDomain->setText("[0,4]");
    ui->sphereNValueSpin->setValue(4);
}

void FunctionProWidget::paintPowerFunc()
{
    QVector<double> x(1001), y(1001);
    for (int i=0; i<1001; ++i)
    {
        x[i] = i/1000.0 * 6;
        y[i] = x[i]*x[i];
    }
    ui->powerFuncPlot->addGraph();
    ui->powerFuncPlot->graph(0)->setData(x,y);
    ui->powerFuncPlot->graph(0)->setName("f(x) = x^2");
    ui->powerFuncPlot->rescaleAxes(true);
    ui->powerFuncPlot->xAxis->setLabel("x");
    ui->powerFuncPlot->yAxis->setLabel("f(x)");
    ui->powerFuncPlot->xAxis->setRange(0,6);
    ui->powerFuncPlot->yAxis->setRange(0,36);
    ui->powerFuncPlot->legend->setVisible(true);
    ui->powerFuncPlot->replot();
}

void FunctionProWidget::paintTrigoFunc()
{
    QVector<double> x(1001), y(1001);
    for (int i=0; i<1001; ++i)
    {
        x[i] = i/1000.0;
        y[i] = x[i] * qCos(4 * x[i]) + x[i] * qSin(20 * x[i]) + 2;
    }

    ui->trigoFuncPlot->addGraph();
    ui->trigoFuncPlot->graph(0)->setData(x,y);
    ui->trigoFuncPlot->graph(0)->setName("f(x) = xcos(4x)+xsin(20x)+2");
    ui->trigoFuncPlot->xAxis->setLabel("x");
    ui->trigoFuncPlot->yAxis->setLabel("f(x)");
    ui->trigoFuncPlot->xAxis->setRange(0,1);
    ui->trigoFuncPlot->yAxis->setRange(0,4);
    ui->trigoFuncPlot->legend->setVisible(true);
    ui->trigoFuncPlot->replot();
}

void FunctionProWidget::on_functions_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(!item->parent()){
        if(item->text(column) == "内置函数"){
            ui->func_stackedWidget->setCurrentWidget(ui->GA_IntroW);
        }
        ui->startDemo->setEnabled(false);
        return;
    }else{
        ui->startDemo->setEnabled(true);
        if(item->text(column) == "f(x) = x^2"){
            ui->func_stackedWidget->setCurrentWidget(ui->powerFuncW);
        }else if(item->text(column) == "f(x) = xcos(4x) + xsin(20x) + 2"){
            ui->func_stackedWidget->setCurrentWidget(ui->trigoFuncW);
        }else{
            ui->func_stackedWidget->setCurrentWidget(ui->sphereFuncW);
        }
    }
}

void FunctionProWidget::on_startDemo_clicked()
{
    QTreeWidgetItem *item =  ui->functions_treeWidget->currentItem();
    if(!item->parent()){
        return;
    }else{
        if(item->text(0) == "f(x) = x^2"){
            emit demoSignal(0,0);
        }else if(item->text(0) == "f(x) = xcos(4x) + xsin(20x) + 2"){
            emit demoSignal(1,0);
        }else{
            emit demoSignal(2,ui->sphereNValueSpin->value());
        }
    }
}

