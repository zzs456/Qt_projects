#include "mwhomepicwidget.h"
#include "ui_mwhomepicwidget.h"



MWHomePicWidget::MWHomePicWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MWHomePicWidget)
{
    ui->setupUi(this);
    index = 0;
    timer = new QTimer;
    timer->start(2000);
    setPixmaps();
    setpicLabel();
    setLabel();
    connect(timer, &QTimer::timeout, this, [=](){
                changedPic(index+1);
            });
}

MWHomePicWidget::~MWHomePicWidget()
{
    delete ui;
}

void MWHomePicWidget::setLabel()
{
    circle_labels.append(ui->picBtn_1);
    circle_labels.append(ui->picBtn_2);
    circle_labels.append(ui->picBtn_3);
    for(int i = 0;i < circle_labels.size();++ i){
        QLabel* temp = circle_labels.at(i);
        if(i == index){
            temp->setPixmap(QPixmap(":/algotithm_pngs/res/algotithm_pngs/c2.png"));
        }else{
            temp->setPixmap(QPixmap(":/algotithm_pngs/res/algotithm_pngs/c1.png"));
        }
        temp->installEventFilter(this);
    }
}

void MWHomePicWidget::setpicLabel()
{
    ui->mw_Home_picLabel->setPixmap(pixmaps[index]);
    ui->mw_Home_picLabel->setScaledContents(true);
}

void MWHomePicWidget::setPixmaps()
{
    pixmaps << QPixmap(":/algotithm_pngs/1")
            << QPixmap(":/algotithm_pngs/2")
            << QPixmap(":/algotithm_pngs/3");
}

void MWHomePicWidget::changedPic(int newIndex)
{
    if(index == newIndex){
        return;
    }
    if(newIndex >= 3){
        newIndex = 0;
    }
    ui->mw_Home_picLabel->setPixmap(pixmaps[newIndex]);
    QLabel *oldTemp = circle_labels[index];
    QLabel *newTemp = circle_labels[newIndex];
    oldTemp->setPixmap(QPixmap(":/algotithm_pngs/res/algotithm_pngs/c1.png"));
    newTemp->setPixmap(QPixmap(":/algotithm_pngs/res/algotithm_pngs/c2.png"));
    index = newIndex;
}


bool MWHomePicWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::Enter)
    {
        for(int i = 0;i < circle_labels.size();++ i){
            QLabel *temp = circle_labels.at(i);
            if(watched == temp){
                changedPic(i);
                timer->stop();
                return true;
            }
        }
        return false;
    }else if(event->type() == QEvent::Leave){
        for(int i = 0;i < circle_labels.size();++ i){
            QLabel *temp = circle_labels.at(i);
            if(watched == temp){
                timer->start(2000);
                return true;
            }
        }
    }
    return QWidget::eventFilter(watched, event);
}
