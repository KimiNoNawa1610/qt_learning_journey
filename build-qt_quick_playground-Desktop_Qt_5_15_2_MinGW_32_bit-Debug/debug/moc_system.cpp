/****************************************************************************
** Meta object code from reading C++ file 'system.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt_quick_playground/controllers/system.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'system.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_System_t {
    QByteArrayData data[26];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_System_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_System_t qt_meta_stringdata_System = {
    {
QT_MOC_LITERAL(0, 0, 6), // "System"
QT_MOC_LITERAL(1, 7, 19), // "screenLockedChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 18), // "temperatureChanged"
QT_MOC_LITERAL(4, 47, 15), // "userNameChanged"
QT_MOC_LITERAL(5, 63, 18), // "currentTimeChanged"
QT_MOC_LITERAL(6, 82, 25), // "navigationLocationChanged"
QT_MOC_LITERAL(7, 108, 9), // "centerMap"
QT_MOC_LITERAL(8, 118, 14), // "QGeoCoordinate"
QT_MOC_LITERAL(9, 133, 11), // "coordinates"
QT_MOC_LITERAL(10, 145, 11), // "setUserName"
QT_MOC_LITERAL(11, 157, 11), // "newUserName"
QT_MOC_LITERAL(12, 169, 14), // "setTemperature"
QT_MOC_LITERAL(13, 184, 14), // "newTemperature"
QT_MOC_LITERAL(14, 199, 15), // "setScreenLocked"
QT_MOC_LITERAL(15, 215, 15), // "newScreenLocked"
QT_MOC_LITERAL(16, 231, 14), // "setCurrentTime"
QT_MOC_LITERAL(17, 246, 14), // "newCurrentTime"
QT_MOC_LITERAL(18, 261, 12), // "timerTimeOut"
QT_MOC_LITERAL(19, 274, 18), // "navigateToLocation"
QT_MOC_LITERAL(20, 293, 8), // "location"
QT_MOC_LITERAL(21, 302, 23), // "handleGeocodingFinished"
QT_MOC_LITERAL(22, 326, 12), // "screenLocked"
QT_MOC_LITERAL(23, 339, 11), // "temperature"
QT_MOC_LITERAL(24, 351, 8), // "userName"
QT_MOC_LITERAL(25, 360, 11) // "currentTime"

    },
    "System\0screenLockedChanged\0\0"
    "temperatureChanged\0userNameChanged\0"
    "currentTimeChanged\0navigationLocationChanged\0"
    "centerMap\0QGeoCoordinate\0coordinates\0"
    "setUserName\0newUserName\0setTemperature\0"
    "newTemperature\0setScreenLocked\0"
    "newScreenLocked\0setCurrentTime\0"
    "newCurrentTime\0timerTimeOut\0"
    "navigateToLocation\0location\0"
    "handleGeocodingFinished\0screenLocked\0"
    "temperature\0userName\0currentTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_System[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       4,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   87,    2, 0x0a /* Public */,
      12,    1,   90,    2, 0x0a /* Public */,
      14,    1,   93,    2, 0x0a /* Public */,
      16,    1,   96,    2, 0x0a /* Public */,
      18,    0,   99,    2, 0x0a /* Public */,
      19,    1,  100,    2, 0x0a /* Public */,
      21,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,

 // properties: name, type, flags
      22, QMetaType::Bool, 0x00495903,
      23, QMetaType::Int, 0x00495903,
      24, QMetaType::QString, 0x00495903,
      25, QMetaType::QString, 0x00495903,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void System::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<System *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->screenLockedChanged(); break;
        case 1: _t->temperatureChanged(); break;
        case 2: _t->userNameChanged(); break;
        case 3: _t->currentTimeChanged(); break;
        case 4: _t->navigationLocationChanged(); break;
        case 5: _t->centerMap((*reinterpret_cast< const QGeoCoordinate(*)>(_a[1]))); break;
        case 6: _t->setUserName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setTemperature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setScreenLocked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setCurrentTime((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->timerTimeOut(); break;
        case 11: _t->navigateToLocation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->handleGeocodingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGeoCoordinate >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (System::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&System::screenLockedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (System::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&System::temperatureChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (System::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&System::userNameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (System::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&System::currentTimeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (System::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&System::navigationLocationChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (System::*)(const QGeoCoordinate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&System::centerMap)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<System *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getScreenLocked(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getTemperature(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getUserName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->currentTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<System *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setScreenLocked(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setTemperature(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setUserName(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCurrentTime(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject System::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_System.data,
    qt_meta_data_System,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *System::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *System::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_System.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int System::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void System::screenLockedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void System::temperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void System::userNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void System::currentTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void System::navigationLocationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void System::centerMap(const QGeoCoordinate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
