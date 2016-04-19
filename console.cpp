#include "console.h"

Console::Console()
{
}

Console::Console(MainWindow *mainWindow)
{
    //qDebug()<< "Create a CONSOLE";
    entry = new QLineEdit(mainWindow);
    entry->setGeometry(80, 530, 200, 30);

    choice = new QLineEdit(mainWindow);
    choice->setGeometry(360,530,100,30);
    choice->setEnabled(false);

    entryToEnter = new QLabel(mainWindow);
    entryToEnter->setGeometry(300,530,70,30);
    entryToEnter->setText("Next OP: ");

    consLabel = new QLabel(mainWindow);
    consLabel->setGeometry(15,530,100,30);
    consLabel->setText("Console:");

    connect(entry,SIGNAL(returnPressed()),this, SLOT(onEditFinished()));
    connect(choice,SIGNAL(returnPressed()),this,SLOT(onNextOpEntered()));
}

Console::~Console()
{
    delete entry;
    delete choice;
    delete consLabel;
    delete entryToEnter;
}

void Console::testOperation(QString s)
{
    if(s == "clear")
    {

        this->choice->clear();
        this->choice->setEnabled(false);
        emit sigResetAllMaps();
        this->entry->setEnabled(true);
        this->entry->setFocus();
    }
   else
    {
        this->choice->clear();
        this->choice->setEnabled(false);
        emit sigResetAllMaps();
        this->entry->setEnabled(true);
        this->entry->setFocus();
    }

}
void Console::onEditFinished()
{
    QString cmd = entry->text();
    //qDebug() << cmd;
    emit sigNewCmd(cmd);
    this->entry->clear();
}

void Console::onNextOpEntered()
{
    QString op = choice->text();
    testOperation(op);
}
void Console::onEndOfEntries()
{
    this->entry->setEnabled(false);

}

void Console::onNextOpEnable()
{
    this->choice->setEnabled(true);
    this->choice->setFocus();
}

void Console::onRestoreConsole()
{
    this->entry->setEnabled(true);
}


