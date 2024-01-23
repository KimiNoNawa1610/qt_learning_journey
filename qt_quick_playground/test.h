#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    void clickMe(QString text);

signals:
public slots:
    void callMe();
};

#endif // TEST_H
