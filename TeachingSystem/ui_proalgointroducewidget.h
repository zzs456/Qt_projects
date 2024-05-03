/********************************************************************************
** Form generated from reading UI file 'proalgointroducewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROALGOINTRODUCEWIDGET_H
#define UI_PROALGOINTRODUCEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProAlgoIntroduceWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *proalgo_introShowL;

    void setupUi(QWidget *ProAlgoIntroduceWidget)
    {
        if (ProAlgoIntroduceWidget->objectName().isEmpty())
            ProAlgoIntroduceWidget->setObjectName("ProAlgoIntroduceWidget");
        ProAlgoIntroduceWidget->resize(679, 580);
        verticalLayout = new QVBoxLayout(ProAlgoIntroduceWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        proalgo_introShowL = new QLabel(ProAlgoIntroduceWidget);
        proalgo_introShowL->setObjectName("proalgo_introShowL");
        QFont font;
        font.setPointSize(16);
        proalgo_introShowL->setFont(font);
        proalgo_introShowL->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(proalgo_introShowL);


        retranslateUi(ProAlgoIntroduceWidget);

        QMetaObject::connectSlotsByName(ProAlgoIntroduceWidget);
    } // setupUi

    void retranslateUi(QWidget *ProAlgoIntroduceWidget)
    {
        ProAlgoIntroduceWidget->setWindowTitle(QCoreApplication::translate("ProAlgoIntroduceWidget", "Form", nullptr));
        proalgo_introShowL->setText(QCoreApplication::translate("ProAlgoIntroduceWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProAlgoIntroduceWidget: public Ui_ProAlgoIntroduceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROALGOINTRODUCEWIDGET_H
