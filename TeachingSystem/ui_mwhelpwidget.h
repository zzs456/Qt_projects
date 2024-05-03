/********************************************************************************
** Form generated from reading UI file 'mwhelpwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWHELPWIDGET_H
#define UI_MWHELPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWHelpWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *mwhelp_intro_l;
    QLabel *mwhelp_intro;
    QLabel *mwhelp_func_l;
    QLabel *mwhelp_func;
    QLabel *mwhelp_usage_l;
    QLabel *mwhelp_usage;
    QLabel *mwhelp_version_l;
    QLabel *mwhelp_version;

    void setupUi(QWidget *MWHelpWidget)
    {
        if (MWHelpWidget->objectName().isEmpty())
            MWHelpWidget->setObjectName("MWHelpWidget");
        MWHelpWidget->resize(994, 587);
        verticalLayout = new QVBoxLayout(MWHelpWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        mwhelp_intro_l = new QLabel(MWHelpWidget);
        mwhelp_intro_l->setObjectName("mwhelp_intro_l");
        QFont font;
        font.setPointSize(12);
        mwhelp_intro_l->setFont(font);
        mwhelp_intro_l->setWordWrap(true);

        gridLayout->addWidget(mwhelp_intro_l, 0, 0, 1, 1);

        mwhelp_intro = new QLabel(MWHelpWidget);
        mwhelp_intro->setObjectName("mwhelp_intro");
        mwhelp_intro->setFont(font);
        mwhelp_intro->setWordWrap(true);

        gridLayout->addWidget(mwhelp_intro, 0, 1, 1, 1);

        mwhelp_func_l = new QLabel(MWHelpWidget);
        mwhelp_func_l->setObjectName("mwhelp_func_l");
        mwhelp_func_l->setFont(font);
        mwhelp_func_l->setWordWrap(true);

        gridLayout->addWidget(mwhelp_func_l, 1, 0, 1, 1);

        mwhelp_func = new QLabel(MWHelpWidget);
        mwhelp_func->setObjectName("mwhelp_func");
        mwhelp_func->setFont(font);
        mwhelp_func->setWordWrap(true);

        gridLayout->addWidget(mwhelp_func, 1, 1, 1, 1);

        mwhelp_usage_l = new QLabel(MWHelpWidget);
        mwhelp_usage_l->setObjectName("mwhelp_usage_l");
        mwhelp_usage_l->setFont(font);
        mwhelp_usage_l->setWordWrap(true);

        gridLayout->addWidget(mwhelp_usage_l, 2, 0, 1, 1);

        mwhelp_usage = new QLabel(MWHelpWidget);
        mwhelp_usage->setObjectName("mwhelp_usage");
        mwhelp_usage->setFont(font);
        mwhelp_usage->setWordWrap(true);

        gridLayout->addWidget(mwhelp_usage, 2, 1, 1, 1);

        mwhelp_version_l = new QLabel(MWHelpWidget);
        mwhelp_version_l->setObjectName("mwhelp_version_l");
        mwhelp_version_l->setFont(font);
        mwhelp_version_l->setWordWrap(true);

        gridLayout->addWidget(mwhelp_version_l, 3, 0, 1, 1);

        mwhelp_version = new QLabel(MWHelpWidget);
        mwhelp_version->setObjectName("mwhelp_version");
        mwhelp_version->setFont(font);
        mwhelp_version->setWordWrap(true);

        gridLayout->addWidget(mwhelp_version, 3, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        verticalLayout->addLayout(gridLayout);


        retranslateUi(MWHelpWidget);

        QMetaObject::connectSlotsByName(MWHelpWidget);
    } // setupUi

    void retranslateUi(QWidget *MWHelpWidget)
    {
        MWHelpWidget->setWindowTitle(QCoreApplication::translate("MWHelpWidget", "Form", nullptr));
        mwhelp_intro_l->setText(QCoreApplication::translate("MWHelpWidget", "\350\275\257\344\273\266\344\273\213\347\273\215", nullptr));
        mwhelp_intro->setText(QCoreApplication::translate("MWHelpWidget", "    \345\256\236\347\216\260\345\244\232\347\247\215\347\256\227\346\263\225\350\247\243\345\206\263\345\244\232\347\261\273\351\227\256\351\242\230\347\232\204\350\277\207\347\250\213\346\274\224\347\244\272", nullptr));
        mwhelp_func_l->setText(QCoreApplication::translate("MWHelpWidget", "\350\275\257\344\273\266\345\212\237\350\203\275", nullptr));
        mwhelp_func->setText(QCoreApplication::translate("MWHelpWidget", "    \347\256\227\346\263\225\345\214\205\346\213\254\351\201\227\344\274\240\347\256\227\346\263\225\343\200\201\347\262\222\345\255\220\347\276\244\347\256\227\346\263\225\343\200\201\350\232\201\347\276\244\347\256\227\346\263\225\343\200\201\347\245\236\347\273\217\347\275\221\347\273\234\347\256\227\346\263\225\343\200\201\345\205\215\347\226\253\347\256\227\346\263\225\343\200\201\346\250\241\347\263\212 C \345\235\207\345\200\274\347\256\227\346\263\225\n"
"    \351\227\256\351\242\230\345\214\205\346\213\254\350\267\257\345\276\204\350\247\204\345\210\222\351\227\256\351\242\230\343\200\201\345\207\275\346\225\260\344\274\230\345\214\226\351\227\256\351\242\230\343\200\201\347\273\204\345\220\210\344\274\230\345\214\226\351\227\256\351\242\230\343\200\201TSP \351\227\256\351\242\230", nullptr));
        mwhelp_usage_l->setText(QCoreApplication::translate("MWHelpWidget", "\350\275\257\344\273\266\344\275\277\347\224\250", nullptr));
        mwhelp_usage->setText(QCoreApplication::translate("MWHelpWidget", "    \346\234\254\350\275\257\344\273\266\346\223\215\344\275\234\347\225\214\351\235\242\345\217\213\345\245\275", nullptr));
        mwhelp_version_l->setText(QCoreApplication::translate("MWHelpWidget", "\347\211\210\346\234\254\345\217\267", nullptr));
        mwhelp_version->setText(QCoreApplication::translate("MWHelpWidget", "    1.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MWHelpWidget: public Ui_MWHelpWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWHELPWIDGET_H
