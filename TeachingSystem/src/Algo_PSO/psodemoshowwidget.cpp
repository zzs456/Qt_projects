#include "psodemoshowwidget.h"
#include "ui_psodemoshowwidget.h"

#include "../MyComponents/mymessagebox.h"
#include "../PublicHeader/Color.h"

#include <QTableWidgetItem>
#include <QElapsedTimer>

PSODemoShowWidget::PSODemoShowWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PSODemoShowWidget)
{
    ui->setupUi(this);
    psoObj = new Algo_PSO;
    m_plotNums = 0;
    initResLegend();
}

PSODemoShowWidget::~PSODemoShowWidget()
{
    delete ui;
}

void PSODemoShowWidget::initWidget()
{
    // 复选框初始化
    ui->hideProPlotCk->setChecked(false);
    ui->hideAverResCk->setChecked(false);
    ui->onlyShowResCk->setChecked(false);

    // 绘图区域初始化
    ui->Pro_CustomPlot->clearGraphs();
    ui->Res_CustomPlot->clearGraphs();
    if(ui->Res_CustomPlot->legend){
        ui->Res_CustomPlot->plotLayout()->remove(ui->Res_CustomPlot->legend);
        ui->Res_CustomPlot->legend = nullptr;
    }
    // ui->Res_CustomPlot->hide();

    // 结果输出区域初始化
    ui->outputResPlain->clear();
    ui->recordResTable->clearContents();
    ui->recordResTable->setRowCount(0);
    ui->tabWidget->setCurrentIndex(0);

    // 参数初始化
    if(m_proClassId == 4){
        ui->C1_Spin->setMaximum(1.0);
        ui->C2_Spin->setMaximum(1.0);
        ui->label_2->setText("保留概率C1:");
        ui->label_3->setText("保留概率C2:");
        ui->winit_Spin->hide();
        ui->wmin_Spin->hide();
        ui->vmax_Spin->hide();
        ui->label_7->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->recordResTable->setColumnHidden(3,true);
        ui->recordResTable->setColumnHidden(4,true);
        ui->recordResTable->setColumnHidden(5,true);
    }else{
        ui->label_7->show();
        ui->label_5->show();
        ui->label_6->show();
        ui->winit_Spin->show();
        ui->wmin_Spin->show();
        ui->vmax_Spin->show();
        ui->label_2->setText("学习因子C1:");
        ui->label_3->setText("学习因子C2:");
        ui->C1_Spin->setMaximum(4.0);
        ui->C2_Spin->setMaximum(4.0);
        ui->popuNums_Spin->setValue(10);
        ui->C1_Spin->setValue(2.0);
        ui->C2_Spin->setValue(2);
        ui->winit_Spin->setValue(1);
        ui->wmin_Spin->setValue(0.4);
        ui->vmax_Spin->setValue(1);
        ui->iterNums_Spin->setValue(100);
        ui->recordResTable->setColumnHidden(3,false);
        ui->recordResTable->setColumnHidden(4,false);
        ui->recordResTable->setColumnHidden(5,false);
    }
}

void PSODemoShowWidget::initResLegend()
{    
    if(!ui->Res_CustomPlot->legend){
        ui->Res_CustomPlot->legend = new QCPLegend;
    }
    // 设置图例位置，这里选择显示在QCPAxisRect下方，同理可设置显示在QCustomPlot中任意位置
    ui->Res_CustomPlot->plotLayout()->addElement(1, 0, ui->Res_CustomPlot->legend);
    // 设置图例行优先排列
    ui->Res_CustomPlot->legend->setFillOrder(QCPLayoutGrid::foColumnsFirst);
    ui->Res_CustomPlot->legend->setWrap(4);
    ui->Res_CustomPlot->legend->setVisible(true);    // 设置图例可见

    ui->Res_CustomPlot->legend->setFont(QFont("Microsoft YaHei", 6));
    // 设置显示比例
    ui->Res_CustomPlot->plotLayout()->setRowStretchFactor(1, 0.001);
    ui->Res_CustomPlot->legend->setBorderPen(Qt::NoPen);    // 设置边框隐藏
}

