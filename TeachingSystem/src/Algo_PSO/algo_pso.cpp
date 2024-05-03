#include "algo_pso.h"

#include <QRandomGenerator>
#include <QtGlobal>
#include <QtMath>
#include <QSet>
#include <QHash>
#include <QDebug>

Algo_PSO::Algo_PSO(QObject *parent)
    : QObject{parent}
{}

void Algo_PSO::initPSO()
{
    if(m_proId == 1){
        m_funcPopus.clear();
    }else if(m_proId == 3){
        m_bpPopus.clear();
    }else if(m_proId == 4){
        m_tspPopus.clear();
        // tspBestElem.clear();
    }/*else{
        m_tspPopus.clear();
        tspBestElem.clear();
    }*/
    m_CurBestResults.clear();
    m_AverBestResults.clear();
}

void Algo_PSO::PSO_Running()
{
    init_popu();    // 初始化种群
    for(int i = 0;i < iterNums;++ i){
        iterOnce(i);
        updateRes();
    }
}

void Algo_PSO::init_popu()
{
    if(m_proId == 1){
        if(m_id == 0){
            initFuncPopu(0,6);
        }else if(m_id == 1){
            initFuncPopu(0,1);
        }else{
            initFuncPopu(0,4);
        }
    }else if(m_proId == 3){
        initBpPopu();
    }else if(m_proId == 4){
        initTspPopu();
    }
}

void Algo_PSO::iterOnce(int iter)
{
    updateSpeed(iter);
    updatePos();
}

void Algo_PSO::updateRes()
{
    double maxFit = 0.0;
    double averFit = 0.0;
    if(m_proId == 1){
        maxFit = getFuncFitness(m_func_bestX);
        for(int i = 0;i < popuNums;++ i){
            averFit += m_funcPopus[i].fit;
        }
    }else if(m_proId == 3){
        maxFit = getBpFitness(m_bp_bestX);
        for(int i = 0;i < popuNums;++ i){
            averFit += m_bpPopus[i].fit;
        }
    }else if(m_proId == 4){
        maxFit = 1 / getTspFitness(m_tsp_bestX);
        for(int i = 0;i < popuNums;++ i){
            averFit += 1 / m_tspPopus[i].fit;
        }
    }
    averFit /= popuNums;
    m_AverBestResults.push_back(averFit);
    m_CurBestResults.push_back(maxFit);
}

double Algo_PSO::getFuncFitness(const QVector<double> &vs)
{
    double ret = 0.0;
    if(m_id == 0){
        ret = vs[0] * vs[0];
    }else if(m_id == 1){
        ret = vs[0] * qCos(4 * vs[0]) + vs[0] * qSin(20 * vs[0]) + 2;
    }else{
        for(int i = 0;i < vs.size();++ i){
            ret += vs[i] * vs[i];
        }
    }
    return ret;
}

double Algo_PSO::getBpFitness(const QVector<int> &e)
{
    double ret = 0.0;
    for(int i = 0;i < e.size();++ i){
        if(e[i] == 1){
            ret += bpData[i+1].first;
        }
    }
    return ret;
}

double Algo_PSO::getTspFitness(const QVector<int> &e)
{
    double ret = 0.0;
    for(int i = 0;i < e.size();++ i){
        int next = (i + 1) % e.size();
        ret += distances[e[i]][e[next]];
    }
    return 1 / ret;
}

void Algo_PSO::updateSpeed(int iter)
{
    if(m_proId == 1){
        updateFuncSpeed(iter);
    }else if(m_proId == 3){
        updateBpSpeed(iter);
    }else if(m_proId == 4){
        updateTspSpeed(iter);
    }
}

