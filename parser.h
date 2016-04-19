#ifndef PARSER_H
#define PARSER_H

#include "compute.h"
#include "polynom.h"
#include <QObject>
#include <iostream>
#include <QString>
#include <QMap>
#include <QChar>
#include <QDebug>

using namespace std;
class Console;
class Status;
//class Compute;
class Parser : public QObject
{
    Q_OBJECT
public:
    Parser();
    ~Parser();

    void commandChecking(QString s); //checking if the command is correct
    //void setCoeffAtIndex(int idx, double c); //allowing to change a coefficient
    //double getCoeff(int idx);

private:
    QMap <int,QString> polyCoeff;
    int idxInMap;
    bool error;

public slots:
    void onNewCmd(QString cmd);

    void onResetMap();
    //void commandChecking();

signals:
      void sigCheckCommand();
      void sigEndOfEntries();
      void sigClearPlot();
      void sigResetAllApp();

    /**** Signals for a DisplayValues() object ****/
      void sigSend2Values(QString cmd);

    /**** Signals for a Compute() object ****/

      void sigDegreeOfPoly(int d);
      void sigCoeff2BeComputed(double c);
      void sigInterval(double x1, double x2);
      void sigCompute();
      void sigWarnStatus(QString prob);


};

#endif // PARSER_H
