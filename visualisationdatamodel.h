#ifndef VISUALISATIONDATAMODEL_H
#define VISUALISATIONDATAMODEL_H

#include <QStringList>
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

public:
    explicit VisualisationDataModel(QObject *parent = nullptr);
    void setData(QVector<QVector<qreal> > data, QStringList names);
    void setData(QVector<QVector<qreal> > data);
    void setNames(QStringList names);

    QStringList allNames() const;
    QJsonDocument dataJson() const;

    int dataRows() const;
    int dataCols() const;

signals:
    void dataChanged();

public slots:

private:
    void generateJsonDocument();
    QVector<QVector<qreal> > m_data;
    QStringList m_names;
    QString     m_dataString;
    QJsonDocument m_dataJson;
};

}
#endif // VISUALISATIONDATAMODEL_H
