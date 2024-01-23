#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QTimer>
#include <QGeoCoordinate>
#include <QGeoCodingManager>
#include <QGeoCodingManagerEngine>
#include <QGeoLocation>

// the System class represents a system with various properties and functionalities
class System : public QObject
{
    Q_OBJECT

    // properties exposed to QML for binding and interaction
    Q_PROPERTY(bool screenLocked READ getScreenLocked WRITE setScreenLocked NOTIFY screenLockedChanged FINAL) // represents the screen lock state
    Q_PROPERTY(int temperature READ getTemperature WRITE setTemperature NOTIFY temperatureChanged FINAL) // represents the system temperature
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName NOTIFY userNameChanged FINAL) // represents the user name
    Q_PROPERTY(QString currentTime READ currentTime WRITE setCurrentTime NOTIFY currentTimeChanged FINAL) // represents the current time

public:

    // constructor for the System class
    explicit System(QObject *parent = nullptr);

    // getter methods for the properties
    bool getScreenLocked() const; // get the screen lock state
    int getTemperature() const; // get the system temperature
    QString getUserName() const; // get the user name
    QString currentTime() const; // get the current time

public slots: // methods for interaction with the front end (QML)
    void setUserName(const QString &newUserName); // set the user name
    void setTemperature(int newTemperature); // set the system temperature
    void setScreenLocked(bool newScreenLocked); // set the screen lock state
    void setCurrentTime(const QString &newCurrentTime); // set the current time
    void timerTimeOut(); // handle timer timeout for updating the current time

signals: // signals emitted when properties change
    void screenLockedChanged(); // signal emitted when the screen lock state changes
    void temperatureChanged(); // signal emitted when the system temperature changes
    void userNameChanged(); // signal emitted when the user name changes
    void currentTimeChanged(); // signal emitted when the current time changes
    void navigationLocationChanged(); // signal emitted when the navigation location changes

public slots: // additional slots for functionality
    void navigateToLocation(const QString &location); // slot to initiate navigation to a location

signals: // signals emitted for specific events
    void centerMap(const QGeoCoordinate &coordinates); // signal emitted to center the map to specific coordinates

private slots: // private slots for handling internal events
    void handleGeocodingFinished(); // slot to handle the completion of geocoding

private:

    // private members representing the internal state of the system
    bool m_screenLocked;
    int m_temperature;
    QString m_userName;
    QString m_currentTime;
    QTimer * m_currentTimeTimer; // timer for updating the current time
    QGeoCodingManager * geocodingManager; // manager for geocoding operations
};

#endif // SYSTEM_H
