/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <visualisation/core/scatterplotviewmodel.h>

using namespace Visualisation;

ScatterPlotViewModel::ScatterPlotViewModel(QWidget *parent)
    : VisualisationViewModel(parent)
{
    this->setUrl(QUrl("qrc:/visualisation/html/scatterplot.html"));
}
