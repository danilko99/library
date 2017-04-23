#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T22:04:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laba3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    book.cpp \
    mylist.cpp \
    librarybook.cpp \
    change.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    book.h \
    mylist.h \
    librarybook.h \
    change.h \
    mythread.h

FORMS    += mainwindow.ui \
    change.ui

RESOURCES += \
    res/ff.qrc
