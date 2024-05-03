#include "algo_aco.h"

#include <QRandomGenerator>
#include <algorithm>
#include <QDebug>

Algo_ACO::Algo_ACO(QObject *parent)
    : QObject{parent}
{}

void Algo_ACO::initACO()
{
    if(m_proId == 1){
        m_funcPopus.clear();
        m_func_bestValue = 0.0;
    }else if(m_proId == 2){
        m_pathPopus.clear();
        pathBestElem.clear();
    }else if(m_proId == 3){
        m_bpPopus.clear();
        m_bp_bestValue = 0.0;
    }else{
        m_tspPopus.clear();
        m_tsp_bestX.clear();
    }
    m_CurBestResults.clear();
    m_AverBestResults.clear();
}

void Algo_ACO::ACO_Running()
{
    init_popu();
    for(int i = 0;i < iterNums;++ i){
        iterOnce(i);
        updateRes();
    }
}

void Algo_ACO::init_popu()
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
        initTspPopu();
    }
}

void Algo_ACO::initFuncPopu(double min, double max)
{
    phes.resize(popuNums);
    for(int i = 0;i < phes.size();++ i){
        phes[i].resize(popuNums);
    }
    int dims = 0;
    if(m_id == 0 || m_id == 1){
        dims = 1;
    }else if(m_id == 2){
        dims = m_funcsphereN;
    }
    for(int i = 0;i < popuNums;++ i){
        ACOFunc_Elem elem;
        elem.phe = 1;
        elem.next = -1;
        elem.bounds = QPair<int,int>(min,max);
        for(int j = 0;j < dims;++ j){
            double temp = QRandomGenerator::global()->generateDouble() * (max - min) + min;
            elem.xs.push_back(temp);
        }
        elem.funcValue = getFuncValue(elem.xs);
        m_funcPopus.push_back(elem);
    }
}

