/********************************************************************************
** Form generated from reading UI file 'mwhomewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWHOMEWIDGET_H
#define UI_MWHOMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mwhomepicwidget.h"
#include "mwhomeprowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MWHomeWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    MWHomePicWidget *mwHome_picWidget;
    MWHomeProWidget *mwHome_proWidget;

    void setupUi(QWidget *MWHomeWidget)
    {
        if (MWHomeWidget->objectName().isEmpty())
            MWHomeWidget->setObjectName("MWHomeWidget");
        MWHomeWidget->resize(774, 593);
        verticalLayout_2 = new QVBoxLayout(MWHomeWidget);
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        mwHome_picWidget = new MWHomePicWidget(MWHomeWidget);
        mwHome_picWidget->setObjectName("mwHome_picWidget");

        verticalLayout->addWidget(mwHome_picWidget);

        mwHome_proWidget = new MWHomeProWidget(MWHomeWidget);
        mwHome_proWidget->setObjectName("mwHome_proWidget");

        verticalLayout->addWidget(mwHome_proWidget);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 2);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MWHomeWidget);

        QMetaObject::connectSlotsByName(MWHomeWidget);
    } // setupUi

    void retranslateUi(QWidget *MWHomeWidget)
    {
        MWHomeWidget->setWindowTitle(QCoreApplication::translate("MWHomeWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MWHomeWidget: public Ui_MWHomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWHOMEWIDGET_H
