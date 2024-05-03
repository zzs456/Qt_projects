#include "func_comp.h"
#include "ui_func_comp.h"

#include "../PublicHeader/Color.h"
#include "../MyComponents/mymessagebox.h"
#include <QtGlobal>
#include <QMessageBox>
#include <QPen>
#include <QColor>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFont>
#include <QDebug>
#include <QPushButton>
#include <QElapsedTimer>
#include <QTimer>
#include <QThread>

Func_Comp::Func_Comp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Func_Comp)
{
    ui->setupUi(this);

    gaObj = new Algo_GA;
    psoObj = new Algo_PSO;
    acoObj = new Algo_ACO;

    delete ui->resPlot->legend;
    ui->resPlot->legend = nullptr;

    ui->resPlot->legend = new QCPLegend;

    // 设置图例位置，这里选择显示在QCPAxisRect下方，同理可设置显示在QCustomPlot中任意位置
    ui->resPlot->plotLayout()->addElement(1, 0, ui->resPlot->legend);
    // 设置图例行优先排列
    ui->resPlot->legend->setFillOrder(QCPLayoutGrid::foColumnsFirst);
    ui->resPlot->legend->setWrap(4);
    ui->resPlot->legend->setVisible(true);    // 设置图例可见

    ui->resPlot->legend->setFont(QFont("Microsoft YaHei", 6));
    // 设置显示比例
    ui->resPlot->plotLayout()->setRowStretchFactor(1, 0.001);
    ui->resPlot->legend->setBorderPen(Qt::NoPen);    // 设置边框隐藏

    m_plotNums = 0;

    // initProPlot();
    initWidget();
}

void Func_Comp::initProPlot()
{
    QVector<double> x(1001), y(1001);
    for (int i=0; i<1001; ++i)
    {
        x[i] = i/1000.0;
        y[i] = x[i] * qCos(4 * x[i]) + x[i] * qSin(20 * x[i]) + 2;
    }
    ui->proPlot->addGraph();
    ui->proPlot->graph(0)->setData(x,y);
    ui->proPlot->graph(0)->setName("y = xcos(4x)+xsin(20x)+2");
    ui->proPlot->xAxis->setLabel("x");
    ui->proPlot->yAxis->setLabel("y");
    ui->proPlot->xAxis->setRange(0,1);
    ui->proPlot->yAxis->setRange(0,3);
    ui->proPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignLeft);
    ui->proPlot->legend->setVisible(true);
    ui->proPlot->replot();
}

void Func_Comp::GA_Running()
{
    gaObj->setFuncId(1);
    gaObj->setProId(1);
    gaObj->setId(1);
    gaObj->initGA();
    ui->PlotTabWidget->setCurrentWidget(ui->proPlotWidget);

    int popu = ui->GApopu_Spin->value();               // 种群大小
    int iterNums = ui->GAiterNums_Spin->value();       // 迭代次数
    double crossPro = ui->cross_Spin->value();          // 交叉概率
    double varPro = ui->var_Spin->value();             // 变异概率
    gaObj->setPopu(popu);
    gaObj->setIterNums(iterNums);
    gaObj->setCrossPro(crossPro);
    gaObj->setVarPro(varPro);
    //gaObj->GA_Running();
    if(ui->proPlot->graphCount() >= 2){
        ui->proPlot->removeGraph(1);
    }
    gaObj->init_Popu();    // 初始化种群
    QTimer *timer = new QTimer;
    count = iterNums;
    connect(timer,&QTimer::timeout,[=](){
        if(count == 0){
            QVector<double> curBestRes = gaObj->CurBestResults();
            QVector<double> averRes = gaObj->AverBestResults();
            updateResPlot(curBestRes,averRes);
            updateResTable(curBestRes.at(curBestRes.size()-1));
            MyMessageBox infoM(MyMessageBoxType_Success,"运行结束!");
            int ret = infoM.exec();
            if(ret == QMessageBox::Accepted){
                infoM.close();
            }else{
                return;
            }
            timer->stop();
        }else{
            gaObj->iterOnce();
            gaObj->updateRes();
            QVector<QPair<double,double>> ret = gaObj->getPoints();
            ui->ShowIterNumsLabel->setText(QString::number(iterNums-count+1));
            // ui->proPlot->clearGraphs();
            // ui->proPlot->replot();

            if(ui->proPlot->graphCount() >= 2){
                ui->proPlot->removeGraph(1);
            }

            // initProPlot();
            QVector<double> xData, yData;
            for(int j = 0;j < ret.size();++ j){
                xData.push_back(ret[j].first);
                yData.push_back(ret[j].second);
            }
            ui->proPlot->addGraph();
            ui->proPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
            ui->proPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
            ui->proPlot->graph(1)->setData(xData, yData);
            ui->proPlot->legend->removeItem(1);
            ui->proPlot->replot();
            decCount();
        }
    });
    timer->start(300);
}

void Func_Comp::PSO_Running()
{
    psoObj->setProId(1);
    psoObj->setId(1);
    psoObj->initPSO();
    ui->PlotTabWidget->setCurrentWidget(ui->proPlotWidget);
    int popu = ui->PSOpopu_Spin->value();               // 种群大小
    double C1 = ui->C1_Spin->value();                    // C1
    double C2 = ui->C2_Spin->value();
    double scale = ui->vmax_Spin->value();
    double w_init = ui->winit_Spin->value();
    double w_min = ui->wmin_Spin->value();
    int iterNums = ui->PSOiterNums_Spin->value();
    psoObj->setPopuNums(popu);
    psoObj->setC1(C1);
    psoObj->setC2(C2);
    psoObj->setVmax(scale);
    psoObj->setVmin(-scale);
    psoObj->setXmin(0);
    psoObj->setXmax(6);
    psoObj->setWinit(w_init);
    psoObj->setWmin(w_min);
    psoObj->setIterNums(iterNums);


    psoObj->init_popu();    // 初始化种群
    QTimer *timer = new QTimer;
    count = iterNums;
    if(ui->proPlot->graphCount() >= 2){
        ui->proPlot->removeGraph(1);
    }
    connect(timer,&QTimer::timeout,[=](){
        if(count == 0){
            QVector<double> curBestRes = psoObj->CurBestResults();
            QVector<double> averRes = psoObj->AverBestResults();
            updateResPlot(curBestRes,averRes);
            updateResTable(curBestRes.at(curBestRes.size()-1));
            MyMessageBox infoM(MyMessageBoxType_Success,"运行结束!");
            int ret = infoM.exec();
            if(ret == QMessageBox::Accepted){
                infoM.close();
            }else{
                return;
            }
            timer->stop();
        }else{
            psoObj->iterOnce(iterNums-count);
            psoObj->updateRes();
            ui->ShowIterNumsLabel->setText(QString::number(iterNums-count+1));
            QVector<QPair<double,double>> ret = psoObj->getPoints();
            // ui->proPlot->clearGraphs();
            // ui->proPlot->replot();
            // initProPlot();
            if(ui->proPlot->graphCount() >= 2){
                ui->proPlot->removeGraph(1);
            }

            QVector<double> xData, yData;
            for(int j = 0;j < ret.size();++ j){
                xData.push_back(ret[j].first);
                yData.push_back(ret[j].second);
            }
            ui->proPlot->addGraph();
            ui->proPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
            ui->proPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
            ui->proPlot->graph(1)->setData(xData, yData);
            ui->proPlot->legend->removeItem(1);
            ui->proPlot->replot();
            decCount();
        }
    });
    timer->start(300);
    // psoObj->PSO_Running();
}

