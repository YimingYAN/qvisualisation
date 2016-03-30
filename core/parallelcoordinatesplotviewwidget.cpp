/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2015 Yiming Yan
****************************************************************************/
#include <visualisation/core/parallelcoordinatesplotviewwidget.h>
#include <visualisation/core/parallelcoordinateplotviewmodel.h>
#include <visualisation/core/visualisationdatamodel.h>

using namespace Visualisation;
ParallelCoordinatesPlotViewWidget::ParallelCoordinatesPlotViewWidget(QWidget *parent)
    : VisualisationViewWidget(parent)
{
    initialise();
}

void ParallelCoordinatesPlotViewWidget::initialise()
{
    VisualisationDataModel* dataModel = new VisualisationDataModel;
    ParallelCoordinatesPlotViewModel* view = new ParallelCoordinatesPlotViewModel(this);
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    setView(view);
    centralWidget()->layout()->addWidget(view);
    setWindowTitle(QString("Parallel Coordinates Plot"));
}