void PSODemoShowWidget::initPSOObj()
{
    psoObj->setProId(m_proClassId);
    if(m_proClassId == 1) psoObj->setId(m_proId);
    if(m_proClassId == 1 && m_proId == 2){
        psoObj->setFuncSphereN(m_funcSphereN);
    }
    // if(m_proClassId == 2){
    //     gaObj->setPathDatas(pathDatas);
    // }
    if(m_proClassId == 3){
        psoObj->setBpDatas(bpDatas);
    }
    if(m_proClassId == 4){
        psoObj->setTSPDatas(tspDatas);
    }
}

void PSODemoShowWidget::paintProPlot()
{
    if(m_proClassId == 1){
        if(m_proId == 0 || m_proId == 1){
            paintInlayFuncPlot();
        }else if(m_proId == 2){
            ui->Pro_CustomPlot->hide();
        }
    }else if(m_proClassId == 3){
        ui->Pro_CustomPlot->hide();
    }else if(m_proClassId == 4){
        paintTspPlot();
    }/*else{
        paintTspPlot();
    }*/
}

void PSODemoShowWidget::paintInlayFuncPlot()
{
    ui->Pro_CustomPlot->clearGraphs();
    QVector<double> x(1001), y(1001);
    if(m_proId == 0){
        for (int i=0; i<1001; ++i){
            x[i] = i/1000.0 * 6.0;
            y[i] = x[i]*x[i];
        }
    }else{
        for (int i=0; i<1001; ++i){
            x[i] = i/1000.0;
            y[i] = x[i] * qCos(4 * x[i]) + x[i] * qSin(20 * x[i]) + 2;
        }
    }
    ui->Pro_CustomPlot->addGraph();
    ui->Pro_CustomPlot->graph(0)->setData(x,y);
    if(m_proId == 0){
        ui->Pro_CustomPlot->graph(0)->setName("f(x) = x^2");
    }else{
        ui->Pro_CustomPlot->graph(0)->setName("f(x) = xcos(4x)+xsin(20x) + 2");
    }
    ui->Pro_CustomPlot->graph(0)->rescaleAxes(true);
    ui->Pro_CustomPlot->xAxis->setLabel("x");
    ui->Pro_CustomPlot->yAxis->setLabel("f(x)");
    ui->Pro_CustomPlot->legend->setVisible(true);
    ui->Pro_CustomPlot->graph(0)->rescaleAxes(false);
    ui->Pro_CustomPlot->replot();
}

void PSODemoShowWidget::paintTspPlot()
{
    ui->Pro_CustomPlot->clearGraphs();
    ui->Pro_CustomPlot->addGraph();
    ui->Pro_CustomPlot->xAxis->setLabel("x");
    ui->Pro_CustomPlot->yAxis->setLabel("y");
    ui->Pro_CustomPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->Pro_CustomPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    QVector<double> xData, yData;
    for(int j = 0;j < tspDatas.size();j ++){
        xData.push_back(tspDatas[j].first);
        yData.push_back(tspDatas[j].second);
    }
    ui->Pro_CustomPlot->graph(0)->setData(xData, yData);
    ui->Pro_CustomPlot->xAxis->rescale();
    ui->Pro_CustomPlot->yAxis->rescale();
    ui->Pro_CustomPlot->xAxis->scaleRange(1.05, ui->Pro_CustomPlot->xAxis->range().center());
    ui->Pro_CustomPlot->yAxis->scaleRange(1.05, ui->Pro_CustomPlot->yAxis->range().center());
    ui->Pro_CustomPlot->replot();
}

void PSODemoShowWidget::on_return_ProMain_clicked()
{
    initWidget();
    m_plotNums = 0;
    if(m_proClassId == 1){
        emit returnFuncMainSignal();
    }else if(m_proClassId == 3){
        emit returnBPMainSignal();
    }else if(m_proClassId == 4){
        emit returnTspMainSignal();
    }/*else{
        emit returnTspMainSignal();
    }*/
}


