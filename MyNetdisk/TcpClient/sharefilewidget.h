#ifndef SHAREFILEWIDGET_H
#define SHAREFILEWIDGET_H

#include "myprotocol.h"
#include <QWidget>

namespace Ui {
class ShareFileWidget;
}

class ShareFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShareFileWidget(QWidget *parent = nullptr);
    ~ShareFileWidget();
    void HandleShareFileWidgetShow(PDU*);

signals:
    void ShareFileToFriends(QStringList&);

private slots:
    void on_m_selectAll_clicked();

    void on_m_cancelAll_clicked();

    void on_m_ok_clicked();

    void on_m_cancel_clicked();

private:
    Ui::ShareFileWidget *ui;
};

#endif // SHAREFILEWIDGET_H
