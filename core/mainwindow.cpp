/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2015 Yiming Yan
****************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <visualisation/core/scatterplotviewwidget.h>
#include <visualisation/core/matrixscatterplotviewwidget.h>
#include <visualisation/core/parallelcoordinatesplotviewwidget.h>

using namespace Visualisation;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_scatter) {
        delete m_scatter;
    }
    if(m_mscatter) {
        delete m_mscatter;
    }
    if(m_parallcoord) {
        delete m_parallcoord;
    }
}

void MainWindow::on_demoButton_clicked()
{
    m_scatter = new ScatterPlotViewWidget;
    m_mscatter = new MatrixScatterPlotViewWidget;
    m_parallcoord = new ParallelCoordinatesPlotViewWidget;

    int numData = 1000;
    int numCols = 5;
    QVector<QVector<qreal> > data;
    QStringList names;
    QVariantList selectedIndices;
    data.resize(numData);

    for(int i=0; i<numCols; ++i) {
        names.append(QString("DataItem" + QString::number(i)));
    }
    for(int i=0; i<numData; ++i) {
        for(int j=0; j<numCols; ++j) {
            qreal bias = 1.0*qrand()/RAND_MAX;
            qreal value = bias*(i+j);
            data[i].append(value);
        }
    }
    for(int i=0; i<numCols; ++i) {
        selectedIndices.append(i);
    }

    m_scatter->setData(data, names);
    m_scatter->setSelectedIndices(selectedIndices);
    m_scatter->show();

    m_mscatter->setData(data, names);
    m_mscatter->setSelectedIndices(selectedIndices);
    m_mscatter->show();

    m_parallcoord->setData(data, names);
    m_parallcoord->setSelectedIndices(selectedIndices);
    m_parallcoord->show();
}
