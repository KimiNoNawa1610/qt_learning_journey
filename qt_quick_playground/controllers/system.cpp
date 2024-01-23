#include "system.h"
#include <QDebug>
#include <QDateTime>
#include <QGeoServiceProvider>
#include <QSslSocket>

System::System(QObject *parent): QObject{parent}, m_screenLocked(true), m_temperature(65), m_userName("TESTER")
{
    // initialize the geocoding manager with the map provider "osm"
    QGeoServiceProvider *serviceProvider = new QGeoServiceProvider("osm");
    geocodingManager = serviceProvider->geocodingManager();

    // initialize timer for updating the current time
    m_currentTimeTimer = new QTimer(this);
    m_currentTimeTimer->setInterval(500);  // update every 500 ms
    m_currentTimeTimer->setSingleShot(true);
    connect(m_currentTimeTimer, &QTimer::timeout, this, &System::timerTimeOut);  // connect the timer to update the time value
    timerTimeOut();  // initial call to set the current time

    // ssl debug
    qDebug()<<QSslSocket::sslLibraryBuildVersionString();
    qDebug()<<QSslSocket::sslLibraryVersionString();
}

// getter for the screenLocked property
bool System::getScreenLocked() const
{
    return m_screenLocked;
}

// setter for the screenLocked property
void System::setScreenLocked(bool newScreenLocked)
{
    if (m_screenLocked == newScreenLocked)
        return;
    m_screenLocked = newScreenLocked;
    emit screenLockedChanged();
}

// getter for the temperature property
int System::getTemperature() const
{
    return m_temperature;
}

// setter for the temperature property
void System::setTemperature(int newTemperature)
{
    if (m_temperature == newTemperature)
        return;
    m_temperature = newTemperature;
    emit temperatureChanged();
}

// getter for the userName property
QString System::getUserName() const
{
    return m_userName;
}

// setter for the userName property
void System::setUserName(const QString &newUserName)
{
    if (m_userName == newUserName)
        return;
    m_userName = newUserName;
    emit userNameChanged();
}

// getter for the currentTime property
QString System::currentTime() const
{
    return m_currentTime;
}

// setter for the currentTime property
void System::setCurrentTime(const QString &newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

void System::timerTimeOut()
{
    // update the current time and restart the timer
    QDateTime dateTime;
    QString currentTime = dateTime.currentDateTime().toString("hh:mm ap");
    setCurrentTime(currentTime);
    m_currentTimeTimer->start();
}

void System::navigateToLocation(const QString &location)
{
    // start geocoding to get the coordinates for the location
    QGeoCodeReply *reply = geocodingManager->geocode(location);
    connect(reply, &QGeoCodeReply::finished, this, &System::handleGeocodingFinished);
}

void System::handleGeocodingFinished()
{
    if (QGeoCodeReply *reply = qobject_cast<QGeoCodeReply *>(sender())) {
        if (reply->error() == QGeoCodeReply::NoError) {
            QList<QGeoLocation> locations = reply->locations();
            if (!locations.isEmpty()) {
                QGeoLocation location = locations.first();
                QGeoCoordinate coordinates = location.coordinate();
                emit centerMap(coordinates);
            }
        }
        reply->deleteLater();
    }
}

