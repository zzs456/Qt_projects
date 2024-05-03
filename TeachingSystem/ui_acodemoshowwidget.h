/********************************************************************************
** Form generated from reading UI file 'acodemoshowwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACODEMOSHOWWIDGET_H
#define UI_ACODEMOSHOWWIDGET_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ACODemoShowWidget
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
    QPushButton *return_ProMain;
    QLabel *label_6;
    QDoubleSpinBox *Alpha_Spin;
    QDoubleSpinBox *Rho_Spin;
    QPushButton *startAlgo;
    QDoubleSpinBox *Q_Spin;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QSpinBox *iterNums_Spin;
    QSpinBox *popuNums_Spin;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *Beta_Spin;

    void setupUi(QWidget *ACODemoShowWidget)
    {
        if (ACODemoShowWidget->objectName().isEmpty())
            ACODemoShowWidget->setObjectName("ACODemoShowWidget");
        ACODemoShowWidget->resize(1197, 824);
        verticalLayout_4 = new QVBoxLayout(ACODemoShowWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(ACODemoShowWidget);
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
        Pro_CustomPlot = new QCustomPlot(ACODemoShowWidget);
        Pro_CustomPlot->setObjectName("Pro_CustomPlot");
        Pro_CustomPlot->setMinimumSize(QSize(400, 300));

        horizontalLayout_2->addWidget(Pro_CustomPlot);

        Res_CustomPlot = new QCustomPlot(ACODemoShowWidget);
        Res_CustomPlot->setObjectName("Res_CustomPlot");
        Res_CustomPlot->setMinimumSize(QSize(400, 300));

        horizontalLayout_2->addWidget(Res_CustomPlot);


        verticalLayout_4->addLayout(horizontalLayout_2);

        bottomShowWidget = new QWidget(ACODemoShowWidget);
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
        if (recordResTable->columnCount() < 9)
            recordResTable->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        recordResTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(para_Set->sizePolicy().hasHeightForWidth());
        para_Set->setSizePolicy(sizePolicy);
        para_Set->setMinimumSize(QSize(300, 400));
        para_Set->setMaximumSize(QSize(16777215, 400));
        para_Set->setFont(font);
        gridLayout = new QGridLayout(para_Set);
        gridLayout->setObjectName("gridLayout");
        return_ProMain = new QPushButton(para_Set);
        return_ProMain->setObjectName("return_ProMain");

        gridLayout->addWidget(return_ProMain, 6, 0, 1, 1);

        label_6 = new QLabel(para_Set);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        Alpha_Spin = new QDoubleSpinBox(para_Set);
        Alpha_Spin->setObjectName("Alpha_Spin");
        Alpha_Spin->setFocusPolicy(Qt::NoFocus);
        Alpha_Spin->setMinimum(0.000000000000000);
        Alpha_Spin->setMaximum(10.000000000000000);
        Alpha_Spin->setSingleStep(0.500000000000000);

        gridLayout->addWidget(Alpha_Spin, 2, 1, 1, 1);

        Rho_Spin = new QDoubleSpinBox(para_Set);
        Rho_Spin->setObjectName("Rho_Spin");
        Rho_Spin->setFocusPolicy(Qt::NoFocus);
        Rho_Spin->setMinimum(0.100000000000000);
        Rho_Spin->setMaximum(0.900000000000000);
        Rho_Spin->setSingleStep(0.050000000000000);

        gridLayout->addWidget(Rho_Spin, 1, 1, 1, 1);

        startAlgo = new QPushButton(para_Set);
        startAlgo->setObjectName("startAlgo");

        gridLayout->addWidget(startAlgo, 6, 1, 1, 1);

        Q_Spin = new QDoubleSpinBox(para_Set);
        Q_Spin->setObjectName("Q_Spin");
        Q_Spin->setFocusPolicy(Qt::NoFocus);
        Q_Spin->setMinimum(1.000000000000000);
        Q_Spin->setMaximum(10.000000000000000);
        Q_Spin->setSingleStep(0.500000000000000);

        gridLayout->addWidget(Q_Spin, 4, 1, 1, 1);

        label_2 = new QLabel(para_Set);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(para_Set);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(para_Set);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        iterNums_Spin = new QSpinBox(para_Set);
        iterNums_Spin->setObjectName("iterNums_Spin");
        iterNums_Spin->setFocusPolicy(Qt::NoFocus);
        iterNums_Spin->setMinimum(50);
        iterNums_Spin->setMaximum(400);
        iterNums_Spin->setSingleStep(10);

        gridLayout->addWidget(iterNums_Spin, 5, 1, 1, 1);

        popuNums_Spin = new QSpinBox(para_Set);
        popuNums_Spin->setObjectName("popuNums_Spin");
        popuNums_Spin->setFocusPolicy(Qt::NoFocus);
        popuNums_Spin->setMinimum(5);
        popuNums_Spin->setMaximum(40);
        popuNums_Spin->setSingleStep(5);

        gridLayout->addWidget(popuNums_Spin, 0, 1, 1, 1);

        label_4 = new QLabel(para_Set);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_5 = new QLabel(para_Set);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        Beta_Spin = new QDoubleSpinBox(para_Set);
        Beta_Spin->setObjectName("Beta_Spin");
        Beta_Spin->setFocusPolicy(Qt::NoFocus);
        Beta_Spin->setMinimum(0.000000000000000);
        Beta_Spin->setMaximum(10.000000000000000);
        Beta_Spin->setSingleStep(0.500000000000000);

        gridLayout->addWidget(Beta_Spin, 3, 1, 1, 1);


        horizontalLayout_3->addWidget(para_Set);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(bottomShowWidget);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 100);
        verticalLayout_4->setStretch(2, 100);

        retranslateUi(ACODemoShowWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ACODemoShowWidget);
    } // setupUi

    void retranslateUi(QWidget *ACODemoShowWidget)
    {
        ACODemoShowWidget->setWindowTitle(QCoreApplication::translate("ACODemoShowWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ACODemoShowWidget", "\350\256\276\347\275\256", nullptr));
        hideProPlotCk->setText(QCoreApplication::translate("ACODemoShowWidget", "\351\232\220\350\227\217\351\227\256\351\242\230\345\233\276\345\203\217", nullptr));
        onlyShowResCk->setText(QCoreApplication::translate("ACODemoShowWidget", "\345\205\250\345\261\217\346\230\276\347\244\272\345\233\276\345\203\217", nullptr));
        hideAverResCk->setText(QCoreApplication::translate("ACODemoShowWidget", "\351\232\220\350\227\217\345\271\263\345\235\207\346\203\205\345\206\265", nullptr));
        clearResBtn->setText(QCoreApplication::translate("ACODemoShowWidget", "\346\270\205\347\251\272\350\277\255\344\273\243\345\233\276\345\203\217", nullptr));
        clearAll->setText(QCoreApplication::translate("ACODemoShowWidget", "\346\270\205\347\251\272\346\211\200\346\234\211", nullptr));
#if QT_CONFIG(accessibility)
        OutputResW->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        tabWidget->setTabText(tabWidget->indexOf(OutputResW), QCoreApplication::translate("ACODemoShowWidget", "\350\276\223\345\207\272\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = recordResTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ACODemoShowWidget", "\350\232\201\347\276\244\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = recordResTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ACODemoShowWidget", "\317\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = recordResTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ACODemoShowWidget", "\316\261", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = recordResTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ACODemoShowWidget", "\316\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = recordResTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ACODemoShowWidget", "Q", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = recordResTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ACODemoShowWidget", "\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = recordResTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ACODemoShowWidget", "\346\234\200\344\274\230\351\200\202\345\272\224\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = recordResTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ACODemoShowWidget", "\346\234\200\344\274\230\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = recordResTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ACODemoShowWidget", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CompResW), QCoreApplication::translate("ACODemoShowWidget", "\347\273\237\350\256\241\347\273\223\346\236\234", nullptr));
        para_Set->setTitle(QCoreApplication::translate("ACODemoShowWidget", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        return_ProMain->setText(QCoreApplication::translate("ACODemoShowWidget", "\350\277\224\345\233\236", nullptr));
        label_6->setText(QCoreApplication::translate("ACODemoShowWidget", "<html><head/><body><p>\344\277\241\346\201\257\347\264\240\345\274\272\345\272\246Q:</p></body></html>", nullptr));
        startAlgo->setText(QCoreApplication::translate("ACODemoShowWidget", "\345\274\200\345\247\213", nullptr));
        label_2->setText(QCoreApplication::translate("ACODemoShowWidget", "\346\214\245\345\217\221\345\233\240\345\255\220\317\201:", nullptr));
        label_3->setText(QCoreApplication::translate("ACODemoShowWidget", "\344\277\241\346\201\257\347\264\240\345\233\240\345\255\220\316\261:", nullptr));
        label->setText(QCoreApplication::translate("ACODemoShowWidget", "\350\232\201\347\276\244\345\244\247\345\260\217:", nullptr));
        label_4->setText(QCoreApplication::translate("ACODemoShowWidget", "\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        label_5->setText(QCoreApplication::translate("ACODemoShowWidget", "<html><head/><body><p>\346\234\237\346\234\233\345\207\275\346\225\260\345\233\240\345\255\220\316\262:</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ACODemoShowWidget: public Ui_ACODemoShowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACODEMOSHOWWIDGET_H
