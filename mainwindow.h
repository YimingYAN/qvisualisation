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
    void loadCsv(const QString& filePath);
    //void loadJson(const QString& filePath);
    //void loadWeblink(const QUrl& filePath);
    //void loadXml(const QString& filePath);
    Ui::MainWindow *ui;
    Visualisation::ScatterPlotViewWidget* m_scatter;
    Visualisation::MatrixScatterPlotViewWidget* m_mscatter;
    Visualisation::ParallelCoordinatesPlotViewWidget* m_parallcoord;
};

#endif // MAINWINDOW_H
