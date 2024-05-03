#ifndef PSODEMOSHOWWIDGET_H
#define PSODEMOSHOWWIDGET_H

#include "algo_pso.h"

#include <QWidget>
#include <QVector>
#include <QPair>

namespace Ui {
class PSODemoShowWidget;
}

class PSODemoShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PSODemoShowWidget(QWidget *parent = nullptr);
    ~PSODemoShowWidget();
    void setProClassId(int id) { m_proClassId = id; }
    void setProId(int id) { m_proId = id; }
    void setFuncSphereN(int n) { m_funcSphereN = n; }

    void setBpDatas(const QVector<QPair<int,int>> &datas) { bpDatas = datas; }
    void setTspDatas(const QVector<QPair<int,int>> &datas) { tspDatas = datas; }

    void initWidget();
    void initResLegend();
    void initPSOObj();


    void paintProPlot();
    void paintInlayFuncPlot();
    void paintTspPlot();

    void updateResPlot(const QVector<double> &,const QVector<double> &);
    void updateResPlain(const QVector<double> &,const QVector<double> &);
    void updateResTable(double,qint64 t);
    void updateBestTspPlot(QVector<int> &);

signals:
    void returnFuncMainSignal();
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
    Ui::PSODemoShowWidget *ui;

    Algo_PSO *psoObj;

    int m_proClassId;
    int m_proId;
    int m_funcSphereN;

    int m_plotNums;

    QVector<QPair<int,int>> bpDatas;
    QVector<QPair<int,int>> tspDatas;
};

#endif // PSODEMOSHOWWIDGET_H
