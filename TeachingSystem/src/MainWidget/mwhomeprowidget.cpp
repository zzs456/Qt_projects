#include "mwhomeprowidget.h"
#include "ui_mwhomeprowidget.h"

MWHomeProWidget::MWHomeProWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MWHomeProWidget)
{
    ui->setupUi(this);
    initMWHomeProWidget();
}

MWHomeProWidget::~MWHomeProWidget()
{
    delete ui;
}

void MWHomeProWidget::initMWHomeProWidget()
{
    ui->mwHomePro_GA->setOpenExternalLinks(true);
    ui->mwHomePro_GA->setText("<a style='text-decoration: none;' href='https://baike.baidu.com/item/%E9%81%97%E4%BC%A0%E7%AE%97%E6%B3%95'>遗传算法</a>");
    ui->mwHomePro_PSO->setOpenExternalLinks(true);
    ui->mwHomePro_PSO->setText("<a style='text-decoration: none;' href='https://baike.baidu.com/item/%E7%B2%92%E5%AD%90%E7%BE%A4%E4%BC%98%E5%8C%96'>粒子群优化算法</a>");
    ui->mwHomePro_ACO->setOpenExternalLinks(true);
    ui->mwHomePro_ACO->setText("<a style='text-decoration: none;' href='https://baike.baidu.com/item/%E8%9A%81%E7%BE%A4%E7%AE%97%E6%B3%95'>蚁群算法</a>");
    // ui->mwHomePro_IA->setOpenExternalLinks(true);
    // ui->mwHomePro_IA->setText("<a style='text-decoration: none;' href='https://baike.baidu.com/item/%E5%85%8D%E7%96%AB%E7%AE%97%E6%B3%95'>免疫算法</a>");
    // ui->mwHomePro_FCM->setOpenExternalLinks(true);
    // ui->mwHomePro_FCM->setText("<a style='text-decoration: none;' href='https://baike.baidu.com/item/%E6%A8%A1%E7%B3%8Ac-%E5%9D%87%E5%80%BC%E8%81%9A%E7%B1%BB%E7%AE%97%E6%B3%95'>模糊C均值聚类算法</a>");
    // ui->mwHomePro_NN->setOpenExternalLinks(true);
    // ui->mwHomePro_NN->setText("<a style='text-decoration: none;' href='https://baike.baidu.com/item/%E7%A5%9E%E7%BB%8F%E7%BD%91%E7%BB%9C%E7%AE%97%E6%B3%95'>神经网络算法</a>");
}

void MWHomeProWidget::on_mwHomePro_start_clicked()
{
    emit mwHomePro_changeMainWidget();
}

