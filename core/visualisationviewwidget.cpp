/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include "ui_visualisationviewwidget.h"
#include <visualisation/core/visualisationviewwidget.h>
#include <visualisation/core/visualisationdatamodel.h>
#include <visualisation/core/visualisationviewmodel.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPainter>
#include <QPrinter>
#include <QSvgGenerator>
#include <QDebug>

using namespace Visualisation;

enum ImageFormat {
    IMG_SVG,
    IMG_PDF,
    IMG_EPS,
    IMG_JPEG,
    IMG_JPG,
    IMG_PNG,
    IMG_TIFF
};

VisualisationViewWidget::VisualisationViewWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VisualisationViewWidget)
    , m_data(0)
    , m_view(0)
{
    ui->setupUi(this);
    ui->centralwidget->setContentsMargins(0,0,0,0);
}

VisualisationViewWidget::~VisualisationViewWidget()
{
    delete ui;
    if(m_data) {
        delete m_data;
    }
    if(m_view) {
        delete m_view;
    }
}

VisualisationViewModel *VisualisationViewWidget::view() const
{
    return m_view;
}

VisualisationDataModel *VisualisationViewWidget::data() const
{
    return m_data;
}

void VisualisationViewWidget::setData(const QVector<QVector<qreal> > &dataVec, const QStringList &names)
{
    m_data->setData(dataVec, names);
}

void VisualisationViewWidget::setSelectedIndices(const QVariantList &selected)
{
    m_data->setSelectedIndices(selected);
}

void VisualisationViewWidget::on_actionSave_triggered()
{
    QString fname = QFileDialog::getSaveFileName(this,"Save...",
                                                 QDir::currentPath(),
                                                 "Image Type (*.png)");
    if(fname.isEmpty()) {
        return;
    }

    QImage image(m_view->geometry().width(), m_view->geometry().height(),
                 QImage::Format_ARGB32_Premultiplied);

    //image.fill(Qt::transparent);
    image.fill(Qt::white);
    QPainter painter(&image);
    m_view->render(&painter);
    painter.end();
    image.save(fname);
}

void VisualisationViewWidget::on_actionSave_As_triggered()
{
    QString selectedFilter;
    QString nfilters("PNG (*.png);;SVG (*.svg);;PDF (*.pdf);;EPS (*.eps);;TIFF (*.tiff);;JPG (*.jpg);;JPEG (*.jpeg)");
    QString fname = QFileDialog::getSaveFileName(this, "Save As...",
                                                 QDir::homePath(),
                                                 nfilters,
                                                 &selectedFilter);
    if(fname.isEmpty()) {
        return;
    }


    QFileInfo finfo = QFileInfo(fname);

    QString suffix;
    QString bpath  = finfo.absolutePath();
    QString bfname = finfo.baseName();

    ImageFormat format;

    if(selectedFilter=="PNG (*.png)") {
        format = IMG_PNG;
        suffix = "png";
    }
    if(selectedFilter=="SVG (*.svg)") {
        format = IMG_SVG;
        suffix = "svg";
    }
    if(selectedFilter=="PDF (*.pdf)") {
        format = IMG_PDF;
        suffix = "pdf";
    }
    if(selectedFilter=="EPS (*.eps)") {
        format = IMG_EPS;
        suffix = "eps";
    }
    if(selectedFilter=="TIFF (*.tiff)") {
        format = IMG_TIFF;
        suffix = "tiff";
    }
    if(selectedFilter=="JPG (*.jpg)") {
        format = IMG_JPG;
        suffix = "jpg";
    }
    if(selectedFilter=="JPEG (*.jpeg)") {
        format = IMG_JPEG;
        suffix = "jpeg";
    }

    fname = bpath+"/"+bfname+"."+suffix;
    fname = QDir::toNativeSeparators(fname);

    QPainter painter;
    int width = m_view->geometry().width();
    int height= m_view->geometry().height();

    switch(format) {
    case IMG_SVG: {
        QSvgGenerator svg;
        svg.setFileName(fname);
        QSize size(width,height);
        svg.setSize(size);
        painter.begin(&svg);
        m_view->render(&painter);
        painter.end();
    }
        break;

        /// \todo Yiming PDF and EPS printing not working
    case IMG_EPS:
    case IMG_PDF: {
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        //printer.setPageSize(QPrinter::A4);
        printer.setResolution(QPrinter::HighResolution);
        printer.setOutputFileName(fname);
        if (!painter.begin(&printer)) { // failed to open file
             QMessageBox::warning(this,
                                  "Cannot Print",
                                   "failed to open file, is it writable?");
             return;
        }
        m_view->render(&painter);
        painter.end();
    }
        break;

    case IMG_TIFF:
    case IMG_JPEG:
    case IMG_JPG:
    case IMG_PNG: {
        QSize size(width,height);
        QImage image(size, QImage::Format_ARGB32);
        image.fill(Qt::white);
        painter.begin(&image);
        m_view->render(&painter);
        painter.end();
        // TODO -Yiming Add quality control
        image.save(fname, suffix.toLocal8Bit(), 100);
    }
        break;

    default:
        QMessageBox::warning(this,"Unknown file extension.","Unknown file extension. File not saved.");
    }
}

void VisualisationViewWidget::setView(VisualisationViewModel *view)
{
    m_view = view;
    m_data = view->dataModel();
}
