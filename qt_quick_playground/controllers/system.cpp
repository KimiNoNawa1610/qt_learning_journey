#include "system.h"

System::System(QObject *parent): QObject{parent}, m_screenLocked(true), m_temperature(65), m_userName("TESTER")
{

}

bool System::screenLocked() const
{
    return m_screenLocked;
}

void System::setscreenLocked(bool newScreenLocked)
{
    if (m_screenLocked == newScreenLocked)
        return;
    m_screenLocked = newScreenLocked;
    emit screenLockedChanged();
}


int System::temperature() const
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

QString System::userName() const
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
