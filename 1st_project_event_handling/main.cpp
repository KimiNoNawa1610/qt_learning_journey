#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /*
     * Project Purpose:
     * Getting used to the event handling methods and basic UI from QT framework
     * understanding how the keyboard, mouse interact with each event
     * understanding the event cycle
    */
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //* QCoreApplication::notify *
    // Send event to the receivers
    // Can override this method in a QApplication subclass and hijack events processing
    // this function is called for all events sent to any object in any thread
    // Notice: Errors you make in this method can seriously harm the rest of your application
    // don't recommend to handle or modify if not necessary

    return a.exec();
}
