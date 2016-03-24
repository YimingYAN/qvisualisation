#include "visualisationviewmodel.h"
#include "visualisationdatamodel.h"

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

VisualisationViewModel::~VisualisationViewModel()
{

}
