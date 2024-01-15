#include "application.h"
#include <QDebug>
#include <QWidget>

Application::Application(int &argc, char **argv): QApplication(argc,argv)
{

}

bool Application::notify(QObject *dest, QEvent *event)
{
    qDebug()<<"Application: notify called";
    QWidget * test = dynamic_cast<QWidget*>(dest);
    if (test){
        qDebug()<<"Cast to QWidget successful";
    }
    else{
        qDebug()<<"Cast to QWidget unsuccessful";
    }

    return QApplication::notify(dest,event); // pass the destination and the event
    // If we do not pass back to the QApplication, the program will choke and there is no communication between the events and destination.
}
