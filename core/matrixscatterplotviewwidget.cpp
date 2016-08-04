/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <visualisation/core/matrixscatterplotviewwidget.h>
#include <visualisation/core/visualisationdatamodel.h>
#include <visualisation/core/visualisationviewmodel.h>

#include <QDebug>
#include <QGridLayout>


using namespace Visualisation;

MatrixScatterPlotViewWidget::MatrixScatterPlotViewWidget(QWidget *parent)
    : VisualisationViewWidget(parent)
{
    initialise();
}

void MatrixScatterPlotViewWidget::initialise()
{
    VisualisationDataModel* dataModel = new VisualisationDataModel;
    VisualisationViewModel* view = new VisualisationViewModel(this);
    view->setUrl(QUrl("qrc:/visualisation/html/matrixscatterplot.html"));
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    setView(view);
    setWindowTitle(QString("Matrix Scatter Plot"));
}
