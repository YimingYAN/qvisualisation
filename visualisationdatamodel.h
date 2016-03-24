#ifndef VISUALISATIONDATAMODEL_H
#define VISUALISATIONDATAMODEL_H

#include <QStringList>
#include <QString>
#include <QVector>
#include <QObject>

namespace Visualisation {
/*!
 * \brief The data object
 */
class VisualisationDataModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString dataString MEMBER m_dataString
               READ dataString NOTIFY dataChanged)


public:
    explicit VisualisationDataModel(QObject *parent = nullptr);
    void setDate(QVector<QVector<qreal> > data);
    void setNames(QStringList names);

    QString dataString() const;
    QStringList allNames() const;

    int dataRows() const;
    int dataCols() const;

signals:
    void dataChanged();

public slots:

private:
    QVector<QVector<qreal> > m_data;
    QStringList m_names;
    QString     m_dataString;
};

}
#endif // VISUALISATIONDATAMODEL_H
