#-------------------------------------------------
#
# Project created by QtCreator 2017-10-16T02:34:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Menu
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    twodimen.cpp \
    threedime.cpp \
    twodimennext.cpp \
    calculate.cpp \
    save.cpp \
    threedimenext.cpp

HEADERS += \
        mainwindow.h \
    twodimen.h \
    threedime.h \
    twodimennext.h \
    calculate.h \
    save.h \
    threedimenext.h

FORMS += \
        mainwindow.ui \
    twodimen.ui \
    threedime.ui \
    twodimennext.ui \
    calculate.ui \
    save.ui \
    threedimenext.ui
