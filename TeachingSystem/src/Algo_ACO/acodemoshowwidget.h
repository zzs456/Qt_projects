#ifndef ACODEMOSHOWWIDGET_H
#define ACODEMOSHOWWIDGET_H

#include "algo_aco.h"

#include <QWidget>
#include <QVector>
#include <QPair>

namespace Ui {
class ACODemoShowWidget;
}

class ACODemoShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ACODemoShowWidget(QWidget *parent = nullptr);
    ~ACODemoShowWidget();
    void setProClassId(int id) { m_proClassId = id; }
    void setProId(int id) { m_proId = id; }
    void setFuncSphereN(int n) { m_funcSphereN = n; }

    void setPathDatas(const QVector<QVector<int>> &datas) { pathDatas = datas; }
    void setBpDatas(const QVector<QPair<int,int>> &datas) { bpDatas = datas; }
    void setTspDatas(const QVector<QPair<int,int>> &datas) { tspDatas = datas; }

    void initWidget();
    void initResLegend();
    void initACOObj();


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
    void returnBPMainSignal();
    void returnTspMainSignal();

private slots:
    void on_return_ProMain_clicked();

    void on_hideProPlotCk_clicked();

    void on_onlyShowResCk_clicked();

    void on_hideAverResCk_clicked();

    void on_clearResBtn_clicked();

    void on_clearAll_clicked();

    void on_startAlgo_clicked();

private:
    Ui::ACODemoShowWidget *ui;

    Algo_ACO *acoObj;

    int m_proClassId;
    int m_proId;
    int m_funcSphereN;

    int m_plotNums;

    QVector<QVector<int>> pathDatas;
    QVector<QPair<int,int>> bpDatas;
    QVector<QPair<int,int>> tspDatas;
};

#endif // ACODEMOSHOWWIDGET_H
