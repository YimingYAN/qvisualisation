#ifndef VISUALISATIONDATAMODEL_H
#define VISUALISATIONDATAMODEL_H

#include <QObject>

namespace Visualisation {
/*!
 * \brief The data object
 */
class VisualisationDataModel : public QObject
{
    Q_OBJECT

public:
    explicit VisualisationDataModel(QObject *parent = nullptr);
    void setDate(QVector<QVector<qreal> > data);
    void setNames(QStringList names);

signals:

public slots:

};
}
#endif // VISUALISATIONDATAMODEL_H
