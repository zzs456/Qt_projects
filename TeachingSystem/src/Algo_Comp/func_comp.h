#ifndef FUNC_COMP_H
#define FUNC_COMP_H

#include "../Algo_GA/algo_ga.h"
#include "../Algo_PSO/algo_pso.h"
#include "../Algo_ACO/algo_aco.h"

#include <QWidget>
#include <QTabWidget>

namespace Ui {
class Func_Comp;
}

class Func_Comp : public QWidget
{
    Q_OBJECT

public:
    explicit Func_Comp(QWidget *parent = nullptr);

    void setAlgoType(int id){ algoType=id; }


    void initWidget();

    void initProPlot();

    void GA_Running();
    void PSO_Running();
    void ACO_Running();

    void updateResPlot(const QVector<double> &cur,const QVector<double> &aver);
    void updateResTable(double cur);
    void updateGAResTable(double cur);
    void updatePSOResTable(double cur);
    void updateACOResTable(double cur);

    void delayMSecs(int msec);

    void decCount();

    ~Func_Comp();

signals:
    void returnCompMain(int);

private slots:

    void on_startDemoBtn_clicked();

    void on_returnBtn_clicked();

    void on_clearResBtn_clicked();

private:
    Ui::Func_Comp *ui;

    int algoType;

    Algo_GA *gaObj;
    Algo_PSO *psoObj;
    Algo_ACO *acoObj;

    int m_plotNums;

    int count;
};

#endif // FUNC_COMP_H
