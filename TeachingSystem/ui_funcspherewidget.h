/********************************************************************************
** Form generated from reading UI file 'funcspherewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCSPHEREWIDGET_H
#define UI_FUNCSPHEREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FuncSphereWidget
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
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FuncSphereWidget)
    {
        if (FuncSphereWidget->objectName().isEmpty())
            FuncSphereWidget->setObjectName("FuncSphereWidget");
        FuncSphereWidget->resize(818, 533);
        verticalLayout_2 = new QVBoxLayout(FuncSphereWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(FuncSphereWidget);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FuncSphereWidget);

        QMetaObject::connectSlotsByName(FuncSphereWidget);
    } // setupUi

    void retranslateUi(QWidget *FuncSphereWidget)
    {
        FuncSphereWidget->setWindowTitle(QCoreApplication::translate("FuncSphereWidget", "Form", nullptr));
        groupBox->setTitle(QString());
        funcName_label->setText(QCoreApplication::translate("FuncSphereWidget", "\345\207\275\346\225\260  :", nullptr));
        funcName->setText(QCoreApplication::translate("FuncSphereWidget", "TextLabel", nullptr));
        funcDomain_label->setText(QCoreApplication::translate("FuncSphereWidget", "\345\256\232\344\271\211\345\237\237  :", nullptr));
        funcDomain->setText(QCoreApplication::translate("FuncSphereWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FuncSphereWidget: public Ui_FuncSphereWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCSPHEREWIDGET_H
