#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QTimer>

class System : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool screenLocked READ getScreenLocked WRITE setScreenLocked NOTIFY screenLockedChanged FINAL) // lock the screen property
    Q_PROPERTY(int temperature READ getTemperature WRITE setTemperature NOTIFY temperatureChanged FINAL)
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName NOTIFY userNameChanged FINAL)
    Q_PROPERTY(QString currentTime READ currentTime WRITE setCurrentTime NOTIFY currentTimeChanged FINAL)
public:
    explicit System(QObject *parent = nullptr);
    bool getScreenLocked() const;
    int getTemperature() const;
    QString getUserName() const;
    QString currentTime() const;


public slots: // methods for working with the front end
    void setUserName(const QString &newUserName);
    void setTemperature(int newTemperature);
    void setScreenLocked(bool newScreenLocked);
    void setCurrentTime(const QString &newCurrentTime);
    void timerTimeOut();

signals:
    void screenLockedChanged();
    void temperatureChanged();
    void userNameChanged();
    void currentTimeChanged();

private:
    bool m_screenLocked;
    int m_temperature;
    QString m_userName;
    QString m_currentTime;
    QTimer * m_currentTimeTimer;
};

#endif // SYSTEM_H
