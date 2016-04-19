#include "mainwindow.h"
#include "compute.h"
//#include "displayvalues.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    graph = new DisplayGraph(this);
    //this->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    console = new Console(this);
    //console->setGeometry(80, 530, 200, 30);

    consLabel = new QLabel(this);
    consLabel->setGeometry(15,530,100,30);
    consLabel->setText("Console:");

    disp = new DisplayValues(this);

    cmpt = new Compute(this);

    statusBar = new Status(this);
    statusBar->setGeometry(80,563,100,30);

    polyDeg = new QLabel(this);
        polyDeg->setGeometry(15,15,200,30);
            polyDeg->setText("Degree of polynom:");

    interval = new QLabel(this);
        interval->setGeometry(500,15,50,30);
            interval->setText("Interval:");

    xmin = new QLabel(this);
        xmin->setGeometry(560,15,50,30);
            xmin->setText("Xmin:");

    /*theMin = new QLabel(this);
    theMin->setGeometry(570, 15, 50, 15);
    theMin->setText("x1");*/

    xmax = new QLabel(this);
        xmax->setGeometry(650, 15, 50, 30);
            xmax->setText("Xmax:");

     /*theMax = new QLabel(this);
     theMax->setGeometry(660, 15, 50, 15);
     theMax->setText("x2");*/

     /*connect(this->console,SIGNAL(sigDegree(QString)),this,SLOT(onDegree(QString)));
     connect(this->console,SIGNAL(sigInterMin(QString)), this,SLOT(onInterMin(QString)));
     connect(this->console, SIGNAL(sigInterMax(QString)), this, SLOT(onInterMax(QString)));*/
     show();
}

MainWindow::~MainWindow()
{
    delete console;
    delete consLabel;
    delete disp;
    delete polyDeg;
    delete cmpt;
    //delete degree;
    delete interval;
    delete xmax;
    //delete theMin;
    //delete theMax;
    delete xmin;

}

/*void onDegree(QString deg)
{

   // MainWindow::degree->setText(deg);

}
void onInterMin(QString min)
{

     //MainWindow::theMin->setText(min);
}
void onInterMax(QString max)
{

     //MainWindow::theMax->setText(max);
}

*/
