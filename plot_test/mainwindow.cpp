#include "mainwindow.h"
#include "qcustomplot.h"
#include <QLabel>
#include <QLayout>
#include <QFont>

void setupBarChartDemo(QCustomPlot *customPlot)
{
  // create empty bar chart objects:
  QCPBars *timeBlock = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  timeBlock->setWidthType(QCPBars::wtPlotCoords);
  timeBlock->setWidth(1);
  customPlot->addPlottable(timeBlock);
  // set names and colors:
  QPen pen;
  pen.setWidthF(1.2);
  pen.setColor(QColor(255, 131, 0));
  timeBlock->setName("timeBlockerative");
  pen.setColor(QColor(150, 222, 0));
  timeBlock->setPen(pen);
  timeBlock->setBrush(QColor(150, 222, 0, 70));

  // prepare x axis with country labels:
  QVector<double> ticks;
  QVector<QString> labels;
  ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
  labels << "block1" << "block2" << "block3" << "block4" << "block5" << "block6" << "block7";
  customPlot->xAxis->setAutoTicks(false);
  customPlot->xAxis->setAutoTickLabels(false);
  customPlot->xAxis->setTickVector(ticks);
  customPlot->xAxis->setTickVectorLabels(labels);
  customPlot->xAxis->setSubTickCount(0);
  customPlot->xAxis->grid()->setVisible(false);
  customPlot->xAxis->setRange(0, 8);

  // prepare y axis:
  customPlot->yAxis->setRange(0, 12.1);
  customPlot->yAxis->setPadding(1); // a bit more space to the left border
  customPlot->yAxis->setLabel("time in mlsecs");
  customPlot->yAxis->grid()->setSubGridVisible(true);
  QPen gridPen;
  gridPen.setStyle(Qt::SolidLine);
  gridPen.setColor(QColor(0, 0, 0, 25));
  customPlot->yAxis->grid()->setPen(gridPen);
  gridPen.setStyle(Qt::DotLine);
  customPlot->yAxis->grid()->setSubGridPen(gridPen);

  // Add data:
  QVector<double> someData;
  someData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;

  timeBlock->setData(ticks, someData);

  // setup legend:
  customPlot->legend->setVisible(true);
  customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
  customPlot->legend->setBrush(QColor(255, 255, 255, 200));
  QPen legendPen;
  legendPen.setColor(QColor(130, 130, 130, 200));
  customPlot->legend->setBorderPen(legendPen);

  //setup zoom only for one axis
  customPlot->setInteractions(QCP::iRangeZoom);
  customPlot->axisRect(0)->setRangeZoom(Qt::Horizontal);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    QCustomPlot *customPlot = new QCustomPlot(this);
    customPlot->setObjectName(QStringLiteral("customPlot"));

    verticalLayout->addWidget(customPlot);

    setCentralWidget(customPlot);
    setupBarChartDemo(customPlot);
}



MainWindow::~MainWindow()
{

}
