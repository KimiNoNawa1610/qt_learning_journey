#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>

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

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Widget, Mouse Pressed" <<event->pos(); // get the position of the mouse
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"Widget, Mouse Released"<<event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"Widget, Mouse Moved"<<event->pos();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug()<<"Window closed";
    //event->accept(); // thing will happen as usual
    //event->ignore();// this will make nothing happen
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug()<<"ContextMenu Event"; // trigger by clicking the menu button on the keyboard

    //QMenu
    QMenu *mMenu = new QMenu(this);
    mMenu->addAction(tr("Action1"));
    mMenu->addAction(tr("Action2"));
    //mMenu->popup(event->pos()); // this will make the menu popup at the position relative to the window
    mMenu->popup(mapToGlobal(event->pos())); // this will make the menu popup at the position relative to the mouse position in the application
    qDebug()<<event->reason(); // this will be helpful for debugging and log file of what event is being triggered;
}

void Widget::enterEvent(QEvent *event) // when the mouse are in the application area
{
    qDebug()<<"Enter event";
}

void Widget::leaveEvent(QEvent *event) // when the mouse are out of the application area
{
    qDebug()<<"Leave event";
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key()<<" Was Pressed";// this will output the number which key was pressed
    qDebug()<<event->text()<<" Was Pressed";// this will output the key letter or symbol which key was pressed
    qDebug()<<"";
}

// void Widget::mousePressEvent(QMouseEvent *event)
// {

// }
