/********************************************************************************
** Form generated from reading UI file 'bpprowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BPPROWIDGET_H
#define UI_BPPROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BpProWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QTreeWidget *bp_treeWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *bp_stackedWidget;
    QWidget *GABpIntroW;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QWidget *SevenBpW;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QTableWidget *sevenBpTableW;
    QWidget *ThirtyBpW;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QTableWidget *thirtyBpTableW;
    QWidget *UserDefBpW;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *thingNums;
    QLabel *label_3;
    QSpinBox *totalWeight;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_15;
    QTableWidget *defBpTableW;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startDemo;

    void setupUi(QWidget *BpProWidget)
    {
        if (BpProWidget->objectName().isEmpty())
            BpProWidget->setObjectName("BpProWidget");
        BpProWidget->resize(954, 651);
        verticalLayout_2 = new QVBoxLayout(BpProWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(BpProWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        bp_treeWidget = new QTreeWidget(splitter);
        QFont font;
        font.setPointSize(12);
        QFont font1;
        font1.setPointSize(10);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(bp_treeWidget);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(bp_treeWidget);
        __qtreewidgetitem3->setFont(0, font);
        bp_treeWidget->setObjectName("bp_treeWidget");
        bp_treeWidget->setMinimumSize(QSize(300, 0));
        bp_treeWidget->setMaximumSize(QSize(300, 16777215));
        bp_treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget#bp_treeWidget {\n"
"	border: none;\n"
"}\n"
"QTreeWidget#bp_treeWidget::item{\n"
"	height: 32px;\n"
"}"));
        bp_treeWidget->setHeaderHidden(true);
        splitter->addWidget(bp_treeWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bp_stackedWidget = new QStackedWidget(layoutWidget);
        bp_stackedWidget->setObjectName("bp_stackedWidget");
        GABpIntroW = new QWidget();
        GABpIntroW->setObjectName("GABpIntroW");
        verticalLayout_4 = new QVBoxLayout(GABpIntroW);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(GABpIntroW);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        bp_stackedWidget->addWidget(GABpIntroW);
        SevenBpW = new QWidget();
        SevenBpW->setObjectName("SevenBpW");
        verticalLayout_5 = new QVBoxLayout(SevenBpW);
        verticalLayout_5->setSpacing(40);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 20, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(SevenBpW);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_6 = new QLabel(SevenBpW);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);

        label_5 = new QLabel(SevenBpW);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        label_7 = new QLabel(SevenBpW);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        sevenBpTableW = new QTableWidget(SevenBpW);
        if (sevenBpTableW->columnCount() < 3)
            sevenBpTableW->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        sevenBpTableW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        sevenBpTableW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        sevenBpTableW->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        sevenBpTableW->setObjectName("sevenBpTableW");
        sevenBpTableW->setStyleSheet(QString::fromUtf8("QTableWidget#sevenTableW{\n"
"	border:0;\n"
"}"));
        sevenBpTableW->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(sevenBpTableW);

        bp_stackedWidget->addWidget(SevenBpW);
        ThirtyBpW = new QWidget();
        ThirtyBpW->setObjectName("ThirtyBpW");
        verticalLayout_6 = new QVBoxLayout(ThirtyBpW);
        verticalLayout_6->setSpacing(40);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 20, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        label_8 = new QLabel(ThirtyBpW);
        label_8->setObjectName("label_8");
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(ThirtyBpW);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        gridLayout_3->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(ThirtyBpW);
        label_10->setObjectName("label_10");
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(ThirtyBpW);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        gridLayout_3->addWidget(label_11, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);

        thirtyBpTableW = new QTableWidget(ThirtyBpW);
        if (thirtyBpTableW->columnCount() < 3)
            thirtyBpTableW->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        thirtyBpTableW->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        thirtyBpTableW->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        thirtyBpTableW->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        thirtyBpTableW->setObjectName("thirtyBpTableW");
        thirtyBpTableW->setStyleSheet(QString::fromUtf8("QTableWidget#thrityBpTableW{\n"
"	border:0;\n"
"}"));
        thirtyBpTableW->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(thirtyBpTableW);

        bp_stackedWidget->addWidget(ThirtyBpW);
        UserDefBpW = new QWidget();
        UserDefBpW->setObjectName("UserDefBpW");
        verticalLayout_3 = new QVBoxLayout(UserDefBpW);
        verticalLayout_3->setSpacing(40);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 20, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(UserDefBpW);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        thingNums = new QSpinBox(UserDefBpW);
        thingNums->setObjectName("thingNums");
        thingNums->setFocusPolicy(Qt::NoFocus);
        thingNums->setMinimum(10);
        thingNums->setMaximum(60);

        gridLayout->addWidget(thingNums, 0, 1, 1, 1);

        label_3 = new QLabel(UserDefBpW);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        totalWeight = new QSpinBox(UserDefBpW);
        totalWeight->setObjectName("totalWeight");
        totalWeight->setMinimum(100);
        totalWeight->setMaximum(1000);

        gridLayout->addWidget(totalWeight, 1, 1, 1, 1);

        label_12 = new QLabel(UserDefBpW);
        label_12->setObjectName("label_12");
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        label_14 = new QLabel(UserDefBpW);
        label_14->setObjectName("label_14");

        gridLayout->addWidget(label_14, 2, 1, 1, 1);

        label_13 = new QLabel(UserDefBpW);
        label_13->setObjectName("label_13");
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        label_15 = new QLabel(UserDefBpW);
        label_15->setObjectName("label_15");

        gridLayout->addWidget(label_15, 3, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        defBpTableW = new QTableWidget(UserDefBpW);
        if (defBpTableW->columnCount() < 3)
            defBpTableW->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        defBpTableW->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        defBpTableW->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        defBpTableW->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        defBpTableW->setObjectName("defBpTableW");
        defBpTableW->setStyleSheet(QString::fromUtf8("QTableWidget#defBpTableW{\n"
"	border:0;\n"
"}"));
        defBpTableW->horizontalHeader()->setVisible(true);
        defBpTableW->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(defBpTableW);

        bp_stackedWidget->addWidget(UserDefBpW);

        verticalLayout->addWidget(bp_stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        startDemo = new QPushButton(layoutWidget);
        startDemo->setObjectName("startDemo");
        startDemo->setFont(font);

        horizontalLayout->addWidget(startDemo);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);

        verticalLayout_2->addWidget(splitter);


        retranslateUi(BpProWidget);

        bp_stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(BpProWidget);
    } // setupUi

    void retranslateUi(QWidget *BpProWidget)
    {
        BpProWidget->setWindowTitle(QCoreApplication::translate("BpProWidget", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = bp_treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("BpProWidget", "\351\227\256\351\242\230\351\200\211\346\213\251", nullptr));

        const bool __sortingEnabled = bp_treeWidget->isSortingEnabled();
        bp_treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = bp_treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("BpProWidget", "\345\206\205\347\275\256\347\244\272\344\276\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("BpProWidget", "7", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("BpProWidget", "30", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = bp_treeWidget->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("BpProWidget", "\350\207\252\345\256\232\344\271\211\351\232\217\346\234\272\347\244\272\344\276\213", nullptr));
        bp_treeWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("BpProWidget", "\347\202\271\345\207\273\345\255\220\351\241\271\351\200\211\346\213\251\345\206\205\347\275\256\347\244\272\344\276\213", nullptr));
        label_4->setText(QCoreApplication::translate("BpProWidget", "\347\211\251\345\223\201\346\225\260:  ", nullptr));
        label_6->setText(QCoreApplication::translate("BpProWidget", "7", nullptr));
        label_5->setText(QCoreApplication::translate("BpProWidget", "\346\200\273\351\207\215:  ", nullptr));
        label_7->setText(QCoreApplication::translate("BpProWidget", "100", nullptr));
        QTableWidgetItem *___qtablewidgetitem = sevenBpTableW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BpProWidget", "\347\211\251\345\223\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = sevenBpTableW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BpProWidget", "\345\210\251\346\266\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = sevenBpTableW->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BpProWidget", "\351\207\215\351\207\217", nullptr));
        label_8->setText(QCoreApplication::translate("BpProWidget", "\347\211\251\345\223\201\346\225\260:  ", nullptr));
        label_9->setText(QCoreApplication::translate("BpProWidget", "30", nullptr));
        label_10->setText(QCoreApplication::translate("BpProWidget", "\346\200\273\351\207\215:  ", nullptr));
        label_11->setText(QCoreApplication::translate("BpProWidget", "1000", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = thirtyBpTableW->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BpProWidget", "\347\211\251\345\223\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = thirtyBpTableW->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BpProWidget", "\345\210\251\346\266\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = thirtyBpTableW->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("BpProWidget", "\351\207\215\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("BpProWidget", "\347\211\251\345\223\201\346\225\260:  ", nullptr));
        label_3->setText(QCoreApplication::translate("BpProWidget", "<html><head/><body><p>\346\200\273\351\207\215:  </p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("BpProWidget", "\345\210\251\346\266\246\350\214\203\345\233\264:  ", nullptr));
        label_14->setText(QCoreApplication::translate("BpProWidget", "20~100", nullptr));
        label_13->setText(QCoreApplication::translate("BpProWidget", "\351\207\215\351\207\217\350\214\203\345\233\264:  ", nullptr));
        label_15->setText(QCoreApplication::translate("BpProWidget", "20~100", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = defBpTableW->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("BpProWidget", "\347\211\251\345\223\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = defBpTableW->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("BpProWidget", "\345\210\251\346\266\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = defBpTableW->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("BpProWidget", "\351\207\215\351\207\217", nullptr));
        startDemo->setText(QCoreApplication::translate("BpProWidget", "\345\274\200\345\247\213\346\274\224\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BpProWidget: public Ui_BpProWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BPPROWIDGET_H
