#include <visualisation/core/scatterplotviewwidget.h>
#include <visualisation/core/visualisationdatamodel.h>
#include <visualisation/core/scatterplotviewmodel.h>

#include <QDebug>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>

using namespace Visualisation;

ScatterPlotViewWidget::ScatterPlotViewWidget(QWidget *parent)
    : VisualisationViewWidget(parent)
    , m_xCombo(0)
    , m_yCombo(0)
    , m_button(0)
{
    initialise();
}

ScatterPlotViewWidget::~ScatterPlotViewWidget()
{
    if(m_xCombo)
        delete m_xCombo;
    if(m_yCombo)
        delete m_yCombo;
    if(m_button)
        delete m_button;
}

void ScatterPlotViewWidget::initialise()
{
    VisualisationDataModel* dataModel = new VisualisationDataModel;
    ScatterPlotViewModel* view = new ScatterPlotViewModel(this);
    view->setDataModel(dataModel);
    view->linkWithJavaScript();
    setView(view);

    QHBoxLayout* hlayout = new QHBoxLayout();
    QLabel* xLabel = new QLabel("X: ", centralWidget());
    m_xCombo = new QComboBox(centralWidget());
    QLabel* yLabel = new QLabel("Y: ", centralWidget());
    m_yCombo = new QComboBox(centralWidget());
    m_button = new QPushButton("Refresh", centralWidget());
    connect(m_button, SIGNAL(clicked()), this, SLOT(updateSelectedIndices()));
    hlayout->addWidget(xLabel);
    hlayout->addWidget(m_xCombo);
    hlayout->insertSpacing(2, 30);
    hlayout->addWidget(yLabel);
    hlayout->addWidget(m_yCombo);
    hlayout->addWidget(m_button);
    hlayout->insertSpacing(5, 30);
    hlayout->addStretch(2);
    centralWidget()->layout()->addItem(hlayout);
    centralWidget()->layout()->addWidget(view);
    centralWidget()->setMinimumSize(200, 200);
    setWindowTitle(QString("Scatter Plot"));
}

void ScatterPlotViewWidget::setData(const QVector<QVector<qreal> > &dataVec,
                                    const QStringList &names)
{
    VisualisationViewWidget::setData(dataVec, names);
    m_xCombo->insertItems(0, names);
    m_yCombo->insertItems(0, names);
    m_xCombo->setCurrentIndex(0);
    m_yCombo->setCurrentIndex(1);
}

void ScatterPlotViewWidget::updateSelectedIndices()
{
    QVariantList selection;
    selection.append(QVariant::fromValue(m_xCombo->currentIndex()));
    selection.append(QVariant::fromValue(m_yCombo->currentIndex()));
    setSelectedIndices(selection);
}
