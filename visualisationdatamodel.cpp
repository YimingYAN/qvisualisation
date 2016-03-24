#include "visualisationdatamodel.h"

#include <QDebug>
using namespace Visualisation;

VisualisationDataModel::VisualisationDataModel(QObject *parent)
    : QObject(parent)
{
    // Testing purpose
    m_dataString = QString("Hello");
}

void VisualisationDataModel::setDate(QVector<QVector<qreal> > data)
{
    m_data = data;
}

void VisualisationDataModel::setNames(QStringList names)
{
    m_names = names;
}

QString VisualisationDataModel::dataString() const
{
    qDebug() << "send dataString : " << m_dataString;
    return m_dataString;
}

QStringList VisualisationDataModel::allNames() const
{
    return m_names;
}

int VisualisationDataModel::dataRows() const
{
    return m_data.size();
}

int VisualisationDataModel::dataCols() const
{
    int size  = 0;
    if(dataRows() > 0) {
        size =  m_data[0].size();
    }
    return size;
}
