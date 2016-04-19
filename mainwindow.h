#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include <QPaintDevice>
#include <QGridLayout>
#include <QTextEdit>
#include <QLineEdit>

#include <QLabel>
#include <QDebug>

#include "displaygraph.h"
#include "displayvalues.h"
#include "console.h"
#include "status.h"


class Console;
class Status;
class DisplayValues;
class Compute;
class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

    Console *console;
    DisplayGraph *graph;
    DisplayValues *disp;
    Status *statusBar;
    QLabel *consLabel;
    Compute *cmpt;

    //QLabel *degree;
    //QLabel *theMin;
    //QLabel *theMax;

private:
    QLabel *polyDeg;

    QLabel *interval;
    QLabel *xmin;

    QLabel *xmax;

};

#endif // MAINWINDOW_H
