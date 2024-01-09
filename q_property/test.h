#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT

private:
    QString p_message;

public:
    explicit test(QObject *parent = nullptr);

    Q_PROPERTY(QString message READ getMessage WRITE setMessage NOTIFY messageChanged);

    QString getMessage();// return the message value
    void setMessage(QString value);
signals:
    void messageChanged(QString message);
};

#endif // TEST_H
