#include "widget.h"
#include "ui_widget.h"
#include "parentbutton.h"
#include "childbutton.h"
#include "childlineedit.h"
#include "eventbutton.h"
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ChildButton * button = new ChildButton(this);
    ChildLineEdit* edit = new ChildLineEdit(this);
    EventButton * ebutton = new EventButton(this);
    button->setText("Child Button");
    ebutton->setText("Custom Event Button");
    connect(button,&ChildButton::clicked,[=](){
        qDebug()<<"Button Clicked";
    });
    ui->verticalLayout->addWidget(edit);
    ui->verticalLayout->addWidget(button);
    ui->verticalLayout->addWidget(ebutton);
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

    // how about key combination

    if(event->modifiers()&Qt::ShiftModifier){ // this will let us know if the shift key was pressed
        qDebug()<<"Shift Key Was Pressed";
    }
    if(event->modifiers()&Qt::ControlModifier){ // this will let us know if the ctrl key was pressed
        qDebug()<<"Ctrl Key Was Pressed";
    }
    if(event->modifiers()&Qt::AltModifier){ // this will let us know if the alt key was pressed
        qDebug()<<"Alt Key Was Pressed";
    }
    // and there are other modifier

}

void Widget::wheelEvent(QWheelEvent *event)
{
    qDebug()<<"Wheel Event Delta"<<event->pixelDelta();// getting the pixel delta from the wheel event
    qDebug()<<"Orientation: "<<event->angleDelta(); // get the orientation
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug()<<"Paint Event Triggered"; // will triggered everytime the application window changes
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"Widget resized, old size: "<<event->oldSize()<<" | New size: "<<event->size();
    // output the old size and the current size of the window application
}

// void Widget::mousePressEvent(QMouseEvent *event)
// {

// }