void Algo_PSO::updateFuncSpeed(int iter)
{
    double w = w_init - (w_init -w_min) * (iter / iterNums);
    for(int i = 0;i < popuNums;++ i){
        double r1 = QRandomGenerator::global()->generateDouble();
        double r2 = QRandomGenerator::global()->generateDouble();
        for(int j = 0;j < m_funcPopus[i].vs.size();++ j){
            double update_velem = m_funcPopus[i].vs[j] * w +
                                  C1 * r1 * (m_funcPopus[i].posMax[j] - m_funcPopus[i].pos[j]) +
                                  C2 * r2 * (m_func_bestX[j] - m_funcPopus[i].pos[j]);
            if(update_velem > vmax){
                update_velem = vmax;
            }
            if(update_velem < vmin){
                update_velem = vmin;
            }
            m_funcPopus[i].vs[j] = update_velem;
        }
    }
}

void Algo_PSO::updateBpSpeed(int iter)
{
    double w = w_init - (w_init -w_min) * (iter / iterNums);
    for(int i = 0;i < popuNums;++ i){
        double r1 = QRandomGenerator::global()->generateDouble();
        double r2 = QRandomGenerator::global()->generateDouble();
        for(int j = 0;j < m_bpPopus[i].vs.size();++ j){
            double update_velem = m_bpPopus[i].vs[j] * w +
                                  C1 * r1 * (m_bpPopus[i].posMax[j] - m_bpPopus[i].pos[j]) +
                                  C2 * r2 * (m_bp_bestX[j] - m_bpPopus[i].pos[j]);
            if(update_velem > vmax){
                update_velem = vmax;
            }
            if(update_velem < vmin){
                update_velem = vmin;
            }
            m_bpPopus[i].vs[j] = update_velem;
        }
    }
}

void Algo_PSO::updateTspSpeed(int iter)
{
    Q_UNUSED(iter);
    for(int i = 0;i < popuNums;++ i){
        m_tspPopus[i].vs.clear();
        QVector<int> temp = m_tspPopus[i].pos;
        QVector<QPair<int,int>> res1 = getSwapElems(temp,m_tspPopus[i].posMax);
        temp = m_tspPopus[i].pos;
        QVector<QPair<int,int>> res2 = getSwapElems(temp,m_tsp_bestX);
        for(int j = 0;j < res1.size();++ j){
            double r1 = QRandomGenerator::global()->generateDouble();
            if(r1 < C1){
                if(m_tspPopus[i].vs.contains(res1[j])){
                    continue;
                }
                m_tspPopus[i].vs.insert(res1[j]);
            }
        }
        for(int j = 0;j < res2.size();++ j){
            double r2 = QRandomGenerator::global()->generateDouble();
            if(r2 < C2){
                if(m_tspPopus[i].vs.contains(res2[j])){
                    continue;
                }
                m_tspPopus[i].vs.insert(res2[j]);
            }
        }
    }
}

QVector<QPair<int, int>> Algo_PSO::getSwapElems(QVector<int> &e1, const QVector<int> &e2)
{
    QVector<QPair<int,int>> ret;
    for(int i = 0;i < e1.size();++ i){
        if(e1[i] == e2[i]){
            continue;
        }else{
            ret.push_back(QPair<int,int>(e1[i],e2[i]));
            do_swapElem(e1,QPair<int,int>(e1[i],e2[i]));
        }
    }
    return ret;
}

void Algo_PSO::do_swapElem(QVector<int> &tar, QPair<int, int> elem)
{
    int i1 = -1;
    int i2 = -1;
    for(int i = 0;i < tar.size();++ i){
        if(tar[i] == elem.first){
            i1 = i;
        }
        if(tar[i] == elem.second){
            i2 = i;
        }
    }
    int temp = tar[i1];
    tar[i1] = tar[i2];
    tar[i2] = temp;
}

void Algo_PSO::updatePos()
{
    if(m_proId == 1){
        updateFuncPos();
    }else if(m_proId == 3){
        updateBpPos();
    }else if(m_proId == 4){
        updateTspPos();
    }
}

