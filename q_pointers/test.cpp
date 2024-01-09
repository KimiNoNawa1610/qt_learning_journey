#include "test.h"
#include <QDebug>

test::test(QObject *parent): QObject{parent}
{
    qInfo()<<"Constructed"<<this;
}

test::~test()
{
    qInfo()<<"Deconstructed"<<this;
}

void test::useWidget()
{
    // see if there is a pointer
    if (!widget.data()){
        qInfo()<<"No Pointer!!";
        return;
    }else{
        qInfo()<<"Widget = "<<widget.data();
        widget.data()->setObjectName("used widget!");
    }
}
