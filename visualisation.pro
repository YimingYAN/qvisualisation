include(qvisualisation.pri)

#QT version check
!minQtVersion(5, 6, 0) {
    message("Cannot build QVisualisation with Qt version $${QT_VERSION}.")
    error("Use at least Qt 5.6.0.")
}

QT += core gui
QT += widgets printsupport svg
QT += webenginewidgets webchannel

CONFIG += c++11
TARGET = qvisualisation
TEMPLATE = app

INCLUDEPATH += $$PWD

SOURCES += main.cpp\
    core/visualisationdatamodel.cpp \
    core/visualisationviewmodel.cpp \
    core/visualisationviewwidget.cpp \
    core/scatterplotviewwidget.cpp \
    core/matrixscatterplotviewwidget.cpp \
    core/parallelcoordinatesplotviewwidget.cpp \
    mainwindow.cpp

HEADERS  += \
    core/visualisationdatamodel.h \
    core/visualisationviewmodel.h \
    core/visualisationviewwidget.h \
    core/scatterplotviewwidget.h \
    core/matrixscatterplotviewwidget.h \
    core/parallelcoordinatesplotviewwidget.h \
    mainwindow.h

FORMS += \
    core/visualisationviewwidget.ui \
    mainwindow.ui

RESOURCES += \
    visualisation.qrc

DISTFILES += \
    README.md \
    LICENSE
