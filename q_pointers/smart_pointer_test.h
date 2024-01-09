#ifndef SMART_POINTER_TEST_H
#define SMART_POINTER_TEST_H

#include <QObject>

class smart_pointer_test : public QObject
{
    Q_OBJECT
public:
    explicit smart_pointer_test(QObject *parent = nullptr);
    ~smart_pointer_test(); // destructor

signals:
};

#endif // SMART_POINTER_TEST_H
