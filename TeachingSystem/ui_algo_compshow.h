/********************************************************************************
** Form generated from reading UI file 'algo_compshow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALGO_COMPSHOW_H
#define UI_ALGO_COMPSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Algo_CompShow
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *AlgoCompW;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QWidget *FuncCompInfoW;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *trigoFuncAccu;
    QLabel *trigoFuncDomain;
    QLabel *trigoFuncName;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QCustomPlot *trigoFuncPlot;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *FuncStartDemo;
    QWidget *TspCompInfoW;
    QVBoxLayout *verticalLayout_3;
    QWidget *TspPointDatasTab;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget;
    QCustomPlot *thirtyTspPlot;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *TspStartDemo;

    void setupUi(QWidget *Algo_CompShow)
    {
        if (Algo_CompShow->objectName().isEmpty())
            Algo_CompShow->setObjectName("Algo_CompShow");
        Algo_CompShow->resize(1013, 730);
        verticalLayout = new QVBoxLayout(Algo_CompShow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Algo_CompShow);
        stackedWidget->setObjectName("stackedWidget");
        AlgoCompW = new QWidget();
        AlgoCompW->setObjectName("AlgoCompW");
        verticalLayout_4 = new QVBoxLayout(AlgoCompW);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(AlgoCompW);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        stackedWidget->addWidget(AlgoCompW);
        FuncCompInfoW = new QWidget();
        FuncCompInfoW->setObjectName("FuncCompInfoW");
        verticalLayout_2 = new QVBoxLayout(FuncCompInfoW);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 20, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(20);
        gridLayout_2->setObjectName("gridLayout_2");
        trigoFuncAccu = new QLabel(FuncCompInfoW);
        trigoFuncAccu->setObjectName("trigoFuncAccu");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(12);
        trigoFuncAccu->setFont(font1);

        gridLayout_2->addWidget(trigoFuncAccu, 2, 1, 1, 1);

        trigoFuncDomain = new QLabel(FuncCompInfoW);
        trigoFuncDomain->setObjectName("trigoFuncDomain");
        trigoFuncDomain->setFont(font1);

        gridLayout_2->addWidget(trigoFuncDomain, 1, 1, 1, 1);

        trigoFuncName = new QLabel(FuncCompInfoW);
        trigoFuncName->setObjectName("trigoFuncName");
        QFont font2;
        font2.setPointSize(12);
        trigoFuncName->setFont(font2);

        gridLayout_2->addWidget(trigoFuncName, 0, 1, 1, 1);

        label_6 = new QLabel(FuncCompInfoW);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_4 = new QLabel(FuncCompInfoW);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(FuncCompInfoW);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        trigoFuncPlot = new QCustomPlot(FuncCompInfoW);
        trigoFuncPlot->setObjectName("trigoFuncPlot");

        verticalLayout_2->addWidget(trigoFuncPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        FuncStartDemo = new QPushButton(FuncCompInfoW);
        FuncStartDemo->setObjectName("FuncStartDemo");
        FuncStartDemo->setFont(font2);

        horizontalLayout->addWidget(FuncStartDemo);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 100);
        verticalLayout_2->setStretch(2, 1);
        stackedWidget->addWidget(FuncCompInfoW);
        TspCompInfoW = new QWidget();
        TspCompInfoW->setObjectName("TspCompInfoW");
        verticalLayout_3 = new QVBoxLayout(TspCompInfoW);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        TspPointDatasTab = new QWidget(TspCompInfoW);
        TspPointDatasTab->setObjectName("TspPointDatasTab");
        horizontalLayout_3 = new QHBoxLayout(TspPointDatasTab);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(TspPointDatasTab);
        if (tableWidget->columnCount() < 31)
            tableWidget->setColumnCount(31);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 9, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 10, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 11, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 12, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 13, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 14, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(0, 15, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(0, 16, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(0, 17, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(0, 18, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(0, 19, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(0, 20, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(0, 21, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(0, 22, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(0, 23, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(0, 24, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(0, 25, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(0, 26, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(0, 27, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(0, 28, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(0, 29, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(0, 30, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(1, 8, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(1, 9, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(1, 10, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(1, 11, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(1, 12, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setItem(1, 13, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setItem(1, 14, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setItem(1, 15, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setItem(1, 16, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setItem(1, 17, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setItem(1, 18, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setItem(1, 19, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget->setItem(1, 20, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget->setItem(1, 21, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget->setItem(1, 22, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget->setItem(1, 23, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget->setItem(1, 24, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget->setItem(1, 25, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget->setItem(1, 26, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget->setItem(1, 27, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget->setItem(1, 28, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget->setItem(1, 29, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget->setItem(1, 30, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget->setItem(2, 6, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget->setItem(2, 7, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget->setItem(2, 8, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget->setItem(2, 9, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget->setItem(2, 10, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget->setItem(2, 11, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget->setItem(2, 12, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget->setItem(2, 13, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget->setItem(2, 14, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget->setItem(2, 15, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget->setItem(2, 16, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget->setItem(2, 17, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget->setItem(2, 18, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget->setItem(2, 19, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget->setItem(2, 20, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget->setItem(2, 21, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget->setItem(2, 22, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget->setItem(2, 23, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget->setItem(2, 24, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget->setItem(2, 25, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        tableWidget->setItem(2, 26, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        tableWidget->setItem(2, 27, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        tableWidget->setItem(2, 28, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableWidget->setItem(2, 29, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        tableWidget->setItem(2, 30, __qtablewidgetitem95);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->horizontalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(tableWidget);


        verticalLayout_3->addWidget(TspPointDatasTab);

        thirtyTspPlot = new QCustomPlot(TspCompInfoW);
        thirtyTspPlot->setObjectName("thirtyTspPlot");

        verticalLayout_3->addWidget(thirtyTspPlot);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        TspStartDemo = new QPushButton(TspCompInfoW);
        TspStartDemo->setObjectName("TspStartDemo");
        TspStartDemo->setFont(font2);

        horizontalLayout_2->addWidget(TspStartDemo);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 40);
        verticalLayout_3->setStretch(1, 120);
        verticalLayout_3->setStretch(2, 1);
        stackedWidget->addWidget(TspCompInfoW);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Algo_CompShow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Algo_CompShow);
    } // setupUi

    void retranslateUi(QWidget *Algo_CompShow)
    {
        Algo_CompShow->setWindowTitle(QCoreApplication::translate("Algo_CompShow", "Form", nullptr));
        label->setText(QCoreApplication::translate("Algo_CompShow", "\347\202\271\345\207\273\345\255\220\351\241\271\345\257\271\346\257\224\347\256\227\346\263\225\346\200\247\350\203\275", nullptr));
        trigoFuncAccu->setText(QCoreApplication::translate("Algo_CompShow", "0.001", nullptr));
        trigoFuncDomain->setText(QCoreApplication::translate("Algo_CompShow", "[0,1]", nullptr));
        trigoFuncName->setText(QCoreApplication::translate("Algo_CompShow", "y = xcos(4x)+xsin(20x)+2", nullptr));
        label_6->setText(QCoreApplication::translate("Algo_CompShow", "\347\262\276\345\272\246  :", nullptr));
        label_4->setText(QCoreApplication::translate("Algo_CompShow", "\345\207\275\346\225\260  :", nullptr));
        label_5->setText(QCoreApplication::translate("Algo_CompShow", "\345\256\232\344\271\211\345\237\237  :", nullptr));
        FuncStartDemo->setText(QCoreApplication::translate("Algo_CompShow", "\345\274\200\345\247\213\346\274\224\347\244\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Algo_CompShow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Algo_CompShow", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Algo_CompShow", "y", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Algo_CompShow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Algo_CompShow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Algo_CompShow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Algo_CompShow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 4);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Algo_CompShow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 5);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Algo_CompShow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 6);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Algo_CompShow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 7);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Algo_CompShow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 8);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Algo_CompShow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 9);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Algo_CompShow", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 10);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Algo_CompShow", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 11);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Algo_CompShow", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 12);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Algo_CompShow", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(0, 13);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Algo_CompShow", "14", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(0, 14);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Algo_CompShow", "15", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(0, 15);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Algo_CompShow", "16", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(0, 16);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Algo_CompShow", "17", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(0, 17);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Algo_CompShow", "18", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(0, 18);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Algo_CompShow", "19", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(0, 19);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Algo_CompShow", "20", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(0, 20);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Algo_CompShow", "21", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(0, 21);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Algo_CompShow", "22", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(0, 22);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Algo_CompShow", "23", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(0, 23);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Algo_CompShow", "24", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(0, 24);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Algo_CompShow", "25", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(0, 25);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Algo_CompShow", "26", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(0, 26);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("Algo_CompShow", "27", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(0, 27);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("Algo_CompShow", "28", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(0, 28);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("Algo_CompShow", "29", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(0, 29);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("Algo_CompShow", "30", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(0, 30);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("Algo_CompShow", "31", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(1, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("Algo_CompShow", "1304", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(1, 1);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("Algo_CompShow", "3639", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(1, 2);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("Algo_CompShow", "4177", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(1, 3);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("Algo_CompShow", "3712", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(1, 4);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("Algo_CompShow", "3488", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(1, 5);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("Algo_CompShow", "2381", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(1, 6);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("Algo_CompShow", "1332", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(1, 7);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("Algo_CompShow", "3715", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(1, 8);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("Algo_CompShow", "3326", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(1, 9);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("Algo_CompShow", "3238", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(1, 10);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("Algo_CompShow", "4196", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(1, 11);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("Algo_CompShow", "4312", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(1, 12);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("Algo_CompShow", "4386", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(1, 13);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("Algo_CompShow", "3007", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(1, 14);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("Algo_CompShow", "3918", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->item(1, 15);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("Algo_CompShow", "4061", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->item(1, 16);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("Algo_CompShow", "4263", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->item(1, 17);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("Algo_CompShow", "3429", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->item(1, 18);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("Algo_CompShow", "3507", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->item(1, 19);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("Algo_CompShow", "3780", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->item(1, 20);
        ___qtablewidgetitem54->setText(QCoreApplication::translate("Algo_CompShow", "3676", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->item(1, 21);
        ___qtablewidgetitem55->setText(QCoreApplication::translate("Algo_CompShow", "4029", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget->item(1, 22);
        ___qtablewidgetitem56->setText(QCoreApplication::translate("Algo_CompShow", "2562", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget->item(1, 23);
        ___qtablewidgetitem57->setText(QCoreApplication::translate("Algo_CompShow", "2788", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget->item(1, 24);
        ___qtablewidgetitem58->setText(QCoreApplication::translate("Algo_CompShow", "3394", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget->item(1, 25);
        ___qtablewidgetitem59->setText(QCoreApplication::translate("Algo_CompShow", "3439", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget->item(1, 26);
        ___qtablewidgetitem60->setText(QCoreApplication::translate("Algo_CompShow", "2935", nullptr));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget->item(1, 27);
        ___qtablewidgetitem61->setText(QCoreApplication::translate("Algo_CompShow", "2778", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget->item(1, 28);
        ___qtablewidgetitem62->setText(QCoreApplication::translate("Algo_CompShow", "2370", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget->item(1, 29);
        ___qtablewidgetitem63->setText(QCoreApplication::translate("Algo_CompShow", "3140", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget->item(1, 30);
        ___qtablewidgetitem64->setText(QCoreApplication::translate("Algo_CompShow", "2545", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget->item(2, 0);
        ___qtablewidgetitem65->setText(QCoreApplication::translate("Algo_CompShow", "2312", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget->item(2, 1);
        ___qtablewidgetitem66->setText(QCoreApplication::translate("Algo_CompShow", "1315", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget->item(2, 2);
        ___qtablewidgetitem67->setText(QCoreApplication::translate("Algo_CompShow", "2244", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget->item(2, 3);
        ___qtablewidgetitem68->setText(QCoreApplication::translate("Algo_CompShow", "1399", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget->item(2, 4);
        ___qtablewidgetitem69->setText(QCoreApplication::translate("Algo_CompShow", "1535", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget->item(2, 5);
        ___qtablewidgetitem70->setText(QCoreApplication::translate("Algo_CompShow", "1676", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget->item(2, 6);
        ___qtablewidgetitem71->setText(QCoreApplication::translate("Algo_CompShow", "695", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget->item(2, 7);
        ___qtablewidgetitem72->setText(QCoreApplication::translate("Algo_CompShow", "1678", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget->item(2, 8);
        ___qtablewidgetitem73->setText(QCoreApplication::translate("Algo_CompShow", "1556", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget->item(2, 9);
        ___qtablewidgetitem74->setText(QCoreApplication::translate("Algo_CompShow", "1229", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget->item(2, 10);
        ___qtablewidgetitem75->setText(QCoreApplication::translate("Algo_CompShow", "1004", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget->item(2, 11);
        ___qtablewidgetitem76->setText(QCoreApplication::translate("Algo_CompShow", "790", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget->item(2, 12);
        ___qtablewidgetitem77->setText(QCoreApplication::translate("Algo_CompShow", "570", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget->item(2, 13);
        ___qtablewidgetitem78->setText(QCoreApplication::translate("Algo_CompShow", "1970", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget->item(2, 14);
        ___qtablewidgetitem79->setText(QCoreApplication::translate("Algo_CompShow", "2179", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget->item(2, 15);
        ___qtablewidgetitem80->setText(QCoreApplication::translate("Algo_CompShow", "2370", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget->item(2, 16);
        ___qtablewidgetitem81->setText(QCoreApplication::translate("Algo_CompShow", "2931", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget->item(2, 17);
        ___qtablewidgetitem82->setText(QCoreApplication::translate("Algo_CompShow", "1908", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget->item(2, 18);
        ___qtablewidgetitem83->setText(QCoreApplication::translate("Algo_CompShow", "2367", nullptr));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget->item(2, 19);
        ___qtablewidgetitem84->setText(QCoreApplication::translate("Algo_CompShow", "2212", nullptr));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget->item(2, 20);
        ___qtablewidgetitem85->setText(QCoreApplication::translate("Algo_CompShow", "2578", nullptr));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget->item(2, 21);
        ___qtablewidgetitem86->setText(QCoreApplication::translate("Algo_CompShow", "2838", nullptr));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget->item(2, 22);
        ___qtablewidgetitem87->setText(QCoreApplication::translate("Algo_CompShow", "1756", nullptr));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget->item(2, 23);
        ___qtablewidgetitem88->setText(QCoreApplication::translate("Algo_CompShow", "1491", nullptr));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget->item(2, 24);
        ___qtablewidgetitem89->setText(QCoreApplication::translate("Algo_CompShow", "2643", nullptr));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget->item(2, 25);
        ___qtablewidgetitem90->setText(QCoreApplication::translate("Algo_CompShow", "3201", nullptr));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget->item(2, 26);
        ___qtablewidgetitem91->setText(QCoreApplication::translate("Algo_CompShow", "3240", nullptr));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget->item(2, 27);
        ___qtablewidgetitem92->setText(QCoreApplication::translate("Algo_CompShow", "2826", nullptr));
        QTableWidgetItem *___qtablewidgetitem93 = tableWidget->item(2, 28);
        ___qtablewidgetitem93->setText(QCoreApplication::translate("Algo_CompShow", "2975", nullptr));
        QTableWidgetItem *___qtablewidgetitem94 = tableWidget->item(2, 29);
        ___qtablewidgetitem94->setText(QCoreApplication::translate("Algo_CompShow", "3550", nullptr));
        QTableWidgetItem *___qtablewidgetitem95 = tableWidget->item(2, 30);
        ___qtablewidgetitem95->setText(QCoreApplication::translate("Algo_CompShow", "2357", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        TspStartDemo->setText(QCoreApplication::translate("Algo_CompShow", "\345\274\200\345\247\213\346\274\224\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Algo_CompShow: public Ui_Algo_CompShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGO_COMPSHOW_H