void Func_Comp::ACO_Running()
{
    acoObj->setProId(1);
    acoObj->setId(1);
    acoObj->initACO();
    ui->PlotTabWidget->setCurrentWidget(ui->proPlotWidget);

    int popu = ui->ACOpopu_Spin->value();
    double rho = ui->Rho_Spin->value();
    double alpha = ui->Alpha_Spin->value();
    double beta = ui->Beta_Spin->value();
    double q = ui->Q_Spin->value();
    int iterNums = ui->ACO_iterNums_Spin->value();
    acoObj->setPopuNums(popu);
    acoObj->setRho(rho);
    acoObj->setAlpha(alpha);
    acoObj->setBeta(beta);
    acoObj->setQ(q);
    acoObj->setIterNums(iterNums);

    acoObj->init_popu();    // 初始化种群

    QTimer *timer = new QTimer;
    count = iterNums;
    if(ui->proPlot->graphCount() >= 2){
        ui->proPlot->removeGraph(1);
    }
    connect(timer,&QTimer::timeout,[=](){
        if(count == 0){
            QVector<double> curBestRes = acoObj->CurBestResults();
            QVector<double> averRes = acoObj->AverBestResults();
            updateResPlot(curBestRes,averRes);
            updateResTable(curBestRes.at(curBestRes.size()-1));
            MyMessageBox infoM(MyMessageBoxType_Success,"运行结束!");
            int ret = infoM.exec();
            if(ret == QMessageBox::Accepted){
                infoM.close();
            }else{
                return;
            }
            timer->stop();
        }else{
            acoObj->iterOnce(iterNums-count);
            acoObj->updateRes();
            ui->ShowIterNumsLabel->setText(QString::number(iterNums-count+1));
            QVector<QPair<double,double>> ret = acoObj->getPoints();
            // ui->proPlot->clearGraphs();
            // ui->proPlot->replot();
            // initProPlot();
            if(ui->proPlot->graphCount() >= 2){
                ui->proPlot->removeGraph(1);
            }
            QVector<double> xData, yData;
            for(int j = 0;j < ret.size();++ j){
                xData.push_back(ret[j].first);
                yData.push_back(ret[j].second);
            }
            ui->proPlot->addGraph();
            ui->proPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
            ui->proPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
            ui->proPlot->graph(1)->setData(xData, yData);
            ui->proPlot->legend->removeItem(1);
            ui->proPlot->replot();
            decCount();
        }
    });
    timer->start(300);
}

void Func_Comp::updateResPlot(const QVector<double> &cur,const QVector<double> &aver)
{
    QPen pen;
    // 绘制当前最优适应值
    QVector<double> xs;
    for(int i = 1;i <= cur.size();++ i){
        xs.push_back(i);
    }

    ui->resPlot->addGraph();
    switch(m_plotNums){
    case 0:
        pen.setColor(QColor(255,0,0));
        break;
    case 1:
        pen.setColor(QColor(255,165,0));
        break;
    case 2:
        pen.setColor(QColor(255,255,0));
        break;
    case 3:
        pen.setColor(QColor(0,128,0));
        break;
    case 4:
        pen.setColor(QColor(0,0,255));
        break;
    case 5:
        pen.setColor(QColor(75,0,130));
        break;
    case 6:
        pen.setColor(QColor(128,0,128));
        break;
    case 7:
        pen.setColor(QColor(255,192,203));
        break;
    case 8:
        pen.setColor(QColor(0,0,139));
        break;
    case 9:
        pen.setColor(QColor(0,255,255));
        break;
    case 10:
        pen.setColor(QColor(128,128,128));
        break;
    case 11:
        pen.setColor(QColor(165,42,42));
        break;
    default:
        pen.setColor(Qt::black);
        break;
    }
    ui->resPlot->graph(2*m_plotNums)->setPen(pen);
    ui->resPlot->graph(2*m_plotNums)->setData(xs,cur);
    QString data = QString("%1").arg(QString::number(m_plotNums+1));
    ui->resPlot->graph(2*m_plotNums)->setName(data);
    // if(m_plotNums) ui->resPlot->graph(m_plotNums)->rescaleAxes(true);
    // else ui->resPlot->graph(m_plotNums)->rescaleAxes(true);
    ui->resPlot->graph(2*m_plotNums)->rescaleAxes(true);
    ui->resPlot->xAxis->setLabel("迭代次数");
    ui->resPlot->yAxis->setLabel("函数值");

    ui->resPlot->addGraph();
    pen.setStyle(Qt::PenStyle::DashLine);   //设置为虚线
    ui->resPlot->graph(2*m_plotNums+1)->setPen(pen);
    ui->resPlot->graph(2*m_plotNums+1)->setData(xs,aver);
    ui->resPlot->graph(2*m_plotNums+1)->rescaleAxes(true);

    ui->resPlot->legend->removeItem(m_plotNums+1);

    ui->resPlot->replot();

    m_plotNums ++;
}

