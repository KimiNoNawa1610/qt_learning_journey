#include <QCoreApplication>
#include <QDebug>
#include <QPointer>
#include "test.h"
#include <QScopedPointer>
#include <QSharedPointer>
#include "smart_pointer_test.h"
#include "consumer.h"

void use_it(smart_pointer_test* obj){
    if(!obj){
        return;
    }
    qInfo()<< "Using" <<obj;
}

void do_stuff(){
    //smart_pointer_test *t =new smart_pointer_test(); // dangling pointer
    QScopedPointer<smart_pointer_test> my_smart_pointer(new smart_pointer_test()); // create an object with QScopedPointer
    use_it(my_smart_pointer.data());

    //pointer is automatically deleted!!
}

void do_delete(test * obj){
    qInfo()<<"Deleting"<<obj;
    obj->deleteLater(); // check to see if anything has reference to this obj pointer, if not, will delete immediately
}
QSharedPointer<test> create_pointer(){
    test *t = new test(); // bad way
    t->setObjectName("Shared Pointer Test Object");
    QSharedPointer<test> p(t,do_delete); // when the pointer get deleted, the function do_delete will be triggered
    return p;
}

void do_stuff_shared(QSharedPointer<consumer> ptr){
    qInfo()<<"In function: "<<ptr.data()->tester;
    ptr.clear(); // clear the QSharedPointer Reference, dropping the object, but does not actually delete
}

QSharedPointer<consumer> make_consumer(){
    // QSharedPointer keep track of the copy and make sure how many reference is there.
    // there is a counter in the pointer. When the counter hits 0 then the pointer is being deleted.
    QSharedPointer<consumer> c(new consumer,&QObject::deleteLater); // creating new consumer
    QSharedPointer<test> ptr = create_pointer(); // create a new pointer
    c.data()->tester.swap(ptr); // swap the two pointer
    do_stuff_shared(c);
    return c;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //* QPointer *

    QObject *obj = new QObject(nullptr); // no parent. Pointer on the heap
    obj ->setObjectName("My Object");

    QPointer<QObject> p (obj);// wrap that pointer to a QPointer (create an object with QPointer)
    test t;
    t.widget = p;
    t.useWidget();

    if(p.data()){
        qInfo()<<p.data();
    }

    delete obj;
    t.useWidget();

    // smart pointers

    // similar to shared_ptr or unique_ptr in cpp

    //* QScopedPointer *

    // The QScopedPointer class stores a pointer to a dynamically allocated object,
    // and deletes it upon the object or value stores in it goes out of scope.
    // Make sure that when we use QScopedPointer, we know what is the scope of a function or class
    // so that we do not get error like pointer cannot be found, etc.

    for(int i =0;i<100;i++){
        do_stuff(); //  will create 100 pointers with the smart_pointer_test object, using and destroy them sequentially.
    }

    //* QSharedPointer *
    QSharedPointer<consumer> consume = make_consumer(); // make another copy
    qInfo()<<"In Main: "<< consume.data()->tester;

    consume.clear();// only clear the reference will not actually delete.

    return a.exec();
}
