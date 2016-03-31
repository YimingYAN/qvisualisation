/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <visualisation/core/parallelcoordinateplotviewmodel.h>

using namespace Visualisation;

ParallelCoordinatesPlotViewModel::ParallelCoordinatesPlotViewModel(QWidget *parent)
    : VisualisationViewModel(parent)
{
    setUrl(QUrl("qrc:/visualisation/html/parallelcoordinatesplot.html"));
}