void Func_Comp::updateResTable(double cur)
{
    if(algoType == 1){
        updateGAResTable(cur);
    }else if(algoType == 2){
        updatePSOResTable(cur);
    }else{
        updateACOResTable(cur);
    }
}

void Func_Comp::updateGAResTable(double cur)
{
    int popu = ui->GApopu_Spin->value();               // 种群大小
    int iterNums = ui->GAiterNums_Spin->value();       // 迭代次数
    double crossPro = ui->cross_Spin->value();          // 交叉概率
    double varPro = ui->var_Spin->value();             // 变异概率
    int rowCounts = ui->GAResTable->rowCount();
    ui->GAResTable->insertRow(rowCounts);
    ui->GAResTable->setItem(rowCounts,0,new QTableWidgetItem(QString::number(m_plotNums)));
    ui->GAResTable->setItem(rowCounts,1,new QTableWidgetItem(QString::number(popu)));
    ui->GAResTable->setItem(rowCounts,2,new QTableWidgetItem(QString::number(crossPro)));
    ui->GAResTable->setItem(rowCounts,3,new QTableWidgetItem(QString::number(varPro)));
    ui->GAResTable->setItem(rowCounts,4,new QTableWidgetItem(QString::number(iterNums)));
    ui->GAResTable->setItem(rowCounts,5,new QTableWidgetItem(QString::number(cur)));
    QPushButton *showOrHide = new QPushButton("隐藏");
    ui->GAResTable->setCellWidget(rowCounts,6,showOrHide);
    connect(showOrHide,&QPushButton::clicked,[=](){
        QTableWidgetItem *item = ui->GAResTable->item(rowCounts,0);
        int id = item->text().toInt()-1;
        if(showOrHide->text() == "隐藏"){
            showOrHide->setText("显示");
            ui->resPlot->graph(2*id)->setVisible(false);
            ui->resPlot->graph(2*id+1)->setVisible(false);
        }else{
            showOrHide->setText("隐藏");
            ui->resPlot->graph(2*id)->setVisible(true);
            ui->resPlot->graph(2*id+1)->setVisible(true);
        }
        ui->resPlot->replot();
    });
}

void Func_Comp::updatePSOResTable(double cur)
{
    int popu = ui->PSOpopu_Spin->value();               // 种群大小
    double C1 = ui->C1_Spin->value();                    // C1
    double C2 = ui->C2_Spin->value();
    double scale = ui->vmax_Spin->value();
    double w_init = ui->winit_Spin->value();
    double w_min = ui->wmin_Spin->value();
    int iterNums = ui->PSOiterNums_Spin->value();
    int rowCounts = ui->PSOResTable->rowCount();
    ui->PSOResTable->insertRow(rowCounts);
    ui->PSOResTable->setItem(rowCounts,0,new QTableWidgetItem(QString::number(m_plotNums)));
    ui->PSOResTable->setItem(rowCounts,1,new QTableWidgetItem(QString::number(popu)));
    ui->PSOResTable->setItem(rowCounts,2,new QTableWidgetItem(QString::number(C1)));
    ui->PSOResTable->setItem(rowCounts,3,new QTableWidgetItem(QString::number(C2)));
    ui->PSOResTable->setItem(rowCounts,4,new QTableWidgetItem(QString::number(scale)));
    ui->PSOResTable->setItem(rowCounts,5,new QTableWidgetItem(QString::number(w_init)));
    ui->PSOResTable->setItem(rowCounts,6,new QTableWidgetItem(QString::number(w_min)));
    ui->PSOResTable->setItem(rowCounts,7,new QTableWidgetItem(QString::number(iterNums)));
    ui->PSOResTable->setItem(rowCounts,8,new QTableWidgetItem(QString::number(cur)));
    QPushButton *showOrHide = new QPushButton("隐藏");
    ui->PSOResTable->setCellWidget(rowCounts,9,showOrHide);
    connect(showOrHide,&QPushButton::clicked,[=](){
        QTableWidgetItem *item = ui->PSOResTable->item(rowCounts,0);
        int id = item->text().toInt()-1;
        if(showOrHide->text() == "隐藏"){
            showOrHide->setText("显示");
            ui->resPlot->graph(2*id)->setVisible(false);
            ui->resPlot->graph(2*id+1)->setVisible(false);
        }else{
            showOrHide->setText("隐藏");
            ui->resPlot->graph(2*id)->setVisible(true);
            ui->resPlot->graph(2*id+1)->setVisible(true);
        }
        ui->resPlot->replot();
    });
}

