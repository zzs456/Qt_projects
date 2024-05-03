#include "proalgoparentwidget.h"
#include "ui_proalgoparentwidget.h"

ProAlgoParentWidget::ProAlgoParentWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProAlgoParentWidget)
{
    ui->setupUi(this);
}

void ProAlgoParentWidget::setQLabelText(ALGORITHM_TYPE target)
{
    switch (target) {
    case ALGORITHM_TYPE_GA:
        ui->proalgo_parentShowL->setText("点击子项进入遗传算法的学习");
        break;
    case ALGORITHM_TYPE_PSO:
        ui->proalgo_parentShowL->setText("点击子项进入粒子群优化算法的学习");
        break;
    case ALGORITHM_TYPE_ACO:
        ui->proalgo_parentShowL->setText("点击子项进入蚁群算法的学习");
        break;
    // case ALGORITHM_TYPE_IA:
    //     ui->proalgo_parentShowL->setText("点击子项进入免疫算法的学习");
    //     break;
    // case ALGORITHM_TYPE_FCM:
    //     ui->proalgo_parentShowL->setText("点击子项进入模糊C均值聚类算法的学习");
    //     break;
    // case ALGORITHM_TYPE_NN:
    //     ui->proalgo_parentShowL->setText("点击子项进入神经网络算法的学习");
    //     break;
    default:
        break;
    }
}

ProAlgoParentWidget::~ProAlgoParentWidget()
{
    delete ui;
}
