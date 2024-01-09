#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // std also has standard handling error
    /* For example we have:
     * std::invalid_argument
     * std::out_of_range
     * std::exception
    */

    // qt error handling methods
    // qWarning
    // qInfo
    // qFatal

    // qt error handling does not use normal try and catch block like in vanila cpp

    int value;
    cout<<"Please enter a number"<<endl;
    cin >> value;
    cout<< "You Entered: "<<value<<endl;

    if(value==NULL){
        qWarning()<<"Your value is null";
    }

    qFatal("Value is not recognized"); // this will quit the program when execute.
    return a.exec();
}
