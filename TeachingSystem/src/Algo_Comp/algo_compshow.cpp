#include "algo_compshow.h"
#include "ui_algo_compshow.h"

Algo_CompShow::Algo_CompShow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Algo_CompShow)
{
    ui->setupUi(this);
    initDatas();
    funcComp = new Func_Comp;
    connect(funcComp,&Func_Comp::returnCompMain,this,&Algo_CompShow::do_returnCompMain);

    tspComp = new Tsp_Comp;
    connect(tspComp,&Tsp_Comp::returnCompMain,this,&Algo_CompShow::do_returnCompMain);

    tspComp->setTSPDatas(tspData);
    tspComp->initWidget();

    ui->stackedWidget->addWidget(funcComp);
    ui->stackedWidget->addWidget(tspComp);
}

Algo_CompShow::~Algo_CompShow()
{
    delete ui;
}

void Algo_CompShow::changeStackedWidget(int id)
{
    switch(id){
    case 0:
        ui->stackedWidget->setCurrentWidget(ui->AlgoCompW);
        break;
    case 1:
        ui->stackedWidget->setCurrentWidget(ui->FuncCompInfoW);
        break;
    case 2:
        ui->stackedWidget->setCurrentWidget(ui->TspCompInfoW);
        break;
    case 3:
        ui->stackedWidget->setCurrentWidget(funcComp);
        break;
    case 4:
        ui->stackedWidget->setCurrentWidget(tspComp);
        break;
    default:
        break;
    }
}

void Algo_CompShow::initDatas()
{
    paintFunc();
    QFile file(":/tsp_inlays/src/TSPPro/tsp_inlay2.txt");
    int rows = 31;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    for (int i = 0; i < rows; ++i){
        QString line = in.readLine();
        QStringList values = line.split(" ");
        QPair<int,int> temp = QPair<int,int>(values[0].toInt(),values[1].toInt());
        tspData.push_back(temp);
    }
    file.close();
    paintPoints();
}

void Algo_CompShow::paintFunc()
{
    QVector<double> x(1001), y(1001);
    for (int i=0; i<1001; ++i)
    {
        x[i] = i/1000.0;
        y[i] = x[i] * qCos(4 * x[i]) + x[i] * qSin(20 * x[i]) + 2;
    }
    ui->trigoFuncPlot->addGraph();
    ui->trigoFuncPlot->graph(0)->setData(x,y);
    ui->trigoFuncPlot->graph(0)->setName("y = xcos(4x)+xsin(20x)+2");
    ui->trigoFuncPlot->xAxis->setLabel("x");
    ui->trigoFuncPlot->yAxis->setLabel("y");
    ui->trigoFuncPlot->xAxis->setRange(0,1);
    ui->trigoFuncPlot->yAxis->setRange(0,3);
    ui->trigoFuncPlot->legend->setVisible(true);
    ui->trigoFuncPlot->replot();
}

void Algo_CompShow::paintPoints()
{
    ui->thirtyTspPlot->addGraph();
    ui->thirtyTspPlot->xAxis->setLabel("x");
    ui->thirtyTspPlot->yAxis->setLabel("y");
    ui->thirtyTspPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->thirtyTspPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    QVector<double> xData, yData;
    for(int j = 0;j < tspData.size();++ j){
        xData.push_back(tspData[j].first);
        yData.push_back(tspData[j].second);
    }
    ui->thirtyTspPlot->graph(0)->setData(xData, yData);
    ui->thirtyTspPlot->xAxis->rescale();
    ui->thirtyTspPlot->yAxis->rescale();
    ui->thirtyTspPlot->xAxis->scaleRange(1.05, ui->thirtyTspPlot->xAxis->range().center());
    ui->thirtyTspPlot->yAxis->scaleRange(1.05, ui->thirtyTspPlot->yAxis->range().center());
    ui->thirtyTspPlot->replot();
}

void Algo_CompShow::on_FuncStartDemo_clicked()
{
    changeStackedWidget(3);
    emit stop_QTreeW();
}


void Algo_CompShow::on_TspStartDemo_clicked()
{
    changeStackedWidget(4);
    emit stop_QTreeW();
}

void Algo_CompShow::do_returnCompMain(int id)
{
    changeStackedWidget(id);
    emit start_QTreeW();
}

