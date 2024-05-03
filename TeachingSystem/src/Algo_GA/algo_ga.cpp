#include "algo_ga.h"

#include <QtGlobal>
#include <QDebug>
#include <QtMath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

Algo_GA::Algo_GA(QObject *parent)
    : QObject{parent}
{}

void Algo_GA::initGA()
{
    if(m_proId == 1){
        m_funcPopus.clear();
    }else if(m_proId == 2){
        m_pathPopus.clear();
        pathBestElem.clear();
    }else if(m_proId == 3){
        m_bpPopus.clear();
    }else{
        m_tspPopus.clear();
        tspBestElem.clear();
    }
    m_CurBestResults.clear();
    m_AverBestResults.clear();
}

void Algo_GA::init_Popu()
{
    if(m_proId == 1){
        if(m_id == 0){
            initFuncPopu(0,6);
        }else if(m_id == 1){
            initFuncPopu(0,1);
        }else{
            initFuncPopu(0,4);
        }
    }else if(m_proId == 2){
        initPathPopu();
    }else if(m_proId == 3){
        initBpPopu();
    }else{
        initTSPPopu();
    }
}

int Algo_GA::compuFuncNums(int minN, int maxN)
{
    int dis = maxN - minN;
    double disD = dis / 0.001;
    int m = 0;
    double t = 1;
    while(t < disD){
        t *= 2;
        ++ m;
    }
    return m;
}

void Algo_GA::initFuncPopu(int minN, int maxN)
{
    int length = compuFuncNums(minN,maxN);
    if(m_id == 0 || m_id == 1){
        GAFunc_Elem elem;
        for(int i = 0;i < m_popu;++ i){
            elem.length = length;
            QString temp = "";
            for(int i = 0;i < length;++ i){
                int index_val = QRandomGenerator::global()->bounded(0,2);
                temp += QString::number(index_val);
            }
            elem.codeInfo = temp;
            m_funcPopus.push_back(elem);
        }
    }else if(m_id == 2){
        for(int i = 0;i < m_popu;++ i){
            GAFunc_Elem elem;
            elem.length = length;
            QString temp = "";
            for(int i = 0;i < m_funcsphereN * length;++ i){
                int index_val = QRandomGenerator::global()->bounded(0,2);
                temp += QString::number(index_val);
            }
            elem.codeInfo = temp;
            m_funcPopus.push_back(elem);
        }
    }
}

void Algo_GA::initPathPopu()
{
    QVector<QVector<int>> temp = pathData;
    int rows = temp.size();
    int cols = temp[0].size();
    for(int i = 0;i < m_popu;){
        int x = 0,y = 0;
        QVector<int> path;
        path.push_back(0);
        while(x != rows - 1 || y != cols - 1){
            int random = QRandomGenerator::global()->bounded(0,3);
            if(random == 0){        // 向上走
                if(x == rows - 1 || temp[x + 1][y] == 1){
                    path.clear();
                    break;
                }else{
                    ++x;
                    path.push_back(cols*x+y);
                }
            }else if(random == 1){      // 向右走
                if(y == cols - 1 || temp[x][y + 1] == 1){
                    path.clear();
                    break;
                }else{
                    ++y;
                    path.push_back(cols*x+y);
                }
            }else{
                if(x == rows - 1 || y == cols - 1 || temp[x+1][y+1] == 1){
                    path.clear();
                    break;
                }else{
                    ++x;
                    ++y;
                    path.push_back(cols*x+y);
                }
            }
        }
        if(path.isEmpty()){
            continue;
        }else{
            ++i;
            GAPath_Elem elem;
            elem.id = m_id;
            elem.codeInfo = path;
            m_pathPopus.push_back(elem);
        }
    }
}

void Algo_GA::initBpPopu()
{
    int length = bpData[0].first;
    int num = 0;
    while(num != m_popu){
        GABP_Elem elem;
        QString temp = "";
        double sum = 0.0;
        for(int i = 0;i < length;++ i){
            int index_val = QRandomGenerator::global()->bounded(0,2);
            if(index_val) sum += bpData[i+1].second;
            temp += QString::number(index_val);
        }
        elem.codeInfo = temp;
        if(sum <= (double)bpData[0].second) {
            m_bpPopus.push_back(elem);
            ++ num;
        }
    }
}

QVector<int> Algo_GA::geneArr(int min, int max)
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

