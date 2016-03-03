#include "plotwidget.h"
#include "qcustomplot.h"
#include <QLabel>
#include <QLayout>

void PlotWidget::setupBarChart(QCustomPlot *customPlot)
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


  customPlot->xAxis->setAutoTicks(false);
  customPlot->xAxis->setAutoTickLabels(false);
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

  // setup legend:
  customPlot->legend->setVisible(true);
  customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
  customPlot->legend->setBrush(QColor(255, 255, 255, 200));
  QPen legendPen;
  legendPen.setColor(QColor(130, 130, 130, 200));
  customPlot->legend->setBorderPen(legendPen);

  //setup zoom only for one axis:
  customPlot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
  customPlot->axisRect(0)->setRangeZoom(Qt::Horizontal);
  customPlot->axisRect(0)->setRangeDrag(Qt::Horizontal);

  setData(timeBlock,customPlot->xAxis);
}
int N = 100000;
void PlotWidget::setData(QCPBars *_bar,QCPAxis *_xAxis)
{
    // prepare x axis with labels:
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> someData;
    for(int i=0; i< N; i++){
         ticks << i;
         labels << "some"+QString::number(i);
     }
    for(int i=0; i< N; i++){
         someData << (qrand() % 50);
     }
    _xAxis->setTickVector(ticks);
    _xAxis->setTickVectorLabels(labels);
    _bar->setData(ticks, someData);
}

PlotWidget::PlotWidget(QWidget *parent) : QWidget(parent)
{    
    QVBoxLayout *verticalLayout = new QVBoxLayout;

    QCustomPlot *customPlot = new QCustomPlot(this);
    customPlot->setObjectName(QStringLiteral("customPlot"));
    verticalLayout->addWidget(customPlot);
    setLayout(verticalLayout);

    setupBarChart(customPlot);
}
