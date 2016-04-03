/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#ifndef VISUALISATIONVIEWMODEL_H
#define VISUALISATIONVIEWMODEL_H

#include <QWebEngineView>
#include <QString>

namespace Visualisation {
class VisualisationDataModel;

/*!
 * \brief The View Model
 */
class VisualisationViewModel : public QWebEngineView
{

public:
    explicit VisualisationViewModel(QWidget *parent = nullptr);
    virtual void setDataModel(VisualisationDataModel* dataModel);
    VisualisationDataModel *dataModel() const;
    virtual void linkWithJavaScript();
    virtual ~VisualisationViewModel();


private:
    VisualisationDataModel* m_dataModel;
};
}
#endif // VISUALISATIONVIEWMODEL_H
