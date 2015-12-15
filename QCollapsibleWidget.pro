#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T16:17:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QAccordionWidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcollapsiblewidget.cpp

HEADERS  += mainwindow.hpp \
    qcollapsiblewidget.hpp

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++14
