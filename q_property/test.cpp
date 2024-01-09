#include "test.h"

test::test(QObject *parent)
    : QObject{parent}
{}

QString test::getMessage()
{
    return this->p_message;
}

void test::setMessage(QString value)
{
    this->p_message = value;
    emit messageChanged(p_message); // building block for Q property
}
