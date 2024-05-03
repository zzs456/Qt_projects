/********************************************************************************
** Form generated from reading UI file 'pathinlayproswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHINLAYPROSWIDGET_H
#define UI_PATHINLAYPROSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_PathInlayProsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *maps_CustomPlot;

    void setupUi(QWidget *PathInlayProsWidget)
    {
        if (PathInlayProsWidget->objectName().isEmpty())
            PathInlayProsWidget->setObjectName("PathInlayProsWidget");
        PathInlayProsWidget->resize(741, 574);
        verticalLayout = new QVBoxLayout(PathInlayProsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        maps_CustomPlot = new QCustomPlot(PathInlayProsWidget);
        maps_CustomPlot->setObjectName("maps_CustomPlot");

        verticalLayout->addWidget(maps_CustomPlot);


        retranslateUi(PathInlayProsWidget);

        QMetaObject::connectSlotsByName(PathInlayProsWidget);
    } // setupUi

    void retranslateUi(QWidget *PathInlayProsWidget)
    {
        PathInlayProsWidget->setWindowTitle(QCoreApplication::translate("PathInlayProsWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathInlayProsWidget: public Ui_PathInlayProsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHINLAYPROSWIDGET_H
