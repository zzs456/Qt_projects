#ifndef MWHOMEPICWIDGET_H
#define MWHOMEPICWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QList>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class MWHomePicWidget;
}

class MWHomePicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWHomePicWidget(QWidget *parent = nullptr);
    ~MWHomePicWidget();

private:
    Ui::MWHomePicWidget *ui;

    QList<QPixmap> pixmaps;
    QList<QLabel*> circle_labels;
    QTimer *timer;

    int index;

    void setLabel();
    void setpicLabel();
    void setPixmaps();

    void changedPic(int);
    // QObject interface
public:
    virtual bool eventFilter(QObject *, QEvent *) override;
};

#endif // MWHOMEPICWIDGET_H
