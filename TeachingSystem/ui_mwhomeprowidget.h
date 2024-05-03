/********************************************************************************
** Form generated from reading UI file 'mwhomeprowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWHOMEPROWIDGET_H
#define UI_MWHOMEPROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWHomeProWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *mwHomePro_GA;
    QLabel *mwHomePro_PSO;
    QLabel *mwHomePro_ACO;
    QSpacerItem *horizontalSpacer;
    QPushButton *mwHomePro_start;

    void setupUi(QWidget *MWHomeProWidget)
    {
        if (MWHomeProWidget->objectName().isEmpty())
            MWHomeProWidget->setObjectName("MWHomeProWidget");
        MWHomeProWidget->resize(918, 143);
        horizontalLayout_3 = new QHBoxLayout(MWHomeProWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(20, 0, 20, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        mwHomePro_GA = new QLabel(MWHomeProWidget);
        mwHomePro_GA->setObjectName("mwHomePro_GA");
        QFont font;
        font.setPointSize(12);
        mwHomePro_GA->setFont(font);

        horizontalLayout->addWidget(mwHomePro_GA);

        mwHomePro_PSO = new QLabel(MWHomeProWidget);
        mwHomePro_PSO->setObjectName("mwHomePro_PSO");
        mwHomePro_PSO->setFont(font);

        horizontalLayout->addWidget(mwHomePro_PSO);

        mwHomePro_ACO = new QLabel(MWHomeProWidget);
        mwHomePro_ACO->setObjectName("mwHomePro_ACO");
        mwHomePro_ACO->setFont(font);

        horizontalLayout->addWidget(mwHomePro_ACO);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        mwHomePro_start = new QPushButton(MWHomeProWidget);
        mwHomePro_start->setObjectName("mwHomePro_start");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        mwHomePro_start->setFont(font1);
        mwHomePro_start->setStyleSheet(QString::fromUtf8("QPushButton#mwHomePro_start{\n"
"	color: blue;\n"
"}"));

        horizontalLayout_2->addWidget(mwHomePro_start);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(MWHomeProWidget);

        QMetaObject::connectSlotsByName(MWHomeProWidget);
    } // setupUi

    void retranslateUi(QWidget *MWHomeProWidget)
    {
        MWHomeProWidget->setWindowTitle(QCoreApplication::translate("MWHomeProWidget", "Form", nullptr));
        mwHomePro_GA->setText(QCoreApplication::translate("MWHomeProWidget", "TextLabel", nullptr));
        mwHomePro_PSO->setText(QCoreApplication::translate("MWHomeProWidget", "TextLabel", nullptr));
        mwHomePro_ACO->setText(QCoreApplication::translate("MWHomeProWidget", "TextLabel", nullptr));
        mwHomePro_start->setText(QCoreApplication::translate("MWHomeProWidget", "\345\274\200\345\247\213\345\255\246\344\271\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MWHomeProWidget: public Ui_MWHomeProWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWHOMEPROWIDGET_H
