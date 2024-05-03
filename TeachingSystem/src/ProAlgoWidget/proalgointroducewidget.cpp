#include "proalgointroducewidget.h"
#include "ui_proalgointroducewidget.h"

ProAlgoIntroduceWidget::ProAlgoIntroduceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProAlgoIntroduceWidget)
{
    ui->setupUi(this);
}

ProAlgoIntroduceWidget::~ProAlgoIntroduceWidget()
{
    delete ui;
}

void ProAlgoIntroduceWidget::setQLabelText(ALGORITHM_TYPE type)
{
    switch (type) {
    case ALGORITHM_TYPE_GA:
        ui->proalgo_introShowL->setText("遗传算法介绍");
        break;
    case ALGORITHM_TYPE_PSO:
        ui->proalgo_introShowL->setText("粒子群优化算法介绍");
        break;
    case ALGORITHM_TYPE_ACO:
        ui->proalgo_introShowL->setText("蚁群算法介绍");
        break;
    // case ALGORITHM_TYPE_IA:
    //     ui->proalgo_introShowL->setText("免疫算法介绍");
    //     break;
    // case ALGORITHM_TYPE_FCM:
    //     ui->proalgo_introShowL->setText("模糊C均值聚类算法介绍");
    //     break;
    // case ALGORITHM_TYPE_NN:
    //     ui->proalgo_introShowL->setText("神经网络算法介绍");
    //     break;
    default:
        break;
    }
}
