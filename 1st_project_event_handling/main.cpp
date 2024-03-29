#include "widget.h"
#include "application.h"
#include "filter.h"
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
    //w.show();

    //* QCoreApplication::notify *
    // Send event to the receivers
    // Can override this method in a QApplication subclass and hijack events processing
    // this function is called for all events sent to any object in any thread
    // Notice: Errors you make in this method can seriously harm the rest of your application
    // don't recommend to handle or modify if not necessary

    // overried QApplication::notify
    // Application b(argc,argv);
    // Widget w1;
    // w1.show();

    // return b.exec();

    //* Override QObject::event method*
    // use to perform extra actions if a normal event method is not enough.

    //* QObject::eventFilter *
    // Filters are useful when one object wants to listen in on events from other objects
    // Listening on the event before they are delivered.

    //Filter * filter = new Filter(&w);
    //a.installEventFilter(filter); // add event filter for the application
    //w.installEventFilter(filter); // add event filter for specific widget
    // every event in the application will be passed on this filter

    //* Where events are comed from*
    /*
     * Some events come from the window (Window System Events/ Spontaneous Events)
     * Those events are generated by window system.
     * Put in some queue and processed one by one in the event loop
     *
     * Others come from the Posted Events
     * Generated by QT or application
     * Stored in queue and processed by the event loop
     *
     * Finally they can come from Sent Events
     * Generated by Qt or application.
     * Sent directly to destination objects.
     *
     * We can use QApplicaiton::postEvent to send our own customized events.
    */

    w.show();
    return a.exec();
}
