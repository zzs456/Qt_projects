#ifndef TSP_COMP_H
#define TSP_COMP_H

#include "../Algo_GA/algo_ga.h"
#include "../Algo_PSO/algo_pso.h"
#include "../Algo_ACO/algo_aco.h"

#include <QWidget>
#include <QTabWidget>

namespace Ui {
class Tsp_Comp;
}

class Tsp_Comp : public QWidget
{
    Q_OBJECT

public:
    explicit Tsp_Comp(QWidget *parent = nullptr);
    ~Tsp_Comp();

    void setAlgoType(int id){ algoType=id; }
    void setTSPDatas(const QVector<QPair<int,int>> &datas) { tspData = datas; }

    void GA_Running();
    void PSO_Running();
    void ACO_Running();

    void initWidget();

    void initProPlot();

    void updateResPlot(const QVector<double> &cur,const QVector<double> &aver);
    void updateResTable(double cur,qint64 t);
    void updateGAResTable(double cur,qint64 t);
    void updatePSOResTable(double cur,qint64 t);
    void updateACOResTable(double cur,qint64 t);

    void updateBestTspPlot(QVector<int> &path);

signals:
    void returnCompMain(int);

private slots:
    void on_returnBtn_clicked();

    void on_startDemoBtn_clicked();

    void on_clearResBtn_clicked();

private:
    Ui::Tsp_Comp *ui;

    int algoType;

    Algo_GA *gaObj;
    Algo_PSO *psoObj;
    Algo_ACO *acoObj;

    int m_plotNums;

    QVector<QPair<int,int>> tspData;
};

#endif // TSP_COMP_H
