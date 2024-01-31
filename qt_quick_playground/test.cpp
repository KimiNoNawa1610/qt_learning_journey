#include "test.h"
#include <QDebug>

test::test(QObject *parent): QObject{parent}
{

}

void test::clickMe(QString text)
{
    qDebug()<<text;
}

void test::callMe()
{
    qDebug()<<"I am being called";
}
