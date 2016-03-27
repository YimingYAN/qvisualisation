#include <visualisation/core/scatterplotviewwidget.h>
#include <visualisation/core/visualisationdatamodel.h>
#include <visualisation/core/scatterplotviewmodel.h>

#include <QDebug>
#include <QGridLayout>

using namespace Visualisation;

ScatterPlotViewWidget::ScatterPlotViewWidget(QWidget *parent)
    : VisualisationViewWidget(parent)
{
    initialise();
}

void ScatterPlotViewWidget::initialise()
{
    VisualisationDataModel* dataModel = new VisualisationDataModel;
    ScatterPlotViewModel* view = new ScatterPlotViewModel(this);
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    setView(view);
    centralWidget()->layout()->addWidget(view);
    setWindowTitle(QString("Scatter Plot"));
}
