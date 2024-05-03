/********************************************************************************
** Form generated from reading UI file 'pathmainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHMAINWIDGET_H
#define UI_PATHMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathMainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *PathMainWidget)
    {
        if (PathMainWidget->objectName().isEmpty())
            PathMainWidget->setObjectName("PathMainWidget");
        PathMainWidget->resize(862, 562);
        verticalLayout = new QVBoxLayout(PathMainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(PathMainWidget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(PathMainWidget);

        QMetaObject::connectSlotsByName(PathMainWidget);
    } // setupUi

    void retranslateUi(QWidget *PathMainWidget)
    {
        PathMainWidget->setWindowTitle(QCoreApplication::translate("PathMainWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathMainWidget: public Ui_PathMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHMAINWIDGET_H
