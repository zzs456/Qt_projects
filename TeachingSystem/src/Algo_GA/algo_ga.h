#ifndef ALGO_GA_H
#define ALGO_GA_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QRandomGenerator>
#include <QSet>
#include <QtGlobal>
#include <algorithm>
#include <QPair>

struct GAFunc_Elem{
    int length;
    QString codeInfo = "";
};

struct GAPath_Elem{
    int id;
    QVector<int> codeInfo;
};

struct GATSP_Elem{
    QVector<int> codeInfo;
};

struct GABP_Elem{
    QString codeInfo = "";
};

class Algo_GA : public QObject
{
    Q_OBJECT
public:
    explicit Algo_GA(QObject *parent = nullptr);
    void setId(int id){ m_id = id; }
    void setPopu(int popu){ m_popu = popu; }
    void setIterNums(int iterNums){ m_iterNums = iterNums; }
    void setCrossPro(double crossPro){ m_crossPro = crossPro; }
    void setVarPro(double varPro){ m_varPro = varPro; }
    void setFuncId(int id){ m_funcId = id; }
    void setProId(int id) { m_proId = id; }
    void setFuncSphereN(int n) { m_funcsphereN = n; }
    void initGA();
    QVector<double> AverBestResults() const;
    QVector<double> CurBestResults() const;

    void iterOnce();

    // 路径规划问题数据初始化
    void setPathDatas(const QVector<QVector<int>> &datas) { pathData = datas; }

    // 背包问题数据初始化
    void setBpDatas(const QVector<QPair<int,int>> &datas) { bpData = datas; }

    // TSP 问题数据初始化
    void setTSPDatas(const QVector<QPair<int,int>> &datas) { tspData = datas; }

    // 初始化种群
    void init_Popu();
    void initFuncPopu(int,int);     // 函数优化问题
    int compuFuncNums(int,int);
    void initPathPopu();            // 路径规划问题
    void initBpPopu();              // 背包问题
    QVector<int> geneArr(int,int);
    void initTSPPopu();             // TSP 问题

    // 选择
    void selectPopu();
    void wheelSelect();
    void prizeSelect();
    double getFuncFitness(GAFunc_Elem e);
    double getFuncStrToDouble(int minN, int maxN, int bits, QString str);
    double getPathFitness(const GAPath_Elem &elem);
    double getTSPFitness(GATSP_Elem);
    double getBPFitness(const GABP_Elem &);

    // 交叉
    void crossPopu();
    void swapFuncElems(GAFunc_Elem &e1,GAFunc_Elem &e2,int index,int length);   // 函数优化问题
    void swapPathElem(GAPath_Elem &e1,GAPath_Elem &e2);                         // 路径规划问题
    void swapBpElem(GABP_Elem &e1,GABP_Elem &e2,int index,int length);          // 背包问题
    void testBpElem(GABP_Elem &e);
    void swapTSPElem(GATSP_Elem &e1,GATSP_Elem &e2);                            // 旅行商问题

    // 变异
    void mutaPopu();

    QVector<int> findOnePath(int,int,int,int);

    // 更新结果
    void updateRes();

    void GA_Running();

    QVector<int> getPathBestElem() const;

    QVector<int> getTspBestElem() const;


    QVector<QPair<double,double>> getPoints();

signals:

private:
    int m_id;               // 函数 id
    int m_popu;             // 种群大小
    int m_iterNums;         // 迭代次数
    double m_crossPro;      // 交叉概率
    double m_varPro;        // 变异概率
    int m_funcId;           // 选择方法

    int m_funcsphereN;

    int m_proId;            // 问题种类
    QVector<double> m_CurBestResults;
    QVector<double> m_AverBestResults;

    // 函数优化
    QVector<GAFunc_Elem> m_funcPopus;

    // 路径规划
    QVector<GAPath_Elem> m_pathPopus;
    QVector<int> pathBestElem;
    QVector<QVector<int>> pathData;

    // 背包问题
    QVector<GABP_Elem> m_bpPopus;
    QVector<QPair<int,int>> bpData;

    // TSP 问题
    QVector<GATSP_Elem> m_tspPopus;
    QVector<QPair<int,int>> tspData;
    QVector<int> tspBestElem;
};

#endif // ALGO_GA_H
