#include "parser.h"

Parser::Parser()
{
   this->idxInMap = 0;
   this->error = false;
    //qDebug()<< "Create a PARSER";
    connect(this,SIGNAL(sigResetAllApp()),this,SLOT(onResetMap()));
}

Parser::~Parser()
{
}

void Parser::onNewCmd(QString cmd)
{
    this->polyCoeff.insert(this->idxInMap, cmd);
    qDebug()<< "Index :" << this->idxInMap << " ,entry: "<< cmd;


    this->commandChecking(polyCoeff[idxInMap]); //checking if the command is correct

        if(idxInMap == polyCoeff[0].toInt()+3)
        {
            emit sigEndOfEntries();

            for(int i=0;i<polyCoeff.size();i++)
            {
                qDebug()<< "In map polyCoeff["<<i<<"] = "<< polyCoeff[i];
                emit sigSend2Values(polyCoeff[i]);

            }

            emit sigDegreeOfPoly(polyCoeff[0].toInt());
            //qDebug()<< "Degree of polynom: " << polyCoeff[0].toInt();

            emit sigInterval(polyCoeff[1].toDouble(), polyCoeff[2].toDouble()); //sending interval
            qDebug() << "Interval xMin = " << polyCoeff[1].toDouble();
            qDebug() << "Interval xMax = " << polyCoeff[2].toDouble();

            for(int j=3;j<polyCoeff.size(); j++)
            {
                emit sigCoeff2BeComputed(polyCoeff[j].toDouble()); //sending all coeff to compute

            }
            idxInMap=0;
            emit sigWarnStatus("All good");
            emit sigCompute();
        }

     idxInMap++;

     if(error)
     {
         idxInMap--;
         error = false;

     }

}

void Parser::commandChecking(QString s)
{

        if(s == "clear")
        {
            emit sigClearPlot();
            emit sigWarnStatus("Cleared");
            error = false;
        }

        if((s.toDouble()==0) && s != QChar('0'))
        {

                emit sigWarnStatus("Wrong entry");
                emit sigResetAllApp();
                error = true;
                qDebug()<<polyCoeff;

            }
}

void Parser::onResetMap()
{
    polyCoeff.clear();
    this->idxInMap = 0;
    qDebug()<< idxInMap;
    qDebug() << "Polycoeff map is cleared";
    //error == false;
}
/*void Parser:: setCoeffAtIndex(int idx, double c)
{
    polyCoeff[idx+3] = c;
}
double Parser:: getCoeff(int idx)
{
    return polyCoeff[idx+3];

}*/


