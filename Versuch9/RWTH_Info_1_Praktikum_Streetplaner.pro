#-------------------------------------------------
#
# Project created by QtCreator 2017-04-24T12:34:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RWTH_Info_1_Praktikum_Streetplaner
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    city.cpp \
    map.cpp \
    abstractmap.cpp \
    street.cpp \
    newcityui.cpp \
    mapionrw.cpp \
    mapio.cpp \
    dijkstra.cpp \
    dijkstradialog.cpp \
    addstreetdialog.cpp

HEADERS  += mainwindow.h \
    city.h \
    map.h \
    abstractmap.h \
    street.h \
    newcityui.h \
    mapio.h \
    mapionrw.h \
    dijkstra.h \
    dijkstradialog.h \
    addstreetdialog.h

FORMS    += mainwindow.ui \
    newcityui.ui \
    dijkstradialog.ui \
    addstreetdialog.ui
