#ifndef TSPMAINWIDGET_H
#define TSPMAINWIDGET_H

#include "../Algo_GA/gademoshowwidget.h"
#include "../Algo_PSO/psodemoshowwidget.h"
#include "../Algo_ACO/acodemoshowwidget.h"
#include "tspprowidget.h"

#include <QWidget>

namespace Ui {
class TSPMainWidget;
}

class TSPMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TSPMainWidget(QWidget *parent = nullptr);
    ~TSPMainWidget();

    void setAlgoType(int type) { algoType = type; }

signals:
    void stop_QTreeW();
    void start_QTreeW();

private slots:
    void do_DemoSignal(const QVector<QPair<int,int>> &);
    void do_TSPMainWidget();

private:
    Ui::TSPMainWidget *ui;

    TSPProWidget *tspProW;
    GADemoShowWidget *tspGAW;
    PSODemoShowWidget *tspPSOW;
    ACODemoShowWidget *tspACOW;

    int algoType;
};

#endif // TSPMAINWIDGET_H
