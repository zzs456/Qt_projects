#include "problemandalgorithm.h"
#include "ui_problemandalgorithm.h"

#include <QStringList>

ProblemAndAlgorithm::ProblemAndAlgorithm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProblemAndAlgorithm)
{
    ui->setupUi(this);

    proAlgoParentWidget = new ProAlgoParentWidget;
    ui->proalgo_stackedWidget->addWidget(proAlgoParentWidget);
    init_MessageType();
    init_ProAlgoInfoWidget();

    funcMainWidget = new FuncMainWidget;
    connect(funcMainWidget,&FuncMainWidget::stop_QTreeW,this,&ProblemAndAlgorithm::hideLeftTree);
    connect(funcMainWidget,&FuncMainWidget::start_QTreeW,this,&ProblemAndAlgorithm::showLeftTree);

    pathMainWidget = new PathMainWidget;
    connect(pathMainWidget,&PathMainWidget::stop_QTreeW,this,&ProblemAndAlgorithm::hideLeftTree);
    connect(pathMainWidget,&PathMainWidget::start_QTreeW,this,&ProblemAndAlgorithm::showLeftTree);

    bpMainWidget = new BpMainWidget;
    connect(bpMainWidget,&BpMainWidget::stop_QTreeW,this,&ProblemAndAlgorithm::hideLeftTree);
    connect(bpMainWidget,&BpMainWidget::start_QTreeW,this,&ProblemAndAlgorithm::showLeftTree);

    tspMainWidget = new TSPMainWidget;
    connect(tspMainWidget,&TSPMainWidget::stop_QTreeW,this,&ProblemAndAlgorithm::hideLeftTree);
    connect(tspMainWidget,&TSPMainWidget::start_QTreeW,this,&ProblemAndAlgorithm::showLeftTree);

    compMainWidget = new Algo_CompShow;
    connect(compMainWidget,&Algo_CompShow::stop_QTreeW,this,&ProblemAndAlgorithm::hideLeftTree);
    connect(compMainWidget,&Algo_CompShow::start_QTreeW,this,&ProblemAndAlgorithm::showLeftTree);

    ui->proalgo_stackedWidget->addWidget(funcMainWidget);
    ui->proalgo_stackedWidget->addWidget(pathMainWidget);
    ui->proalgo_stackedWidget->addWidget(bpMainWidget);
    ui->proalgo_stackedWidget->addWidget(tspMainWidget);

    ui->proalgo_stackedWidget->addWidget(compMainWidget);


    QTreeWidgetItem *temp = ui->algo_treeWidget->topLevelItem(0);
    ui->algo_treeWidget->setCurrentItem(temp);
    changeToParentWidget(temp->text(0));
}

ProblemAndAlgorithm::~ProblemAndAlgorithm()
{
    delete ui;
}

void ProblemAndAlgorithm::on_algo_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(!item->parent()){
        changeToParentWidget(item->text(column));
    }else{
        if(item->text(column) == "简介"){
            QString algoName = item->parent()->text(column);
            changeToInfoWidget(algoName);
        }else if(item->text(column) == "函数优化问题"){
            if(item->parent()->text(column) == "算法比较"){
                compMainWidget->changeStackedWidget(1);
                ui->proalgo_stackedWidget->setCurrentWidget(compMainWidget);
                return;
            }
            ui->proalgo_stackedWidget->setCurrentWidget(funcMainWidget);
            if(item->parent()->text(column) == "遗传算法"){
                funcMainWidget->setAlgoType(1);
            }else if(item->parent()->text(column) == "粒子群优化算法"){
                funcMainWidget->setAlgoType(2);
            }else if(item->parent()->text(column) == "蚁群算法"){
                funcMainWidget->setAlgoType(3);
            }
        }else if(item->text(column) == "路径规划问题"){
            ui->proalgo_stackedWidget->setCurrentWidget(pathMainWidget);
            if(item->parent()->text(column) == "遗传算法"){
                pathMainWidget->setAlgoType(1);
            }else if(item->parent()->text(column) == "蚁群算法"){
                pathMainWidget->setAlgoType(3);
            }
        }else if(item->text(column) == "背包问题"){
            ui->proalgo_stackedWidget->setCurrentWidget(bpMainWidget);
            if(item->parent()->text(column) == "遗传算法"){
                bpMainWidget->setAlgoType(1);
            }else if(item->parent()->text(column) == "粒子群优化算法"){
                bpMainWidget->setAlgoType(2);
            }else if(item->parent()->text(column) == "蚁群算法"){
                bpMainWidget->setAlgoType(3);
            }
        }else{
            if(item->parent()->text(column) == "算法比较"){
                compMainWidget->changeStackedWidget(2);
                ui->proalgo_stackedWidget->setCurrentWidget(compMainWidget);
                return;
            }
            ui->proalgo_stackedWidget->setCurrentWidget(tspMainWidget);
            if(item->parent()->text(column) == "遗传算法"){
                tspMainWidget->setAlgoType(1);
            }else if(item->parent()->text(column) == "粒子群优化算法"){
                tspMainWidget->setAlgoType(2);
            }else if(item->parent()->text(column) == "蚁群算法"){
                tspMainWidget->setAlgoType(3);
            }
        }
    }
    // qDebug() << "单击信号: " << item << "column: " << column;
}


