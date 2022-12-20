#-------------------------------------------------
#
# Project created by QtCreator 2019-05-19T14:28:11
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Member.cpp \
        MemberCollection.cpp \
        error1.cpp \
        error2.cpp \
        main.cpp \
        mainwindow.cpp \
        seat.cpp \
        window_21.cpp \
        window_22.cpp \
        window_31.cpp \
        window_32.cpp \
        window_33.cpp \
        window_41.cpp \
        window_42.cpp

HEADERS += \
        Member.h \
        MemberCollection.h \
        error1.h \
        error2.h \
        mainwindow.h \
        seat.h \
        window_21.h \
        window_22.h \
        window_31.h \
        window_32.h \
        window_33.h \
        window_41.h \
        window_42.h

FORMS += \
        error1.ui \
        error2.ui \
        mainwindow.ui \
        window_21.ui \
        window_22.ui \
        window_31.ui \
        window_32.ui \
        window_33.ui \
        window_41.ui \
        window_42.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
