/********************************************************************************
** Form generated from reading UI file 'functrigowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTRIGOWIDGET_H
#define UI_FUNCTRIGOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_FuncTrigoWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *funcName_label;
    QLabel *funcName;
    QLabel *funcDomain_label;
    QLabel *funcDomain;
    QCustomPlot *func_showWidget;

    void setupUi(QWidget *FuncTrigoWidget)
    {
        if (FuncTrigoWidget->objectName().isEmpty())
            FuncTrigoWidget->setObjectName("FuncTrigoWidget");
        FuncTrigoWidget->resize(990, 617);
        verticalLayout_2 = new QVBoxLayout(FuncTrigoWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(FuncTrigoWidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 20, 0, 20);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(12);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        funcName_label = new QLabel(groupBox);
        funcName_label->setObjectName("funcName_label");
        QFont font;
        font.setPointSize(12);
        funcName_label->setFont(font);
        funcName_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(funcName_label, 0, 0, 1, 1);

        funcName = new QLabel(groupBox);
        funcName->setObjectName("funcName");
        funcName->setFont(font);

        gridLayout->addWidget(funcName, 0, 1, 1, 1);

        funcDomain_label = new QLabel(groupBox);
        funcDomain_label->setObjectName("funcDomain_label");
        funcDomain_label->setFont(font);
        funcDomain_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(funcDomain_label, 1, 0, 1, 1);

        funcDomain = new QLabel(groupBox);
        funcDomain->setObjectName("funcDomain");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(12);
        funcDomain->setFont(font1);

        gridLayout->addWidget(funcDomain, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);

        func_showWidget = new QCustomPlot(FuncTrigoWidget);
        func_showWidget->setObjectName("func_showWidget");

        verticalLayout->addWidget(func_showWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FuncTrigoWidget);

        QMetaObject::connectSlotsByName(FuncTrigoWidget);
    } // setupUi

    void retranslateUi(QWidget *FuncTrigoWidget)
    {
        FuncTrigoWidget->setWindowTitle(QCoreApplication::translate("FuncTrigoWidget", "Form", nullptr));
        groupBox->setTitle(QString());
        funcName_label->setText(QCoreApplication::translate("FuncTrigoWidget", "\345\207\275\346\225\260  :", nullptr));
        funcName->setText(QCoreApplication::translate("FuncTrigoWidget", "TextLabel", nullptr));
        funcDomain_label->setText(QCoreApplication::translate("FuncTrigoWidget", "\345\256\232\344\271\211\345\237\237  :", nullptr));
        funcDomain->setText(QCoreApplication::translate("FuncTrigoWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FuncTrigoWidget: public Ui_FuncTrigoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTRIGOWIDGET_H
