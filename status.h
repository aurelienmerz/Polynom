#ifndef STATUS_H
#define STATUS_H

#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include "mainwindow.h"
//#include "parser.h"

class Parser;

class Status : public QLineEdit
{
    Q_OBJECT
public:
    Status();
    Status(MainWindow *mainWindow);
    ~Status();

    QLineEdit *statusBar;
    QLabel *name;

public slots:
    void actualStatus(QString prob);
    void onReset();
};

#endif // STATUS_H
