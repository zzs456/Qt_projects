QT       += core gui
QT       += sql
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qcustomplot.cpp \
    src/Algo_ACO/acodemoshowwidget.cpp \
    src/Algo_ACO/algo_aco.cpp \
    src/Algo_Comp/algo_compshow.cpp \
    src/Algo_Comp/func_comp.cpp \
    src/Algo_Comp/tsp_comp.cpp \
    src/Algo_GA/algo_ga.cpp \
    src/Algo_GA/gademoshowwidget.cpp \
    src/Algo_PSO/algo_pso.cpp \
    src/Algo_PSO/psodemoshowwidget.cpp \
    src/BackpackPro/bpmainwidget.cpp \
    src/BackpackPro/bpprowidget.cpp \
    src/FunctionPro/funcmainwidget.cpp \
    src/FunctionPro/functionprowidget.cpp \
    src/LoginWidget/dbinstance.cpp \
    src/LoginWidget/logindialog.cpp \
    src/MainWidget/mainwidget.cpp \
    src/MainWidget/mwhomepicwidget.cpp \
    src/MainWidget/mwhomeprowidget.cpp \
    src/MainWidget/mwhomewidget.cpp \
    src/MyComponents/mymessagebox.cpp \
    src/PathPro/pathmainwidget.cpp \
    src/PathPro/pathprowidget.cpp \
    src/ProAlgoWidget/proalgointroducewidget.cpp \
    src/ProAlgoWidget/proalgoparentwidget.cpp \
    src/ProAlgoWidget/problemandalgorithm.cpp \
    src/SettingWidget/mwhelpwidget.cpp \
    src/SettingWidget/mwsettingwidget.cpp \
    src/TSPPro/tspmainwidget.cpp \
    src/TSPPro/tspprowidget.cpp \
    src/main.cpp \
    src/widget.cpp \
    tsp_comp.cpp

HEADERS += \
    qcustomplot.h \
    src/Algo_ACO/acodemoshowwidget.h \
    src/Algo_ACO/algo_aco.h \
    src/Algo_Comp/algo_compshow.h \
    src/Algo_Comp/func_comp.h \
    src/Algo_Comp/tsp_comp.h \
    src/Algo_GA/algo_ga.h \
    src/Algo_GA/gademoshowwidget.h \
    src/Algo_PSO/algo_pso.h \
    src/Algo_PSO/psodemoshowwidget.h \
    src/BackpackPro/bpmainwidget.h \
    src/BackpackPro/bpprowidget.h \
    src/FunctionPro/funcmainwidget.h \
    src/FunctionPro/functionprowidget.h \
    src/LoginWidget/dbinstance.h \
    src/LoginWidget/logindialog.h \
    src/MainWidget/mainwidget.h \
    src/MainWidget/mwhomepicwidget.h \
    src/MainWidget/mwhomeprowidget.h \
    src/MainWidget/mwhomewidget.h \
    src/MyComponents/mymessagebox.h \
    src/PathPro/pathmainwidget.h \
    src/PathPro/pathprowidget.h \
    src/ProAlgoWidget/myalgorithmtype.h \
    src/ProAlgoWidget/proalgointroducewidget.h \
    src/ProAlgoWidget/proalgoparentwidget.h \
    src/ProAlgoWidget/problemandalgorithm.h \
    src/PublicHeader/Color.h \
    src/SettingWidget/mwhelpwidget.h \
    src/SettingWidget/mwsettingwidget.h \
    src/TSPPro/tspmainwidget.h \
    src/TSPPro/tspprowidget.h \
    src/widget.h \
    tsp_comp.h

FORMS += \
    src/Algo_ACO/acodemoshowwidget.ui \
    src/Algo_Comp/algo_compshow.ui \
    src/Algo_Comp/func_comp.ui \
    src/Algo_Comp/tsp_comp.ui \
    src/Algo_GA/gademoshowwidget.ui \
    src/Algo_PSO/psodemoshowwidget.ui \
    src/BackpackPro/bpmainwidget.ui \
    src/BackpackPro/bpprowidget.ui \
    src/FunctionPro/funcmainwidget.ui \
    src/FunctionPro/functionprowidget.ui \
    src/LoginWidget/logindialog.ui \
    src/MainWidget/mainwidget.ui \
    src/MainWidget/mwhomepicwidget.ui \
    src/MainWidget/mwhomeprowidget.ui \
    src/MainWidget/mwhomewidget.ui \
    src/MyComponents/mymessagebox.ui \
    src/PathPro/pathmainwidget.ui \
    src/PathPro/pathprowidget.ui \
    src/ProAlgoWidget/proalgointroducewidget.ui \
    src/ProAlgoWidget/proalgoparentwidget.ui \
    src/ProAlgoWidget/problemandalgorithm.ui \
    src/SettingWidget/mwhelpwidget.ui \
    src/SettingWidget/mwsettingwidget.ui \
    src/TSPPro/tspmainwidget.ui \
    src/TSPPro/tspprowidget.ui \
    src/widget.ui \
    tsp_comp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res_Icon.qrc \
    res_pngs.qrc \
    res_texts.qrc

DISTFILES +=
