#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T17:08:22
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plot-test
TEMPLATE = app
INCLUDEPATH += d:/topka/plot_test

#this stuff is shit!!!
#win32 {
#    win32-msvc:LIBS += d:/topka/plot_test/ easy_profiler
#    #LIBS += d:/topka/plot_test/easy_profiler.lib
#}
#    #win32-msvc:LIBS += d:/topka/plot_test/easy_profiler.lib

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    plotwidget.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    plotwidget.h \
    profiler.h
