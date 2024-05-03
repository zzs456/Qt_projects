/********************************************************************************
** Form generated from reading UI file 'bpmainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BPMAINWIDGET_H
#define UI_BPMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BpMainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *BpMainWidget)
    {
        if (BpMainWidget->objectName().isEmpty())
            BpMainWidget->setObjectName("BpMainWidget");
        BpMainWidget->resize(1016, 713);
        verticalLayout = new QVBoxLayout(BpMainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(BpMainWidget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(BpMainWidget);

        QMetaObject::connectSlotsByName(BpMainWidget);
    } // setupUi

    void retranslateUi(QWidget *BpMainWidget)
    {
        BpMainWidget->setWindowTitle(QCoreApplication::translate("BpMainWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BpMainWidget: public Ui_BpMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BPMAINWIDGET_H
