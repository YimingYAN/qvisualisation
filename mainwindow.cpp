#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualisationdatamodel.h"
#include "visualisationviewmodel.h"
#include "matrixscatterplotviewmodel.h"
#include "scatterplotviewmodel.h"
#include "parallelcoordinateplot.h"

#include <QGridLayout>
#include <QVector>

using namespace Visualisation;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    VisualisationDataModel* dataModel = new VisualisationDataModel;
    QVector<QVector<qreal> > data;
    QStringList names;
    data.resize(5);
    for(int i=0; i<3; ++i) {
        names.append(QString("DataItem" + QString::number(i)));
    }
    for(int i=0; i<5; ++i) {
        for(int j=0; j<3; ++j) {
            data[i].append(0.5*(i+j));
        }
    }
    dataModel->setData(data, names);

    // For different node, we declaire different ViewModel
    //ScatterPlotViewModel* view = new ScatterPlotViewModel(this);
    ParallelCoordinatesPlot* view = new ParallelCoordinatesPlot(this);
    //MatrixScatterPlotViewModel* view = new MatrixScatterPlotViewModel(this);
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(view);
    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
