QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatwidget.cpp \
    filewidget.cpp \
    logindialog.cpp \
    main.cpp \
    myprotocol.cpp \
    privatechat.cpp \
    sharefilewidget.cpp \
    widget.cpp

HEADERS += \
    chatwidget.h \
    filewidget.h \
    logindialog.h \
    myprotocol.h \
    privatechat.h \
    sharefilewidget.h \
    widget.h

FORMS += \
    chatwidget.ui \
    filewidget.ui \
    logindialog.ui \
    privatechat.ui \
    sharefilewidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    iconRes.qrc \
    res.qrc
