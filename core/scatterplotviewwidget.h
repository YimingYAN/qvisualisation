#ifndef SCATTERPLOTVIEWWIDGET_H
#define SCATTERPLOTVIEWWIDGET_H
#include <visualisation/core/visualisationviewwidget.h>

namespace Visualisation {

class ScatterPlotViewWidget : public VisualisationViewWidget
{
public:
    explicit ScatterPlotViewWidget(QWidget *parent = 0);
    void initialise();
};

}

#endif // SCATTERPLOTVIEWWIDGET_H
