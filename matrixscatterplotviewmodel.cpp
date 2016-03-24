#include "matrixscatterplotviewmodel.h"

using namespace Visualisation;
MatrixScatterPlotViewModel::MatrixScatterPlotViewModel(QWidget *parent)
    : VisualisationViewModel(parent)
{
    setUrl(QUrl("qrc:/visualisation/html/matrixscatterplot.html"));
}
