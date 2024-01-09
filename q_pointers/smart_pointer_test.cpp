#include "smart_pointer_test.h"
#include <QDebug>

smart_pointer_test::smart_pointer_test(QObject *parent): QObject{parent}
{
    qInfo()<<"Constructed"<<this;
}

smart_pointer_test::~smart_pointer_test()
{
    qInfo()<<"Deconstructed"<<this;
}
