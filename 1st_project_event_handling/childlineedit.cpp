#include "childlineedit.h"
#include <QDebug>

ChildLineEdit::ChildLineEdit(QWidget *parent): ParentLineEdit{parent}
{

}

void ChildLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"Child Line Edit Pressed";
    ParentLineEdit::keyPressEvent(event);// this will pass the same event for the child and the parent
}
