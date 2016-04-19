#ifndef POLYNOM_H
#define POLYNOM_H

#include "displayvalues.h"
#include <QDebug>
class Polynom
{
public:
    Polynom();
    ~Polynom();
    void setDeg(int d);
    void setCoeff(int i, double c);
    double getCoeffAtIndex(int idx);

private:
    int idx;
    int degree;
    QMap<int,double> polynomCoeff;

};

#endif // POLYNOM_H
