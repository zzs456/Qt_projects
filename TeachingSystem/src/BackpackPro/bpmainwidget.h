#ifndef BPMAINWIDGET_H
#define BPMAINWIDGET_H

#include "../Algo_GA/gademoshowwidget.h"
#include "../Algo_PSO/psodemoshowwidget.h"
#include "../Algo_ACO/acodemoshowwidget.h"
#include "bpprowidget.h"

#include <QWidget>

namespace Ui {
class BpMainWidget;
}

class BpMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BpMainWidget(QWidget *parent = nullptr);
    ~BpMainWidget();
    void setAlgoType(int type) { algoType = type; }

signals:
    void stop_QTreeW();
    void start_QTreeW();

private slots:
    void do_DemoSignal(const QVector<QPair<int,int>> &);
    void do_BPMainWidget();

private:
    Ui::BpMainWidget *ui;

    BpProWidget *bpProW;
    GADemoShowWidget *bpGAW;
    PSODemoShowWidget *bpPSOW;
    ACODemoShowWidget *bpACOW;
    int algoType;
};

#endif // BPMAINWIDGET_H
