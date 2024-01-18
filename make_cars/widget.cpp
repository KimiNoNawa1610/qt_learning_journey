#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    // initialize the painter
    QPainter painter(this);
    QPen mPen(Qt::black);
    mPen.setWidth(3);
    painter.setPen(mPen);

    // drawing shapes to make the car

    // upper section
    int startAngle = 15*16;
    int spanAngle = 150*16;
    QRectF outRect(100,100,200,200);
    QRectF inRect(110,110,180,180);

    painter.drawArc(outRect,startAngle,spanAngle); // draw an arc
    painter.drawArc(inRect,20*16,65*16);
    painter.drawArc(inRect,92*16,68*16);

    // draw upper vertical lines
    painter.drawLine(197,110,197,170); // draw a line
    painter.drawLine(207,110,207,170);

    // draw low horizontal lines
    painter.drawLine(120,170,195,170);
    painter.drawLine(210,170,285,170);

    // back section
    painter.drawLine(105,174,50,179);// horizontal top
    painter.drawLine(50,179,45,235);// vertical back

    // front section
    painter.drawLine(300,174,390,175);// horizontal top
    painter.drawLine(390,175,400,235);// vertical back

    // frames
    QRectF backTireFrame(90,200,80,80);
    QRectF frontTireFrame(270,200,80,80);
    painter.drawArc(backTireFrame,0,170*16);
    painter.drawArc(frontTireFrame,10*16,170*16);

    // lower connectors
    painter.drawLine(45,235,93,232);// back
    painter.drawLine(170,240,270,240);// middle
    painter.drawLine(350,235,400,235);// front

    // back tire
    painter.drawEllipse(100,210,60,60);
    painter.setBrush(Qt::black);

    painter.drawEllipse(110,220,40,40);
    painter.setBrush(Qt::NoBrush);

    // front tire
    painter.drawEllipse(280,210,60,60);
    painter.setBrush(Qt::black);

    painter.drawEllipse(290,220,40,40);
    painter.setBrush(Qt::NoBrush);









}
