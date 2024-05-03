#include "tsp_comp.h"
#include "ui_tsp_comp.h"

Tsp_Comp::Tsp_Comp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tsp_Comp)
{
    ui->setupUi(this);
}

Tsp_Comp::~Tsp_Comp()
{
    delete ui;
}
