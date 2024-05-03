/********************************************************************************
** Form generated from reading UI file 'proalgoparentwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROALGOPARENTWIDGET_H
#define UI_PROALGOPARENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProAlgoParentWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *proalgo_parentShowL;

    void setupUi(QWidget *ProAlgoParentWidget)
    {
        if (ProAlgoParentWidget->objectName().isEmpty())
            ProAlgoParentWidget->setObjectName("ProAlgoParentWidget");
        ProAlgoParentWidget->resize(467, 337);
        verticalLayout = new QVBoxLayout(ProAlgoParentWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        proalgo_parentShowL = new QLabel(ProAlgoParentWidget);
        proalgo_parentShowL->setObjectName("proalgo_parentShowL");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        proalgo_parentShowL->setFont(font);
        proalgo_parentShowL->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(proalgo_parentShowL);


        retranslateUi(ProAlgoParentWidget);

        QMetaObject::connectSlotsByName(ProAlgoParentWidget);
    } // setupUi

    void retranslateUi(QWidget *ProAlgoParentWidget)
    {
        ProAlgoParentWidget->setWindowTitle(QCoreApplication::translate("ProAlgoParentWidget", "Form", nullptr));
        proalgo_parentShowL->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProAlgoParentWidget: public Ui_ProAlgoParentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROALGOPARENTWIDGET_H
