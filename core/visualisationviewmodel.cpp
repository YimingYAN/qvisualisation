/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <core/visualisationviewmodel.h>
#include <core/visualisationdatamodel.h>
#include <QWebChannel>

using namespace Visualisation;

VisualisationViewModel::VisualisationViewModel(QWidget *parent)
    : QWebEngineView(parent)
    , m_dataModel(0)
{

}

void VisualisationViewModel::setDataModel(VisualisationDataModel *dataModel)
{
    m_dataModel = dataModel;
}

void VisualisationViewModel::linkWithJavaScript()
{
    if(m_dataModel) {
        QWebChannel* channel = new QWebChannel(this);
        channel->registerObject(QStringLiteral("dataModel"), m_dataModel);
        this->page()->setWebChannel(channel);
    }
    return;
}

VisualisationViewModel::~VisualisationViewModel()
{

}

VisualisationDataModel *VisualisationViewModel::dataModel() const
{
    return m_dataModel;
}
