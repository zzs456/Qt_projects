#ifndef PATHPROWIDGET_H
#define PATHPROWIDGET_H

#include <QWidget>
#include <QVector>
#include <QTreeWidget>
#include <QTreeWidgetItem>

namespace Ui {
class PathProWidget;
}

class PathProWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PathProWidget(QWidget *parent = nullptr);
    ~PathProWidget();

    void setInlayData(int);

    void paintPathPlot();

    void geneDefMaps(int,int);

    QVector<QVector<QVector<int>>> getPathDatas() const;

signals:
    void demoSignal(const QVector<QVector<int>> &);

private slots:
    void on_path_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_startDemo_clicked();

private:
    Ui::PathProWidget *ui;
    QVector<QVector<QVector<int>>> pathDatas;
    QVector<QVector<int>> m_pathData;
};

#endif // PATHPROWIDGET_H