void Algo_GA::initTSPPopu()
{
    srand((unsigned)time(NULL));
    QVector<int> vs;
    for(int i = 0;i < m_popu;++ i){
        vs = geneArr(0,tspData.size()-1);
        GATSP_Elem e;
        e.codeInfo = vs;
        m_tspPopus.push_back(e);
    }
}

void Algo_GA::iterOnce()
{
    selectPopu();
    crossPopu();
    mutaPopu();
}

void Algo_GA::selectPopu()
{
    if(m_funcId == 1){
        wheelSelect();
    }else{
        prizeSelect();
    }
}

void Algo_GA::wheelSelect()
{
    if(m_proId == 1){
        QVector<GAFunc_Elem> newElems = m_funcPopus;
        m_funcPopus.clear();
        QVector<double> fits;
        double sum = 0.0;
        for(int i = 0;i < m_popu;++ i){
            sum += getFuncFitness(newElems[i]);
            fits.push_back(sum);
        }
        for(int i = 0;i < m_popu;++ i){
            fits[i] /= sum;
        }
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            int index = std::lower_bound(fits.begin(),fits.end(),temp) - fits.begin();
            m_funcPopus.push_back(newElems[index]);
        }
    }else if(m_proId == 2){
        QVector<GAPath_Elem> newElems = m_pathPopus;
        m_pathPopus.clear();
        QVector<double> fits;
        double sum = 0.0;
        for(int i = 0;i < m_popu;++ i){
            sum += getPathFitness(newElems[i]);
            fits.push_back(sum);
        }
        for(int i = 0;i < m_popu;++ i){
            fits[i] /= sum;
        }
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            int index = std::lower_bound(fits.begin(),fits.end(),temp) - fits.begin();
            m_pathPopus.push_back(newElems[index]);
        }
    }else if(m_proId == 3){
        QVector<GABP_Elem> newElems = m_bpPopus;
        m_bpPopus.clear();
        QVector<double> fits;
        double sum = 0.0;
        for(int i = 0;i < m_popu;++ i){
            sum += getBPFitness(newElems[i]);
            fits.push_back(sum);
        }
        for(int i = 0;i < m_popu;++ i){
            fits[i] /= sum;
        }
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            int index = std::lower_bound(fits.begin(),fits.end(),temp) - fits.begin();
            m_bpPopus.push_back(newElems[index]);
        }
    }else{
        QVector<GATSP_Elem> newElems = m_tspPopus;
        m_tspPopus.clear();
        QVector<double> fits;
        double sum = 0.0;
        for(int i = 0;i < m_popu;++ i){
            sum += getTSPFitness(newElems[i]);
            fits.push_back(sum);
        }
        for(int i = 0;i < m_popu;++ i){
            fits[i] /= sum;
        }
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            int index = std::lower_bound(fits.begin(),fits.end(),temp) - fits.begin();
            m_tspPopus.push_back(newElems[index]);
        }
    }
}

void Algo_GA::prizeSelect()
{
    if(m_proId == 1){
        QVector<GAFunc_Elem> newElems = m_funcPopus;
        m_funcPopus.clear();
        while(m_funcPopus.size() < m_popu){
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2){
                continue;
            }else{
                double fit1 = getFuncFitness(newElems[i1]);
                double fit2 = getFuncFitness(newElems[i2]);
                if(fit1 >= fit2){
                    m_funcPopus.push_back(newElems[i1]);
                }else{
                    m_funcPopus.push_back(newElems[i2]);
                }
            }
        }
    }else if(m_proId == 2){
        QVector<GAPath_Elem> newElems = m_pathPopus;
        m_pathPopus.clear();
        while(m_pathPopus.size() < m_popu){
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2){
                continue;
            }else{
                double fit1 = getPathFitness(newElems[i1]);
                double fit2 = getPathFitness(newElems[i2]);
                if(fit1 >= fit2){
                    m_pathPopus.push_back(newElems[i1]);
                }else{
                    m_pathPopus.push_back(newElems[i2]);
                }
            }
        }
    }else if(m_proId == 3){
        QVector<GABP_Elem> newElems = m_bpPopus;
        m_bpPopus.clear();
        while(m_bpPopus.size() < m_popu){
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2){
                continue;
            }else{
                double fit1 = getBPFitness(newElems[i1]);
                double fit2 = getBPFitness(newElems[i2]);
                if(fit1 >= fit2){
                    m_bpPopus.push_back(newElems[i1]);
                }else{
                    m_bpPopus.push_back(newElems[i2]);
                }
            }
        }
    }else{
        QVector<GATSP_Elem> newElems = m_tspPopus;
        m_tspPopus.clear();
        while(m_tspPopus.size() < m_popu){
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2){
                continue;
            }else{
                double fit1 = getTSPFitness(newElems[i1]);
                double fit2 = getTSPFitness(newElems[i2]);
                if(fit1 >= fit2){
                    m_tspPopus.push_back(newElems[i1]);
                }else{
                    m_tspPopus.push_back(newElems[i2]);
                }
            }
        }
    }
}

