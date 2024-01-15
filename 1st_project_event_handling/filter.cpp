#include "filter.h"
#include <QEvent>
#include <QDebug>


Filter::Filter(QObject *parent): QObject{parent}
{

}

bool Filter::eventFilter(QObject *watched, QEvent *event)
{
    qDebug()<<"Event Overrided";
    return QObject::eventFilter(watched,event); // very important that we return the parent
}
