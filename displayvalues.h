#ifndef DISPLAYVALUES_H
#define DISPLAYVALUES_H

#include <QTextEdit>
//#include <QWidget>
#include <QMap>
#include <QDebug>
#include "mainwindow.h"

class DisplayValues: public QTextEdit
{
    Q_OBJECT
public:
    DisplayValues();
    DisplayValues(MainWindow *mw);
    ~DisplayValues();
    QTextEdit *values;

    void setWelcome();

public slots:
    void onValuesFromParser(QString cmd);
    void onPtsReceived(double x, double y);
    void onResetMap();

private:
    QMap<int,QString> displayMap;
    int dispIdx;
};

#endif // DISPLAYVALUES_H
