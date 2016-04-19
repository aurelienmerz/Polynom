#include "polynom.h"

Polynom::Polynom()
{
    this->degree = 0;

}

Polynom::~Polynom()
{
}

void Polynom::setDeg(int d)
{
    this->degree = d;
}

void Polynom::setCoeff(int i, double c)
{
    this->idx = i;
    polynomCoeff.insert(i,c);
}

double Polynom::getCoeffAtIndex(int idx)
{
    return polynomCoeff[idx];
}
