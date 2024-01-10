#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include <QDate>
#include <QVariant>
#include <algorithm>
#include <QHash>
#include <QSet>
#include <QMap>
#include <QLinkedList>
#include "cat.h"
#include "dog.h"

void test(QObject* obj){
    qInfo()<< obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //* QObject *

    dog d;
    cat c;

    d.setObjectName("LuLu"); // set the name for the object d
    c.setObjectName("MiLu"); // set the name for the object c

    test(&c); // output the address memory of the object and the name of the object
    test(&d); // output the address meemory of the object and the name of the object

    //* Qint *

    // typedef -- redefine the type of an existing datatype
    // different integertype for calculations

    qint8 int8 = 0;
    qint16 int16 = 12313;
    qint32 int32 = 1231215145;
    qint64 int64 = 1231251512341231252;
    qintptr intptr = 0;

    qInfo()<<"Size of int8 "<<sizeof(int8) <<" bytes";
    qInfo()<<"Size of int16 "<<sizeof(int16)<<" bytes";
    qInfo()<<"Size of int32 "<<sizeof(int32)<<" bytes";
    qInfo()<<"Size of int64 "<<sizeof(int64)<<" bytes";
    qInfo()<<"Size of intptr "<<sizeof(intptr)<<" bytes";


    //* QString *
    QString name = "My Name";
    // QString provide unicode character string
    // similar to string in Python rather than string class in cpp

    qInfo()<<name;
    qInfo()<<name.mid(1,3); // get the substring from start to end index
    qInfo()<<name.insert(0,"Mr. "); // insert another string at index
    qInfo()<<name.split(" ");// split by character in a string
    int index = name.indexOf("M"); // get the index of a character
    qInfo()<< name.remove(0,index+1).trimmed(); // remove substring from the string and white space

    // QDate, QTimeand QDateTime

    QDate today = QDate::currentDate(); // get the current date base on system clock
    qInfo() << today;
    qInfo() << today.addDays(1);
    qInfo() << today.addYears(10);
    qInfo() << today.toString(Qt::DateFormat::SystemLocaleDate); // match the local system date format


    QTime now = QTime::currentTime();
    qInfo()<<now;
    qInfo()<<now.toString(Qt::DateFormat::DefaultLocaleLongDate);
    qInfo()<<now.toString(Qt::DateFormat::DefaultLocaleShortDate);

    QDateTime datetimenow = QDateTime::currentDateTime();
    qInfo()<< datetimenow;

    //* QByteArray *
    QString greeting = "Hello World";
    QByteArray buffer(greeting.toLatin1());
    buffer.append("!");
    qInfo()<< buffer.rightJustified(20,'.');
    qInfo()<< buffer.length();

    //* QVariant *
    // work with different datatype
    // similar to auto in valina cpp but also include types from Qt so it is much wider cast
    QVariant value1 = 1;
    QVariant value2 = "Hello";

    qInfo()<<value1;
    qInfo()<<value2;

    //* QStringList *
    QString data = "Talonss1610";
    QStringList strList = data.split("");
    qInfo()<<strList;

    foreach(QString str, strList){ // similar to foreach in js
        qInfo()<<str;
    }

    strList.sort();
    qInfo()<<strList;

    QString myvar = "o";

    if(strList.contains(myvar)){
        qInfo()<<strList.indexOf(myvar); // get the first position of the string or char if there is many

    }

    //* QList *
    // has similarities to the QStringList but can work with different datatype
    // similar to python list datatype

    QList<int> myIntList;
    myIntList.append(0);
    myIntList.append(1);
    myIntList.append(1000);

    qInfo()<<myIntList;

    foreach(int in, myIntList){
        qInfo()<<in;
    }

    std::sort(myIntList.begin(),myIntList.end());

    myIntList.pop_back(); // remove last element in the list
    myIntList.pop_front(); // remove the first element in the list
    myIntList.removeAt(0); // remove element at index

    qInfo()<<myIntList;

    //* QVector *
    // better performance than QList
    // Should be the first choice of dynamic array
    // QList stores item on the heap while QVector puts them sequentially, hence increasing performance
    // similar design pattern to QList so no difference than QList

    QVector<QDate> dates;
    dates.append(QDate::currentDate());
    dates.append(dates[0].addDays(1));

    qInfo() << dates;

    //* QHash *
    // provide a key-value pair that is similar to a dictionary in Python

    QHash<QString,int> ages; // declare the datatype of key and value
    ages.insert("Artoria",1000);
    ages.insert("Merlin",1300);
    ages.insert("Victoria",81);
    //ages.insert("Tesla","86"); // this will cause error since the Hash is string key and in value
    ages.insert("Thorfin",55);
    ages.insert("Canute",65);

    qInfo()<<ages.size();
    foreach(QString key, ages.keys()){
        qInfo()<<key<<"age is "<<ages[key]; // get the value for a key similar to Python dictionary
    }

    //* QSet *
    // similar to a set in Python, stores value in un-ordered collections
    QSet<QString> people;
    people.insert("Washington");
    people.insert("Frankin");
    people.insert("Adams");
    people.insert("Jefferson");
    people.insert("Paine");
    qInfo()<<"\nUS Prominent People:";
    foreach(QString person, people){
        qInfo()<<person;
    }

    //* QMap *
    // is a template class that provides a red-black-tree-based dictionary
    // similar to QHash, it stores a pairs of key-value
    // a little bit slower than QHash

    QMap<QString, QString> locations;
    locations.insert("Eiffel Tower","France");
    locations.insert("Voyager","Space");
    locations.insert("Kyoto","Japan");

    foreach(QString key, locations.keys()){
        qInfo()<<key<<"is in "<<locations[key]; // get the value for a key similar to Python dictionary
    }

    //* QLinkedList *
    // stores a list of values and provides iterator-based access as well as constant time insertions and removals
    // but we will not use it much
    // should be using std::list instead
    QLinkedList<int> list;
    for(int i = 0; i < 10; i++) {
        list.append(i);
    }

    list.removeFirst();
    list.removeLast();
    list.removeOne(5);
    if(list.contains(3)) qInfo() << "Contains 3";
    list.clear();

    qInfo() << "Done";








    return a.exec();
}
