/********************************************************************************
** Form generated from reading UI file 'tspinlayproswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSPINLAYPROSWIDGET_H
#define UI_TSPINLAYPROSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_TSPInlayProsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *points_CustomPlot;

    void setupUi(QWidget *TSPInlayProsWidget)
    {
        if (TSPInlayProsWidget->objectName().isEmpty())
            TSPInlayProsWidget->setObjectName("TSPInlayProsWidget");
        TSPInlayProsWidget->resize(735, 474);
        verticalLayout = new QVBoxLayout(TSPInlayProsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        points_CustomPlot = new QCustomPlot(TSPInlayProsWidget);
        points_CustomPlot->setObjectName("points_CustomPlot");

        verticalLayout->addWidget(points_CustomPlot);


        retranslateUi(TSPInlayProsWidget);

        QMetaObject::connectSlotsByName(TSPInlayProsWidget);
    } // setupUi

    void retranslateUi(QWidget *TSPInlayProsWidget)
    {
        TSPInlayProsWidget->setWindowTitle(QCoreApplication::translate("TSPInlayProsWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TSPInlayProsWidget: public Ui_TSPInlayProsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSPINLAYPROSWIDGET_H
