#ifndef PROALGOINTRODUCEWIDGET_H
#define PROALGOINTRODUCEWIDGET_H

#include "myalgorithmtype.h"
#include <QWidget>

namespace Ui {
class ProAlgoIntroduceWidget;
}

class ProAlgoIntroduceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProAlgoIntroduceWidget(QWidget *parent = nullptr);
    ~ProAlgoIntroduceWidget();

    void setQLabelText(ALGORITHM_TYPE);

private:
    Ui::ProAlgoIntroduceWidget *ui;
};

#endif // PROALGOINTRODUCEWIDGET_H
