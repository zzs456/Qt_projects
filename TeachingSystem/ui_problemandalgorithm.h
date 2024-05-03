/********************************************************************************
** Form generated from reading UI file 'problemandalgorithm.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROBLEMANDALGORITHM_H
#define UI_PROBLEMANDALGORITHM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProblemAndAlgorithm
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *proalgo_leftWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTreeWidget *algo_treeWidget;
    QPushButton *proalgo_returnMainWidgetBtn;
    QStackedWidget *proalgo_stackedWidget;

    void setupUi(QWidget *ProblemAndAlgorithm)
    {
        if (ProblemAndAlgorithm->objectName().isEmpty())
            ProblemAndAlgorithm->setObjectName("ProblemAndAlgorithm");
        ProblemAndAlgorithm->resize(1212, 817);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/res/icons/window_icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        ProblemAndAlgorithm->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(ProblemAndAlgorithm);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(ProblemAndAlgorithm);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        proalgo_leftWidget = new QWidget(splitter);
        proalgo_leftWidget->setObjectName("proalgo_leftWidget");
        proalgo_leftWidget->setMinimumSize(QSize(200, 0));
        proalgo_leftWidget->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(proalgo_leftWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        algo_treeWidget = new QTreeWidget(proalgo_leftWidget);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/algotithm_pngs/res/algotithm_pngs/GA.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/algotithm_pngs/res/algotithm_pngs/Introduce.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font1;
        font1.setPointSize(10);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/problem_icons/res/problems_icons/func_Extreme.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/problem_icons/res/problems_icons/path_plan.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/problem_icons/res/problems_icons/bp_pro.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/problem_icons/res/problems_icons/tsp_pro.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/algotithm_pngs/res/algotithm_pngs/PSO.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/algotithm_pngs/res/algotithm_pngs/ACO.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/algotithm_pngs/res/algotithm_pngs/vs.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(algo_treeWidget);
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFont(0, font1);
        __qtreewidgetitem1->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setFont(0, font1);
        __qtreewidgetitem2->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setFont(0, font1);
        __qtreewidgetitem3->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem4->setFont(0, font1);
        __qtreewidgetitem4->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem5->setFont(0, font1);
        __qtreewidgetitem5->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(algo_treeWidget);
        __qtreewidgetitem6->setFont(0, font);
        __qtreewidgetitem6->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem7->setFont(0, font1);
        __qtreewidgetitem7->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem8->setFont(0, font1);
        __qtreewidgetitem8->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem9->setFont(0, font1);
        __qtreewidgetitem9->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem10->setFont(0, font1);
        __qtreewidgetitem10->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(algo_treeWidget);
        __qtreewidgetitem11->setFont(0, font);
        __qtreewidgetitem11->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem12->setFont(0, font1);
        __qtreewidgetitem12->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem13->setFont(0, font1);
        __qtreewidgetitem13->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem14 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem14->setFont(0, font1);
        __qtreewidgetitem14->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem15 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem15->setFont(0, font1);
        __qtreewidgetitem15->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem16 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem16->setFont(0, font1);
        __qtreewidgetitem16->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem17 = new QTreeWidgetItem(algo_treeWidget);
        __qtreewidgetitem17->setFont(0, font);
        __qtreewidgetitem17->setIcon(0, icon9);
        QTreeWidgetItem *__qtreewidgetitem18 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem18->setFont(0, font1);
        __qtreewidgetitem18->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem19 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem19->setFont(0, font1);
        __qtreewidgetitem19->setIcon(0, icon6);
        algo_treeWidget->setObjectName("algo_treeWidget");
        algo_treeWidget->setMinimumSize(QSize(200, 0));
        algo_treeWidget->setMaximumSize(QSize(16777215, 16777215));
        algo_treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget#algo_treeWidget{\n"
"	border:none;\n"
"	border-top: 1px solid rgb(200,200,200);\n"
"}"));
        algo_treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        algo_treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        algo_treeWidget->setHeaderHidden(true);

        verticalLayout->addWidget(algo_treeWidget);

        proalgo_returnMainWidgetBtn = new QPushButton(proalgo_leftWidget);
        proalgo_returnMainWidgetBtn->setObjectName("proalgo_returnMainWidgetBtn");
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        proalgo_returnMainWidgetBtn->setFont(font2);

        verticalLayout->addWidget(proalgo_returnMainWidgetBtn);


        verticalLayout_2->addLayout(verticalLayout);

        splitter->addWidget(proalgo_leftWidget);
        proalgo_stackedWidget = new QStackedWidget(splitter);
        proalgo_stackedWidget->setObjectName("proalgo_stackedWidget");
        proalgo_stackedWidget->setMinimumSize(QSize(600, 0));
        splitter->addWidget(proalgo_stackedWidget);

        verticalLayout_3->addWidget(splitter);


        retranslateUi(ProblemAndAlgorithm);

        QMetaObject::connectSlotsByName(ProblemAndAlgorithm);
    } // setupUi

    void retranslateUi(QWidget *ProblemAndAlgorithm)
    {
        ProblemAndAlgorithm->setWindowTitle(QCoreApplication::translate("ProblemAndAlgorithm", "admin", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = algo_treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\347\256\227\346\263\225\345\255\246\344\271\240", nullptr));

        const bool __sortingEnabled = algo_treeWidget->isSortingEnabled();
        algo_treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = algo_treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\351\201\227\344\274\240\347\256\227\346\263\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\347\256\200\344\273\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\345\207\275\346\225\260\344\274\230\345\214\226\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\350\267\257\345\276\204\350\247\204\345\210\222\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\350\203\214\345\214\205\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\346\227\205\350\241\214\345\225\206\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = algo_treeWidget->topLevelItem(1);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\347\262\222\345\255\220\347\276\244\344\274\230\345\214\226\347\256\227\346\263\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem7->child(0);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\347\256\200\344\273\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem7->child(1);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\345\207\275\346\225\260\344\274\230\345\214\226\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem7->child(2);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\350\203\214\345\214\205\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem7->child(3);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\346\227\205\350\241\214\345\225\206\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem12 = algo_treeWidget->topLevelItem(2);
        ___qtreewidgetitem12->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\350\232\201\347\276\244\347\256\227\346\263\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem12->child(0);
        ___qtreewidgetitem13->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\347\256\200\344\273\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem12->child(1);
        ___qtreewidgetitem14->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\345\207\275\346\225\260\344\274\230\345\214\226\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem12->child(2);
        ___qtreewidgetitem15->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\350\267\257\345\276\204\350\247\204\345\210\222\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem12->child(3);
        ___qtreewidgetitem16->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\350\203\214\345\214\205\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem12->child(4);
        ___qtreewidgetitem17->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\346\227\205\350\241\214\345\225\206\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem18 = algo_treeWidget->topLevelItem(3);
        ___qtreewidgetitem18->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\347\256\227\346\263\225\346\257\224\350\276\203", nullptr));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem18->child(0);
        ___qtreewidgetitem19->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\345\207\275\346\225\260\344\274\230\345\214\226\351\227\256\351\242\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem18->child(1);
        ___qtreewidgetitem20->setText(0, QCoreApplication::translate("ProblemAndAlgorithm", "\346\227\205\350\241\214\345\225\206\351\227\256\351\242\230", nullptr));
        algo_treeWidget->setSortingEnabled(__sortingEnabled);

        proalgo_returnMainWidgetBtn->setText(QCoreApplication::translate("ProblemAndAlgorithm", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProblemAndAlgorithm: public Ui_ProblemAndAlgorithm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBLEMANDALGORITHM_H
