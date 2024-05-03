#ifndef MWSETTINGWIDGET_H
#define MWSETTINGWIDGET_H

#include <QWidget>

namespace Ui {
class MWSettingWidget;
}

class MWSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWSettingWidget(QWidget *parent = nullptr);
    ~MWSettingWidget();

    void setUsername(QString);

private slots:
    void on_m_changePW_clicked();

    void on_m_changeOK_clicked();

    void on_m_changeCancel_clicked();

private:
    Ui::MWSettingWidget *ui;

    QString m_strUsername;
};

#endif // MWSETTINGWIDGET_H
