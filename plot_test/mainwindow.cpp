#include <QLabel>
#include <QLayout>
#include <QFont>

#include "mainwindow.h"
#include "qcustomplot.h"
#include "plotwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout;

    PlotWidget *plotW = new PlotWidget(this);

    verticalLayout->addWidget(plotW);

    // Set layout in QWidget
    QWidget *window = new QWidget();
    window->setLayout(verticalLayout);

    // Set QWidget as the central layout of the main window
    setCentralWidget(window);
}



MainWindow::~MainWindow()
{

}
