/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <visualisation/core/matrixscatterplotviewmodel.h>

using namespace Visualisation;
MatrixScatterPlotViewModel::MatrixScatterPlotViewModel(QWidget *parent)
    : VisualisationViewModel(parent)
{
    setUrl(QUrl("qrc:/visualisation/html/matrixscatterplot.html"));
}
