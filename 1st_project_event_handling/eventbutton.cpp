#include "eventbutton.h"
#include <QEvent>
#include <QDebug>

EventButton::EventButton(QWidget *parent): QPushButton(parent)
{

}

bool EventButton::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick){
        qDebug()<<"Button: mouse press or double clicked";
    }
    return QPushButton::event(event);// very important to include this.
}
