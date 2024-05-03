/********************************************************************************
** Form generated from reading UI file 'tspmainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSPMAINWIDGET_H
#define UI_TSPMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TSPMainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *TSPMainWidget)
    {
        if (TSPMainWidget->objectName().isEmpty())
            TSPMainWidget->setObjectName("TSPMainWidget");
        TSPMainWidget->resize(769, 534);
        verticalLayout = new QVBoxLayout(TSPMainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(TSPMainWidget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(TSPMainWidget);

        QMetaObject::connectSlotsByName(TSPMainWidget);
    } // setupUi

    void retranslateUi(QWidget *TSPMainWidget)
    {
        TSPMainWidget->setWindowTitle(QCoreApplication::translate("TSPMainWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TSPMainWidget: public Ui_TSPMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSPMAINWIDGET_H
