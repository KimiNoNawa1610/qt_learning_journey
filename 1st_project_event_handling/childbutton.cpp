#include "childbutton.h"
#include <QDebug>

ChildButton::ChildButton(QWidget *parent): ParentButton{parent}
{

}

void ChildButton::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Child Button Mouse Press Event Called";
    ParentButton::mousePressEvent(event);//event propagation after the event is being handle by the child class, the parent class will also handle the event
}
