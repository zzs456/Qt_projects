#ifndef WIDGET_H
#define WIDGET_H

#include "./MainWidget/mainwidget.h"
#include "./ProAlgoWidget/problemandalgorithm.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class rootWidget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void MyShow(QString);

private:
    Ui::rootWidget *ui;
    QString m_strUsername;

    MainWidget *mainWidget;
    ProblemAndAlgorithm *proAndAlgo;

private slots:
    void do_mainWidget_changeMainWidget();
    void do_returnMainWidget();

private slots:
    void handleQuit();
};
#endif // WIDGET_H