void PSODemoShowWidget::on_hideProPlotCk_clicked()
{
    if((m_proClassId == 1 && m_proId == 2) || m_proClassId == 3){
        return;
    }
    if(ui->hideProPlotCk->isChecked()){
        if(!ui->Pro_CustomPlot->isHidden()){
            ui->Pro_CustomPlot->hide();
        }
    }else{
        if(ui->Pro_CustomPlot->isHidden()){
            ui->Pro_CustomPlot->show();
        }
    }
}


void PSODemoShowWidget::on_onlyShowResCk_clicked()
{
    if(ui->onlyShowResCk->isChecked()){
        if(!ui->Pro_CustomPlot->isHidden()){
            ui->Pro_CustomPlot->hide();
        }

        if(!ui->bottomShowWidget->isHidden()){
            ui->bottomShowWidget->hide();
        }
    }else{
        if(ui->bottomShowWidget->isHidden()){
            ui->bottomShowWidget->show();
        }
        if(ui->Pro_CustomPlot->isHidden() && (m_proClassId != 1 || m_proId != 2) && m_proClassId != 3){
            ui->Pro_CustomPlot->show();
        }
    }
}


void PSODemoShowWidget::on_hideAverResCk_clicked()
{
    if(ui->hideAverResCk->isChecked()){
        int size = ui->Res_CustomPlot->graphCount();
        for(int i = 0;i < size;++ i){
            if(i % 2 == 1){
                ui->Res_CustomPlot->graph(i)->setVisible(false);
            }
        }
    }else{
        int size = ui->Res_CustomPlot->graphCount();
        for(int i = 0;i < size;++ i){
            if(i % 2 == 1){
                ui->Res_CustomPlot->graph(i)->setVisible(true);
            }
        }
    }
    ui->Res_CustomPlot->replot();
}


void PSODemoShowWidget::on_clearResBtn_clicked()
{
    ui->Res_CustomPlot->clearGraphs();
    if(ui->Res_CustomPlot->legend){
        ui->Res_CustomPlot->plotLayout()->remove(ui->Res_CustomPlot->legend);
        ui->Res_CustomPlot->legend = nullptr;
    }
    ui->Res_CustomPlot->replot();
    m_plotNums = 0;
}


void PSODemoShowWidget::on_clearAll_clicked()
{
    // 绘图区域初始化
    if((m_proClassId != 1 || m_proId != 2) && m_proClassId != 3){
        ui->Pro_CustomPlot->clearGraphs();
        ui->Pro_CustomPlot->replot();
    }
    ui->Res_CustomPlot->clearGraphs();
    if(ui->Res_CustomPlot->legend){
        ui->Res_CustomPlot->plotLayout()->remove(ui->Res_CustomPlot->legend);
        ui->Res_CustomPlot->legend = nullptr;
    }
    ui->Res_CustomPlot->replot();
    // ui->Res_CustomPlot->hide();
    paintProPlot();

    m_plotNums = 0;

    // 结果输出区域初始化
    ui->outputResPlain->clear();
    ui->recordResTable->clearContents();
    ui->recordResTable->setRowCount(0);
}


