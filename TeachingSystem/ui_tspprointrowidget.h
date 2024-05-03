/********************************************************************************
** Form generated from reading UI file 'tspprointrowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSPPROINTROWIDGET_H
#define UI_TSPPROINTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TSPProIntroWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *TSPProIntroWidget)
    {
        if (TSPProIntroWidget->objectName().isEmpty())
            TSPProIntroWidget->setObjectName("TSPProIntroWidget");
        TSPProIntroWidget->resize(725, 498);
        verticalLayout = new QVBoxLayout(TSPProIntroWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TSPProIntroWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(TSPProIntroWidget);

        QMetaObject::connectSlotsByName(TSPProIntroWidget);
    } // setupUi

    void retranslateUi(QWidget *TSPProIntroWidget)
    {
        TSPProIntroWidget->setWindowTitle(QCoreApplication::translate("TSPProIntroWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("TSPProIntroWidget", "\351\201\227\344\274\240\347\256\227\346\263\225\n"
"\346\227\205\350\241\214\345\225\206\351\227\256\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TSPProIntroWidget: public Ui_TSPProIntroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSPPROINTROWIDGET_H
