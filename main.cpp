/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2015 Yiming Yan
****************************************************************************/
#include <QApplication>
#include <visualisation/core/mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
