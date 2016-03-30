/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2015 Yiming Yan
****************************************************************************/
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
               READ allNames WRITE setNames NOTIFY namesChanged)
    Q_PROPERTY(int dataRows READ dataRows NOTIFY dataChanged)
    Q_PROPERTY(QVariantList selectedIndices READ selectedIndices
               WRITE setSelectedIndices NOTIFY selectedIndicesChanged)

public:
    explicit VisualisationDataModel(QObject *parent = nullptr);
    void setData(const QVector<QVector<qreal> > &data,
                 const QStringList &names);
    void setData(const QVector<QVector<qreal> > &data);
    void setNames(const QStringList &names);

    QStringList allNames() const;
    QJsonDocument dataJson() const;

    int dataRows() const;
    int dataCols() const;

    QVariantList selectedIndices() const;
    void setSelectedIndices(const QVariantList &selectedIndices);

signals:
    void dataChanged();
    void namesChanged();
    void selectedIndicesChanged();

public slots:

private:
    void generateDataJsonDocument();
    QVector<QVector<qreal> > m_data;
    QJsonDocument m_dataJson;
    QStringList   m_names;
    QVariantList  m_selectedIndices; // List<int> is not recognised by js
};

}
#endif // VISUALISATIONDATAMODEL_H
