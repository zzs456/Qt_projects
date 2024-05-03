/********************************************************************************
** Form generated from reading UI file 'func_comp.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNC_COMP_H
#define UI_FUNC_COMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Func_Comp
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_9;
    QWidget *PlotWidget;
    QVBoxLayout *verticalLayout_8;
    QTabWidget *PlotTabWidget;
    QWidget *proPlotWidget;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *proPlot;
    QWidget *resPlotWidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *resPlot;
    QWidget *ResWidget;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *ResTabWidget;
    QWidget *GA_Res;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *GAResTable;
    QWidget *PSO_Res;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *PSOResTable;
    QWidget *ACO_Res;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *ACOResTable;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *clearResBtn;
    QLabel *ShowIterNumsLabel;
    QWidget *ParaWidget;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *ParaTabWidget;
    QWidget *GA_Para;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *cross_Spin;
    QSpinBox *GApopu_Spin;
    QDoubleSpinBox *var_Spin;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *GAiterNums_Spin;
    QLabel *label_2;
    QWidget *PSO_Para;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QSpinBox *PSOpopu_Spin;
    QLabel *label_7;
    QDoubleSpinBox *C1_Spin;
    QLabel *label_11;
    QDoubleSpinBox *C2_Spin;
    QLabel *label_8;
    QDoubleSpinBox *vmax_Spin;
    QLabel *label_9;
    QDoubleSpinBox *winit_Spin;
    QLabel *label_10;
    QDoubleSpinBox *wmin_Spin;
    QLabel *label_5;
    QSpinBox *PSOiterNums_Spin;
    QWidget *ACO_Para;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QSpinBox *ACOpopu_Spin;
    QLabel *label_12;
    QDoubleSpinBox *Rho_Spin;
    QLabel *label_16;
    QDoubleSpinBox *Alpha_Spin;
    QLabel *label_14;
    QDoubleSpinBox *Beta_Spin;
    QLabel *label_17;
    QDoubleSpinBox *Q_Spin;
    QLabel *label_15;
    QSpinBox *ACO_iterNums_Spin;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *returnBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *startDemoBtn;

    void setupUi(QWidget *Func_Comp)
    {
        if (Func_Comp->objectName().isEmpty())
            Func_Comp->setObjectName("Func_Comp");
        Func_Comp->resize(1059, 725);
        horizontalLayout_4 = new QHBoxLayout(Func_Comp);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        PlotWidget = new QWidget(Func_Comp);
        PlotWidget->setObjectName("PlotWidget");
        verticalLayout_8 = new QVBoxLayout(PlotWidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        PlotTabWidget = new QTabWidget(PlotWidget);
        PlotTabWidget->setObjectName("PlotTabWidget");
        QFont font;
        font.setPointSize(14);
        PlotTabWidget->setFont(font);
        proPlotWidget = new QWidget();
        proPlotWidget->setObjectName("proPlotWidget");
        QFont font1;
        font1.setPointSize(12);
        proPlotWidget->setFont(font1);
        horizontalLayout = new QHBoxLayout(proPlotWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        proPlot = new QCustomPlot(proPlotWidget);
        proPlot->setObjectName("proPlot");

        horizontalLayout->addWidget(proPlot);

        PlotTabWidget->addTab(proPlotWidget, QString());
        resPlotWidget = new QWidget();
        resPlotWidget->setObjectName("resPlotWidget");
        verticalLayout = new QVBoxLayout(resPlotWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        resPlot = new QCustomPlot(resPlotWidget);
        resPlot->setObjectName("resPlot");

        verticalLayout->addWidget(resPlot);

        PlotTabWidget->addTab(resPlotWidget, QString());

        verticalLayout_8->addWidget(PlotTabWidget);


        verticalLayout_9->addWidget(PlotWidget);

        ResWidget = new QWidget(Func_Comp);
        ResWidget->setObjectName("ResWidget");
        QFont font2;
        font2.setPointSize(9);
        ResWidget->setFont(font2);
        verticalLayout_6 = new QVBoxLayout(ResWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        ResTabWidget = new QTabWidget(ResWidget);
        ResTabWidget->setObjectName("ResTabWidget");
        ResTabWidget->setFont(font);
        GA_Res = new QWidget();
        GA_Res->setObjectName("GA_Res");
        GA_Res->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(GA_Res);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        GAResTable = new QTableWidget(GA_Res);
        if (GAResTable->columnCount() < 7)
            GAResTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        GAResTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        GAResTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        GAResTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        GAResTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        GAResTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        GAResTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        GAResTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        GAResTable->setObjectName("GAResTable");

        verticalLayout_3->addWidget(GAResTable);

        ResTabWidget->addTab(GA_Res, QString());
        PSO_Res = new QWidget();
        PSO_Res->setObjectName("PSO_Res");
        PSO_Res->setFont(font1);
        verticalLayout_4 = new QVBoxLayout(PSO_Res);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        PSOResTable = new QTableWidget(PSO_Res);
        if (PSOResTable->columnCount() < 10)
            PSOResTable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        PSOResTable->setHorizontalHeaderItem(9, __qtablewidgetitem16);
        PSOResTable->setObjectName("PSOResTable");
        PSOResTable->setFont(font1);

        verticalLayout_4->addWidget(PSOResTable);

        ResTabWidget->addTab(PSO_Res, QString());
        ACO_Res = new QWidget();
        ACO_Res->setObjectName("ACO_Res");
        ACO_Res->setFont(font1);
        verticalLayout_5 = new QVBoxLayout(ACO_Res);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        ACOResTable = new QTableWidget(ACO_Res);
        if (ACOResTable->columnCount() < 9)
            ACOResTable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        ACOResTable->setHorizontalHeaderItem(8, __qtablewidgetitem25);
        ACOResTable->setObjectName("ACOResTable");
        ACOResTable->setFont(font1);

        verticalLayout_5->addWidget(ACOResTable);

        ResTabWidget->addTab(ACO_Res, QString());

        verticalLayout_6->addWidget(ResTabWidget);


        verticalLayout_9->addWidget(ResWidget);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        clearResBtn = new QPushButton(Func_Comp);
        clearResBtn->setObjectName("clearResBtn");
        clearResBtn->setFont(font);

        horizontalLayout_3->addWidget(clearResBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        ShowIterNumsLabel = new QLabel(Func_Comp);
        ShowIterNumsLabel->setObjectName("ShowIterNumsLabel");
        QFont font3;
        font3.setPointSize(16);
        ShowIterNumsLabel->setFont(font3);
        ShowIterNumsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ShowIterNumsLabel);

        ParaWidget = new QWidget(Func_Comp);
        ParaWidget->setObjectName("ParaWidget");
        verticalLayout_7 = new QVBoxLayout(ParaWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        ParaTabWidget = new QTabWidget(ParaWidget);
        ParaTabWidget->setObjectName("ParaTabWidget");
        ParaTabWidget->setFont(font);
        GA_Para = new QWidget();
        GA_Para->setObjectName("GA_Para");
        GA_Para->setFont(font3);
        gridLayout = new QGridLayout(GA_Para);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(GA_Para);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cross_Spin = new QDoubleSpinBox(GA_Para);
        cross_Spin->setObjectName("cross_Spin");
        cross_Spin->setFocusPolicy(Qt::NoFocus);
        cross_Spin->setKeyboardTracking(true);
        cross_Spin->setMinimum(0.000000000000000);
        cross_Spin->setMaximum(0.900000000000000);
        cross_Spin->setSingleStep(0.050000000000000);

        gridLayout->addWidget(cross_Spin, 1, 1, 1, 1);

        GApopu_Spin = new QSpinBox(GA_Para);
        GApopu_Spin->setObjectName("GApopu_Spin");
        GApopu_Spin->setFocusPolicy(Qt::NoFocus);
        GApopu_Spin->setReadOnly(false);
        GApopu_Spin->setKeyboardTracking(false);
        GApopu_Spin->setMinimum(5);
        GApopu_Spin->setMaximum(100);
        GApopu_Spin->setSingleStep(5);

        gridLayout->addWidget(GApopu_Spin, 0, 1, 1, 1);

        var_Spin = new QDoubleSpinBox(GA_Para);
        var_Spin->setObjectName("var_Spin");
        var_Spin->setFocusPolicy(Qt::NoFocus);
        var_Spin->setKeyboardTracking(true);
        var_Spin->setMinimum(0.000000000000000);
        var_Spin->setMaximum(0.100000000000000);
        var_Spin->setSingleStep(0.010000000000000);

        gridLayout->addWidget(var_Spin, 2, 1, 1, 1);

        label_4 = new QLabel(GA_Para);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(GA_Para);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        GAiterNums_Spin = new QSpinBox(GA_Para);
        GAiterNums_Spin->setObjectName("GAiterNums_Spin");
        GAiterNums_Spin->setFocusPolicy(Qt::NoFocus);
        GAiterNums_Spin->setKeyboardTracking(true);
        GAiterNums_Spin->setMinimum(50);
        GAiterNums_Spin->setMaximum(400);
        GAiterNums_Spin->setSingleStep(10);

        gridLayout->addWidget(GAiterNums_Spin, 3, 1, 1, 1);

        label_2 = new QLabel(GA_Para);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        ParaTabWidget->addTab(GA_Para, QString());
        PSO_Para = new QWidget();
        PSO_Para->setObjectName("PSO_Para");
        PSO_Para->setFont(font);
        gridLayout_2 = new QGridLayout(PSO_Para);
        gridLayout_2->setObjectName("gridLayout_2");
        label_6 = new QLabel(PSO_Para);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        PSOpopu_Spin = new QSpinBox(PSO_Para);
        PSOpopu_Spin->setObjectName("PSOpopu_Spin");
        PSOpopu_Spin->setFocusPolicy(Qt::NoFocus);
        PSOpopu_Spin->setMinimum(5);
        PSOpopu_Spin->setSingleStep(5);

        gridLayout_2->addWidget(PSOpopu_Spin, 0, 1, 1, 1);

        label_7 = new QLabel(PSO_Para);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        C1_Spin = new QDoubleSpinBox(PSO_Para);
        C1_Spin->setObjectName("C1_Spin");
        C1_Spin->setFocusPolicy(Qt::NoFocus);
        C1_Spin->setMinimum(0.000000000000000);
        C1_Spin->setMaximum(4.000000000000000);
        C1_Spin->setSingleStep(0.050000000000000);

        gridLayout_2->addWidget(C1_Spin, 1, 1, 1, 1);

        label_11 = new QLabel(PSO_Para);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        C2_Spin = new QDoubleSpinBox(PSO_Para);
        C2_Spin->setObjectName("C2_Spin");
        C2_Spin->setFocusPolicy(Qt::NoFocus);
        C2_Spin->setMinimum(0.000000000000000);
        C2_Spin->setMaximum(4.000000000000000);
        C2_Spin->setSingleStep(0.050000000000000);

        gridLayout_2->addWidget(C2_Spin, 2, 1, 1, 1);

        label_8 = new QLabel(PSO_Para);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        vmax_Spin = new QDoubleSpinBox(PSO_Para);
        vmax_Spin->setObjectName("vmax_Spin");
        vmax_Spin->setFocusPolicy(Qt::NoFocus);
        vmax_Spin->setDecimals(3);
        vmax_Spin->setMinimum(0.005000000000000);
        vmax_Spin->setMaximum(0.500000000000000);
        vmax_Spin->setSingleStep(0.005000000000000);

        gridLayout_2->addWidget(vmax_Spin, 3, 1, 1, 1);

        label_9 = new QLabel(PSO_Para);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 4, 0, 1, 1);

        winit_Spin = new QDoubleSpinBox(PSO_Para);
        winit_Spin->setObjectName("winit_Spin");
        winit_Spin->setFocusPolicy(Qt::NoFocus);
        winit_Spin->setMinimum(0.600000000000000);
        winit_Spin->setMaximum(1.000000000000000);
        winit_Spin->setSingleStep(0.050000000000000);

        gridLayout_2->addWidget(winit_Spin, 4, 1, 1, 1);

        label_10 = new QLabel(PSO_Para);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 5, 0, 1, 1);

        wmin_Spin = new QDoubleSpinBox(PSO_Para);
        wmin_Spin->setObjectName("wmin_Spin");
        wmin_Spin->setFocusPolicy(Qt::NoFocus);
        wmin_Spin->setMinimum(0.400000000000000);
        wmin_Spin->setMaximum(0.600000000000000);
        wmin_Spin->setSingleStep(0.050000000000000);

        gridLayout_2->addWidget(wmin_Spin, 5, 1, 1, 1);

        label_5 = new QLabel(PSO_Para);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 6, 0, 1, 1);

        PSOiterNums_Spin = new QSpinBox(PSO_Para);
        PSOiterNums_Spin->setObjectName("PSOiterNums_Spin");
        PSOiterNums_Spin->setFocusPolicy(Qt::NoFocus);
        PSOiterNums_Spin->setMinimum(50);
        PSOiterNums_Spin->setMaximum(400);
        PSOiterNums_Spin->setSingleStep(10);

        gridLayout_2->addWidget(PSOiterNums_Spin, 6, 1, 1, 1);

        ParaTabWidget->addTab(PSO_Para, QString());
        ACO_Para = new QWidget();
        ACO_Para->setObjectName("ACO_Para");
        ACO_Para->setFont(font);
        gridLayout_3 = new QGridLayout(ACO_Para);
        gridLayout_3->setObjectName("gridLayout_3");
        label_13 = new QLabel(ACO_Para);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        ACOpopu_Spin = new QSpinBox(ACO_Para);
        ACOpopu_Spin->setObjectName("ACOpopu_Spin");
        ACOpopu_Spin->setFocusPolicy(Qt::NoFocus);
        ACOpopu_Spin->setMinimum(5);
        ACOpopu_Spin->setMaximum(40);
        ACOpopu_Spin->setSingleStep(5);

        gridLayout_3->addWidget(ACOpopu_Spin, 0, 1, 1, 1);

        label_12 = new QLabel(ACO_Para);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        Rho_Spin = new QDoubleSpinBox(ACO_Para);
        Rho_Spin->setObjectName("Rho_Spin");
        Rho_Spin->setFocusPolicy(Qt::NoFocus);
        Rho_Spin->setMinimum(0.100000000000000);
        Rho_Spin->setMaximum(0.900000000000000);
        Rho_Spin->setSingleStep(0.050000000000000);

        gridLayout_3->addWidget(Rho_Spin, 1, 1, 1, 1);

        label_16 = new QLabel(ACO_Para);
        label_16->setObjectName("label_16");
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        Alpha_Spin = new QDoubleSpinBox(ACO_Para);
        Alpha_Spin->setObjectName("Alpha_Spin");
        Alpha_Spin->setFocusPolicy(Qt::NoFocus);
        Alpha_Spin->setMinimum(0.000000000000000);
        Alpha_Spin->setMaximum(10.000000000000000);
        Alpha_Spin->setSingleStep(0.500000000000000);

        gridLayout_3->addWidget(Alpha_Spin, 2, 1, 1, 1);

        label_14 = new QLabel(ACO_Para);
        label_14->setObjectName("label_14");
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_14, 3, 0, 1, 1);

        Beta_Spin = new QDoubleSpinBox(ACO_Para);
        Beta_Spin->setObjectName("Beta_Spin");
        Beta_Spin->setFocusPolicy(Qt::NoFocus);
        Beta_Spin->setMinimum(0.000000000000000);
        Beta_Spin->setMaximum(10.000000000000000);
        Beta_Spin->setSingleStep(0.500000000000000);

        gridLayout_3->addWidget(Beta_Spin, 3, 1, 1, 1);

        label_17 = new QLabel(ACO_Para);
        label_17->setObjectName("label_17");
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_17, 4, 0, 1, 1);

        Q_Spin = new QDoubleSpinBox(ACO_Para);
        Q_Spin->setObjectName("Q_Spin");
        Q_Spin->setFocusPolicy(Qt::NoFocus);
        Q_Spin->setMinimum(0.100000000000000);
        Q_Spin->setMaximum(0.900000000000000);
        Q_Spin->setSingleStep(0.050000000000000);

        gridLayout_3->addWidget(Q_Spin, 4, 1, 1, 1);

        label_15 = new QLabel(ACO_Para);
        label_15->setObjectName("label_15");
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_15, 5, 0, 1, 1);

        ACO_iterNums_Spin = new QSpinBox(ACO_Para);
        ACO_iterNums_Spin->setObjectName("ACO_iterNums_Spin");
        ACO_iterNums_Spin->setFocusPolicy(Qt::NoFocus);
        ACO_iterNums_Spin->setMinimum(50);
        ACO_iterNums_Spin->setMaximum(400);
        ACO_iterNums_Spin->setSingleStep(10);

        gridLayout_3->addWidget(ACO_iterNums_Spin, 5, 1, 1, 1);

        ParaTabWidget->addTab(ACO_Para, QString());

        verticalLayout_7->addWidget(ParaTabWidget);


        verticalLayout_2->addWidget(ParaWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        returnBtn = new QPushButton(Func_Comp);
        returnBtn->setObjectName("returnBtn");
        returnBtn->setFont(font3);

        horizontalLayout_2->addWidget(returnBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        startDemoBtn = new QPushButton(Func_Comp);
        startDemoBtn->setObjectName("startDemoBtn");
        startDemoBtn->setFont(font3);

        horizontalLayout_2->addWidget(startDemoBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 20);
        verticalLayout_2->setStretch(2, 100);
        verticalLayout_2->setStretch(3, 1);

        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);

        retranslateUi(Func_Comp);

        PlotTabWidget->setCurrentIndex(0);
        ResTabWidget->setCurrentIndex(2);
        ParaTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Func_Comp);
    } // setupUi

    void retranslateUi(QWidget *Func_Comp)
    {
        Func_Comp->setWindowTitle(QCoreApplication::translate("Func_Comp", "Form", nullptr));
        PlotTabWidget->setTabText(PlotTabWidget->indexOf(proPlotWidget), QCoreApplication::translate("Func_Comp", "\351\227\256\351\242\230", nullptr));
        PlotTabWidget->setTabText(PlotTabWidget->indexOf(resPlotWidget), QCoreApplication::translate("Func_Comp", "\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = GAResTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Func_Comp", "\346\233\262\347\272\277id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = GAResTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Func_Comp", "\347\247\215\347\276\244\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = GAResTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Func_Comp", "\344\272\244\345\217\211\346\246\202\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = GAResTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Func_Comp", "\345\217\230\345\274\202\346\246\202\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = GAResTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Func_Comp", "\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = GAResTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Func_Comp", "\346\234\200\344\274\230\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = GAResTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Func_Comp", "\346\230\257\345\220\246\346\230\276\347\244\272", nullptr));
        ResTabWidget->setTabText(ResTabWidget->indexOf(GA_Res), QCoreApplication::translate("Func_Comp", "\351\201\227\344\274\240", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = PSOResTable->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Func_Comp", "\346\233\262\347\272\277id", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = PSOResTable->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Func_Comp", "\347\247\215\347\276\244\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = PSOResTable->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Func_Comp", "C1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = PSOResTable->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Func_Comp", "C2", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = PSOResTable->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Func_Comp", "Vmax", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = PSOResTable->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Func_Comp", "W0", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = PSOResTable->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Func_Comp", "Wmin", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = PSOResTable->horizontalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Func_Comp", "\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = PSOResTable->horizontalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Func_Comp", "\346\234\200\344\274\230\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = PSOResTable->horizontalHeaderItem(9);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Func_Comp", "\346\230\257\345\220\246\346\230\276\347\244\272", nullptr));
        ResTabWidget->setTabText(ResTabWidget->indexOf(PSO_Res), QCoreApplication::translate("Func_Comp", "\347\262\222\345\255\220\347\276\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = ACOResTable->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Func_Comp", "\346\233\262\347\272\277id", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = ACOResTable->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Func_Comp", "\350\232\201\347\276\244\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = ACOResTable->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Func_Comp", "\317\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = ACOResTable->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Func_Comp", "\316\261", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = ACOResTable->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Func_Comp", "\316\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = ACOResTable->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Func_Comp", "Q", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = ACOResTable->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Func_Comp", "\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = ACOResTable->horizontalHeaderItem(7);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Func_Comp", "\346\234\200\344\274\230\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = ACOResTable->horizontalHeaderItem(8);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Func_Comp", "\346\230\257\345\220\246\346\230\276\347\244\272", nullptr));
        ResTabWidget->setTabText(ResTabWidget->indexOf(ACO_Res), QCoreApplication::translate("Func_Comp", "\350\232\201\347\276\244", nullptr));
        clearResBtn->setText(QCoreApplication::translate("Func_Comp", "\346\270\205\347\251\272", nullptr));
        ShowIterNumsLabel->setText(QString());
        label->setText(QCoreApplication::translate("Func_Comp", "\347\247\215\347\276\244\345\244\247\345\260\217:", nullptr));
        label_4->setText(QCoreApplication::translate("Func_Comp", "\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        label_3->setText(QCoreApplication::translate("Func_Comp", "\345\217\230\345\274\202\346\246\202\347\216\207:", nullptr));
        label_2->setText(QCoreApplication::translate("Func_Comp", "\344\272\244\345\217\211\346\205\250\347\216\207:", nullptr));
        ParaTabWidget->setTabText(ParaTabWidget->indexOf(GA_Para), QCoreApplication::translate("Func_Comp", "\351\201\227\344\274\240", nullptr));
        label_6->setText(QCoreApplication::translate("Func_Comp", "\347\247\215\347\276\244\345\244\247\345\260\217:", nullptr));
        label_7->setText(QCoreApplication::translate("Func_Comp", "\345\255\246\344\271\240\345\233\240\345\255\220C1:", nullptr));
        label_11->setText(QCoreApplication::translate("Func_Comp", "\345\255\246\344\271\240\345\233\240\345\255\220C2:", nullptr));
        label_8->setText(QCoreApplication::translate("Func_Comp", "<html><head/><body><p>|V<span style=\" vertical-align:sub;\">max</span>|:</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Func_Comp", "<html><head/><body><p>W<span style=\" vertical-align:sub;\">0</span>:</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("Func_Comp", "<html><head/><body><p>W<span style=\" vertical-align:sub;\">min</span>:</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Func_Comp", "\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        ParaTabWidget->setTabText(ParaTabWidget->indexOf(PSO_Para), QCoreApplication::translate("Func_Comp", "\347\262\222\345\255\220\347\276\244", nullptr));
        label_13->setText(QCoreApplication::translate("Func_Comp", "\350\232\201\347\276\244\345\244\247\345\260\217:", nullptr));
        label_12->setText(QCoreApplication::translate("Func_Comp", "\346\214\245\345\217\221\345\233\240\345\255\220\317\201:", nullptr));
        label_16->setText(QCoreApplication::translate("Func_Comp", "\344\277\241\346\201\257\347\264\240\345\233\240\345\255\220\316\261:", nullptr));
        label_14->setText(QCoreApplication::translate("Func_Comp", "<html><head/><body><p>\346\234\237\346\234\233\345\207\275\346\225\260\345\233\240\345\255\220\316\262:</p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("Func_Comp", "<html><head/><body><p>\345\214\272\351\227\264\347\274\251\345\260\217\345\233\240\345\255\220Q:</p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("Func_Comp", "\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        ParaTabWidget->setTabText(ParaTabWidget->indexOf(ACO_Para), QCoreApplication::translate("Func_Comp", "\350\232\201\347\276\244", nullptr));
        returnBtn->setText(QCoreApplication::translate("Func_Comp", "\350\277\224\345\233\236", nullptr));
        startDemoBtn->setText(QCoreApplication::translate("Func_Comp", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Func_Comp: public Ui_Func_Comp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNC_COMP_H
