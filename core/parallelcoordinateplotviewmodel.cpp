#include <visualisation/core/parallelcoordinateplotviewmodel.h>

using namespace Visualisation;

ParallelCoordinatesPlotViewModel::ParallelCoordinatesPlotViewModel(QWidget *parent)
    : VisualisationViewModel(parent)
{
    setUrl(QUrl("qrc:/visualisation/html/parallelcoordinatesplot.html"));
}
