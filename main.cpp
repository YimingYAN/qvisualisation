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

    int numData = 500;
    int numCols = 5;
    QVector<QVector<qreal> > data;
    QVector<QVector<QVector<qreal> > > boxPlotData;
    QStringList names;
    QVariantList selectedIndices;
    data.resize(numData);
    boxPlotData.resize(numData);

    for(int i=0; i<numCols; ++i) {
        names.append(QString("DataItem" + QString::number(i)));
    }
    for(int i=0; i<numData; ++i) {
        boxPlotData[i].resize(numCols);
        for(int j=0; j<numCols; ++j) {
            boxPlotData[i][j].resize(5);
            qreal bias = 1.0*qrand()/RAND_MAX;
            qreal value = bias*(i+j);
            data[i].append(value);
            boxPlotData[i][j][0] = value*0.95;
            boxPlotData[i][j][1] = value*0.98;
            boxPlotData[i][j][2] = value;
            boxPlotData[i][j][3] = value*1.02;
            boxPlotData[i][j][4] = value*1.05;
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
    w3.setBoxPlotData(boxPlotData);
    w3.show();

    return a.exec();
}
