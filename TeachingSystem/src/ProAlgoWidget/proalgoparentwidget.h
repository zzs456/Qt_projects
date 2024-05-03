#ifndef PROALGOPARENTWIDGET_H
#define PROALGOPARENTWIDGET_H

#include "myalgorithmtype.h"
#include <QWidget>

namespace Ui {
class ProAlgoParentWidget;
}

class ProAlgoParentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProAlgoParentWidget(QWidget *parent = nullptr);
    void setQLabelText(ALGORITHM_TYPE);
    ~ProAlgoParentWidget();

private:
    Ui::ProAlgoParentWidget *ui;
};

#endif // PROALGOPARENTWIDGET_H
