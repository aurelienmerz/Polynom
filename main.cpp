#include <QtGui/QApplication>
#include <QObject>
#include "mainwindow.h"
#include "console.h"
#include "parser.h"
//#include "compute.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Parser *p = new Parser();
    //Compute *cmpt = new Compute();

    /************** Connecting signals & slots between parser and the compute section ***************/

    QObject::connect(p,SIGNAL(sigDegreeOfPoly(int)),w.cmpt,SLOT(onDegreeOfPoly(int)));
    QObject::connect(p,SIGNAL(sigCoeff2BeComputed(double)),w.cmpt,SLOT(onCoeff2Compute(double)));
    QObject::connect(p,SIGNAL(sigInterval(double,double)),w.cmpt,SLOT(onInterval(double,double)));
    QObject::connect(p,SIGNAL(sigCompute()),w.cmpt,SLOT(onComputePoints()));

    /*************** Connecting signals & slots between parser and displayValues ***************/
    QObject::connect(p,SIGNAL(sigSend2Values(QString)),w.disp,SLOT(onValuesFromParser(QString)));

    /*************** Connecting signals & slots between parser and displayGrapher ***************/
    QObject::connect(p,SIGNAL(sigClearPlot()),w.graph,SLOT(onClearPlot()));

    /*************** Connecting signals & slots between parser and console from MainWindow ***************/
    QObject::connect(w.console,SIGNAL(sigNewCmd(QString)),p,SLOT(onNewCmd(QString)));
    QObject::connect(p,SIGNAL(sigEndOfEntries()), w.console,SLOT(onEndOfEntries()));
    QObject::connect(p,SIGNAL(sigWarnStatus(QString)), w.statusBar,SLOT(actualStatus(QString)));



    /*************** Connecting signals & slots between compute and displayGraph ***************/
    QObject::connect(w.cmpt,SIGNAL(sigSendPts2Display(double,double)),w.graph,SLOT(onPtsReceived(double,double)));
    QObject::connect(w.cmpt,SIGNAL(sigEndOfComputing()),w.graph,SLOT(onEndOfComputing()));
    QObject::connect(w.cmpt,SIGNAL(sigInterval(double)),w.graph,SLOT(onInterval(double)));
    QObject::connect(w.cmpt,SIGNAL(sigSendPts4Show(double,double)),w.disp,SLOT(onPtsReceived(double,double)));

    /*************** Connecting signals & slots between displayGraph and all other ***************/
    QObject::connect(w.console,SIGNAL(sigResetAllMaps()),w.cmpt,SLOT(onResetAllMaps()));
    QObject::connect(w.console,SIGNAL(sigResetAllMaps()),p,SLOT(onResetMap()));
    QObject::connect(w.console,SIGNAL(sigResetAllMaps()),w.disp,SLOT(onResetMap()));
    QObject::connect(w.console,SIGNAL(sigResetAllMaps()),w.graph,SLOT(onClearPlot()));
    QObject::connect(w.cmpt,SIGNAL(sigNextOpEnable()),w.console,SLOT(onNextOpEnable()));
    QObject::connect(w.console,SIGNAL(sigResetAllMaps()),w.statusBar,SLOT(onReset()));


    w.setWindowTitle("Polynom Grapher");
    w.setGeometry(50,100,1200,600);

    return a.exec();
}
