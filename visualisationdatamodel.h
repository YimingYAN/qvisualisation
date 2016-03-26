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
    Q_PROPERTY(QStringList allNames
               READ allNames WRITE setNames NOTIFY dataChanged)
    Q_PROPERTY(int dataRows READ dataRows)
    Q_PROPERTY(QVariantList selectedIndices READ selectedIndices
               WRITE setSelectedIndices NOTIFY selectedIndicesChanged)

public:
    explicit VisualisationDataModel(QObject *parent = nullptr);
    void setData(QVector<QVector<qreal> > data, QStringList names);
    void setData(QVector<QVector<qreal> > data);
    void setNames(QStringList names);

    QStringList allNames() const;
    QJsonDocument dataJson() const;

    int dataRows() const;
    int dataCols() const;

    QVariantList selectedIndices() const;
    void setSelectedIndices(const QVariantList &selectedIndices);

signals:
    void dataChanged();
    void selectedIndicesChanged();

public slots:

private:
    void generateJsonDocument();
    QVector<QVector<qreal> > m_data;
    QStringList   m_names;
    QString       m_dataString;
    QJsonDocument m_dataJson;
    QVariantList  m_selectedIndices; // List<int> is not recognised by js
};

}
#endif // VISUALISATIONDATAMODEL_H