void Algo_ACO::initPathPopu()
{
    int rows = pathData.size();
    int cols = pathData[0].size();
    int gridNums = rows * cols;
    double distances = qSqrt((rows-1)*(rows-1) + (cols-1)*(cols-1));
    double initQ = q / distances;
    phes.resize(gridNums);
    for(int i = 0;i < phes.size();++ i){
        phes[i].resize(gridNums);
    }
    for(int i = 0;i < gridNums;++ i){
        for(int j = 0;j < gridNums;++ j){
            if(i >= j){
                phes[i][j] = 0;
            }else{
                int row1 = i / cols;
                int col1 = i % cols;
                int row2 = j / cols;
                int col2 = j % cols;
                if(pathData[row1][col1] == 0 && pathData[row2][col2] == 0){
                    if((row1 == row2 && col1 + 1 == col2) || (row1 + 1 == row2 && col1 == col2) ||
                        (row1 + 1 == row2 && col1 + 1 == col2)){
                        phes[i][j] = initQ;
                    }else{
                        phes[i][j] = 0;
                    }
                }else{
                    phes[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0;i < popuNums;++ i){
        ACOPath_Elem elem;
        elem.walked.push_back(0);
        m_pathPopus.push_back(elem);
    }
}

void Algo_ACO::initBpPopu()
{
    phes.resize(bpData.size());
    for(int i = 0;i < bpData.size();++ i){
        phes[i].resize(bpData.size());
    }
    double sumValue = 0.0;
    // for(int i = 0;i < bpData.size();++ i){
    //     m_bp_bestX.push_back(0);
    // }
    sumValue += bpData[1].first;
    m_bp_bestValue = sumValue;

    int sum_Value = 0.0;
    for(int i = 1;i < bpData.size();++ i){
        sum_Value += bpData[i].first;
    }
    for(int i = 0;i < bpData.size();++ i){
        for(int j = 0;j < bpData.size();++ j){
            if(j == 0) phes[i][j] = 0;
            if(i != j) phes[i][j] = q * sumValue / sum_Value;
            else phes[i][j] = 0;
        }
    }
    for(int i = 0;i < popuNums;++ i){
        ACOBP_Elem elem;
        m_bpPopus.push_back(elem);
    }
}

void Algo_ACO::initTspPopu()
{
    distances.resize(tspData.size());
    phes.resize(tspData.size());
    //phes_changes.resize(tspData.size());
    for(int i = 0;i < tspData.size();++ i){
        distances[i].resize(tspData.size());
        phes[i].resize(tspData.size());
        //phes_changes[i].resize(tspData.size());
    }
    for(int i = 0;i < tspData.size();++ i){
        for(int j = 0;j < tspData.size();++ j){
            double disX = tspData[i].first - tspData[j].first;
            double disY = tspData[i].second - tspData[j].second;
            double dis_power = disX * disX + disY * disY;
            distances[i][j] = qSqrt(dis_power);
        }
    }
    double sumLength = 0.0;
    for(int i = 0;i < distances.size();++ i){
        int start = i;
        int end = (i + 1) % distances.size();
        sumLength += distances[start][end];
        m_tsp_bestX.push_back(i);
    }
    for(int i = 0;i < tspData.size();++ i){
        for(int j = 0;j < tspData.size();++ j){
            if(i != j) phes[i][j] = q / sumLength;
            else phes[i][j] = 0;
            // phes_changes[i][j] = 0;
        }
    }
    for(int i = 0;i < popuNums;++ i){
        ACOTsp_Elem elem;
        m_tspPopus.push_back(elem);
    }
}

double Algo_ACO::getFuncValue(const QVector<double> &vs)
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

double Algo_ACO::getPathLength(const QVector<int> &elem)
{
    double dis = 0.0;
    QVector<QVector<int>> temp = pathData;
    int cols = temp[0].size();
    for(int i = 0;i < elem.size() - 1;++ i){
        int x1 = elem[i] / cols;
        int y1 = elem[i] % cols;
        int x2 = elem[i+1] / cols;
        int y2 = elem[i+1] % cols;
        double disX = x2 - x1;
        double disY = y2 - y1;
        dis += qSqrt(disX * disX + disY * disY);
    }
    return dis;
}

void Algo_ACO::init_popuPos()
{
    if(m_proId == 1){
        return;
    }else if(m_proId == 2){
        for(int i = 0;i < popuNums;++ i){
            m_pathPopus[i].walked.clear();
            m_pathPopus[i].walked.push_back(0);
            m_pathPopus[i].pathLength = 0.0;
        }
    }else if(m_proId == 3){
        initBp_popuPos();
    }else if(m_proId == 4){
        initTsp_popuPos();
    }
}

void Algo_ACO::initBp_popuPos()
{
    for(int i = 0;i < popuNums;++ i){
        m_bpPopus[i].walked.clear();
        m_bpPopus[i].remains.clear();
        m_bpPopus[i].valueSum = 0.0;
    }
    for(int i = 0;i < popuNums;++ i){
        int startIndex = 0;
        m_bpPopus[i].start = startIndex;
        m_bpPopus[i].walked.push_back(startIndex);
        for(int j = 1;j < bpData.size();++ j){
            m_bpPopus[i].remains.insert(j);
        }
        m_bpPopus[i].valueSum = 0.0;
        m_bpPopus[i].weightSum = 0.0;
    }
}

void Algo_ACO::initTsp_popuPos()
{
    for(int i = 0;i < popuNums;++ i){
        m_tspPopus[i].walked.clear();
        m_tspPopus[i].remains.clear();
    }
    for(int i = 0;i < popuNums;++ i){
        int startIndex = QRandomGenerator::global()->bounded(0,tspData.size());
        m_tspPopus[i].start = startIndex;
        m_tspPopus[i].walked.push_back(startIndex);
        for(int j = 0;j < tspData.size();++ j){
            if(j != startIndex)
                m_tspPopus[i].remains.insert(j);
        }
        m_tspPopus[i].pathLength = 0.0;
    }
}

void Algo_ACO::update_popuList()
{
    if(m_proId == 1){
        updateFunc_popuList();
    }else if(m_proId == 2){
        updatePath_popuList();
    }else if(m_proId == 3){
        updateBp_popuList();
    }else{
        updateTsp_popuList();
    }
}

void Algo_ACO::updateFunc_popuList()
{
    for(int i = 0;i < phes.size();++ i){
        for(int j = 0;j < phes[0].size();++ j){
            phes[i][j] = 0;
        }
    }
    for(int i = 0;i < popuNums;++ i){
        int nums = 0;
        for(int j = 0;j < popuNums;++ j){
            if(m_funcPopus[i].funcValue < m_funcPopus[j].funcValue){
                phes[i][j] = m_funcPopus[j].funcValue - m_funcPopus[i].funcValue;
            }else{
                phes[i][j] = 0;
                ++ nums;
            }
        }
        int next = -1;
        if(nums == popuNums){
            next = i;
        }else{
            double sum = 0.0;
            QVector<int> ids;
            QVector<double> probSum;
            for(int j = 0;j < popuNums;++ j){
                if(phes[i][j] > 0){
                    ids.push_back(j);
                    sum += qPow(m_funcPopus[j].phe,alpha) * qPow(phes[i][j],beta);
                    probSum.push_back(sum);
                }
            }
            for(int j = 0;j < probSum.size();++ j){
                probSum[j] /= sum;
            }
            double randomD = QRandomGenerator::global()->generateDouble();
            int index = std::upper_bound(probSum.begin(),probSum.end(),randomD) - probSum.begin();
            next = ids[index];
        }
        m_funcPopus[i].next = next;
    }
}

void Algo_ACO::updatePath_popuList()
{
    for(int i = 0;i < popuNums;){
        int rows = pathData.size();
        int cols = pathData[0].size();
        int target = rows * cols - 1;
        QSet<int> sets;
        sets.insert(0);
        while(true){
            int start = m_pathPopus[i].walked[m_pathPopus[i].walked.size()-1];
            if(start == target){
                ++ i;
                break;
            }
            double sum = 0.0;
            QVector<int> ends;
            QVector<double> probSums;
            int row_start = start / cols;
            int col_start = start % cols;
            if(row_start < rows - 1 && phes[start][start+cols] != 0){
                if(!sets.contains(start+cols)){
                    ends.push_back(start+cols);
                    double disX = (double)rows - row_start - 2;
                    double disY = (double)cols - col_start - 1;
                    double distan = qSqrt(disX * disX + disY * disY + 0.5);
                    sum = sum + qPow(phes[start][start+cols],alpha) * qPow(1 / distan,beta);
                    probSums.push_back(sum);
                }
            }
            if(col_start < cols - 1 && phes[start][start+1] != 0){
                if(!sets.contains(start+1)){
                    ends.push_back(start+1);
                    double disX = (double)rows - row_start - 1;
                    double disY = (double)cols - col_start - 2;
                    double distan = qSqrt(disX * disX + disY * disY + 0.5);
                    sum += qPow(phes[start][start+1],alpha) * qPow(1 / distan,beta);
                    probSums.push_back(sum);
                }
            }
            if(row_start < rows - 1 && col_start < cols - 1 && phes[start][start+cols+1] != 0){
                if(!sets.contains(start+cols+1)){
                    ends.push_back(start+cols+1);
                    double disX = (double)rows - row_start - 2;
                    double disY = (double)cols - col_start - 2;
                    double distan = qSqrt(disX * disX + disY * disY + 0.5);
                    sum += qPow(phes[start][start+cols+1],alpha) * qPow(1 / distan,beta);
                    probSums.push_back(sum);
                }
            }
            if(probSums.isEmpty()){
                sets.insert(start);
                m_pathPopus[i].walked.pop_back();
                m_pathPopus[i].pathLength = getPathLength(m_pathPopus[i].walked);
            }else{
                for(int j = 0;j < probSums.size();++ j){
                    probSums[j] /= sum;
                }
                double randomD = QRandomGenerator::global()->generateDouble();
                int index = std::upper_bound(probSums.begin(),probSums.end(),randomD) - probSums.begin();
                int end = ends[index];
                m_pathPopus[i].walked.push_back(end);
                int row_start = start / cols;
                int col_start = start % cols;
                int row_end = end / cols;
                int col_end = end % cols;
                m_pathPopus[i].pathLength += qSqrt((row_end-row_start)*(row_end-row_start)+(col_end-col_start)*(col_end-col_start));
            }
        }

    }
}

void Algo_ACO::updateBp_popuList()
{
    for(int i = 0;i < popuNums;++ i){
        while(true){
            int start = m_bpPopus[i].walked[m_bpPopus[i].walked.size()-1];
            double sum = 0.0;
            QVector<int> ends;
            QVector<double> probSums;
            QVector<int> removes;
            for(int value : m_bpPopus[i].remains){
                if(m_bpPopus[i].weightSum + bpData[value].second > bpData[0].second){
                    removes.push_back(value);
                }
            }
            for(int value : removes){
                m_bpPopus[i].remains.remove(value);
            }
            if(m_bpPopus[i].remains.isEmpty()){
                break;
            }
            for(int value : m_bpPopus[i].remains){
                ends.push_back(value);
                double prob = qPow(phes[start][value],alpha) * qPow(static_cast<double>(bpData[value].first)/bpData[value].second,beta);
                sum += prob;
                probSums.push_back(sum);
            }
            for(int j = 0;j < probSums.size();++ j){
                probSums[j] /= sum;
            }
            double randomD = QRandomGenerator::global()->generateDouble();
            int index = std::upper_bound(probSums.begin(),probSums.end(),randomD) - probSums.begin();
            int end = ends[index];
            m_bpPopus[i].walked.push_back(end);
            m_bpPopus[i].remains.remove(end);
            m_bpPopus[i].valueSum += bpData[end].first;
            m_bpPopus[i].weightSum += bpData[end].second;
            if(m_bpPopus[i].remains.isEmpty()){
                break;
            }
        }
    }
}

void Algo_ACO::updateTsp_popuList()
{
    for(int k = 0;k < tspData.size();++ k){
        for(int i = 0;i < popuNums;++ i){
            if(k == tspData.size() - 1){
                int start = m_tspPopus[i].walked[m_tspPopus[i].walked.size()-1];
                int end = m_tspPopus[i].start;
                m_tspPopus[i].pathLength += distances[start][end];
            }else{
                int start = m_tspPopus[i].walked[m_tspPopus[i].walked.size()-1];
                double sum = 0.0;
                QVector<int> ends;
                QVector<double> probSums;
                for (int value : m_tspPopus[i].remains) {
                    ends.push_back(value);
                    double prob = qPow(phes[start][value],alpha) * qPow(1 / distances[start][value],beta);
                    sum += prob;
                    probSums.push_back(sum);
                }
                for(int j = 0;j < probSums.size();++ j){
                    probSums[j] /= sum;
                }
                double randomD = QRandomGenerator::global()->generateDouble();
                int index = std::upper_bound(probSums.begin(),probSums.end(),randomD) - probSums.begin();
                int end = ends[index];
                m_tspPopus[i].walked.push_back(end);
                m_tspPopus[i].remains.remove(end);
                m_tspPopus[i].pathLength += distances[start][end];
            }
        }
    }
}

void Algo_ACO::update_phes(int iter)
{
    if(m_proId == 1){
        updateFunc_phes(iter);
    }else if(m_proId == 2){
        updatePath_phes();
    }else if(m_proId == 3){
        updateBp_phes();
    }else{
        updateTsp_phes();
    }
}

void Algo_ACO::updateFunc_phes(int iter)
{
    QVector<ACOFunc_Elem> temp = m_funcPopus;
    for(int i = 0;i < popuNums;++ i){
        double min = temp[0].bounds.first;
        double max = temp[0].bounds.second;
        m_funcPopus[i].next = -1;
        double phes_incre = temp[temp[i].next].funcValue - temp[i].funcValue;
        m_funcPopus[i].phe = (1 - rho) * temp[i].phe + phes_incre;
        for(int j = 0;j < temp[0].xs.size();++ j){
            double random_num = QRandomGenerator::global()->generateDouble() - 0.5;
            m_funcPopus[i].xs[j] = temp[temp[i].next].xs[j] + random_num * qPow(q,iter);
            if(m_funcPopus[i].xs[j] < min){
                m_funcPopus[i].xs[j] = min;
            }else if(m_funcPopus[i].xs[j] > max){
                m_funcPopus[i].xs[j] = max;
            }
        }
        m_funcPopus[i].funcValue = getFuncValue(m_funcPopus[i].xs);
    }
}

void Algo_ACO::updatePath_phes()
{
    for(int i = 0;i < popuNums;++ i){
        double incre = q / m_pathPopus[i].pathLength;
        for(int j = 0;j < m_pathPopus[i].walked.size()-1;++ j){
            int start = m_pathPopus[i].walked[j];
            int end = m_pathPopus[i].walked[j+1];
            phes[start][end] = (1 - rho) * phes[start][end] + incre;
        }
    }
}

void Algo_ACO::updateBp_phes()
{
    for(int i = 0;i < phes.size();++ i){
        for(int j = 0;j < phes[0].size();++ j){
            if(i != j) phes[i][j] = (1 - rho) * phes[i][j];
        }
    }
    int sumValue = 0.0;
    for(int i = 1;i < bpData.size();++ i){
        sumValue += bpData[i].first;
    }
    for(int i = 0;i < popuNums;++ i){
        double incre = q * m_bpPopus[i].valueSum / sumValue;
        int nums = m_bpPopus[i].walked.size();
        for(int j = 0;j < nums - 1;++ j){
            phes[m_bpPopus[i].walked[j]][m_bpPopus[i].walked[j+1]] += incre;
        }
    }
}

void Algo_ACO::updateTsp_phes()
{
    for(int i = 0;i < phes.size();++ i){
        for(int j = 0;j < phes[0].size();++ j){
            if(i != j) phes[i][j] = (1 - rho) * phes[i][j];
        }
    }
    for(int i = 0;i < popuNums;++ i){
        double incre = q / m_tspPopus[i].pathLength;
        int nums = tspData.size();
        for(int j = 0;j < nums;++ j){
            int startIndex = j;
            int endIndex = (j + 1) % nums;
            phes[m_tspPopus[i].walked[startIndex]][m_tspPopus[i].walked[endIndex]] += incre;
        }
    }
}

void Algo_ACO::iterOnce(int iter)
{
    init_popuPos();
    update_popuList();
    update_phes(iter);
}

void Algo_ACO::updateRes()
{
    double maxFit = 0.0;
    double averFit = 0.0;
    if(m_proId == 1){
        maxFit = m_funcPopus[0].funcValue;
        for(int i = 0;i < popuNums;++ i){
            averFit += m_funcPopus[i].funcValue;
            if(m_funcPopus[i].funcValue > maxFit){
                maxFit = m_funcPopus[i].funcValue;
            }
        }
        if(maxFit > m_func_bestValue){
            m_func_bestValue = maxFit;
        }else{
            maxFit = m_func_bestValue;
        }
    }else if(m_proId == 2){
        maxFit = m_pathPopus[0].pathLength;
        int maxId = 0;
        for(int i = 0;i < popuNums;++ i){
            averFit += m_pathPopus[i].pathLength;
            if(m_pathPopus[i].pathLength < maxFit){
                maxFit = m_pathPopus[i].pathLength;
                maxId = i;
            }
        }
        if(m_CurBestResults.isEmpty()){
            pathBestElem = m_pathPopus[maxId].walked;
        }else{
            double minDis = m_CurBestResults[m_CurBestResults.size()-1];
            if(maxFit < minDis){
                pathBestElem = m_pathPopus[maxId].walked;
            }else{
                maxFit = minDis;
            }
        }
    }else if(m_proId == 3){
        maxFit = m_bpPopus[0].valueSum;
        for(int i = 0;i < popuNums;++ i){
            averFit += m_bpPopus[i].valueSum;
            if(m_bpPopus[i].valueSum > maxFit){
                maxFit = m_bpPopus[i].valueSum;
            }
        }
        if(maxFit > m_bp_bestValue){
            m_bp_bestValue = maxFit;
        }else{
            maxFit = m_bp_bestValue;
        }
    }else{
        double minDis = 0.0;
        maxFit = m_tspPopus[0].pathLength;
        int maxId = 0;
        for(int i = 0;i < m_tsp_bestX.size();++ i){
            int start = i;
            int end = (i + 1) % m_tsp_bestX.size();
            minDis += distances[m_tsp_bestX[start]][m_tsp_bestX[end]];
        }
        for(int i = 0;i < popuNums;++ i){
            averFit += m_tspPopus[i].pathLength;
            if(m_tspPopus[i].pathLength < maxFit){
                maxFit = m_tspPopus[i].pathLength;
                maxId = i;
            }
        }
        if(maxFit < minDis){
            m_tsp_bestX = m_tspPopus[maxId].walked;
        }else{
            maxFit = minDis;
        }
    }
    averFit /= popuNums;
    m_AverBestResults.push_back(averFit);
    m_CurBestResults.push_back(maxFit);
}

QVector<double> Algo_ACO::CurBestResults() const
{
    return m_CurBestResults;
}

QVector<double> Algo_ACO::AverBestResults() const
{
    return m_AverBestResults;
}

QVector<int> Algo_ACO::tsp_bestX() const
{
    return m_tsp_bestX;
}

QVector<int> Algo_ACO::getPathBestElem() const
{
    return pathBestElem;
}

QVector<QPair<double, double> > Algo_ACO::getPoints()
{
    QVector<QPair<double,double>> ret;
    for(int i = 0;i < m_funcPopus.size();++ i){
        double x = m_funcPopus[i].xs[0];
        double y = m_funcPopus[i].funcValue;
        ret.push_back(QPair<double,double>(x,y));
    }
    return ret;
}
