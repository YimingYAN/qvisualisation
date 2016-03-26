#ifndef VISUALISATIONDATAMODEL_H
#define VISUALISATIONDATAMODEL_H

#include <QStringList>
#include <QVariantList>
#include <QString>
#include <QVector>
#include <QJsonDocument>
#include <QObject>

namespace Visualisation {
/*!
 * \brief The data object
 */
class VisualisationDataModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QJsonDocument dataJson MEMBER m_dataJson
               READ dataJson NOTIFY dataChanged)
    Q_PROPERTY(QJsonDocument boxplotDataJson MEMBER m_boxplotDataJson
               READ boxplotDataJson NOTIFY boxplotDataChanged)
    Q_PROPERTY(QStringList allNames
               READ allNames WRITE setNames NOTIFY dataChanged)
    Q_PROPERTY(int dataRows READ dataRows)
    Q_PROPERTY(QVariantList selectedIndices READ selectedIndices
               WRITE setSelectedIndices NOTIFY selectedIndicesChanged)

public:
    explicit VisualisationDataModel(QObject *parent = nullptr);
    void setData(const QVector<QVector<qreal> > &data,
                 const QStringList &names);
    void setData(const QVector<QVector<qreal> > &data);
    void setBoxplotData(const QVector<QVector<QVector<qreal> > > &boxPlotData);
    void setNames(const QStringList &names);

    QStringList allNames() const;
    QJsonDocument dataJson() const;
    QJsonDocument boxplotDataJson() const;

    int dataRows() const;
    int dataCols() const;

    QVariantList selectedIndices() const;
    void setSelectedIndices(const QVariantList &selectedIndices);

signals:
    void dataChanged();
    void selectedIndicesChanged();
    void boxplotDataChanged();

public slots:

private:
    void generateDataJsonDocument();
    void generateBoxplotJsonDcoument();
    QVector<QVector<qreal> > m_data;
    QJsonDocument m_dataJson;
    QVector<QVector<QVector<qreal> > >  m_boxplotData;
    QJsonDocument m_boxplotDataJson;
    QStringList   m_names;
    QString       m_dataString;
    QVariantList  m_selectedIndices; // List<int> is not recognised by js
};

}
#endif // VISUALISATIONDATAMODEL_H
