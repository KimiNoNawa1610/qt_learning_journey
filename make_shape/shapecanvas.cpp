#include "shapecanvas.h"
#include <QPainter>

ShapeCanvas::ShapeCanvas(QWidget *parent)
    : QWidget{parent}
{}

void ShapeCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawRect(QRect(0,0,width()-1,height()-1));
}

bool ShapeCanvas::getTransformed() const
{
    return transformed;
}

void ShapeCanvas::setTransformed(bool newTransformed)
{
    transformed = newTransformed;
    update();
}

bool ShapeCanvas::getAntialized() const
{
    return antialized;
}

void ShapeCanvas::setAntialized(bool newAntialized)
{
    antialized = newAntialized;
    update();
}

QSize ShapeCanvas::sizeHint() const
{
    return QSize(500,300);
}

QSize ShapeCanvas::minimumSizeHint() const
{
    return QSize(400,200);
}

QBrush ShapeCanvas::getBrush() const
{
    return brush;
}

void ShapeCanvas::setBrush(const QBrush &newBrush)
{
    brush = newBrush;
    update();
}

ShapeCanvas::Shape ShapeCanvas::getShape() const
{
    return shape;
}

void ShapeCanvas::setShape(Shape newShape)
{
    shape = newShape;
    update();
}

QPen ShapeCanvas::getPen() const
{
    return pen;
}

void ShapeCanvas::setPen(const QPen &newPen)
{
    pen = newPen;
    update();
}
