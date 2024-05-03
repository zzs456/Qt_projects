#ifndef PATHMAINWIDGET_H
#define PATHMAINWIDGET_H

#include "../Algo_GA/gademoshowwidget.h"
#include "../Algo_ACO/acodemoshowwidget.h"
#include "pathprowidget.h"

#include <QWidget>

namespace Ui {
class PathMainWidget;
}

class PathMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PathMainWidget(QWidget *parent = nullptr);
    ~PathMainWidget();
    void setAlgoType(int type) { algoType = type; }

signals:
    void stop_QTreeW();
    void start_QTreeW();

private slots:
    void do_DemoSignal(const QVector<QVector<int>> &);
    void do_PathMainWidget();

private:
    Ui::PathMainWidget *ui;
    PathProWidget *pathProW;
    GADemoShowWidget *pathGAW;
    ACODemoShowWidget *pathACOW;
    int algoType;
};

#endif // PATHMAINWIDGET_H
