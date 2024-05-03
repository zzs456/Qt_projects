#ifndef MWHOMEWIDGET_H
#define MWHOMEWIDGET_H

#include <QWidget>

namespace Ui {
class MWHomeWidget;
}

class MWHomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWHomeWidget(QWidget *parent = nullptr);
    ~MWHomeWidget();

signals:
    void mwHome_changeMainWidget();

private:
    void do_mwHomePro_changeMainWidgetSignal();

private:
    Ui::MWHomeWidget *ui;
};

#endif // MWHOMEWIDGET_H
