#ifndef BPPROWIDGET_H
#define BPPROWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class BpProWidget;
}

class BpProWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BpProWidget(QWidget *parent = nullptr);
    void setInlayData(int);
    void initBpTableW();

    void geneDefThings();
    ~BpProWidget();

signals:
    void demoSignal(const QVector<QPair<int,int>> &);

private slots:
    void on_bp_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_startDemo_clicked();

private:
    Ui::BpProWidget *ui;

    QVector<QVector<QPair<int,int>>> bpDatas;
    QVector<QPair<int,int>> m_bpData;
};

#endif // BPPROWIDGET_H
