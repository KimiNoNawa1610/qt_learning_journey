#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "source.h"
#include "destination.h"
#include "station.h"
#include "radio.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    source objSource;
    destination objDestination;
    QObject::connect(&objSource,&source::mySignal,&objDestination,&destination::onMessage);// connecting the signal to the source
    //objSource.test();

    radio boombox; // radio object

    station* channels[3];

    // create stations
    channels[0] = new station(&boombox,94,"Rock & Roll");
    channels[1] = new station(&boombox,101,"Chill");
    channels[2] = new station(&boombox,85,"News");

    // connect radio with stations
    boombox.connect(&boombox,&radio::quit,&a, &QCoreApplication::quit,Qt::QueuedConnection); // QueuedConnection used primarily with thread
    // do{
    //     cout << "Please Enter on,off,test or quit:"<<endl;
    //     QTextStream qtin(stdin); // reading the standard input instead of cin >>. Problem: Why this part is never execute,
    //     the user cannot input anything. It go directly to the else statement

    //     QString line = qtin.readLine().trimmed().toUpper(); // available library to read input, remove white space and convert to upper case

    //     if(line=="ON"){
    //         qInfo()<<"The Radio Is Turned On.";
    //     }else if(line == "OFF"){
    //         qInfo()<<"The Radio Is Turned Off.";
    //     }else if(line == "TEST"){
    //         qInfo()<<"The Radio Is Running.";
    //     }else if(line == "QUIT"){
    //         qInfo()<<"Quitting.";
    //         quitRequested = true;
    //     }

    // }while(true);

    cout << "Please Enter on,off,test or quit:"<<endl;
    QTextStream qtin(stdin); // reading the standard input instead of cin >>. Problem: Why this part is never execute,
    //the user cannot input anything. It go directly to the else statement

    QString line = qtin.readLine().trimmed().toUpper(); // available library to read input, remove white space and convert to upper case

    if(line=="ON"){
        qInfo()<<"The Radio Is Turned On.";
    }else if(line == "OFF"){
        qInfo()<<"The Radio Is Turned Off.";
    }else if(line == "TEST"){
        qInfo()<<"The Radio Is Running.";
    }else if(line == "QUIT"){
        qInfo()<<"Quitting.";
        //quitRequested = true;
    }else{
        qInfo()<<"Please Enter again";
    }

    return a.exec();
}
