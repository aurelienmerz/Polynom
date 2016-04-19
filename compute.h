#ifndef COMPUTE_H
#define COMPUTE_H

//#include "parser.h"
#include "polynom.h"
#include <QDebug>
#include <QPoint>
#include <QProgressBar>
#include <qmath.h>
#include "mainwindow.h"
class Parser;

class Compute : public QObject
{
    Q_OBJECT
public:
    Compute();
    Compute(MainWindow *mw);

    ~Compute();
    void resetProgressBar();
    void computePoints();
    void sendValues();

signals:
    void sigSendPts2Display(double x, double y);
    void sigSendPts4Show(double x, double y);
    void sigEndOfComputing();
    void sigInterval(double);
    void sigNextOpEnable();


public slots:
    void onCoeff2Compute(double c);
    void onInterval(double x1, double x2);
    void onDegreeOfPoly(int d);
    void onComputePoints();
    void onResetAllMaps();

private:

    int idx;
    int ptIndex;
    int idxCmpt;
    int degCmpt;
    int lenghtOfMap;
    double y;

    QMap <int,double> yCoords; //map with all the computed y coord
    QMap <int,double> xCoords; //map with all the x
    QMap <int,double> coeffForCmpt; //map with coeff received from parser
    QMap <int,int> exponents; //map with the exponents

    double step;
    double xMin;
    double xMAx;
    double interval;
    QProgressBar *b;
    double getPointAtIndex(int idx);

    //QPoint pointArray[]; //array of all computed points

};

#endif // COMPUTE_H