void PSODemoShowWidget::on_startAlgo_clicked()
{
    if(m_plotNums == 7){
        QMessageBox::warning(this,"提示信息","迭代图像太多，请进行适当的清理!");
        return;
    }
    initResLegend();
    if(ui->Res_CustomPlot->isHidden()){
        ui->Res_CustomPlot->show();
    }
    psoObj->initPSO();
    int popu = ui->popuNums_Spin->value();               // 种群大小
    double C1 = ui->C1_Spin->value();                    // C1
    double C2 = ui->C2_Spin->value();
    double scale = ui->vmax_Spin->value();
    double w_init = ui->winit_Spin->value();
    double w_min = ui->wmin_Spin->value();
    int iterNums = ui->iterNums_Spin->value();
    psoObj->setProId(m_proClassId);
    if(m_proClassId == 1) psoObj->setId(m_proId);
    psoObj->setPopuNums(popu);
    psoObj->setC1(C1);
    psoObj->setC2(C2);
    if(m_proClassId == 1){
        psoObj->setVmax(scale);
        psoObj->setVmin(-scale);
        if(m_proId == 0){
            psoObj->setXmin(0);
            psoObj->setXmax(6);
        }else if(m_proId == 1){
            psoObj->setXmin(0);
            psoObj->setXmax(1);
        }else{
            psoObj->setXmin(0);
            psoObj->setXmax(4);
        }
    }else if(m_proClassId == 3){
        psoObj->setVmax(scale);
        psoObj->setVmin(-scale);
    }
    if(m_proClassId == 1 || m_proClassId == 3){
        psoObj->setWinit(w_init);
        psoObj->setWmin(w_min);
    }
    psoObj->setIterNums(iterNums);
    QElapsedTimer timer;
    timer.start();
    psoObj->PSO_Running();
    QVector<double> curBestRes = psoObj->CurBestResults();
    QVector<double> averBestRes = psoObj->AverBestResults();
    updateResPlain(curBestRes,averBestRes);
    if(m_proClassId == 4){
        QVector<int> path = psoObj->tsp_bestX();
        updateBestTspPlot(path);
    }
    updateResPlot(curBestRes,averBestRes);
    qint64 times = timer.elapsed();
    updateResTable(curBestRes.at(curBestRes.size()-1),times);

    MyMessageBox infoM(MyMessageBoxType_Success,QString("运行结束,总共运行%1ms!").arg(QString::number(times)));
    int ret = infoM.exec();
    if(ret == QMessageBox::Accepted){
        infoM.close();
    }else{
        return;
    }
}

void PSODemoShowWidget::updateResPlot(const QVector<double> &cur,const QVector<double> &aver)
{
    QPen pen;
    // 绘制当前最优适应值
    QVector<double> xs;
    for(int i = 1;i <= cur.size();++ i){
        xs.push_back(i);
    }
    ui->Res_CustomPlot->addGraph();
    MyColor curColor =  static_cast<MyColor>(m_plotNums);
    switch (curColor) {
    case MyColor_Red:
        pen.setColor(Qt::red);
        break;
    case MyColor_Orange:
        pen.setColor(QColor(255,165,0));
        break;
    case MyColor_Yellow:
        pen.setColor(Qt::yellow);
        break;
    case MyColor_Green:
        pen.setColor(Qt::green);
        break;
    case MyColor_Cyan:
        pen.setColor(Qt::cyan);
        break;
    case MyColor_Blue:
        pen.setColor(Qt::blue);
        break;
    case MyColor_Purple:
        pen.setColor(QColor(128,0,128));
        break;
    default:
        pen.setColor(Qt::black);
        break;
    }
    ui->Res_CustomPlot->graph(2*m_plotNums)->setPen(pen);
    ui->Res_CustomPlot->graph(2*m_plotNums)->setData(xs,cur);
    QString data = QString("%1").arg(QString::number(m_plotNums+1));
    // QString data = QString("(%1,%2,%3,%4)").arg(QString::number(ui->popu_Spin->value())).arg(QString::number(ui->cross_Spin->value())).arg(QString::number(ui->var_Spin->value())).arg(QString::number(ui->iterNums_Spin->value()));
    ui->Res_CustomPlot->graph(2*m_plotNums)->setName(data);
    if(m_plotNums) ui->Res_CustomPlot->graph(2*m_plotNums)->rescaleAxes(true);
    else ui->Res_CustomPlot->graph(2*m_plotNums)->rescaleAxes();
    ui->Res_CustomPlot->xAxis->setLabel("迭代次数");
    if(m_proClassId == 1) ui->Res_CustomPlot->yAxis->setLabel("函数值");
    else if(m_proClassId == 3) ui->Res_CustomPlot->yAxis->setLabel("总价值");
    else ui->Res_CustomPlot->yAxis->setLabel("路径长度");
    // ui->Res_CustomPlot->xAxis->setRange(0,xs.size());
    // 绘制每代平均适应值
    ui->Res_CustomPlot->addGraph();
    pen.setStyle(Qt::PenStyle::DashLine);   //设置为虚线
    ui->Res_CustomPlot->graph(2*m_plotNums+1)->setPen(pen);
    ui->Res_CustomPlot->graph(2*m_plotNums+1)->setData(xs,aver);
    ui->Res_CustomPlot->graph(2*m_plotNums+1)->rescaleAxes(true);

    if(ui->hideAverResCk->isChecked()){
        ui->Res_CustomPlot->graph(2*m_plotNums+1)->setVisible(false);
    }
    // ui->Res_CustomPlot->graph(2*m_plotNums+1)->addToLegend(nullptr);

    ui->Res_CustomPlot->legend->removeItem(m_plotNums+1);

    ui->Res_CustomPlot->replot();
    m_plotNums ++;
}

