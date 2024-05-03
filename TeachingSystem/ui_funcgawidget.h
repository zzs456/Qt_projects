/********************************************************************************
** Form generated from reading UI file 'funcgawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCGAWIDGET_H
#define UI_FUNCGAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FuncGAWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *func_CusPlot;
    QCustomPlot *iter_CusPlot;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGroupBox *para_Set;
    QGridLayout *gridLayout;
    QDoubleSpinBox *cross_Spin;
    QSpinBox *popu_Spin;
    QGroupBox *selectAlgo_GB;
    QRadioButton *wheel_Btn;
    QRadioButton *prize_Btn;
    QPushButton *return_funcMain;
    QSpinBox *iterNums_Spin;
    QLabel *label_2;
    QPushButton *startAlgo;
    QDoubleSpinBox *var_Spin;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QWidget *FuncGAWidget)
    {
        if (FuncGAWidget->objectName().isEmpty())
            FuncGAWidget->setObjectName("FuncGAWidget");
        FuncGAWidget->resize(854, 606);
        verticalLayout_2 = new QVBoxLayout(FuncGAWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        func_CusPlot = new QCustomPlot(FuncGAWidget);
        func_CusPlot->setObjectName("func_CusPlot");
        func_CusPlot->setMinimumSize(QSize(0, 300));

        horizontalLayout->addWidget(func_CusPlot);

        iter_CusPlot = new QCustomPlot(FuncGAWidget);
        iter_CusPlot->setObjectName("iter_CusPlot");
        iter_CusPlot->setMinimumSize(QSize(0, 300));

        horizontalLayout->addWidget(iter_CusPlot);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        plainTextEdit = new QPlainTextEdit(FuncGAWidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setEnabled(true);
        plainTextEdit->setMinimumSize(QSize(300, 300));
        plainTextEdit->setMaximumSize(QSize(16777215, 300));
        plainTextEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(plainTextEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        para_Set = new QGroupBox(FuncGAWidget);
        para_Set->setObjectName("para_Set");
        para_Set->setMinimumSize(QSize(300, 300));
        para_Set->setMaximumSize(QSize(16777215, 300));
        QFont font;
        font.setPointSize(12);
        para_Set->setFont(font);
        gridLayout = new QGridLayout(para_Set);
        gridLayout->setSpacing(12);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cross_Spin = new QDoubleSpinBox(para_Set);
        cross_Spin->setObjectName("cross_Spin");
        cross_Spin->setFocusPolicy(Qt::NoFocus);
        cross_Spin->setKeyboardTracking(true);
        cross_Spin->setMinimum(0.600000000000000);
        cross_Spin->setMaximum(0.900000000000000);
        cross_Spin->setSingleStep(0.050000000000000);

        gridLayout->addWidget(cross_Spin, 1, 1, 1, 1);

        popu_Spin = new QSpinBox(para_Set);
        popu_Spin->setObjectName("popu_Spin");
        popu_Spin->setFocusPolicy(Qt::NoFocus);
        popu_Spin->setReadOnly(false);
        popu_Spin->setKeyboardTracking(false);
        popu_Spin->setMinimum(5);
        popu_Spin->setMaximum(100);
        popu_Spin->setSingleStep(5);

        gridLayout->addWidget(popu_Spin, 0, 1, 1, 1);

        selectAlgo_GB = new QGroupBox(para_Set);
        selectAlgo_GB->setObjectName("selectAlgo_GB");
        selectAlgo_GB->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        wheel_Btn = new QRadioButton(selectAlgo_GB);
        wheel_Btn->setObjectName("wheel_Btn");
        wheel_Btn->setGeometry(QRect(20, 20, 118, 23));
        wheel_Btn->setChecked(false);
        prize_Btn = new QRadioButton(selectAlgo_GB);
        prize_Btn->setObjectName("prize_Btn");
        prize_Btn->setGeometry(QRect(140, 20, 118, 23));
        prize_Btn->setChecked(true);

        gridLayout->addWidget(selectAlgo_GB, 4, 0, 1, 2);

        return_funcMain = new QPushButton(para_Set);
        return_funcMain->setObjectName("return_funcMain");

        gridLayout->addWidget(return_funcMain, 5, 0, 1, 1);

        iterNums_Spin = new QSpinBox(para_Set);
        iterNums_Spin->setObjectName("iterNums_Spin");
        iterNums_Spin->setFocusPolicy(Qt::NoFocus);
        iterNums_Spin->setKeyboardTracking(true);
        iterNums_Spin->setMinimum(100);
        iterNums_Spin->setMaximum(400);
        iterNums_Spin->setSingleStep(50);

        gridLayout->addWidget(iterNums_Spin, 3, 1, 1, 1);

        label_2 = new QLabel(para_Set);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        startAlgo = new QPushButton(para_Set);
        startAlgo->setObjectName("startAlgo");

        gridLayout->addWidget(startAlgo, 5, 1, 1, 1);

        var_Spin = new QDoubleSpinBox(para_Set);
        var_Spin->setObjectName("var_Spin");
        var_Spin->setFocusPolicy(Qt::NoFocus);
        var_Spin->setKeyboardTracking(true);
        var_Spin->setMinimum(0.010000000000000);
        var_Spin->setMaximum(0.200000000000000);
        var_Spin->setSingleStep(0.010000000000000);

        gridLayout->addWidget(var_Spin, 2, 1, 1, 1);

        label_4 = new QLabel(para_Set);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(para_Set);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(para_Set);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addWidget(para_Set);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FuncGAWidget);

        QMetaObject::connectSlotsByName(FuncGAWidget);
    } // setupUi

    void retranslateUi(QWidget *FuncGAWidget)
    {
        FuncGAWidget->setWindowTitle(QCoreApplication::translate("FuncGAWidget", "Form", nullptr));
        para_Set->setTitle(QCoreApplication::translate("FuncGAWidget", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        selectAlgo_GB->setTitle(QCoreApplication::translate("FuncGAWidget", "\351\200\211\346\213\251\347\256\227\346\263\225", nullptr));
        wheel_Btn->setText(QCoreApplication::translate("FuncGAWidget", "\350\275\256\347\233\230", nullptr));
        prize_Btn->setText(QCoreApplication::translate("FuncGAWidget", "\344\272\214\345\205\203\351\224\246\346\240\207", nullptr));
        return_funcMain->setText(QCoreApplication::translate("FuncGAWidget", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("FuncGAWidget", "\344\272\244\345\217\211\346\205\250\347\216\207:", nullptr));
        startAlgo->setText(QCoreApplication::translate("FuncGAWidget", "\345\274\200\345\247\213", nullptr));
        label_4->setText(QCoreApplication::translate("FuncGAWidget", "\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        label_3->setText(QCoreApplication::translate("FuncGAWidget", "\345\217\230\345\274\202\346\246\202\347\216\207:", nullptr));
        label->setText(QCoreApplication::translate("FuncGAWidget", "\347\247\215\347\276\244\345\244\247\345\260\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FuncGAWidget: public Ui_FuncGAWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCGAWIDGET_H
