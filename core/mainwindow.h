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

namespace Visualisation {
class ScatterPlotViewWidget;
class MatrixScatterPlotViewWidget;
class ParallelCoordinatesPlotViewWidget;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_demoButton_clicked();

private:
    Ui::MainWindow *ui;
    Visualisation::ScatterPlotViewWidget* m_scatter;
    Visualisation::MatrixScatterPlotViewWidget* m_mscatter;
    Visualisation::ParallelCoordinatesPlotViewWidget* m_parallcoord;
};

#endif // MAINWINDOW_H
