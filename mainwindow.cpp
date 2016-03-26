#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualisationdatamodel.h"
#include "visualisationviewmodel.h"
#include "matrixscatterplotviewmodel.h"
#include "scatterplotviewmodel.h"
#include "parallelcoordinateplot.h"

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

    VisualisationDataModel* dataModel = new VisualisationDataModel;
    QVector<QVector<qreal> > data;
    QStringList names;
    QVariantList selectedIndices;
    data.resize(5);
    for(int i=0; i<3; ++i) {
        names.append(QString("DataItem" + QString::number(i)));
    }
    for(int i=0; i<5; ++i) {
        for(int j=0; j<3; ++j) {
            qreal bias = 1.0*qrand()/RAND_MAX;
            data[i].append(bias*(i+j));
        }
    }
    dataModel->setData(data, names);
    selectedIndices.append(0);
    //selectedIndices.append(1);
    selectedIndices.append(2);
    //selectedIndices.append(3);
    dataModel->setSelectedIndices(selectedIndices);

    // For different node, we declaire different ViewModel
    //ScatterPlotViewModel* view = new ScatterPlotViewModel(this);
    MatrixScatterPlotViewModel* view = new MatrixScatterPlotViewModel(this);
    //ParallelCoordinatesPlot* view = new ParallelCoordinatesPlot(this);
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