double Algo_GA::getFuncFitness(GAFunc_Elem e)
{
    double ret = 0.0;
    if(m_id == 0){
        ret = getFuncStrToDouble(0,6,e.length,e.codeInfo);
        ret = ret * ret;
    }else if(m_id == 1){
        ret = getFuncStrToDouble(0,1,e.length,e.codeInfo);
        ret = ret * qCos(4 * ret) + ret * qSin(20 * ret) + 2;
    }else if(m_id == 2){
        for(int i = 0;i < e.codeInfo.size()/e.length;++ i){
            double d = getFuncStrToDouble(0,4,e.length,e.codeInfo.mid(i*e.length,e.length));
            ret = ret + d * d;
        }
    }else{
        ret = 0.0;
    }
    return ret;
}

double Algo_GA::getFuncStrToDouble(int minN, int maxN, int bits, QString str)
{
    double deno = qPow(2,bits) - 1;
    bool isOk;
    int val = str.toInt(&isOk,2);
    double ret = minN + ((maxN - minN) / deno) * val;
    return ret;
}

double Algo_GA::getPathFitness(const GAPath_Elem &elem)
{
    double dis = 0.0;
    QVector<QVector<int>> temp = pathData;
    int cols = temp[0].size();
    for(int i = 0;i < elem.codeInfo.size() - 1;++ i){
        int x1 = elem.codeInfo[i] / cols;
        int y1 = elem.codeInfo[i] % cols;
        int x2 = elem.codeInfo[i+1] / cols;
        int y2 = elem.codeInfo[i+1] % cols;
        double disX = x2 - x1;
        double disY = y2 - y1;
        dis += qSqrt(disX * disX + disY * disY);
    }
    return 1 / dis;
}

double Algo_GA::getTSPFitness(GATSP_Elem e)
{
    double dis = 0.0;
    for(int i = 0;i < e.codeInfo.size();++ i){
        int next = (i + 1) % e.codeInfo.size();
        double disX,disY;
        disX = tspData[e.codeInfo[next]].first - tspData[e.codeInfo[i]].first;
        disY = tspData[e.codeInfo[next]].second - tspData[e.codeInfo[i]].second;
        dis += qSqrt(disX * disX + disY * disY);
    }
    return 1 / dis;
}

double Algo_GA::getBPFitness(const GABP_Elem &elem)
{
    double ret = 0.0;
    for(int i = 0;i < elem.codeInfo.size();++ i){
        if(elem.codeInfo[i] == '1'){
            ret += bpData[i+1].first;
        }
    }
    return ret;
}

void Algo_GA::crossPopu()
{
    if(m_proId == 1){
        for(int i = 0;i < m_popu / 2;){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_crossPro){
                ++ i;
                continue;
            }
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2) continue;
            ++ i;
            if(m_id == 0 || m_id == 1){
                int index = QRandomGenerator::global()->bounded(1,m_funcPopus[0].length);
                swapFuncElems(m_funcPopus[i1],m_funcPopus[i2],index,m_funcPopus[0].length);
            }else if(m_id == 2){
                int index = QRandomGenerator::global()->bounded(1,m_funcsphereN * m_funcPopus[0].length);
                swapFuncElems(m_funcPopus[i1],m_funcPopus[i2],index,m_funcsphereN * m_funcPopus[0].length);
            }
        }
    }else if(m_proId == 2){
        for(int i = 0;i < m_popu / 2;){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_crossPro){
                ++ i;
                continue;
            }
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2) continue;
            ++ i;
            swapPathElem(m_pathPopus[i1],m_pathPopus[i2]);
        }
    }else if(m_proId == 3){
        for(int i = 0;i < m_popu / 2;){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_crossPro){
                ++ i;
                continue;
            }
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2) continue;
            ++ i;
            int length = bpData[0].first;
            int index = QRandomGenerator::global()->bounded(1,length);
            swapBpElem(m_bpPopus[i1],m_bpPopus[i2],index,length);
            testBpElem(m_bpPopus[i1]);
            testBpElem(m_bpPopus[i2]);
        }
    }else{
        for(int i = 0;i < m_popu / 2;){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_crossPro){
                ++ i;
                continue;
            }
            int i1 = QRandomGenerator::global()->bounded(0,m_popu);
            int i2 = QRandomGenerator::global()->bounded(0,m_popu);
            if(i1 == i2) continue;
            ++ i;
            swapTSPElem(m_tspPopus[i1],m_tspPopus[i2]);
        }
    }
}

