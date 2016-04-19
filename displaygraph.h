#ifndef DISPLAYGRAPH_H
#define DISPLAYGRAPH_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include <QLine>
#include <QRect>
#include <QGridLayout>
#include <QDebug>
#include <QColor>
#include <QString>
#include <QPen>
#include <QMap>
#include <QPointF>
using namespace std;
class MainWindow;

class DisplayGraph : public QWidget

{
    Q_OBJECT
public:

    DisplayGraph();
    DisplayGraph(MainWindow *mw);
    ~DisplayGraph();

    void paintEvent(QPaintEvent *e);
    void setDisplay();

private:
    QMap<int,QPointF> points;
    int grphIdx;
    bool toBeCleared;
    bool pointsIsFilled;
    bool alreadyDrawn;
    double interval;
    //QPainter *painter;
public slots:
     void onPtsReceived(double x, double y);
     void onEndOfComputing();
     void onInterval(double i);
     void onClearPlot();
     void onResetMap();

signals:

     void sigClearPlot();

};

#endif // DISPLAYGRAPH_H
