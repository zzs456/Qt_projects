#ifndef PROBLEMANDALGORITHM_H
#define PROBLEMANDALGORITHM_H

#include "myalgorithmtype.h"
#include "proalgoparentwidget.h"
#include "proalgointroducewidget.h"

#include "../FunctionPro/funcmainwidget.h"
#include "../PathPro/pathmainwidget.h"
#include "../BackpackPro/bpmainwidget.h"
#include "../TSPPro/tspmainwidget.h"

#include "../Algo_Comp/algo_compshow.h"

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>
#include <QHash>

namespace Ui {
class ProblemAndAlgorithm;
}

class ProblemAndAlgorithm : public QWidget
{
    Q_OBJECT

public:
    explicit ProblemAndAlgorithm(QWidget *parent = nullptr);
    ~ProblemAndAlgorithm();

signals:
    void returnToMainWidget();

private slots:
    void on_algo_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_proalgo_returnMainWidgetBtn_clicked();

    void hideLeftTree();
    void showLeftTree();

private:
    Ui::ProblemAndAlgorithm *ui;
    ProAlgoParentWidget *proAlgoParentWidget;
    QHash<QString,ALGORITHM_TYPE> listQStringAlgoType;
    QHash<ALGORITHM_TYPE,ProAlgoIntroduceWidget*> listProAlgoIntroWidgets;

    FuncMainWidget *funcMainWidget;
    PathMainWidget *pathMainWidget;
    BpMainWidget *bpMainWidget;
    TSPMainWidget *tspMainWidget;

    Algo_CompShow *compMainWidget;

private:
    void init_MessageType();
    void init_ProAlgoInfoWidget();
    void changeToParentWidget(QString);
    void changeToInfoWidget(QString);
};

#endif // PROBLEMANDALGORITHM_H
