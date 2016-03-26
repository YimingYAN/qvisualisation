#include <visualisation/core/scatterplotviewmodel.h>

using namespace Visualisation;

ScatterPlotViewModel::ScatterPlotViewModel(QWidget *parent)
    : VisualisationViewModel(parent)
{
    this->setUrl(QUrl("qrc:/visualisation/html/scatterplot.html"));
}
