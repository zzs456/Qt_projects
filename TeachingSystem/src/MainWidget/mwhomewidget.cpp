#include "mwhomewidget.h"
#include "ui_mwhomewidget.h"

MWHomeWidget::MWHomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MWHomeWidget)
{
    ui->setupUi(this);

    connect(ui->mwHome_proWidget,&MWHomeProWidget::mwHomePro_changeMainWidget,this,&MWHomeWidget::do_mwHomePro_changeMainWidgetSignal);
}

MWHomeWidget::~MWHomeWidget()
{
    delete ui;
}

void MWHomeWidget::do_mwHomePro_changeMainWidgetSignal()
{
    emit mwHome_changeMainWidget();
}
