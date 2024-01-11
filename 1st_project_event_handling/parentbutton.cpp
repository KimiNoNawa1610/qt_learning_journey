#include "parentbutton.h"
#include <QDebug>

ParentButton::ParentButton(QWidget *parent): QPushButton{parent}
{

}

void ParentButton::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Parent Button Mouse Press Event Called";
    QPushButton::mousePressEvent(event); // pass the event back to the parent
}
