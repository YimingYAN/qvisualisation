#ifndef VISUALISATIONVIEWMODEL_H
#define VISUALISATIONVIEWMODEL_H

#include <QWebEngineView>
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
    virtual ~VisualisationViewModel();

protected:

private:
    VisualisationDataModel* m_dataModel;
};
}
#endif // VISUALISATIONVIEWMODEL_H
