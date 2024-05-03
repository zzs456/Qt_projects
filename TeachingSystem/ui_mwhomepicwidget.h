/********************************************************************************
** Form generated from reading UI file 'mwhomepicwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWHOMEPICWIDGET_H
#define UI_MWHOMEPICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWHomePicWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *mw_Home_picLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *picBtn_1;
    QLabel *picBtn_2;
    QLabel *picBtn_3;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *MWHomePicWidget)
    {
        if (MWHomePicWidget->objectName().isEmpty())
            MWHomePicWidget->setObjectName("MWHomePicWidget");
        MWHomePicWidget->resize(902, 543);
        verticalLayout = new QVBoxLayout(MWHomePicWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mw_Home_picLabel = new QLabel(MWHomePicWidget);
        mw_Home_picLabel->setObjectName("mw_Home_picLabel");
        mw_Home_picLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout->addWidget(mw_Home_picLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 6);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        picBtn_1 = new QLabel(MWHomePicWidget);
        picBtn_1->setObjectName("picBtn_1");

        horizontalLayout_2->addWidget(picBtn_1);

        picBtn_2 = new QLabel(MWHomePicWidget);
        picBtn_2->setObjectName("picBtn_2");

        horizontalLayout_2->addWidget(picBtn_2);

        picBtn_3 = new QLabel(MWHomePicWidget);
        picBtn_3->setObjectName("picBtn_3");

        horizontalLayout_2->addWidget(picBtn_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 10);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 1);

        retranslateUi(MWHomePicWidget);

        QMetaObject::connectSlotsByName(MWHomePicWidget);
    } // setupUi

    void retranslateUi(QWidget *MWHomePicWidget)
    {
        MWHomePicWidget->setWindowTitle(QCoreApplication::translate("MWHomePicWidget", "Form", nullptr));
        mw_Home_picLabel->setText(QCoreApplication::translate("MWHomePicWidget", "TextLabel", nullptr));
        picBtn_1->setText(QString());
        picBtn_2->setText(QString());
        picBtn_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MWHomePicWidget: public Ui_MWHomePicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWHOMEPICWIDGET_H
