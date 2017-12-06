/****************************************************************************
** Meta object code from reading C++ file 'XmlClient.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "XmlClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XmlClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XmlClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      38,   10,   10,   10, 0x05,
      68,   10,   10,   10, 0x05,
     100,   10,   10,   10, 0x05,
     116,  113,   10,   10, 0x05,
     155,  153,   10,   10, 0x05,
     177,   10,   10,   10, 0x05,
     194,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     212,   10,   10,   10, 0x08,
     228,   10,   10,   10, 0x08,
     259,  247,   10,   10, 0x08,
     299,   10,   10,   10, 0x08,
     321,  311,   10,   10, 0x0a,
     345,   10,   10,   10, 0x0a,
     363,  359,   10,   10, 0x0a,
     388,  384,   10,   10, 0x0a,
     416,  408,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_XmlClient[] = {
    "XmlClient\0\0createDescription(QString)\0"
    "createCommand(CommandHolder*)\0"
    "createVariable(VariableHolder*)\0"
    "createDone()\0,,\0updateVariable(bool,QString,QString)\0"
    ",\0updateDone(bool,bool)\0lostConnection()\0"
    "gotError(QString)\0sockConnected()\0"
    "sockDisconnected()\0socketError\0"
    "sockError(QAbstractSocket::SocketError)\0"
    "sockReady()\0host,port\0openServer(QString,int)\0"
    "closeServer()\0cmd\0sendCommand(QString)\0"
    "cfg\0sendConfig(QString)\0cfg,cmd\0"
    "sendConfigCommand(QString,QString)\0"
};

void XmlClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        XmlClient *_t = static_cast<XmlClient *>(_o);
        switch (_id) {
        case 0: _t->createDescription((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->createCommand((*reinterpret_cast< CommandHolder*(*)>(_a[1]))); break;
        case 2: _t->createVariable((*reinterpret_cast< VariableHolder*(*)>(_a[1]))); break;
        case 3: _t->createDone(); break;
        case 4: _t->updateVariable((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->updateDone((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->lostConnection(); break;
        case 7: _t->gotError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sockConnected(); break;
        case 9: _t->sockDisconnected(); break;
        case 10: _t->sockError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 11: _t->sockReady(); break;
        case 12: _t->openServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->closeServer(); break;
        case 14: _t->sendCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->sendConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->sendConfigCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData XmlClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject XmlClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XmlClient,
      qt_meta_data_XmlClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &XmlClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *XmlClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *XmlClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XmlClient))
        return static_cast<void*>(const_cast< XmlClient*>(this));
    return QObject::qt_metacast(_clname);
}

int XmlClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void XmlClient::createDescription(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XmlClient::createCommand(CommandHolder * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XmlClient::createVariable(VariableHolder * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XmlClient::createDone()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void XmlClient::updateVariable(bool _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void XmlClient::updateDone(bool _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void XmlClient::lostConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void XmlClient::gotError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
