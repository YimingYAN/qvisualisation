/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <core/scatterplotviewwidget.h>
#include <core/matrixscatterplotviewwidget.h>
#include <core/parallelcoordinatesplotviewwidget.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDir>

#include <QDebug>

using namespace Visualisation;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_demoButton_clicked()
{
    VisualisationViewWidget* scatter = new ScatterPlotViewWidget(this);
    VisualisationViewWidget* mscatter = new MatrixScatterPlotViewWidget(this);
    VisualisationViewWidget* parallcoord = new ParallelCoordinatesPlotViewWidget(this);

    int numData = 1000;
    int numCols = 5;

    QStringList names;
    for(int i=0; i<numCols; ++i) {
        names.append(QString("DataItem" + QString::number(i)));
    }

    // Random data
    QVector<QVector<qreal> > data;
    data.resize(numData);
    for(int i=0; i<numData; ++i) {
        data[i].reserve(numCols);
        for(int j=0; j<numCols; ++j) {
            qreal bias = 1.0*qrand()/RAND_MAX;
            qreal value = bias*(i+j);
            data[i].append(value);
        }
    }

    // Populate selected indices
    QVariantList selectedIndices;
    selectedIndices.reserve(numCols);
    for(int i=0; i<numCols; ++i) {
        selectedIndices.append(i);
    }

    scatter->setData(data, names);
    scatter->setAttribute(Qt::WA_DeleteOnClose);
    scatter->setSelectedIndices(selectedIndices);
    scatter->show();

    mscatter->setData(data, names);
    mscatter->setAttribute(Qt::WA_DeleteOnClose);
    mscatter->setSelectedIndices(selectedIndices);
    mscatter->show();

    parallcoord->setData(data, names);
    parallcoord->setAttribute(Qt::WA_DeleteOnClose);
    parallcoord->setSelectedIndices(selectedIndices);
    parallcoord->show();
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    QDir::homePath(),
                                                    tr("Data Files (*.csv)"));
    if(!fileName.isEmpty()) {
        ui->filePathLineEdit->setText(fileName);
    }
}

void MainWindow::on_plotButton_clicked()
{
    QString fileName = ui->filePathLineEdit->text();
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this,
                             tr("Open File Error"),
                             file.errorString(),
                             QMessageBox::Ok);
        return;
    }

    int counter = 0;
    QVector<QVector<qreal> > data;
    QStringList names;
    QVariantList selectedIndices;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        line = line.trimmed();
        QString str(line);
        if(counter == 0) {
            names = str.split(",");
            qDebug() << names;
        } else {
            QStringList strlist = str.split(",");
            QVector<qreal> tmp;
            for(int i=0; i<strlist.length(); ++i) {
                tmp.append(strlist[i].toDouble());
            }
            data.append(tmp);
        }
        qDebug() << "counter: " << counter << line;
        ++counter;
    }

    if(data.size() == 0) {
        QMessageBox::warning(this,
                             tr("Open File Error"),
                             tr("No data."),
                             QMessageBox::Ok);
        return;
    }
    int numCols = data[0].size();
    for(int i=0; i<numCols; ++i) {
        selectedIndices.append(i);
    }

    if(ui->scatter->isChecked()) {
        VisualisationViewWidget* scatter = new ScatterPlotViewWidget(this);
        scatter->setAttribute(Qt::WA_DeleteOnClose);
        scatter->setData(data, names);
        scatter->setSelectedIndices(selectedIndices);
        scatter->show();
    }
    if(ui->matrixScatter->isChecked()) {
        VisualisationViewWidget* mscatter = new MatrixScatterPlotViewWidget(this);
        mscatter->setAttribute(Qt::WA_DeleteOnClose);
        mscatter->setData(data, names);
        mscatter->setSelectedIndices(selectedIndices);
        mscatter->show();
    }
    if(ui->paralCoord->isChecked()) {
        VisualisationViewWidget* parallcoord = new ParallelCoordinatesPlotViewWidget(this);
        parallcoord->setAttribute(Qt::WA_DeleteOnClose);
        parallcoord->setData(data, names);
        parallcoord->setSelectedIndices(selectedIndices);
        parallcoord->show();
    }
}
