#include "parallelcoordinateplot.h"

using namespace Visualisation;

ParallelCoordinatesPlot::ParallelCoordinatesPlot(QWidget *parent)
    : VisualisationViewModel(parent)
{
    setUrl(QUrl("qrc:/visualisation/html/parallelcoordinatesplot.html"));
}
