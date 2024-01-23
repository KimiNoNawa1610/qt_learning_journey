#include "system.h"
#include <QDebug>
#include <QDateTime>

System::System(QObject *parent): QObject{parent}, m_screenLocked(true), m_temperature(65), m_userName("TESTER")
{
    m_currentTimeTimer = new QTimer(this);
    m_currentTimeTimer->setInterval(500);// update every 500 ms
    m_currentTimeTimer->setSingleShot(true);
    connect(m_currentTimeTimer,&QTimer::timeout,this,&System::timerTimeOut); // connect with the timer to update the time value
    timerTimeOut();
}


bool System::getScreenLocked() const
{
    return m_screenLocked;
}

void System::setScreenLocked(bool newScreenLocked)
{
    if (m_screenLocked == newScreenLocked)
        return;
    m_screenLocked = newScreenLocked;
    emit screenLockedChanged();
}

int System::getTemperature() const
{
    return m_temperature;
}

void System::setTemperature(int newTemperature)
{
    if (m_temperature == newTemperature)
        return;
    m_temperature = newTemperature;
    emit temperatureChanged();
}

QString System::getUserName() const
{
    return m_userName;
}

void System::setUserName(const QString &newUserName)
{
    if (m_userName == newUserName)
        return;
    m_userName = newUserName;
    emit userNameChanged();
}

QString System::currentTime() const
{
    return m_currentTime;
}

void System::setCurrentTime(const QString &newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

void System::timerTimeOut()
{
    QDateTime dateTime;
    QString currentTime = dateTime.currentDateTime().toString("hh:m ap");
    setCurrentTime(currentTime);
    m_currentTimeTimer->start();
}
