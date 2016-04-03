/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#ifndef VISUALISATIONVIEWWIDGET_H
#define VISUALISATIONVIEWWIDGET_H

#include <QMainWindow>
#include <QVariantList>
#include <QVector>
#include <QGridLayout>

namespace Ui {
class VisualisationViewWidget;
}

namespace Visualisation {
class VisualisationDataModel;
class VisualisationViewModel;

class VisualisationViewWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit VisualisationViewWidget(QWidget *parent = 0);
    ~VisualisationViewWidget();

    /*!
     * \brief Initialise your visualisation widget. This function must be called
     * inside the inherited classes' constrcutors.
     * In the function, you should:
     * 1. Create data model
     * 2. Create view model and set the data model to the view model
     * 3. Set view model to the widget
     * 4. Update mainwindow name using setWindowTitle(const QString &title) function
     */
    virtual void initialise() = 0;

    void setView(VisualisationViewModel *view);
    VisualisationViewModel *view() const;
    VisualisationDataModel *data() const;

    virtual void setData(const QVector<QVector<qreal> >& dataVec,
                         const QStringList& names);
    virtual void setSelectedIndices(const QVariantList &selected);

private slots:
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();

private:
    Ui::VisualisationViewWidget *ui;
    VisualisationDataModel      *m_data;
    VisualisationViewModel      *m_view;
};

}

#endif // VISUALISATIONVIEWWIDGET_H
