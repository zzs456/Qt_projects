#ifndef ALGO_COMPSHOW_H
#define ALGO_COMPSHOW_H

#include "func_comp.h"
#include "tsp_comp.h"

#include <QWidget>
#include <QVector>
#include <QPair>
#include <QFile>

namespace Ui {
class Algo_CompShow;
}

class Algo_CompShow : public QWidget
{
    Q_OBJECT

public:
    explicit Algo_CompShow(QWidget *parent = nullptr);
    ~Algo_CompShow();
    void setTSPDatas(const QVector<QPair<int,int>> &datas) { tspData = datas; }

    void changeStackedWidget(int id);

private:
    void initDatas();
    void paintFunc();
    void paintPoints();

signals:
    void stop_QTreeW();
    void start_QTreeW();

private slots:
    void on_FuncStartDemo_clicked();

    void on_TspStartDemo_clicked();

    void do_returnCompMain(int id);

private:
    Ui::Algo_CompShow *ui;

    Func_Comp *funcComp;
    Tsp_Comp *tspComp;

    QVector<QPair<int,int>> tspData;
};

#endif // ALGO_COMPSHOW_H
