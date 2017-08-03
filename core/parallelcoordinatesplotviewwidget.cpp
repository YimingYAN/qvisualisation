/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <core/parallelcoordinatesplotviewwidget.h>
#include <core/visualisationviewmodel.h>
#include <core/visualisationdatamodel.h>

using namespace Visualisation;
ParallelCoordinatesPlotViewWidget::ParallelCoordinatesPlotViewWidget(QWidget *parent)
    : VisualisationViewWidget(parent)
{
    initialise();
}

void ParallelCoordinatesPlotViewWidget::initialise()
{
    VisualisationDataModel* dataModel = new VisualisationDataModel;
    VisualisationViewModel* view = new VisualisationViewModel(this);
    view->setUrl(QUrl("qrc:/visualisation/html/parallelcoordinatesplot.html"));
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    setView(view);
    setWindowTitle(QString("Parallel Coordinates Plot"));
}

