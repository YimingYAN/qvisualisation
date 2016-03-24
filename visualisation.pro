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
TARGET = visualisation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    visualisationdatamodel.cpp \
    visualisationviewmodel.cpp \
    scatterplotviewmodel.cpp \
    parallelcoordinateplot.cpp \
    matrixscatterplotviewmodel.cpp

HEADERS  += mainwindow.h \
    visualisationdatamodel.h \
    visualisationviewmodel.h \
    scatterplotviewmodel.h \
    parallelcoordinateplot.h \
    matrixscatterplotviewmodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    visualisation.qrc
