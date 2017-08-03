/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

enum SOURCE_TYPE {
    CSV,
    JSON,
    XML,
    URL
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_demoButton_clicked();
    void on_loadButton_clicked();
    void on_plotButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
