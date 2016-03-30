/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2015 Yiming Yan
****************************************************************************/
#include <QApplication>
#include <visualisation/core/scatterplotviewwidget.h>
#include <visualisation/core/matrixscatterplotviewwidget.h>
#include <visualisation/core/parallelcoordinatesplotviewwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    Visualisation::ScatterPlotViewWidget w1;
    Visualisation::MatrixScatterPlotViewWidget w2;
    Visualisation::ParallelCoordinatesPlotViewWidget w3;

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

    w1.setData(data, names);
    w1.setSelectedIndices(selectedIndices);
    w1.show();

    w2.setData(data, names);
    w2.setSelectedIndices(selectedIndices);
    w2.show();

    w3.setData(data, names);
    w3.setSelectedIndices(selectedIndices);
    w3.show();

    return a.exec();
}
