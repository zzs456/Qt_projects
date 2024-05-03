/********************************************************************************
** Form generated from reading UI file 'gademoshowwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GADEMOSHOWWIDGET_H
#define UI_GADEMOSHOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_GADemoShowWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *hideProPlotCk;
    QCheckBox *onlyShowResCk;
    QCheckBox *hideAverResCk;
    QPushButton *clearResBtn;
    QPushButton *clearAll;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *Pro_CustomPlot;
    QCustomPlot *Res_CustomPlot;
    QWidget *bottomShowWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QWidget *OutputResW;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *outputResPlain;
    QWidget *CompResW;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *recordResTable;
    QGroupBox *para_Set;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *var_Spin;
    QLabel *label_2;
    QSpinBox *popu_Spin;
    QLabel *label;
    QDoubleSpinBox *cross_Spin;
    QGroupBox *selectAlgo_GB;
    QRadioButton *wheel_Btn;
    QRadioButton *prize_Btn;
    QPushButton *return_ProMain;
    QPushButton *startAlgo;
    QSpinBox *iterNums_Spin;

    void setupUi(QWidget *GADemoShowWidget)
    {
        if (GADemoShowWidget->objectName().isEmpty())
            GADemoShowWidget->setObjectName("GADemoShowWidget");
        GADemoShowWidget->resize(1186, 752);
        verticalLayout_4 = new QVBoxLayout(GADemoShowWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(GADemoShowWidget);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        hideProPlotCk = new QCheckBox(groupBox);
        hideProPlotCk->setObjectName("hideProPlotCk");

        horizontalLayout->addWidget(hideProPlotCk);

        onlyShowResCk = new QCheckBox(groupBox);
        onlyShowResCk->setObjectName("onlyShowResCk");

        horizontalLayout->addWidget(onlyShowResCk);

        hideAverResCk = new QCheckBox(groupBox);
        hideAverResCk->setObjectName("hideAverResCk");

        horizontalLayout->addWidget(hideAverResCk);

        clearResBtn = new QPushButton(groupBox);
        clearResBtn->setObjectName("clearResBtn");

        horizontalLayout->addWidget(clearResBtn);

        clearAll = new QPushButton(groupBox);
        clearAll->setObjectName("clearAll");

        horizontalLayout->addWidget(clearAll);


        verticalLayout_4->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Pro_CustomPlot = new QCustomPlot(GADemoShowWidget);
        Pro_CustomPlot->setObjectName("Pro_CustomPlot");
        Pro_CustomPlot->setMinimumSize(QSize(400, 300));

        horizontalLayout_2->addWidget(Pro_CustomPlot);

        Res_CustomPlot = new QCustomPlot(GADemoShowWidget);
        Res_CustomPlot->setObjectName("Res_CustomPlot");
        Res_CustomPlot->setMinimumSize(QSize(400, 300));

        horizontalLayout_2->addWidget(Res_CustomPlot);


        verticalLayout_4->addLayout(horizontalLayout_2);

        bottomShowWidget = new QWidget(GADemoShowWidget);
        bottomShowWidget->setObjectName("bottomShowWidget");
        verticalLayout_3 = new QVBoxLayout(bottomShowWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        tabWidget = new QTabWidget(bottomShowWidget);
        tabWidget->setObjectName("tabWidget");
        QFont font1;
        font1.setPointSize(10);
        tabWidget->setFont(font1);
        OutputResW = new QWidget();
        OutputResW->setObjectName("OutputResW");
        verticalLayout = new QVBoxLayout(OutputResW);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        outputResPlain = new QPlainTextEdit(OutputResW);
        outputResPlain->setObjectName("outputResPlain");
        outputResPlain->setStyleSheet(QString::fromUtf8("QPlainTextEdit#outputResPlain{\n"
"	border:0;\n"
"}"));
        outputResPlain->setReadOnly(true);

        verticalLayout->addWidget(outputResPlain);

        tabWidget->addTab(OutputResW, QString());
        CompResW = new QWidget();
        CompResW->setObjectName("CompResW");
        verticalLayout_2 = new QVBoxLayout(CompResW);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        recordResTable = new QTableWidget(CompResW);
        if (recordResTable->columnCount() < 7)
            recordResTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        recordResTable->setObjectName("recordResTable");
        recordResTable->setFocusPolicy(Qt::NoFocus);
        recordResTable->setStyleSheet(QString::fromUtf8("QTableWidget#recordResTable{\n"
"	border:0;\n"
"}"));

        verticalLayout_2->addWidget(recordResTable);

        tabWidget->addTab(CompResW, QString());

        horizontalLayout_3->addWidget(tabWidget);

        para_Set = new QGroupBox(bottomShowWidget);
        para_Set->setObjectName("para_Set");
        para_Set->setMinimumSize(QSize(300, 300));
        para_Set->setMaximumSize(QSize(16777215, 300));
        para_Set->setFont(font);
        gridLayout = new QGridLayout(para_Set);
        gridLayout->setSpacing(12);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(para_Set);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(para_Set);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        var_Spin = new QDoubleSpinBox(para_Set);
        var_Spin->setObjectName("var_Spin");
        var_Spin->setFocusPolicy(Qt::NoFocus);
        var_Spin->setKeyboardTracking(true);
        var_Spin->setMinimum(0.010000000000000);
        var_Spin->setMaximum(0.100000000000000);
        var_Spin->setSingleStep(0.010000000000000);

        gridLayout->addWidget(var_Spin, 2, 1, 1, 1);

        label_2 = new QLabel(para_Set);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        popu_Spin = new QSpinBox(para_Set);
        popu_Spin->setObjectName("popu_Spin");
        popu_Spin->setFocusPolicy(Qt::NoFocus);
        popu_Spin->setReadOnly(false);
        popu_Spin->setKeyboardTracking(false);
        popu_Spin->setMinimum(10);
        popu_Spin->setMaximum(100);
        popu_Spin->setSingleStep(5);

        gridLayout->addWidget(popu_Spin, 0, 1, 1, 1);

        label = new QLabel(para_Set);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cross_Spin = new QDoubleSpinBox(para_Set);
        cross_Spin->setObjectName("cross_Spin");
        cross_Spin->setFocusPolicy(Qt::NoFocus);
        cross_Spin->setKeyboardTracking(true);
        cross_Spin->setMinimum(0.600000000000000);
        cross_Spin->setMaximum(0.900000000000000);
        cross_Spin->setSingleStep(0.050000000000000);

        gridLayout->addWidget(cross_Spin, 1, 1, 1, 1);

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

        return_ProMain = new QPushButton(para_Set);
        return_ProMain->setObjectName("return_ProMain");

        gridLayout->addWidget(return_ProMain, 5, 0, 1, 1);

        startAlgo = new QPushButton(para_Set);
        startAlgo->setObjectName("startAlgo");

        gridLayout->addWidget(startAlgo, 5, 1, 1, 1);

        iterNums_Spin = new QSpinBox(para_Set);
        iterNums_Spin->setObjectName("iterNums_Spin");
        iterNums_Spin->setFocusPolicy(Qt::NoFocus);
        iterNums_Spin->setKeyboardTracking(true);
        iterNums_Spin->setMinimum(50);
        iterNums_Spin->setMaximum(400);
        iterNums_Spin->setSingleStep(10);

        gridLayout->addWidget(iterNums_Spin, 3, 1, 1, 1);


        horizontalLayout_3->addWidget(para_Set);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(bottomShowWidget);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 100);
        verticalLayout_4->setStretch(2, 100);

        retranslateUi(GADemoShowWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GADemoShowWidget);
    } // setupUi

    void retranslateUi(QWidget *GADemoShowWidget)
    {
        GADemoShowWidget->setWindowTitle(QCoreApplication::translate("GADemoShowWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GADemoShowWidget", "\350\256\276\347\275\256", nullptr));
        hideProPlotCk->setText(QCoreApplication::translate("GADemoShowWidget", "\351\232\220\350\227\217\351\227\256\351\242\230\345\233\276\345\203\217", nullptr));
        onlyShowResCk->setText(QCoreApplication::translate("GADemoShowWidget", "\345\205\250\345\261\217\346\230\276\347\244\272\345\233\276\345\203\217", nullptr));
        hideAverResCk->setText(QCoreApplication::translate("GADemoShowWidget", "\351\232\220\350\227\217\345\271\263\345\235\207\346\203\205\345\206\265", nullptr));
        clearResBtn->setText(QCoreApplication::translate("GADemoShowWidget", "\346\270\205\347\251\272\350\277\255\344\273\243\345\233\276\345\203\217", nullptr));
        clearAll->setText(QCoreApplication::translate("GADemoShowWidget", "\346\270\205\347\251\272\346\211\200\346\234\211", nullptr));
#if QT_CONFIG(accessibility)
        OutputResW->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        tabWidget->setTabText(tabWidget->indexOf(OutputResW), QCoreApplication::translate("GADemoShowWidget", "\350\276\223\345\207\272\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = recordResTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GADemoShowWidget", "\347\247\215\347\276\244\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = recordResTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GADemoShowWidget", "\344\272\244\345\217\211\346\246\202\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = recordResTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GADemoShowWidget", "\345\217\230\345\274\202\346\246\202\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = recordResTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GADemoShowWidget", "\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = recordResTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GADemoShowWidget", "\346\234\200\344\274\230\351\200\202\345\272\224\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = recordResTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GADemoShowWidget", "\346\234\200\344\274\230\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = recordResTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GADemoShowWidget", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CompResW), QCoreApplication::translate("GADemoShowWidget", "\347\273\237\350\256\241\347\273\223\346\236\234", nullptr));
        para_Set->setTitle(QCoreApplication::translate("GADemoShowWidget", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("GADemoShowWidget", "\345\217\230\345\274\202\346\246\202\347\216\207:", nullptr));
        label_4->setText(QCoreApplication::translate("GADemoShowWidget", "\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        label_2->setText(QCoreApplication::translate("GADemoShowWidget", "\344\272\244\345\217\211\346\205\250\347\216\207:", nullptr));
        label->setText(QCoreApplication::translate("GADemoShowWidget", "\347\247\215\347\276\244\345\244\247\345\260\217:", nullptr));
        selectAlgo_GB->setTitle(QCoreApplication::translate("GADemoShowWidget", "\351\200\211\346\213\251\347\256\227\346\263\225", nullptr));
        wheel_Btn->setText(QCoreApplication::translate("GADemoShowWidget", "\350\275\256\347\233\230", nullptr));
        prize_Btn->setText(QCoreApplication::translate("GADemoShowWidget", "\344\272\214\345\205\203\351\224\246\346\240\207", nullptr));
        return_ProMain->setText(QCoreApplication::translate("GADemoShowWidget", "\350\277\224\345\233\236", nullptr));
        startAlgo->setText(QCoreApplication::translate("GADemoShowWidget", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GADemoShowWidget: public Ui_GADemoShowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GADEMOSHOWWIDGET_H
