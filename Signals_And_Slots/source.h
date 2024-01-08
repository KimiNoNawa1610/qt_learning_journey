#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>

class source : public QObject
{
    Q_OBJECT
public:
    explicit source(QObject *parent = nullptr);

    void test();

signals:
    void mySignal(QString message);// look like a normal cpp function
    // signal is a way that we let the destination object know what is happening
    // need QObject
    // anything under signals do not need to implement.

};

#endif // SOURCE_H