void Func_Comp::updateACOResTable(double cur)
{
    int popu = ui->ACOpopu_Spin->value();
    double rho = ui->Rho_Spin->value();
    double alpha = ui->Alpha_Spin->value();
    double beta = ui->Beta_Spin->value();
    double q = ui->Q_Spin->value();
    int iterNums = ui->ACO_iterNums_Spin->value();
    int rowCounts = ui->ACOResTable->rowCount();
    ui->ACOResTable->insertRow(rowCounts);
    ui->ACOResTable->setItem(rowCounts,0,new QTableWidgetItem(QString::number(m_plotNums)));
    ui->ACOResTable->setItem(rowCounts,1,new QTableWidgetItem(QString::number(popu)));
    ui->ACOResTable->setItem(rowCounts,2,new QTableWidgetItem(QString::number(rho)));
    ui->ACOResTable->setItem(rowCounts,3,new QTableWidgetItem(QString::number(alpha)));
    ui->ACOResTable->setItem(rowCounts,4,new QTableWidgetItem(QString::number(beta)));
    ui->ACOResTable->setItem(rowCounts,5,new QTableWidgetItem(QString::number(q)));
    ui->ACOResTable->setItem(rowCounts,6,new QTableWidgetItem(QString::number(iterNums)));
    ui->ACOResTable->setItem(rowCounts,7,new QTableWidgetItem(QString::number(cur)));
    QPushButton *showOrHide = new QPushButton("隐藏");
    ui->ACOResTable->setCellWidget(rowCounts,8,showOrHide);
    connect(showOrHide,&QPushButton::clicked,[=](){
        QTableWidgetItem *item = ui->ACOResTable->item(rowCounts,0);
        int id = item->text().toInt()-1;
        if(showOrHide->text() == "隐藏"){
            showOrHide->setText("显示");
            ui->resPlot->graph(2*id)->setVisible(false);
            ui->resPlot->graph(2*id+1)->setVisible(false);
        }else{
            showOrHide->setText("隐藏");
            ui->resPlot->graph(2*id)->setVisible(true);
            ui->resPlot->graph(2*id+1)->setVisible(true);
        }
        ui->resPlot->replot();
    });
}

void Func_Comp::delayMSecs(int msec)
{
    QTimer::singleShot(msec, this, [=](){});
}

void Func_Comp::decCount()
{
    count --;
}

Func_Comp::~Func_Comp()
{
    delete ui;
}


void Func_Comp::on_startDemoBtn_clicked()
{
    if(m_plotNums == 0){
        ui->resPlot->show();
    }

    if(m_plotNums == 12){
        QMessageBox::warning(this,"提示信息","迭代图像太多，请进行适当的清理!");
        return;
    }
    if(ui->ParaTabWidget->currentWidget() == ui->GA_Para){
        algoType = 1;
        GA_Running();
    }else if(ui->ParaTabWidget->currentWidget() == ui->PSO_Para){
        algoType = 2;
        PSO_Running();
    }else{
        algoType = 3;
        ACO_Running();
    }
}


void Func_Comp::on_returnBtn_clicked()
{
    initWidget();
    emit returnCompMain(1);
}

void Func_Comp::initWidget()
{
    ui->resPlot->clearGraphs();
    ui->resPlot->replot();
    ui->resPlot->hide();
    ui->proPlot->clearGraphs();
    initProPlot();
    ui->PlotTabWidget->setCurrentWidget(ui->proPlotWidget);
    ui->GAResTable->clearContents();
    ui->GAResTable->setRowCount(0);
    ui->PSOResTable->clearContents();
    ui->PSOResTable->setRowCount(0);
    ui->ACOResTable->clearContents();
    ui->ACOResTable->setRowCount(0);
    ui->ResTabWidget->setCurrentWidget(ui->GA_Res);
    ui->ParaTabWidget->setCurrentWidget(ui->GA_Para);
    m_plotNums = 0;
    ui->ShowIterNumsLabel->setText("");
}

void Func_Comp::on_clearResBtn_clicked()
{
    initWidget();
}

