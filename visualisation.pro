#-------------------------------------------------
#
# Project created by QtCreator 2016-03-24T15:28:12
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): {
    QT += widgets
    greaterThan(QT_MINOR_VERSION, 3): QT += webenginewidgets webchannel
}
CONFIG   += c++11
TARGET = visualisation
TEMPLATE = app

INCLUDEPATH += $$PWD/../

message($$INCLUDEPATH)

SOURCES += main.cpp\
        mainwindow.cpp \
    core/visualisationdatamodel.cpp \
    core/visualisationviewmodel.cpp \
    core/scatterplotviewmodel.cpp \
    core/parallelcoordinateplot.cpp \
    core/matrixscatterplotviewmodel.cpp

HEADERS  += mainwindow.h \
    core/visualisationdatamodel.h \
    core/visualisationviewmodel.h \
    core/scatterplotviewmodel.h \
    core/parallelcoordinateplot.h \
    core/matrixscatterplotviewmodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    visualisation.qrc
