#include "watertank.h"
#include <QPen>
#include <QPainter>
#include <QBrush>

WaterTank::WaterTank(QWidget *parent): QWidget{parent}, waterHeight(50), timer(new QTimer(this))
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,this,[=](){
        if(waterHeight>=300){
            waterHeight -= 290;
        }else if(waterHeight<300 && waterHeight>120){
            waterHeight +=10;
        }else{
            waterHeight +=5;
        }

        // emit water status
        if(waterHeight<=220){
            emit normal();
        }else if(waterHeight>=221 && waterHeight<239){
            emit warning();
        }else{
            emit danger();
        }


        update();
    });
    timer->start();
}

void WaterTank::paintEvent(QPaintEvent *event)
{
    // setup painter
    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::black);

    QPainter painter(this);
    painter.setPen(mPen);
    painter.setBrush(Qt::gray);

    // draw water line
    painter.drawLine(10,10,10,300); // left
    painter.drawLine(10,300,300,300); // bottom
    painter.drawLine(300,300,300,10); // right

    painter.setBrush(Qt::blue);
    painter.drawRect(10,300-waterHeight,290,waterHeight);



}

QSize WaterTank::sizeHint() const
{
    return QSize(400,400);
}
