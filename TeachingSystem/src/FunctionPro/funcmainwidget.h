#ifndef FUNCMAINWIDGET_H
#define FUNCMAINWIDGET_H

#include "../Algo_GA/gademoshowwidget.h"
#include "../Algo_PSO/psodemoshowwidget.h"
#include "../Algo_ACO/acodemoshowwidget.h"
#include "functionprowidget.h"

#include <QWidget>

namespace Ui {
class FuncMainWidget;
}

class FuncMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FuncMainWidget(QWidget *parent = nullptr);
    ~FuncMainWidget();

    void setAlgoType(int type) { algoType = type; }

signals:
    void stop_QTreeW();
    void start_QTreeW();

private slots:
    void do_GADemoSignal(int,int);
    void do_FuncMainSignal();

private:
    Ui::FuncMainWidget *ui;

    FunctionProWidget *funcProW;
    GADemoShowWidget *funcGAW;
    PSODemoShowWidget *funcPSOW;
    ACODemoShowWidget *funcACOW;

    // FuncGAWidget *funcGAW;
    int algoType;

};

#endif // FUNCMAINWIDGET_H
