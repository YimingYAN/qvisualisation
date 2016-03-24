#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualisationviewmodel.h"
#include "scatterplotviewmodel.h"
#include "parallelcoordinateplot.h"
#include "matrixscatterplotviewmodel.h"

#include <QGridLayout>

using namespace Visualisation;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // For different node, we declaire different ViewModel
    //ScatterPlotViewModel* view = new ScatterPlotViewModel(this);
    //ParallelCoordinatesPlot* view = new ParallelCoordinatesPlot(this);
    MatrixScatterPlotViewModel* view = new MatrixScatterPlotViewModel(this);
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(view);
    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
