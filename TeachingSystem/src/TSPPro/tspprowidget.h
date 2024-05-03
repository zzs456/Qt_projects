#ifndef TSPPROWIDGET_H
#define TSPPROWIDGET_H

#include <QWidget>
#include <QVector>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPair>

namespace Ui {
class TSPProWidget;
}

class TSPProWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TSPProWidget(QWidget *parent = nullptr);
    ~TSPProWidget();
    void setInlayData(int);

    bool geneDefPoints();

    void paintTspPlot();

    QVector<QVector<QPair<int, int>>> getTspDatas() const;

    QVector<QPair<int, int>> tspData() const;

signals:
    void demoSignal(const QVector<QPair<int,int>> &);

private slots:
    void on_tsp_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_startDemo_clicked();

private:
    Ui::TSPProWidget *ui;

    QVector<QVector<QPair<int,int>>> tspDatas;

    QVector<QPair<int,int>> m_tspData;
};

#endif // TSPPROWIDGET_H