void PSODemoShowWidget::updateResPlain(const QVector<double> &cur,const QVector<double> &aver)
{
    int nums = cur.size();
    for(int i = 1;i <= nums;++ i){
        QString data;
        if(m_proClassId == 1 || m_proClassId == 3) data = QString("迭代次数:%1\t\t本代平均:%2\t\t目前最优:%3").arg(QString::number(i)).arg(QString::number(aver[i-1])).arg(QString::number(cur[i-1]));
        else data = QString("迭代次数:%1\t\t本代平均路径长度:%2\t\t目前最优路径长度:%3").arg(QString::number(i)).arg(QString::number(aver[i-1])).arg(QString::number(cur[i-1]));
        ui->outputResPlain->appendPlainText(data);
    }
    ui->outputResPlain->appendPlainText("\n\n");
}

void PSODemoShowWidget::updateResTable(double cur,qint64 t)
{
    int popu = ui->popuNums_Spin->value();               // 种群大小
    double C1 = ui->C1_Spin->value();                    // C1
    double C2 = ui->C2_Spin->value();
    double scale = ui->vmax_Spin->value();
    double w_init = ui->winit_Spin->value();
    double w_min = ui->wmin_Spin->value();
    int iterNums = ui->iterNums_Spin->value();
    int rowCounts = ui->recordResTable->rowCount();
    ui->recordResTable->insertRow(rowCounts);
    ui->recordResTable->setItem(rowCounts,0,new QTableWidgetItem(QString::number(popu)));
    ui->recordResTable->setItem(rowCounts,1,new QTableWidgetItem(QString::number(C1)));
    ui->recordResTable->setItem(rowCounts,2,new QTableWidgetItem(QString::number(C2)));
    ui->recordResTable->setItem(rowCounts,6,new QTableWidgetItem(QString::number(iterNums)));
    ui->recordResTable->setItem(rowCounts,9,new QTableWidgetItem(QString::number(t)));
    if(m_proClassId == 1 || m_proClassId == 3){
        ui->recordResTable->setItem(rowCounts,3,new QTableWidgetItem(QString::number(scale)));
        ui->recordResTable->setItem(rowCounts,4,new QTableWidgetItem(QString::number(w_init)));
        ui->recordResTable->setItem(rowCounts,5,new QTableWidgetItem(QString::number(w_min)));
        ui->recordResTable->setItem(rowCounts,7,new QTableWidgetItem(QString::number(cur)));
        ui->recordResTable->setItem(rowCounts,8,new QTableWidgetItem(QString::number(cur)));
    }else{
        ui->recordResTable->setItem(rowCounts,7,new QTableWidgetItem(QString::number(1/cur)));
        ui->recordResTable->setItem(rowCounts,8,new QTableWidgetItem(QString::number(cur)));
    }
}

void PSODemoShowWidget::updateBestTspPlot(QVector<int> &path)
{
    paintProPlot();
    QVector<double> xDatas,yDatas;
    int length = tspDatas.size();
    for(int i = 0;i < length;i ++){
        int x,y;
        int index = path[i];
        x = tspDatas[index].first;
        y = tspDatas[index].second;
        xDatas.push_back(x);
        yDatas.push_back(y);
    }
    xDatas.push_back(tspDatas[path[0]].first);
    yDatas.push_back(tspDatas[path[0]].second);
    for(int i = 0;i < length;i ++){
        ui->Pro_CustomPlot->addGraph();
        ui->Pro_CustomPlot->graph(i+1)->setScatterStyle(QCPScatterStyle::ssDisc);
        ui->Pro_CustomPlot->graph(i+1)->setData({xDatas[i],xDatas[i+1]}, {yDatas[i],yDatas[i+1]});
    }
    ui->Pro_CustomPlot->replot();
}

