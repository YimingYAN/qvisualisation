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
    , m_scatter(0)
    , m_mscatter(0)
    , m_parallcoord(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_scatter;
    delete m_mscatter;
    delete m_parallcoord;
}

void MainWindow::on_demoButton_clicked()
{
    m_scatter = new ScatterPlotViewWidget;
    m_mscatter = new MatrixScatterPlotViewWidget;
    m_parallcoord = new ParallelCoordinatesPlotViewWidget;

    int numData = 1000;
    int numCols = 5;
    QVector<QVector<qreal> > data;
    QStringList names;
    QVariantList selectedIndices;
    data.resize(numData);

    for(int i=0; i<numCols; ++i) {
        names.append(QString("DataItem" + QString::number(i)));
    }
    for(int i=0; i<numData; ++i) {
        for(int j=0; j<numCols; ++j) {
            qreal bias = 1.0*qrand()/RAND_MAX;
            qreal value = bias*(i+j);
            data[i].append(value);
        }
    }
    for(int i=0; i<numCols; ++i) {
        selectedIndices.append(i);
    }

    m_scatter->setData(data, names);
    m_scatter->setSelectedIndices(selectedIndices);
    m_scatter->show();

    m_mscatter->setData(data, names);
    m_mscatter->setSelectedIndices(selectedIndices);
    m_mscatter->show();

    m_parallcoord->setData(data, names);
    m_parallcoord->setSelectedIndices(selectedIndices);
    m_parallcoord->show();
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
        m_scatter = new ScatterPlotViewWidget;
        m_scatter->setData(data, names);
        m_scatter->setSelectedIndices(selectedIndices);
        m_scatter->show();
    }
    if(ui->matrixScatter->isChecked()) {
        m_mscatter = new MatrixScatterPlotViewWidget;
        m_mscatter->setData(data, names);
        m_mscatter->setSelectedIndices(selectedIndices);
        m_mscatter->show();
    }
    if(ui->paralCoord->isChecked()) {
        m_parallcoord = new ParallelCoordinatesPlotViewWidget;
        m_parallcoord->setData(data, names);
        m_parallcoord->setSelectedIndices(selectedIndices);
        m_parallcoord->show();
    }
}
