#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>

class System : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool screenLocked READ screenLocked WRITE setScreenLocked NOTIFY screenLockedChanged FINAL) // lock the screen property
    Q_PROPERTY(int temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged FINAL)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged FINAL)
public:
    explicit System(QObject *parent = nullptr);

    bool screenLocked() const; // getter for screenLocked
    void setscreenLocked(bool newScreenLocked); // setter for screenLocked

    float WRITE() const;

    int temperature() const;
    void setTemperature(int newTemperature);

    QString userName() const;
    void setUserName(const QString &newUserName);

signals:
    void screenLockedChanged(); // signal method
    void temperatureChanged();

    void userNameChanged();

private:
    bool m_screenLocked;
    int m_temperature;
    QString m_userName;
};

#endif // SYSTEM_H
