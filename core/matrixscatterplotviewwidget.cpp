#include <visualisation/core/matrixscatterplotviewwidget.h>
#include <visualisation/core/visualisationdatamodel.h>
#include <visualisation/core/matrixscatterplotviewmodel.h>

#include <QDebug>
#include <QGridLayout>


using namespace Visualisation;

MatrixScatterPlotViewWidget::MatrixScatterPlotViewWidget(QWidget *parent)
    : VisualisationViewWidget(parent)
{
    initialise();
}

void MatrixScatterPlotViewWidget::initialise()
{
    VisualisationDataModel* dataModel = new VisualisationDataModel;
    MatrixScatterPlotViewModel* view = new MatrixScatterPlotViewModel(this);
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    setView(view);
    centralWidget()->layout()->addWidget(view);
    setWindowTitle(QString("Matrix Scatter Plot"));
}