void Algo_GA::mutaPopu()
{
    if(m_proId == 1){
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_varPro){
                continue;
            }
            if(m_id == 0 || m_id == 1){
                int index = QRandomGenerator::global()->bounded(0,m_funcPopus[0].length);
                m_funcPopus[i].codeInfo[index] = (m_funcPopus[i].codeInfo[index] == '0') ? '1' : '0';
            }else if(m_id == 2){
                int index = QRandomGenerator::global()->bounded(0,m_funcsphereN * m_funcPopus[0].length);
                m_funcPopus[i].codeInfo[index] = (m_funcPopus[i].codeInfo[index] == '0') ? '1' : '0';
            }
        }
    }else if(m_proId == 2){
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_varPro){
                continue;
            }
            int index1 = QRandomGenerator::global()->bounded(0,m_pathPopus[i].codeInfo.size());
            int index2 = QRandomGenerator::global()->bounded(0,m_pathPopus[i].codeInfo.size());
            int minIndex = qMin(index1,index2);
            int maxIndex = qMax(index1,index2);
            if(minIndex == maxIndex){
                break;
            }
            int src = m_pathPopus[i].codeInfo[minIndex];
            int dest = m_pathPopus[i].codeInfo[maxIndex];
            QVector<int> copyData = m_pathPopus[i].codeInfo;
            int cols = pathData[0].size();
            int x1 = src / cols;
            int y1 = src % cols;
            int x2 = dest / cols;
            int y2 = dest % cols;
            QVector<int> repPath;
            repPath = findOnePath(x1,y1,x2,y2);
            if(repPath.size() <= 2){
                return;
            }
            m_pathPopus[i].codeInfo.clear();
            //qDebug() << copyPath.size() << "\t" << minIndex << "\t" << maxIndex;

            for(int j = 0;j < minIndex;++ j){
                m_pathPopus[i].codeInfo.push_back(copyData[j]);
            }
            for(int j = 0;j < repPath.size();++ j){
                m_pathPopus[i].codeInfo.push_back(repPath[j]);
            }
            for(int j = maxIndex+1;j < copyData.size();++j){
                m_pathPopus[i].codeInfo.push_back(copyData[j]);
            }
        }
    }else if(m_proId == 3){
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_varPro){
                continue;
            }
            int index = QRandomGenerator::global()->bounded(0,bpData[0].first);
            m_bpPopus[i].codeInfo[index] = (m_bpPopus[i].codeInfo[index] == '0') ? '1' : '0';
            testBpElem(m_bpPopus[i]);
        }
    }else{
        for(int i = 0;i < m_popu;++ i){
            double temp = QRandomGenerator::global()->generateDouble();
            if(temp > m_varPro){
                continue;
            }
            int length = m_tspPopus[i].codeInfo.size();
            int index1 = QRandomGenerator::global()->bounded(0,length);
            int index2 = QRandomGenerator::global()->bounded(0,length);
            while(index2 == index1) index2 = QRandomGenerator::global()->bounded(0,length);
            int minIndex = qMin(index1,index2);
            int maxIndex = qMax(index1,index2);
            int tempN = m_tspPopus[i].codeInfo[minIndex];
            m_tspPopus[i].codeInfo[minIndex] = m_tspPopus[i].codeInfo[maxIndex];
            m_tspPopus[i].codeInfo[maxIndex] = tempN;
        }
    }
}

