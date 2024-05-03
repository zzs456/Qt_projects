#include "bpprowidget.h"
#include "ui_bpprowidget.h"

#include "../MyComponents/mymessagebox.h"

#include <QFile>
#include <QTableWidgetItem>
#include <QRandomGenerator>
#include <QMessageBox>

BpProWidget::BpProWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BpProWidget)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,3);
    for(int i = 0;i < 2;++ i){
        setInlayData(i);
    }
    initBpTableW();
    QTreeWidgetItem *temp = ui->bp_treeWidget->topLevelItem(0);
    ui->bp_treeWidget->setCurrentItem(temp);
    ui->bp_stackedWidget->setCurrentWidget(ui->GABpIntroW);
    ui->startDemo->setEnabled(false);
}

void BpProWidget::setInlayData(int id)
{
    QVector<QPair<int,int>> ret;
    QFile file;
    int rows,cols;
    if(id == 0){
        file.setFileName(":/bp_inlays/src/BackpackPro/bp_inlay1.txt");
        rows = 8;cols = 2;
    }else{
        file.setFileName(":/bp_inlays/src/BackpackPro/bp_inlay2.txt");
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
    bpDatas.push_back(ret);
}

void BpProWidget::initBpTableW()
{
    for(int i = 1;i < bpDatas[0].size();++ i){
        int rowCounts = ui->sevenBpTableW->rowCount();
        ui->sevenBpTableW->insertRow(rowCounts);
        ui->sevenBpTableW->setItem(rowCounts,0,new QTableWidgetItem(QString::number(i)));
        ui->sevenBpTableW->setItem(rowCounts,1,new QTableWidgetItem(QString::number(bpDatas[0][i].first)));
        ui->sevenBpTableW->setItem(rowCounts,2,new QTableWidgetItem(QString::number(bpDatas[0][i].second)));
    }
    for(int i = 1;i < bpDatas[1].size();++ i){
        int rowCounts = ui->thirtyBpTableW->rowCount();
        ui->thirtyBpTableW->insertRow(rowCounts);
        ui->thirtyBpTableW->setItem(rowCounts,0,new QTableWidgetItem(QString::number(i)));
        ui->thirtyBpTableW->setItem(rowCounts,1,new QTableWidgetItem(QString::number(bpDatas[1][i].first)));
        ui->thirtyBpTableW->setItem(rowCounts,2,new QTableWidgetItem(QString::number(bpDatas[1][i].second)));
    }
}

void BpProWidget::geneDefThings()
{
    m_bpData.clear();
    int thingsNum = ui->thingNums->value();
    int totalWt = ui->totalWeight->value();
    QPair<int,int> headPair = QPair<int,int>(thingsNum,totalWt);
    m_bpData.push_back(headPair);
    for(int i = 0;i < thingsNum;++ i){
        int profit = QRandomGenerator::global()->bounded(20,101);
        int weight = QRandomGenerator::global()->bounded(20,101);
        QPair<int,int> temp = QPair<int,int>(profit,weight);
        m_bpData.push_back(temp);
    }
}

BpProWidget::~BpProWidget()
{
    delete ui;
}

void BpProWidget::on_bp_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(!item->parent()){
        if(item->text(column) == "内置示例"){
            ui->bp_stackedWidget->setCurrentWidget(ui->GABpIntroW);
            ui->startDemo->setEnabled(false);
        }else{
            ui->bp_stackedWidget->setCurrentWidget(ui->UserDefBpW);
            ui->startDemo->setEnabled(true);
        }
    }else{
        ui->startDemo->setEnabled(true);
        if(item->text(column) == "7"){
            ui->bp_stackedWidget->setCurrentWidget(ui->SevenBpW);
        }else{
            ui->bp_stackedWidget->setCurrentWidget(ui->ThirtyBpW);
        }
    }
}


void BpProWidget::on_startDemo_clicked()
{
    QTreeWidgetItem *item =  ui->bp_treeWidget->currentItem();
    if(!item->parent()){
        if(item->text(0) == "内置示例"){
            return;
        }else{
            ui->defBpTableW->clearContents();
            ui->defBpTableW->setRowCount(0);
            geneDefThings();
            for(int i = 1;i <= m_bpData[0].first;++ i){
                int rowCounts = ui->defBpTableW->rowCount();
                ui->defBpTableW->insertRow(rowCounts);
                ui->defBpTableW->setItem(rowCounts,0,new QTableWidgetItem(QString::number(i)));
                ui->defBpTableW->setItem(rowCounts,1,new QTableWidgetItem(QString::number(m_bpData[i].first)));
                ui->defBpTableW->setItem(rowCounts,2,new QTableWidgetItem(QString::number(m_bpData[i].second)));
            }
            MyMessageBox infoM(MyMessageBoxType_Question,"确定使用此示例吗?",this);
            if(QMessageBox::Accepted == infoM.exec()){
                infoM.close();
                emit demoSignal(m_bpData);
            }else{
                ui->defBpTableW->clearContents();
                ui->defBpTableW->setRowCount(0);
                return;
            }
        }
        return;
    }else{
        if(item->text(0) == "7"){
            emit demoSignal(bpDatas[0]);
        }else{
            emit demoSignal(bpDatas[1]);
        }
    }
}

