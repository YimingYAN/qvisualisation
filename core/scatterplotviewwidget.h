/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2015 Yiming Yan
****************************************************************************/
#ifndef SCATTERPLOTVIEWWIDGET_H
#define SCATTERPLOTVIEWWIDGET_H
#include <visualisation/core/visualisationviewwidget.h>
#include <QObject>

class QComboBox;
class QPushButton;

namespace Visualisation {

class ScatterPlotViewWidget : public VisualisationViewWidget
{
    Q_OBJECT

public:
    explicit ScatterPlotViewWidget(QWidget *parent = 0);
    ~ScatterPlotViewWidget();
    void initialise();
    void setData(const QVector<QVector<qreal> > &dataVec,
                 const QStringList &names);

private slots:
    void updateSelectedIndices();

private:
    QComboBox* m_xCombo;
    QComboBox* m_yCombo;
    QPushButton* m_button;
};

}

#endif // SCATTERPLOTVIEWWIDGET_H