QVector<int> Algo_GA::findOnePath(int x1, int y1, int x2, int y2)
{
    QVector<QVector<int>> temp = pathData;
    // int rows = temp.size();
    int cols = temp[0].size();
    QVector<int> path;
    for(int i = 0;i < 1;){
        int x = x1,y = y1;
        path.push_back(cols*x1+y1);
        while(x != x2 || y != y2){
            int random = QRandomGenerator::global()->bounded(0,3);
            if(random == 0){        // 向上走
                if(x == x2 || temp[x + 1][y] == 1){
                    path.clear();
                    break;
                }else{
                    ++x;
                    path.push_back(cols*x+y);
                }
            }else if(random == 1){      // 向右走
                if(y == y2 || temp[x][y + 1] == 1){
                    path.clear();
                    break;
                }else{
                    ++y;
                    path.push_back(cols*x+y);
                }
            }else{
                if(x == x2 || y == y2 || temp[x+1][y+1] == 1){
                    path.clear();
                    break;
                }else{
                    ++x;
                    ++y;
                    path.push_back(cols*x+y);
                }
            }
        }
        if(path.isEmpty()){
            continue;
        }else{
            ++i;
        }
    }
    return path;
}

void Algo_GA::updateRes()
{
    int maxId = 0;
    double maxFit = 0;
    double sum = 0.0;
    for(int i = 0;i < m_popu;++ i){
        double temp = 0.0;
        if(m_proId == 1){
            temp = getFuncFitness(m_funcPopus[i]);
        }else if(m_proId == 2){
            temp = getPathFitness(m_pathPopus[i]);
        }else if(m_proId == 3){
            temp = getBPFitness(m_bpPopus[i]);
        }else{
            temp = getTSPFitness(m_tspPopus[i]);
        }
        if(m_proId == 1 || m_proId == 3){
            sum += temp;
        }else{
            sum += 1 / temp;
        }
        if(temp > maxFit){
            maxFit = temp;
            maxId = i;
        }
    }
    m_AverBestResults.push_back(sum / m_popu);
    if(m_CurBestResults.isEmpty()){
        if(m_proId == 1){
            m_CurBestResults.push_back(maxFit);
        }else if(m_proId == 2){
            m_CurBestResults.push_back(1/maxFit);
            pathBestElem = m_pathPopus[maxId].codeInfo;
        }else if(m_proId == 3){
            m_CurBestResults.push_back(maxFit);
        }else{
            m_CurBestResults.push_back(1/maxFit);
            tspBestElem = m_tspPopus[maxId].codeInfo;
        }
    }else{
        double CurBestFit = m_CurBestResults[m_CurBestResults.size()-1];
        if(m_proId == 2 || m_proId == 4){
            CurBestFit = 1/CurBestFit;
        }
        if(m_proId == 2) pathBestElem = (CurBestFit > maxFit) ? pathBestElem : m_pathPopus[maxId].codeInfo;
        if(m_proId == 4) tspBestElem = (CurBestFit > maxFit) ? tspBestElem : m_tspPopus[maxId].codeInfo;

        if(m_proId == 1 || m_proId == 3) m_CurBestResults.push_back(qMax(CurBestFit,maxFit));
        else m_CurBestResults.push_back(1/qMax(CurBestFit,maxFit));
    }
}

void Algo_GA::swapFuncElems(GAFunc_Elem &e1, GAFunc_Elem &e2, int index, int length)
{
    QString str1_l = e1.codeInfo.left(index);
    QString str1_r = e1.codeInfo.right(length-index);
    QString str2_l = e2.codeInfo.left(index);
    QString str2_r = e2.codeInfo.right(length-index);
    e1.codeInfo = str1_l + str2_r;
    e2.codeInfo = str2_l + str1_r;
}

void Algo_GA::swapPathElem(GAPath_Elem &e1, GAPath_Elem &e2)
{
    QSet<int> set(e1.codeInfo.begin(),e1.codeInfo.end());
    QVector<int> repeatNums;
    for(int i = 0;i < e2.codeInfo.size();++ i){
        if(set.contains(e2.codeInfo[i])){
            repeatNums.push_back(e2.codeInfo[i]);
        }
    }
    if(repeatNums.size() <= 2){
        return;
    }else{
        int random = QRandomGenerator::global()->bounded(1,repeatNums.size()-1);
        int target = repeatNums[random];
        int index1 = std::lower_bound(e1.codeInfo.begin(),e1.codeInfo.end(),target)-e1.codeInfo.begin();
        int index2 = std::lower_bound(e2.codeInfo.begin(),e2.codeInfo.end(),target)-e2.codeInfo.begin();
        QVector<int> e1_temp = e1.codeInfo;
        QVector<int> e2_temp = e2.codeInfo;
        e1.codeInfo.clear();
        e2.codeInfo.clear();
        for(int i = 0;i < index1;++ i){
            e1.codeInfo.push_back(e1_temp[i]);
        }
        for(int i = index2;i < e2_temp.size();++ i){
            e1.codeInfo.push_back(e2_temp[i]);
        }
        for(int i = 0;i < index2;++ i){
            e2.codeInfo.push_back(e2_temp[i]);
        }
        for(int i = index1;i < e1_temp.size();++ i){
            e2.codeInfo.push_back(e1_temp[i]);
        }
    }
}

