#ifndef FUNCTIONPROWIDGET_H
#define FUNCTIONPROWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class FunctionProWidget;
}

class FunctionProWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionProWidget(QWidget *parent = nullptr);
    ~FunctionProWidget();

    void initFuncProWidget();

    // 绘制图像
    void paintPowerFunc();
    void paintTrigoFunc();

signals:
    void demoSignal(int,int);

private slots:
    void on_functions_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_startDemo_clicked();

private:
    Ui::FunctionProWidget *ui;
};

#endif // FUNCTIONPROWIDGET_H
