#ifndef ALGO_ACO_H
#define ALGO_ACO_H

#include <QObject>
#include <QtGlobal>
#include <QVector>
#include <QSet>

struct ACOFunc_Elem{
    QVector<double> xs;
    QPair<int,int> bounds;
    double phe;
    int next;
    double funcValue;
};

struct ACOPath_Elem
{
    QVector<int> walked;
    double pathLength;
};

struct ACOBP_Elem{
    int start;
    QVector<int> walked;
    QSet<int> remains;
    double valueSum;
    double weightSum;
};

struct ACOTsp_Elem{
    int start;
    QVector<int> walked;
    QSet<int> remains;
    double pathLength;
};

class Algo_ACO : public QObject
{
    Q_OBJECT
public:
    explicit Algo_ACO(QObject *parent = nullptr);
    void setProId(int id) { m_proId = id; }
    void setFuncSphereN(int n) { m_funcsphereN = n; }
    void setId(int id){ m_id = id; }
    void setPopuNums(int num) { popuNums = num; }
    void setRho(double c) { rho = c; }
    void setAlpha(double c) { alpha = c; }
    void setBeta(double c) { beta = c; }
    void setQ(double q) { this->q = q; }
    void setIterNums(int nums) { iterNums = nums; }

    // 路径规划问题数据初始化
    void setPathDatas(const QVector<QVector<int>> &datas) { pathData = datas; }

    // 背包问题数据初始化
    void setBpDatas(const QVector<QPair<int,int>> &datas) { bpData = datas; }

    // TSP 问题数据初始化
    void setTSPDatas(const QVector<QPair<int,int>> &datas) { tspData = datas; }


    void initACO();
    void ACO_Running();


    void init_popu();
    void initFuncPopu(double min,double max);
    void initPathPopu();
    void initBpPopu();
    void initTspPopu();

    double getFuncValue(const QVector<double> &e);
    double getPathLength(const QVector<int> &elem);

    void init_popuPos();
    void initBp_popuPos();
    void initTsp_popuPos();

    void update_popuList();
    void updateFunc_popuList();
    void updatePath_popuList();
    void updateBp_popuList();
    void updateTsp_popuList();

    void update_phes(int iter);
    void updateFunc_phes(int iter);
    void updatePath_phes();
    void updateBp_phes();
    void updateTsp_phes();


    void iterOnce(int iter);
    void updateRes();


    QVector<double> CurBestResults() const;

    QVector<double> AverBestResults() const;

    QVector<int> tsp_bestX() const;

    QVector<int> getPathBestElem() const;

    QVector<QPair<double,double>> getPoints();

signals:


private:
    int m_funcsphereN;
    int m_proId;            // 问题种类
    int m_id;               // 函数 id

    int popuNums;
    double rho;
    double alpha;
    double beta;
    double q;
    int iterNums;

    QVector<double> m_CurBestResults;
    QVector<double> m_AverBestResults;

    QVector<ACOFunc_Elem> m_funcPopus;
    double m_func_bestValue;

    // 路径规划
    QVector<ACOPath_Elem> m_pathPopus;
    QVector<int> pathBestElem;
    QVector<QVector<int>> pathData;


    QVector<QPair<int,int>> bpData;
    QVector<ACOBP_Elem> m_bpPopus;
    double m_bp_bestValue;

    QVector<QPair<int,int>> tspData;
    QVector<ACOTsp_Elem> m_tspPopus;
    QVector<int> m_tsp_bestX;
    QVector<QVector<double>> distances;

    QVector<QVector<double>> phes;
    // QVector<QVector<double>> phes_changes;
};

#endif // ALGO_ACO_H