void ProblemAndAlgorithm::on_proalgo_returnMainWidgetBtn_clicked()
{
    emit returnToMainWidget();
}

void ProblemAndAlgorithm::hideLeftTree()
{
    ui->proalgo_leftWidget->hide();
}

void ProblemAndAlgorithm::showLeftTree()
{
    ui->proalgo_leftWidget->show();
}

void ProblemAndAlgorithm::init_MessageType()
{
    listQStringAlgoType.insert("遗传算法",ALGORITHM_TYPE_GA);
    listQStringAlgoType.insert("粒子群优化算法",ALGORITHM_TYPE_PSO);
    listQStringAlgoType.insert("蚁群算法",ALGORITHM_TYPE_ACO);
    // listQStringAlgoType.insert("免疫算法",ALGORITHM_TYPE_IA);
    // listQStringAlgoType.insert("模糊C均值聚类算法",ALGORITHM_TYPE_FCM);
    // listQStringAlgoType.insert("神经网络算法",ALGORITHM_TYPE_NN);
}

void ProblemAndAlgorithm::init_ProAlgoInfoWidget()
{
    ProAlgoIntroduceWidget *GAIntroWidget = new ProAlgoIntroduceWidget;
    GAIntroWidget->setQLabelText(ALGORITHM_TYPE_GA);
    ui->proalgo_stackedWidget->addWidget(GAIntroWidget);
    listProAlgoIntroWidgets.insert(ALGORITHM_TYPE_GA,GAIntroWidget);

    ProAlgoIntroduceWidget *PSOIntroWidget = new ProAlgoIntroduceWidget;
    PSOIntroWidget->setQLabelText(ALGORITHM_TYPE_PSO);
    ui->proalgo_stackedWidget->addWidget(PSOIntroWidget);
    listProAlgoIntroWidgets.insert(ALGORITHM_TYPE_PSO,PSOIntroWidget);

    ProAlgoIntroduceWidget *ACOIntroWidget = new ProAlgoIntroduceWidget;
    ACOIntroWidget->setQLabelText(ALGORITHM_TYPE_ACO);
    ui->proalgo_stackedWidget->addWidget(ACOIntroWidget);
    listProAlgoIntroWidgets.insert(ALGORITHM_TYPE_ACO,ACOIntroWidget);

    // ProAlgoIntroduceWidget *IAIntroWidget = new ProAlgoIntroduceWidget;
    // IAIntroWidget->setQLabelText(ALGORITHM_TYPE_IA);
    // ui->proalgo_stackedWidget->addWidget(IAIntroWidget);
    // listProAlgoIntroWidgets.insert(ALGORITHM_TYPE_IA,IAIntroWidget);

    // ProAlgoIntroduceWidget *FCMIntroWidget = new ProAlgoIntroduceWidget;
    // FCMIntroWidget->setQLabelText(ALGORITHM_TYPE_FCM);
    // ui->proalgo_stackedWidget->addWidget(FCMIntroWidget);
    // listProAlgoIntroWidgets.insert(ALGORITHM_TYPE_FCM,FCMIntroWidget);

    // ProAlgoIntroduceWidget *NNIntroWidget = new ProAlgoIntroduceWidget;
    // NNIntroWidget->setQLabelText(ALGORITHM_TYPE_NN);
    // ui->proalgo_stackedWidget->addWidget(NNIntroWidget);
    // listProAlgoIntroWidgets.insert(ALGORITHM_TYPE_NN,NNIntroWidget);
}

void ProblemAndAlgorithm::changeToParentWidget(QString algoName)
{
    if(algoName != "算法比较"){
        proAlgoParentWidget->setQLabelText(listQStringAlgoType[algoName]);
        ui->proalgo_stackedWidget->setCurrentWidget(proAlgoParentWidget);
    }else{
        compMainWidget->changeStackedWidget(0);
        ui->proalgo_stackedWidget->setCurrentWidget(compMainWidget);
    }
}

void ProblemAndAlgorithm::changeToInfoWidget(QString algoName)
{
    ui->proalgo_stackedWidget->setCurrentWidget(listProAlgoIntroWidgets[listQStringAlgoType[algoName]]);
}
