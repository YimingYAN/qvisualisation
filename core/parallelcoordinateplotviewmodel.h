/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#ifndef PARALLELCOORDINATEPLOT_H
#define PARALLELCOORDINATEPLOT_H
#include <visualisation/core/visualisationviewmodel.h>

namespace Visualisation  {
class ParallelCoordinatesPlotViewModel : public VisualisationViewModel
{
public:
    ParallelCoordinatesPlotViewModel(QWidget* parent = nullptr);
};
}
#endif // PARALLELCOORDINATEPLOT_H
