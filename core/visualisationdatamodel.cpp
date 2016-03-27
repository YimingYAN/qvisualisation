#include <visualisation/core/visualisationdatamodel.h>

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
using namespace Visualisation;

VisualisationDataModel::VisualisationDataModel(QObject *parent)
    : QObject(parent)
{

}

/*!
 * \brief Recommanded function for setting data and names.
 */
void VisualisationDataModel::setData(const QVector<QVector<qreal> > &data, const QStringList &names)
{
    if(data.size() < 1 || names.size() < 1) {
        return;
    }
    for(int i=0; i<data.size(); ++i) {
        if(data[i].size() != names.size()) {
            return;
        }
    }
    m_data = data;
    m_names = names;
    generateDataJsonDocument();
}

void VisualisationDataModel::setData(const QVector<QVector<qreal> > &data)
{
    if(data.size() < 1) {
        return;
    }
    if(m_names.size() > 0) {
        for(int i=0; i<data.size(); ++i) {
            if(data[i].size() != m_names.size()) {
                return;
            }
        }
    }
    m_data = data;
    generateDataJsonDocument();
}

void VisualisationDataModel::setNames(const QStringList &names)
{
    if(names.size() < 1) {
        return;
    }
    if(m_data.size() > 0) {
        for(int i=0; i<m_data.size(); ++i) {
            if(m_data[i].size() != names.size()) {
                return;
            }
        }
    }
    m_names = names;
    generateDataJsonDocument();
}

QStringList VisualisationDataModel::allNames() const
{
    return m_names;
}

QJsonDocument VisualisationDataModel::dataJson() const
{
    return m_dataJson;
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

void VisualisationDataModel::generateDataJsonDocument()
{
    QJsonArray jsonArray;
    for(int i=0; i<m_data.size(); ++i) {
        QJsonObject object;
        for(int j=0; j<m_names.size(); ++j) {
            object[m_names[j]] = m_data[i][j];
        }
        jsonArray.append(object);
    }
    m_dataJson.setArray(jsonArray);
}

void VisualisationDataModel::generateBoxplotJsonDcoument()
{
    QJsonArray jsonArray;
    for(int i=0; i<m_boxplotData.size(); ++i) {
        QJsonArray jsonInnerArray;
        for(int j=0; j<m_boxplotData[i].size(); ++j) {
            QJsonObject object;
            object["whiskersBottom"]=m_boxplotData[i][j][0];
            object["firstQuartile"] =m_boxplotData[i][j][1];
            object["secondQuartile"]=m_boxplotData[i][j][2];
            object["thirdQuartile"] =m_boxplotData[i][j][3];
            object["whiskersTop"]   =m_boxplotData[i][j][4];
            jsonInnerArray.append(object);
        }
        jsonArray.append(jsonInnerArray);
    }
    m_boxplotDataJson.setArray(jsonArray);
}

void VisualisationDataModel::setBoxplotData(const QVector<QVector<QVector<qreal> > > &boxPlotData)
{
    if(boxPlotData.size() == 0 || boxPlotData.size() != m_data.size()) {
        return;
    }
    for(int i=0; i<boxPlotData.size(); ++i) {
        if(boxPlotData[i].size() != m_data[i].size()) {
            return;
        }
    }
    m_boxplotData = boxPlotData;
    generateBoxplotJsonDcoument();
}

QJsonDocument VisualisationDataModel::boxplotDataJson() const
{
    return m_boxplotDataJson;
}

QVariantList VisualisationDataModel::selectedIndices() const
{
    return m_selectedIndices;
}

void VisualisationDataModel::setSelectedIndices(const QVariantList &selectedIndices)
{
    m_selectedIndices = selectedIndices;
}
