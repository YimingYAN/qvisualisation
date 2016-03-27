#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <visualisation/core/visualisationdatamodel.h>
#include <visualisation/core/visualisationviewmodel.h>
#include <visualisation/core/matrixscatterplotviewmodel.h>
#include <visualisation/core/scatterplotviewmodel.h>
#include <visualisation/core/parallelcoordinateplotviewmodel.h>

#include <QtGlobal>
#include <QGridLayout>
#include <QVector>
#include <QVariantList>

using namespace Visualisation;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int numData = 500;
    int numCols = 5;

    VisualisationDataModel* dataModel = new VisualisationDataModel;
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
    dataModel->setData(data, names);
    dataModel->setBoxplotData(boxPlotData);
    for(int i=0; i<numCols; ++i) {
        selectedIndices.append(i);
    }
    dataModel->setSelectedIndices(selectedIndices);

    // For different node, we declaire different ViewModel
    ScatterPlotViewModel* view = new ScatterPlotViewModel(this);
    //MatrixScatterPlotViewModel* view = new MatrixScatterPlotViewModel(this);
    //ParallelCoordinatesPlotViewModel* view = new ParallelCoordinatesPlotViewModel(this);
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    QGridLayout* layout = new QGridLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(view);
    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