void Algo_PSO::updateFuncPos()
{
    double oldPopuMax = getFuncFitness(m_func_bestX);
    for(int i = 0;i < popuNums;++ i){
        for(int j = 0;j < m_funcPopus[i].pos.size();++ j){
            double update_xelem = m_funcPopus[i].pos[j] + m_funcPopus[i].vs[j];
            if(update_xelem > xmax){
                update_xelem = xmax;
            }
            if(update_xelem < xmin){
                update_xelem = xmin;
            }
            m_funcPopus[i].pos[j] = update_xelem;
        }
        m_funcPopus[i].fit = getFuncFitness(m_funcPopus[i].pos);
        double oldMax = getFuncFitness(m_funcPopus[i].posMax);
        if(m_funcPopus[i].fit > oldMax){
            m_funcPopus[i].posMax = m_funcPopus[i].pos;
        }
        if(m_funcPopus[i].fit > oldPopuMax){
            m_func_bestX = m_funcPopus[i].pos;
        }
    }
}

void Algo_PSO::updateBpPos()
{
    double oldPopuMax = getBpFitness(m_bp_bestX);
    for(int i = 0;i < popuNums;++ i){
        for(int j = 0;j < m_bpPopus[i].pos.size();++ j){
            int update_xelem = -1;
            double ran = QRandomGenerator::global()->generateDouble();
            double res = 1 / (1 + qExp(-m_bpPopus[i].vs[j]));
            if(ran < res){
                update_xelem = 1;
            }else{
                update_xelem = 0;
            }
            m_bpPopus[i].pos[j] = update_xelem;
        }
        testBpElem(m_bpPopus[i]);
        m_bpPopus[i].fit = getBpFitness(m_bpPopus[i].pos);
        double oldMax = getBpFitness(m_bpPopus[i].posMax);
        if(m_bpPopus[i].fit > oldMax){
            m_bpPopus[i].posMax = m_bpPopus[i].pos;
        }
        if(m_bpPopus[i].fit > oldPopuMax){
            m_bp_bestX = m_bpPopus[i].pos;
        }
    }
}

void Algo_PSO::updateTspPos()
{
    double oldPopuMax = getTspFitness(m_tsp_bestX);
    for(int i = 0;i < popuNums;++ i){
        for(auto j = m_tspPopus[i].vs.cbegin();j != m_tspPopus[i].vs.cend();++ j){
            do_swapElem(m_tspPopus[i].pos,*j);
        }
        m_tspPopus[i].fit = getTspFitness(m_tspPopus[i].pos);
        double oldMax = getTspFitness(m_tspPopus[i].posMax);
        if(m_tspPopus[i].fit > oldMax){
            m_tspPopus[i].posMax = m_tspPopus[i].pos;
        }
        if(m_tspPopus[i].fit > oldPopuMax){
            // qDebug() << "Hello";
            m_tsp_bestX = m_tspPopus[i].pos;
        }
    }
}

void Algo_PSO::initFuncPopu(double min, double max)
{
    int dims = 0;
    if(m_id == 0 || m_id == 1){
        dims = 1;
    }else if(m_id == 2){
        dims = m_funcsphereN;
    }
    double maxId = 0;
    double maxFit = 0.0;
    for(int i = 0;i < popuNums;++ i){
        PSOFunc_Elem elem;
        for(int j = 0;j < dims;++ j){
            double pos_elem = QRandomGenerator::global()->generateDouble() * (max - min) + min;
            double v_elem = QRandomGenerator::global()->generateDouble() * (vmax - vmin) + vmin;
            double posMax_elem = pos_elem;
            elem.pos.push_back(pos_elem);
            elem.vs.push_back(v_elem);
            elem.posMax.push_back(posMax_elem);
        }
        elem.fit = getFuncFitness(elem.pos);
        m_funcPopus.push_back(elem);
        if(elem.fit > maxFit){
            maxId = i;
            maxFit = elem.fit;
        }
    }
    m_func_bestX = m_funcPopus[maxId].pos;
}

