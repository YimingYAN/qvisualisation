/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <visualisation/core/scatterplotviewwidget.h>
#include <visualisation/core/visualisationdatamodel.h>
#include <visualisation/core/visualisationviewmodel.h>

#include <QDebug>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

using namespace Visualisation;

ScatterPlotViewWidget::ScatterPlotViewWidget(QWidget *parent)
    : VisualisationViewWidget(parent)
    , m_xCombo(0)
    , m_yCombo(0)
    , m_button(0)
{
    initialise();
}

ScatterPlotViewWidget::~ScatterPlotViewWidget()
{
    delete m_xCombo;
    delete m_yCombo;
    delete m_button;
}

void ScatterPlotViewWidget::initialise()
{
    VisualisationDataModel* dataModel = new VisualisationDataModel;
    VisualisationViewModel* view = new VisualisationViewModel(this);
    view->setUrl(QUrl("qrc:/visualisation/html/scatterplot.html"));
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    setView(view);

    QLabel* xLabel = new QLabel("X: ", centralWidget());
    addItemToToolBar(xLabel);
    m_xCombo = new QComboBox(centralWidget());
    addItemToToolBar(m_xCombo);
    QLabel* yLabel = new QLabel("Y: ", centralWidget());
    addItemToToolBar(yLabel);
    m_yCombo = new QComboBox(centralWidget());
    addItemToToolBar(m_yCombo);
    m_button = new QPushButton("Refresh", centralWidget());
    addItemToToolBar(m_button);
    connect(m_button, SIGNAL(clicked()), this, SLOT(updateSelectedIndices()));
    centralWidget()->setMinimumSize(200, 200);
    setWindowTitle(QString("Scatter Plot"));
}

void ScatterPlotViewWidget::setData(const QVector<QVector<qreal> > &dataVec,
                                    const QStringList &names)
{
    VisualisationViewWidget::setData(dataVec, names);
    m_xCombo->insertItems(0, names);
    m_yCombo->insertItems(0, names);
    m_xCombo->setCurrentIndex(0);
    m_yCombo->setCurrentIndex(1);
}

void ScatterPlotViewWidget::updateSelectedIndices()
{
    QVariantList selection;
    selection.append(QVariant::fromValue(m_xCombo->currentIndex()));
    selection.append(QVariant::fromValue(m_yCombo->currentIndex()));
    setSelectedIndices(selection);
}
