#include "displaygraph.h"
#include "mainwindow.h"

DisplayGraph::DisplayGraph()
{

}
DisplayGraph::DisplayGraph(MainWindow *mw) : QWidget(mw)
{
    //qDebug()<< "Create a DISPLAYGRAPH";
    //setStyleSheet(QString::fromUtf8("background-color: rgb(153, 255, 153);"));
    this->grphIdx = 0;
    this->toBeCleared = false;
    this->pointsIsFilled = false;
    this->alreadyDrawn = false;
    this->interval = 0;
    setGeometry(5,50,900,450);
    show();

    connect(this,SIGNAL(sigClearPlot()),this,SLOT(onClearPlot()));

}
void DisplayGraph::onInterval(double i)
{
    this->interval = i;
}
DisplayGraph::~DisplayGraph()
{

}

// saves all the values in respective Maps
void DisplayGraph::onPtsReceived(double x, double y)
{
    QPointF p;

    p.setX((x*890/(2*this->interval))+446);
    p.setY((-y*446/(2*this->interval))+224);

    points.insert(grphIdx,p);
    qDebug()<< "QPointF map points["<<grphIdx<<"] = "<<points[grphIdx];
    grphIdx++;

}

void DisplayGraph::onEndOfComputing()
{
    this->pointsIsFilled = true;
    repaint();
}

void DisplayGraph::onClearPlot()
{
    this->update();
}
void DisplayGraph::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    //setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));//(153, 255, 153);"));
    QPen pen;
    QPen pen2;
    QPen pen3;

    pen.setColor(QColor(51,51,51));
    pen2.setColor(QColor(255,189,7));
    pen3.setColor(QColor(204,204,204));

    pen.setWidth(1);
    pen2.setWidth(1.5);

    painter.setPen(pen3);

    for(int i=2;i<=900;i+=20)
    {
        //vertical lines
        painter.drawLine(i,2,i,446);

    }
    for(int j=2;j<=460;j+=20)
    {
        painter.drawLine(2,j,888,j);
    }

    //main lines
    pen.setWidth(2);
    painter.setPen(pen);

    painter.drawRect(2,2,888,446);
    painter.drawLine(2,224,890,224);
    painter.drawLine(445,2,445,446);

    if(pointsIsFilled == true)
    {
        for(int i=0;i<(this->points.size());i++)
        {
            //painter.drawPoint(points[i].x(),points[i].y());
            //pen.setColor(QColor(51,51,255));
            painter.setPen(pen2);
            painter.drawPoint(points[i]);
        }
        pointsIsFilled = false;
    }

}

void DisplayGraph::onResetMap()
{
    points.clear();
    emit sigClearPlot();
    //toBeCleared == false;
    qDebug() << "Point map is cleared";
}
