/****************************************************************************
** Meta object code from reading C++ file 'PgpLinkWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "PgpLinkWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PgpLinkWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PgpLinkWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   14,   14,   14, 0x08,
      62,   14,   14,   14, 0x08,
      88,   82,   14,   14, 0x08,
     110,   14,   14,   14, 0x08,
     125,  120,   14,   14, 0x0a,
     144,   14,   14,   14, 0x0a,
     166,  157,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PgpLinkWindow[] = {
    "PgpLinkWindow\0\0cmd\0sendCommand(QString)\0"
    "refreshStatePressed()\0countResetPressed()\0"
    "state\0logEnableChanged(int)\0timeout()\0"
    "path\0addPgpRow(QString)\0addPgpDone()\0"
    "id,value\0updatePgpField(QString,QString)\0"
};

void PgpLinkWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PgpLinkWindow *_t = static_cast<PgpLinkWindow *>(_o);
        switch (_id) {
        case 0: _t->sendCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->refreshStatePressed(); break;
        case 2: _t->countResetPressed(); break;
        case 3: _t->logEnableChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->timeout(); break;
        case 5: _t->addPgpRow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->addPgpDone(); break;
        case 7: _t->updatePgpField((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PgpLinkWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PgpLinkWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PgpLinkWindow,
      qt_meta_data_PgpLinkWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PgpLinkWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PgpLinkWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PgpLinkWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PgpLinkWindow))
        return static_cast<void*>(const_cast< PgpLinkWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int PgpLinkWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PgpLinkWindow::sendCommand(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
