#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "mwhomewidget.h"
#include "../SettingWidget/mwsettingwidget.h"
#include "../SettingWidget/mwhelpwidget.h"
#include "../MyComponents/mymessagebox.h"

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void setUsername(QString);

private:
    Ui::MainWidget *ui;

    QString m_strUsername;

    MWHomeWidget *mwHomeWidget;
    MWSettingWidget *mwSettingWidget;
    MWHelpWidget *mwHelpWidget;

    void setMWListWidget();
    void setMWStackedWidget();

signals:
    void quitSignal();
    void mainWidget_changeMainWidget();

private slots:
    void do_mwListWidgetChange(int);
    void do_mwHome_changeMainWidgetSignal();
};

#endif // MAINWIDGET_H
