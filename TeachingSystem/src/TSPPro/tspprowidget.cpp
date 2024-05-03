#include "tspprowidget.h"
#include "ui_tspprowidget.h"

#include "../MyComponents/mymessagebox.h"

#include <QFile>
#include <QSet>
#include <QRandomGenerator>

TSPProWidget::TSPProWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TSPProWidget)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,3);
    for(int i = 0;i < 2;++ i){
        setInlayData(i);
    }
    paintTspPlot();
    QTreeWidgetItem *temp = ui->tsp_treeWidget->topLevelItem(0);
    ui->tsp_treeWidget->setCurrentItem(temp);
    ui->tsp_stackedWidget->setCurrentWidget(ui->GATspIntroW);
    ui->startDemo->setEnabled(false);
}

TSPProWidget::~TSPProWidget()
{
    delete ui;
}

void TSPProWidget::setInlayData(int id)
{
    QVector<QPair<int,int>> ret;
    QFile file;
    int rows,cols;
    if(id == 0){
        file.setFileName(":/tsp_inlays/src/TSPPro/tsp_inlay1.txt");
        rows = 10;cols = 2;
    }else{
        file.setFileName(":/tsp_inlays/src/TSPPro/tsp_inlay2.txt");
        rows = 31;cols = 2;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    for (int i = 0; i < rows; ++i){
        QString line = in.readLine();
        QStringList values = line.split(" ");
        QPair<int,int> temp = QPair<int,int>(values[0].toInt(),values[1].toInt());
        ret.push_back(temp);
    }
    file.close();
    tspDatas.push_back(ret);
}

bool TSPProWidget::geneDefPoints()
{
    m_tspData.clear();
    int points = ui->pointNums->value();
    int xmin = ui->xMin->value();
    int xmax = ui->xMax->value();
    int ymin = ui->yMin->value();
    int ymax = ui->yMax->value();
    if(xmin > xmax || ymin > ymax){
        MyMessageBox infoM(MyMessageBoxType_Info,"定义域存在问题",this);
        int ret = infoM.exec();
        if(ret == QMessageBox::Accepted){
            infoM.close();
        }
        return false;
    }
    if((xmax-xmin+1)*(ymax-ymin+1) < points){
        MyMessageBox infoM(MyMessageBoxType_Info,"定义域范围内点数过少",this);
        int ret = infoM.exec();
        if(ret == QMessageBox::Accepted){
            infoM.close();
        }
        return false;
    }
    QSet<QPair<int,int>> pointSet;
    while(pointSet.size() != points){
        int x = QRandomGenerator::global()->bounded(xmin,xmax+1);
        int y = QRandomGenerator::global()->bounded(ymin,ymax+1);
        pointSet.insert(QPair<int,int>(x,y));
    }
    for (auto value : pointSet) {
        m_tspData.append(value);
    }
    return true;
}

void TSPProWidget::paintTspPlot()
{
    for(int i = 0;i < tspDatas.size();i ++){
        if(i == 0){
            ui->TenTspW->addGraph();
            ui->TenTspW->xAxis->setLabel("x");
            ui->TenTspW->yAxis->setLabel("y");
            ui->TenTspW->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
            ui->TenTspW->graph(0)->setLineStyle(QCPGraph::lsNone);
            QVector<double> xData, yData;
            for(int j = 0;j < tspDatas[i].size();++ j){
                xData.push_back(tspDatas[i][j].first);
                yData.push_back(tspDatas[i][j].second);
            }
            ui->TenTspW->graph(0)->setData(xData, yData);
            ui->TenTspW->xAxis->rescale();
            ui->TenTspW->yAxis->rescale();
            ui->TenTspW->xAxis->scaleRange(1.05, ui->TenTspW->xAxis->range().center());
            ui->TenTspW->yAxis->scaleRange(1.05, ui->TenTspW->yAxis->range().center());
            ui->TenTspW->replot();
        }else{
            ui->ThirtyOneTspW->addGraph();
            ui->ThirtyOneTspW->xAxis->setLabel("x");
            ui->ThirtyOneTspW->yAxis->setLabel("y");
            ui->ThirtyOneTspW->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
            ui->ThirtyOneTspW->graph(0)->setLineStyle(QCPGraph::lsNone);
            QVector<double> xData, yData;
            for(int j = 0;j < tspDatas[i].size();++ j){
                xData.push_back(tspDatas[i][j].first);
                yData.push_back(tspDatas[i][j].second);
            }
            ui->ThirtyOneTspW->graph(0)->setData(xData, yData);
            ui->ThirtyOneTspW->xAxis->rescale();
            ui->ThirtyOneTspW->yAxis->rescale();
            ui->ThirtyOneTspW->xAxis->scaleRange(1.05, ui->ThirtyOneTspW->xAxis->range().center());
            ui->ThirtyOneTspW->yAxis->scaleRange(1.05, ui->ThirtyOneTspW->yAxis->range().center());
            ui->ThirtyOneTspW->replot();
        }
    }
}

void TSPProWidget::on_tsp_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(!item->parent()){
        if(item->text(column) == "内置示例"){
            ui->tsp_stackedWidget->setCurrentWidget(ui->GATspIntroW);
            ui->startDemo->setEnabled(false);
        }else{
            ui->tsp_stackedWidget->setCurrentWidget(ui->UserDefTspW);
            ui->startDemo->setEnabled(true);
        }
    }else{
        ui->startDemo->setEnabled(true);
        if(item->text(column) == "10"){
            ui->tsp_stackedWidget->setCurrentWidget(ui->TenTspW);
        }else if(item->text(column) == "31"){
            ui->tsp_stackedWidget->setCurrentWidget(ui->ThirtyOneTspW);
        }else{
            return;
        }
    }
}

void TSPProWidget::on_startDemo_clicked()
{
    QTreeWidgetItem *item =  ui->tsp_treeWidget->currentItem();
    if(!item->parent()){
        if(item->text(0) == "内置示例"){
            return;
        }else{
            bool ret = geneDefPoints();
            if(ret) emit demoSignal(m_tspData);
        }
        return;
    }else{
        if(item->text(0) == "10"){
            emit demoSignal(tspDatas[0]);
        }else{
            emit demoSignal(tspDatas[1]);
        }
    }
}

QVector<QPair<int, int>> TSPProWidget::tspData() const
{
    return m_tspData;
}

QVector<QVector<QPair<int, int>>> TSPProWidget::getTspDatas() const
{
    return tspDatas;
}


