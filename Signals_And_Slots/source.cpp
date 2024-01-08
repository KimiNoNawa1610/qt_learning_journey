#include "source.h"

source::source(QObject *parent)
    : QObject{parent}
{

}

void source::test()
{
    emit mySignal("Hello World");// specific to QT
    // we can have one signal and many slots connect to it
}
