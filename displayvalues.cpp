#include "displayvalues.h"

DisplayValues::DisplayValues()
{
    //qDebug()<< "Create a DISPLAYVALUES";

}

DisplayValues::DisplayValues(MainWindow *mw)
{
    this->dispIdx=0;
    values = new QTextEdit(mw);
    values->setGeometry(900,0,300,600);
    values->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 255, 153);"));
    setWelcome();
}

DisplayValues::~DisplayValues()
{
    delete values;
}

void DisplayValues::onValuesFromParser(QString cmd)
{
    this->displayMap.insert(dispIdx,cmd);
    //qDebug() << "displayMap["<<dispIdx<<"]"<< " = " << displayMap[dispIdx];

    QString equation;
    int deg = displayMap[0].toInt();

    QMap <int, int> exp; //map made of the exponent
    if(dispIdx == displayMap[0].toInt()+3)
    {
        //this loop saves the exponents into the "exp" map
        for(int j=0;j<displayMap[0].toInt();j++)
        {
            exp.insert(j,deg);
            qDebug()<< "exposant: " << exp[j];
            deg--;
        }
        //this loop builds the equation form for the txt edit
        for(int i=3,j=0;i<displayMap.size();i++,j++)
        {
            //qDebug() << "displayMap["<<i<<"] = "<< displayMap[i];
            equation += "+" + displayMap[i]+"*x^"+ QString::number(exp[j]);
        }
        values->append("------------------------------------");
        values->append("Interval: ["+displayMap[1]+","+displayMap[2]+"]");
        values->append("f(x) = "+equation);
        values->append("All points computed:");
        values->append("\n");
    }
    dispIdx++;
}

void DisplayValues::onPtsReceived(double x, double y)
{

    values->append("[x = "+QString::number(x)+" , y = "+QString::number(y)+"]");
}
void DisplayValues::setWelcome()
{
    values->append("--- Polynom Grapher Application ---");
    values->append("\n");
    values->append("Commands");
    values->append("1. Enter polynom degree");
    values->append("2. Enter interval min");
    values->append("3. Enter interval max");
    values->append("4. Enter coefficient from higher degree to lower");
    values->append("\n");
    values->append("Enter the command 'clear' for clearing the plot");
    values->append("\n");
}
void DisplayValues::onResetMap()
{
    displayMap.clear();
    dispIdx = 0;
    values->clear();
    setWelcome();
    qDebug() << "display map is cleared";
}
