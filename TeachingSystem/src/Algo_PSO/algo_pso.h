#ifndef ALGO_PSO_H
#define ALGO_PSO_H

#include "algo_pso.h"

#include <QObject>
#include <QtGlobal>
#include <QVector>
#include <QSet>

struct PSOFunc_Elem{
    QVector<double> pos;
    QVector<double> vs;
    QVector<double> posMax;
    double fit;
};

struct PSOBP_Elem{
    QVector<int> pos;
    QVector<double> vs;
    QVector<int> posMax;
    double fit;
};

struct PSOTsp_Elem{
    QVector<int> pos;
    QSet<QPair<int,int>> vs;
    QVector<int> posMax;
    double fit;
};

class Algo_PSO : public QObject
{
    Q_OBJECT
public:
    explicit Algo_PSO(QObject *parent = nullptr);
    void setProId(int id) { m_proId = id; }
    void setFuncSphereN(int n) { m_funcsphereN = n; }
    void setId(int id){ m_id = id; }
    void setPopuNums(int num) { popuNums = num; }
    void setC1(double c) { C1 = c; }
    void setC2(double c) { C2 = c; }
    void setVmin(double v) { vmin = v; }
    void setVmax(double v) { vmax = v; }
    void setXmin(double x) { xmin = x; }
    void setXmax(double x) { xmax = x; }
    void setWinit(double w) { w_init = w; }
    void setWmin(double w) { w_min = w; }
    void setIterNums(int nums) { iterNums = nums; }

    // 背包问题数据初始化
    void setBpDatas(const QVector<QPair<int,int>> &datas) { bpData = datas; }

    // TSP 问题数据初始化
    void setTSPDatas(const QVector<QPair<int,int>> &datas) { tspData = datas; }

    void initPSO();
    void PSO_Running();


    void init_popu();
    void initFuncPopu(double,double);
    void initBpPopu();              // 背包问题
    void testBpElem(PSOBP_Elem &e);
    void initTspPopu();
    QVector<int> geneArr(int, int);

    void iterOnce(int iter);
    void updateRes();

    double getFuncFitness(const QVector<double> &e);
    double getBpFitness(const QVector<int> &e);
    double getTspFitness(const QVector<int> &e);


    void updateSpeed(int);
    void updateFuncSpeed(int);
    void updateBpSpeed(int);

    void updateTspSpeed(int);
    QVector<QPair<int,int>> getSwapElems(QVector<int> &e1,const QVector<int> &e2);
    void do_swapElem(QVector<int> &tar,QPair<int,int> elem);

    void updatePos();
    void updateFuncPos();
    void updateBpPos();
    void updateTspPos();


    QVector<double> CurBestResults() const;

    QVector<double> AverBestResults() const;

    QVector<int> tsp_bestX() const;

    QVector<QPair<double,double>> getPoints();

signals:


private:
    int m_funcsphereN;
    int m_proId;            // 问题种类
    int m_id;               // 函数 id

    int popuNums;
    double C1;
    double C2;
    double vmin;
    double vmax;
    double xmin;
    double xmax;
    double w_init;
    double w_min;
    int iterNums;

    QVector<double> m_CurBestResults;
    QVector<double> m_AverBestResults;


    QVector<PSOFunc_Elem> m_funcPopus;
    QVector<double> m_func_bestX;


    QVector<QPair<int,int>> bpData;
    QVector<PSOBP_Elem> m_bpPopus;
    QVector<int> m_bp_bestX;

    QVector<QPair<int,int>> tspData;
    QVector<PSOTsp_Elem> m_tspPopus;
    QVector<int> m_tsp_bestX;
    QVector<QVector<double>> distances;
};

#endif // ALGO_PSO_H
