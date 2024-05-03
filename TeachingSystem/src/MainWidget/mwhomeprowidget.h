#ifndef MWHOMEPROWIDGET_H
#define MWHOMEPROWIDGET_H

#include <QWidget>

namespace Ui {
class MWHomeProWidget;
}

class MWHomeProWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWHomeProWidget(QWidget *parent = nullptr);
    ~MWHomeProWidget();

signals:
    void mwHomePro_changeMainWidget();

private slots:
    void on_mwHomePro_start_clicked();

private:
    Ui::MWHomeProWidget *ui;

    void initMWHomeProWidget();
};

#endif // MWHOMEPROWIDGET_H
