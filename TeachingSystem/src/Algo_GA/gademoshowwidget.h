#ifndef GADEMOSHOWWIDGET_H
#define GADEMOSHOWWIDGET_H

#include "algo_ga.h"

#include <QWidget>

namespace Ui {
class GADemoShowWidget;
}

class GADemoShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GADemoShowWidget(QWidget *parent = nullptr);
    void setProClassId(int id) { m_proClassId = id; }
    void setProId(int id) { m_proId = id; }
    void setFuncSphereN(int n) { m_funcSphereN = n; }
    void setPathDatas(const QVector<QVector<int>> &datas) { pathDatas = datas; }
    void setTspDatas(const QVector<QPair<int,int>> &datas) { tspDatas = datas; }
    void setBpDatas(const QVector<QPair<int,int>> &datas) { bpDatas = datas; }

    ~GADemoShowWidget();

    void initWidget();
    void initGAObj();
    void initResLegend();

    void paintProPlot();
    void paintInlayFuncPlot();
    void paintPathPlot();
    void paintTspPlot();


    void updateResPlot(const QVector<double> &,const QVector<double> &);
    void updateResPlain(const QVector<double> &,const QVector<double> &);
    void updateResTable(double,qint64 t);
    void updateBestPathPlot(const QVector<int> &);
    void updateBestTspPlot(QVector<int> &);

signals:
    void returnFuncMainSignal();
    void returnPathMainSignal();
    void returnTspMainSignal();
    void returnBpMainSignal();

private slots:
    void on_return_ProMain_clicked();

    void on_startAlgo_clicked();

    void on_hideProPlotCk_clicked();

    void on_hideAverResCk_clicked();

    void on_clearResBtn_clicked();

    void on_clearAll_clicked();

    void on_onlyShowResCk_clicked();

private:
    Ui::GADemoShowWidget *ui;

    Algo_GA *gaObj;

    int m_proClassId;
    int m_proId;
    int m_funcSphereN;

    int m_plotNums;

    QVector<QVector<int>> pathDatas;
    QVector<QPair<int,int>> tspDatas;
    QVector<QPair<int,int>> bpDatas;
};

#endif // GADEMOSHOWWIDGET_H