void Algo_GA::swapBpElem(GABP_Elem &e1, GABP_Elem &e2, int index, int length)
{
    QString str1_l = e1.codeInfo.left(index);
    QString str1_r = e1.codeInfo.right(length-index);
    QString str2_l = e2.codeInfo.left(index);
    QString str2_r = e2.codeInfo.right(length-index);
    e1.codeInfo = str1_l + str2_r;
    e2.codeInfo = str2_l + str1_r;
}

void Algo_GA::testBpElem(GABP_Elem &e)
{
    double sum = 0.0;
    for(int i = 0;i < e.codeInfo.size();++ i){
        if(e.codeInfo[i] == '1') sum += bpData[i+1].second;
    }
    if(sum <= bpData[0].second){
        return;
    }
    QVector<QPair<int,double>> vs;
    for(int i = 0;i < e.codeInfo.size();++ i){
        if(e.codeInfo[i] == '1') vs.push_back(QPair<int,double>(i+1,bpData[i+1].first/bpData[i+1].second));
    }
    std::sort(vs.begin(),vs.end(),[](const QPair<int, double> &a, const QPair<int, double> &b) {
        return a.second < b.second;
    });
    for(int i = 0;i < vs.size();++ i){
        sum -= bpData[vs[i].first].second;
        e.codeInfo[vs[i].first-1] = '0';
        if(sum <= bpData[0].second){
            break;
        }
    }
}

void Algo_GA::swapTSPElem(GATSP_Elem &e1, GATSP_Elem &e2)
{
    int length = e1.codeInfo.size();
    int index1 = QRandomGenerator::global()->bounded(0,length);
    int index2 = QRandomGenerator::global()->bounded(0,length);
    int minIndex = qMin(index1,index2);
    int maxIndex = qMax(index1,index2);
    QVector<int> v1 = e1.codeInfo.mid(minIndex,maxIndex-minIndex+1);
    QVector<int> v2 = e2.codeInfo.mid(minIndex,maxIndex-minIndex+1);
    for(int i = 0;i < e1.codeInfo.size();++ i){
        if(!v2.contains(e1.codeInfo[i])){
            v2.push_back(e1.codeInfo[i]);
        }
        if(!v1.contains(e2.codeInfo[i])){
            v1.push_back(e2.codeInfo[i]);
        }
    }
    e1.codeInfo = v2;
    e2.codeInfo = v1;
}


void Algo_GA::GA_Running()
{
    init_Popu();    // 初始化种群
    for(int i = 0;i < m_iterNums;++ i){
        iterOnce();
        updateRes();
    }
}

QVector<int> Algo_GA::getPathBestElem() const
{
    return pathBestElem;
}

QVector<int> Algo_GA::getTspBestElem() const
{
    return tspBestElem;
}

QVector<QPair<double, double> > Algo_GA::getPoints()
{
    QVector<QPair<double,double>> ret;
    for(int i = 0;i < m_funcPopus.size();++ i){
        double x = 0.0;
        double y = 0.0;
        if(m_id == 0){
            x = getFuncStrToDouble(0,6,m_funcPopus[i].length,m_funcPopus[i].codeInfo);
            y = x * x;
            ret.push_back(QPair<double,double>(x,y));
        }else if(m_id == 1){
            x = getFuncStrToDouble(0,1,m_funcPopus[i].length,m_funcPopus[i].codeInfo);
            y = x * qCos(4 * x) + x * qSin(20 * x) + 2;
            ret.push_back(QPair<double,double>(x,y));
        }else if(m_id == 2){
            for(int i = 0;i < m_funcPopus[i].codeInfo.size()/m_funcPopus[i].length;++ i){
                double d = getFuncStrToDouble(0,4,m_funcPopus[i].length,m_funcPopus[i].codeInfo.mid(i*m_funcPopus[i].length,m_funcPopus[i].length));
                y = x + d * d;
                ret.push_back(QPair<double,double>(x,y));
            }
        }
    }
    return ret;
}

QVector<double> Algo_GA::AverBestResults() const
{
    return m_AverBestResults;
}

QVector<double> Algo_GA::CurBestResults() const
{
    return m_CurBestResults;
}
