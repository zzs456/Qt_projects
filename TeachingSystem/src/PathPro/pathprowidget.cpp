#include "pathprowidget.h"
#include "ui_pathprowidget.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <algorithm>

PathProWidget::PathProWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PathProWidget)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,3);
    for(int i = 0;i < 3;++ i){
        setInlayData(i);
    }
    paintPathPlot();
    QTreeWidgetItem *temp = ui->path_treeWidget->topLevelItem(0);
    ui->path_treeWidget->setCurrentItem(temp);
    ui->path_stackedWidget->setCurrentWidget(ui->GAPathIntroW);
    ui->startDemo->setEnabled(false);
}

PathProWidget::~PathProWidget()
{
    delete ui;
}

void PathProWidget::on_path_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(!item->parent()){
        if(item->text(column) == "内置示例"){
            ui->path_stackedWidget->setCurrentWidget(ui->GAPathIntroW);
            ui->startDemo->setEnabled(false);
        }else{
            ui->path_stackedWidget->setCurrentWidget(ui->UserDefPathW);
            ui->startDemo->setEnabled(true);
        }
    }else{
        ui->startDemo->setEnabled(true);
        if(item->text(column) == "5 * 5"){
            ui->path_stackedWidget->setCurrentWidget(ui->FivePathW);
        }else if(item->text(column) == "20 * 15"){
            ui->path_stackedWidget->setCurrentWidget(ui->TwentyPathW);
        }else{
            ui->path_stackedWidget->setCurrentWidget(ui->ThirtyPathW);
        }
    }
}

void PathProWidget::geneDefMaps(int defR, int defC)
{
    QVector<QVector<int>> vs;
    for(int i = 0;i < defR;++ i){
        QVector<int> temp;
        for(int j = 0;j < defC;j ++){
            int random = QRandomGenerator::global()->bounded(0,2);
            temp.push_back(random);
        }
        vs.push_back(temp);
    }
    int x = 0,y = 0;
    vs[0][0] = 0;
    vs[defR-1][defC-1] = 0;
    while(x != defR - 1 || y != defC - 1){
        int random = QRandomGenerator::global()->bounded(0,3);
        if(random == 0){
            if(x + 1 == defR){
                continue;
            }else{
                ++x;
                vs[x][y] = 0;
            }
        }else if(random == 1){
            if(y + 1 == defC){
                continue;
            }else{
                ++y;
                vs[x][y] = 0;
            }
        }else{
            if(x + 1 == defR || y + 1 == defC){
                continue;
            }else{
                ++x;++y;
                vs[x][y] = 0;
            }
        }
    }
    m_pathData = vs;
}

void PathProWidget::setInlayData(int id)
{
    QVector<QVector<int>> ret;
    QFile file;
    int rows,cols;
    if(id == 0){
        file.setFileName(":/path_inlays/src/PathPro/path_inlay1.txt");
        rows = 5;
        cols = 5;
    }else if(id == 1){
        file.setFileName(":/path_inlays/src/PathPro/path_inlay2.txt");
        rows = 15;
        cols = 20;
    }else{
        file.setFileName(":/path_inlays/src/PathPro/path_inlay3.txt");
        rows = 30;
        cols = 30;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    for (int i = 0; i < rows; ++i){
        QVector<int> temp;
        QString line = in.readLine();
        QStringList values = line.split(" ");
        for (int j = 0; j < cols; ++j){
            int value = values[j].toInt();
            temp.push_back(value);
        }
        ret.push_back(temp);
    }
    std::reverse(ret.begin(),ret.end());
    file.close();
    pathDatas.push_back(ret);
}

void PathProWidget::paintPathPlot()
{
    for(int i = 0;i < pathDatas.size();i ++){
        QVector<QVector<int>> temp = pathDatas[i];
        int rows = temp.size();
        int cols = temp[0].size();
        if(i == 0){
            ui->FivePathW->addGraph();
            ui->FivePathW->xAxis->setRange(0, cols);
            ui->FivePathW->yAxis->setRange(0, rows);
        }else if(i == 1){
            ui->TwentyPathW->addGraph();
            ui->TwentyPathW->xAxis->setRange(0, cols);
            ui->TwentyPathW->yAxis->setRange(0, rows);
        }else{
            ui->ThirtyPathW->addGraph();
            ui->ThirtyPathW->xAxis->setRange(0, cols);
            ui->ThirtyPathW->yAxis->setRange(0, rows);
        }
        for(int row = 0;row < rows;row ++){
            for(int col = 0;col < cols;col ++){
                QCPItemRect *rect;
                if(i == 0) rect = new QCPItemRect(ui->FivePathW);
                else if(i == 1) rect = new QCPItemRect(ui->TwentyPathW);
                else rect = new QCPItemRect(ui->ThirtyPathW);
                rect->topLeft->setCoords(col,row+1);
                rect->bottomRight->setCoords(col+1,row);
                if(temp[row][col]){
                    rect->setBrush(QBrush(Qt::black));
                }else{
                    rect->setBrush(QBrush(Qt::white));
                }
            }
        }
        if(i == 0) ui->FivePathW->replot();
        else if(i == 1) ui->TwentyPathW->replot();
        else ui->ThirtyPathW->replot();
    }
}

void PathProWidget::on_startDemo_clicked()
{
    QTreeWidgetItem *item =  ui->path_treeWidget->currentItem();
    if(!item->parent()){
        if(item->text(0) == "内置示例"){
            return;
        }else{
            int defRows = ui->pathHSpin->value();
            int defCols = ui->pathWSpin->value();
            geneDefMaps(defRows,defCols);
            emit demoSignal(m_pathData);
        }
    }else{
        if(item->text(0) == "5 * 5"){
            emit demoSignal(pathDatas[0]);
        }else if(item->text(0) == "20 * 15"){
            emit demoSignal(pathDatas[1]);
        }else{
            emit demoSignal(pathDatas[2]);
        }
    }
}

QVector<QVector<QVector<int>>> PathProWidget::getPathDatas() const
{
    return pathDatas;
}
