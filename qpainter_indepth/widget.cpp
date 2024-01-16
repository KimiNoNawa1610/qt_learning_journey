#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include <QPixmap>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // drawing on a pixmap
    // QPixmap mPix(width(), height()); // the default color is black
    // mPix.fill(Qt::yellow) // change the default fill color of the pixmap
    // QPen pen;
    // pen.setWidth(5);
    // pen.setColor(Qt::white);

    // QPainter painter(&mPix);
    // painter.setPen(pen);
    // painter.setBrush(Qt::green);
    // painter.drawRect(50,50,100,100);
    // ui->label->setPixmap(mPix);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    // // the only way to draw on a QWidget is to modify the paintEvent
    // QPen mPen(Qt::red);
    // mPen.setWidth(3);
    // QPainter painter(this);
    // painter.setPen(mPen);
    // qDebug()<< "Logical coordinates: "<<painter.window();// this is the size of the widget
    // qDebug()<<"Physical coordinates: "<<painter.viewport(); // will be the same as the logical coordinates
    // painter.drawRect(50,50,100,100);

    // // change the logical coordinates
    // painter.save(); // save the painter state

    // painter.setWindow(0,0,300,200); // logical coordinates
    // //painter.setViewport(0,0,300,200); // physical coordinates this will make the green rectangle overlap with the red rectangle
    // mPen.setColor(Qt::green);
    // painter.setPen(mPen); //
    // painter.drawRect(50,50,100,100);// since we change the painter coordinates, the rectangle will be bigger.

    // painter.restore();

    // more about drawing shapes
    QPainter painter(this);
    QPen mPen;
    mPen.setColor(Qt::black);
    mPen.setWidth(5);

    painter.setPen(mPen);

    // draw a normal rectangle
    painter.setBrush(Qt::red);
    painter.drawRect(10,10,100,100);// drawing the rectangle starting at coordinate (10,10) with 100 width and 100 length

    // draw an ellipse
    painter.setBrush(Qt::gray);
    painter.drawEllipse(300,10,200,100);

    // we can draw other stuff such as:
    // draw rectangle with round corner
    // draw lines
    // draw polygon


}
