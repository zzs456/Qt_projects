#include "mwhelpwidget.h"
#include "ui_mwhelpwidget.h"

MWHelpWidget::MWHelpWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MWHelpWidget)
{
    ui->setupUi(this);
}

MWHelpWidget::~MWHelpWidget()
{
    delete ui;
}
