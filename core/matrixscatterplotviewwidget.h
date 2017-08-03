/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#ifndef MATRIXSCATTERPLOTVIEWWIDGET_H
#define MATRIXSCATTERPLOTVIEWWIDGET_H
#include <core/visualisationviewwidget.h>

namespace Visualisation {

class MatrixScatterPlotViewWidget : public VisualisationViewWidget
{
public:
    explicit MatrixScatterPlotViewWidget(QWidget *parent = 0);
    void initialise();
};

}
#endif // MATRIXSCATTERPLOTVIEWWIDGET_H
