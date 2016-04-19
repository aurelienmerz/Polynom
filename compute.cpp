#include "compute.h"

Compute::Compute()
{

}

Compute::Compute(MainWindow *mw)
{
    this->step = 0.001;
    this->idx = 0;
    this->idxCmpt = 0;
    this->degCmpt = 0;
    this->lenghtOfMap = 0;
    this->ptIndex=0;
    this->y = 0;
//ATTENTION!!!!
    b = new QProgressBar(mw);
    b->setGeometry(500,535,200,50);
    b->setValue(0);

}

Compute::~Compute()
{
    delete b;

}

void Compute::onDegreeOfPoly(int d)
{
    this->degCmpt = d;
    int degCopy = this->degCmpt;

    //this loop saves the exponents into the "exponents" map
    for(int j=0;j<=degCmpt;j++)
    {
        exponents.insert(j,degCopy);
        degCopy--;
    }

}

void Compute::onCoeff2Compute(double c)
{
    this->coeffForCmpt.insert(idx,c); // inserting the coeffs from parser into map
    qDebug() << "In map coeffForCmpt["<< idx << "] = " << coeffForCmpt[idx];
    idx++;
}
void Compute::onComputePoints()
{
  computePoints();
}

void Compute::computePoints()
{  this->b->setRange(0,this->coeffForCmpt.size());

    for(double i = this->xMin; i <=(this->xMin + this->interval); i+=this->step)
    {
        y=0;
        //qDebug()<<i;
        for(int j=0;j<exponents.size();j++)
        {
            y += coeffForCmpt[j]*qPow(i,exponents[j]);
        }
        xCoords.insert(ptIndex,i);
        yCoords.insert(ptIndex,y);

        this->b->setValue(ptIndex/2);
        //qDebug()<< "PB value:" << this->b->value();
        ptIndex++;
    }

    for(int k=0;k<ptIndex;k++)
    {
        emit sigSendPts2Display(xCoords[k],yCoords[k]); //sends the computed points to the graph
    }
    sendValues();
    emit sigEndOfComputing();
    emit sigNextOpEnable();

}
void Compute::sendValues()
{
    for(int k=0;k<xCoords.size();k++)
    {
        emit sigSendPts4Show(xCoords[k],yCoords[k]);
    }
}
void Compute::resetProgressBar()
{
    this->b->setValue(0);
}

//Setting the interval for computing the points
void Compute::onInterval(double x1, double x2)
{
    this->xMin = x1;
    this->xMAx = x2;
    this->interval = this->xMAx-this->xMin;

    emit sigInterval(this->interval);

    this->lenghtOfMap = (int) ((this->interval)*(1/step));

}

void Compute::onResetAllMaps()
{
    yCoords.clear(); //map with all the computed y coord
    xCoords.clear(); //map with all the x
    coeffForCmpt.clear(); //map with coeff received from parser
    exponents.clear(); //map with the exponents
    resetProgressBar();
    this->idx = 0;
    this->idxCmpt = 0;
    this->degCmpt = 0;
    this->lenghtOfMap = 0;
    this->ptIndex=0;
    this->y = 0;
    this->xMin = 0;
    this->xMAx = 0;
    qDebug() << "all maps are cleared and variables are reset";
}

double Compute::getPointAtIndex(int idx)
{
    return yCoords[idx];
}