void Algo_PSO::initBpPopu()
{
    int length = bpData[0].first;
    int num = 0;
    double maxId = 0;
    double maxFit = 0.0;
    while(num != popuNums){
        PSOBP_Elem elem;
        double sum = 0.0;
        for(int i = 0;i < length;++ i){
            int index_val = QRandomGenerator::global()->bounded(0,2);
            if(index_val) sum += bpData[i+1].second;
            elem.pos.push_back(index_val);
            double v_elem = QRandomGenerator::global()->generateDouble() * (vmax - vmin) + vmin;
            elem.vs.push_back(v_elem);
        }
        if(sum <= (double)bpData[0].second) {
            double fit = getBpFitness(elem.pos);
            elem.fit = fit;
            elem.posMax = elem.pos;
            m_bpPopus.push_back(elem);
            if(elem.fit > maxFit){
                maxId = num;
                maxFit = elem.fit;
            }
            ++ num;
        }
    }
    m_bp_bestX = m_bpPopus[maxId].pos;
}

void Algo_PSO::testBpElem(PSOBP_Elem &e)
{
    double sum = 0.0;
    for(int i = 0;i < e.pos.size();++ i){
        if(e.pos[i]) sum += bpData[i+1].second;
    }
    if(sum <= bpData[0].second){
        return;
    }
    QVector<QPair<int,double>> vs;
    for(int i = 0;i < e.pos.size();++ i){
        if(e.pos[i]) vs.push_back(QPair<int,double>(i+1,bpData[i+1].first/bpData[i+1].second));
    }
    std::sort(vs.begin(),vs.end(),[](const QPair<int, double> &a, const QPair<int, double> &b) {
        return a.second < b.second;
    });
    for(int i = 0;i < vs.size();++ i){
        sum -= bpData[vs[i].first].second;
        e.pos[vs[i].first-1] = 0;
        if(sum <= bpData[0].second){
            break;
        }
    }
}

QVector<int> Algo_PSO::geneArr(int min, int max)
{
    QVector<int> permutation;
    for (int i = min; i <= max; ++i) {
        permutation.append(i);
    }
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(permutation.begin(), permutation.end(), rng);
    return permutation;
}

void Algo_PSO::initTspPopu()
{
    distances.resize(tspData.size());
    for(int i = 0;i < tspData.size();++ i){
        distances[i].resize(tspData.size());
    }
    for(int i = 0;i < tspData.size();++ i){
        for(int j = 0;j < tspData.size();++ j){
            double disX = tspData[i].first - tspData[j].first;
            double disY = tspData[i].second - tspData[j].second;
            double dis_power = disX * disX + disY * disY;
            distances[i][j] = qSqrt(dis_power);
        }
    }
    srand((unsigned)time(NULL));
    int maxId = -1;
    double maxFit = 0.0;
    QVector<int> vs;
    for(int i = 0;i < popuNums;++ i){
        vs = geneArr(0,tspData.size()-1);
        PSOTsp_Elem e;
        e.pos = vs;
        e.posMax = e.pos;
        e.vs.clear();
        e.fit = getTspFitness(e.pos);
        if(e.fit > maxFit){
            maxId = i;
            maxFit = e.fit;
        }
        m_tspPopus.push_back(e);
    }
    m_tsp_bestX = m_tspPopus[maxId].pos;
}

QVector<double> Algo_PSO::CurBestResults() const
{
    return m_CurBestResults;
}

QVector<double> Algo_PSO::AverBestResults() const
{
    return m_AverBestResults;
}

QVector<int> Algo_PSO::tsp_bestX() const
{
    return m_tsp_bestX;
}

QVector<QPair<double, double> > Algo_PSO::getPoints()
{
    QVector<QPair<double,double>> ret;
    for(int i = 0;i < m_funcPopus.size();++ i){
        double x = m_funcPopus[i].pos[0];
        double y = m_funcPopus[i].fit;
        ret.push_back(QPair<double,double>(x,y));
    }
    return ret;
}
