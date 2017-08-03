/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#ifndef PARALLELCOORDINATESPLOTVIEWWIDGET_H
#define PARALLELCOORDINATESPLOTVIEWWIDGET_H
#include <core/visualisationviewwidget.h>

namespace Visualisation {
class ParallelCoordinatesPlotViewWidget : public VisualisationViewWidget
{
public:
    explicit ParallelCoordinatesPlotViewWidget(QWidget *parent = 0);
    void initialise();
};

}

#endif // PARALLELCOORDINATESPLOTVIEWWIDGET_H
