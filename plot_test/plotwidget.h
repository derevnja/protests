#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>

class QCustomPlot;
class QCPBars;
class QCPAxis;
class QLabel;

class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = 0);

signals:

public slots:
private:
    //QLabel *m_someLabel;
    QCustomPlot *customPlot;
    ///create chart and fill it with data
    void setupBarChart(QCustomPlot *customPlot);
    ///set data to visualize on bars
    void setData(QCPBars *_bar,QCPAxis *_xAxis);
};

#endif // PLOTWIDGET_H
