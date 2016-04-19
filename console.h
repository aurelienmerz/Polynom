#ifndef CONSOLE_H
#define CONSOLE_H

#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <iostream>
#include "compute.h"
#include "mainwindow.h"

using namespace std;
class Parser;

class Console : public QLineEdit
{
    Q_OBJECT

public:
    Console();
    Console(MainWindow *mw);
    ~Console();

    QLineEdit *entry;
    QLineEdit *choice;

    void testOperation(QString s);

signals:
    void sigNewCmd(QString cmd);
    void sigDegree(QString deg);
    void sigInterMin(QString min);
    void sigInterMax(QString max);

    void sigResetAllMaps();
    void sigResetProgressBar();

public slots:
    void onEditFinished();
    void onEndOfEntries();
    void onRestoreConsole();

    void onNextOpEnable();
    void onNextOpEntered();

private:

    QLabel *consLabel;
    QLabel *entryToEnter;
};

#endif // CONSOLE_H
