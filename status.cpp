#include "status.h"

Status::Status()
{

}

Status::Status(MainWindow *mainWindow)
{
    statusBar = new QLineEdit(mainWindow);
    statusBar->setGeometry(80,563,200,30);
    statusBar->setReadOnly(true);

    name = new QLabel(mainWindow);
    name->setText("Status: ");
    name->setGeometry(25, 563, 50, 30);
}

Status::~Status()
{
    delete statusBar;
}

void Status::actualStatus(QString prob)
{
    statusBar->setText(prob);

}
void Status::onReset()
{

    statusBar->setText("Plot cleared");
}
