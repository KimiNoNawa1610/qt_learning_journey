#include "indicator.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Indicator::Indicator(QWidget *parent): QWidget{parent}, greenActive(false), redActive(false),yellowActive(false),lightOn(true)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
    timer = new QTimer(this);
    timer->setInterval(500); // this will make the ligh flash with a frequency
    connect(timer,&QTimer::timeout,this,[=](){
        toggleLight();
    });
    timer->start();
}

void Indicator::normal()
{
    greenActive = true;
    yellowActive = redActive = false;
}

void Indicator::warning()
{
    yellowActive = true;
    greenActive = redActive = false;
}

void Indicator::danger()
{
    redActive = true;
    yellowActive = greenActive = false;
}

void Indicator::toggleLight()
{
    if(!lightOn){
        lightOn = true;
    }else{
        lightOn = false;
    }
    update();
}

void Indicator::paintEvent(QPaintEvent *event)
{
    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::black);

    QPainter painter(this);
    painter.setPen(mPen);
    painter.setBrush(Qt::gray);
    // brush is the cover that us used to fill the background

    painter.drawRect(QRectF(0,0,120,330)); // drawing the rectangle with the painter

    // draw the three light indication
    painter.setBrush(Qt::black);
    painter.drawEllipse(10,10,100,100);

    painter.setBrush(Qt::black);
    painter.drawEllipse(10,115,100,100);

    painter.setBrush(Qt::black);
    painter.drawEllipse(10,220,100,100);

    //if lightOn then paint the according color base of each indication
    if (lightOn){
        if(redActive){
            painter.setBrush(Qt::red);
            painter.drawEllipse(10,10,100,100);
        }else if(greenActive){
            painter.setBrush(Qt::green);
            painter.drawEllipse(10,115,100,100);
        }else if(yellowActive){
            painter.setBrush(Qt::yellow);
            painter.drawEllipse(10,220,100,100);
        }
    }
}

QSize Indicator::sizeHint() const
{
    return QSize(120,350);// modify the default size of the widget
}
