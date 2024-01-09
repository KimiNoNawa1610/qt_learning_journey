#include <QCoreApplication>
#include "test.h"
#include "watcher.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test tester;
    watcher destination;
    QObject::connect(&tester, &test::messageChanged,&destination,&watcher::messageChanged);
    tester.setProperty("message","hello world");// set the property
    //tester.setMessage("testing");

    /*
     * We are calling setProperty which look for the message property and based on the Q_PROPERTY definition,
     * it will perform the following action.
     * this gives us more control over the property of a class and instead of making multiple signals and slots.
*/



    return a.exec();
}
