/********************************************************************************
** Form generated from reading UI file 'funcmainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCMAINWIDGET_H
#define UI_FUNCMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FuncMainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *FuncMainWidget)
    {
        if (FuncMainWidget->objectName().isEmpty())
            FuncMainWidget->setObjectName("FuncMainWidget");
        FuncMainWidget->resize(927, 640);
        verticalLayout = new QVBoxLayout(FuncMainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(FuncMainWidget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(FuncMainWidget);

        QMetaObject::connectSlotsByName(FuncMainWidget);
    } // setupUi

    void retranslateUi(QWidget *FuncMainWidget)
    {
        FuncMainWidget->setWindowTitle(QCoreApplication::translate("FuncMainWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FuncMainWidget: public Ui_FuncMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCMAINWIDGET_H
