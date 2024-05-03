#ifndef MWHELPWIDGET_H
#define MWHELPWIDGET_H

#include <QWidget>

namespace Ui {
class MWHelpWidget;
}

class MWHelpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWHelpWidget(QWidget *parent = nullptr);
    ~MWHelpWidget();

private:
    Ui::MWHelpWidget *ui;
};

#endif // MWHELPWIDGET_H
