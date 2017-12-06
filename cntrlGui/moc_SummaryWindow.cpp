/****************************************************************************
** Meta object code from reading C++ file 'SummaryWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SummaryWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SummaryWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SummaryWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      29,   25,   14,   14, 0x05,
      57,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   82,   14,   14, 0x08,
     106,   14,   14,   14, 0x08,
     127,   14,   14,   14, 0x08,
     147,   14,   14,   14, 0x08,
     169,   14,   14,   14, 0x08,
     189,   14,   14,   14, 0x08,
     216,   14,   14,   14, 0x08,
     235,   14,   14,   14, 0x08,
     254,   14,   14,   14, 0x08,
     283,  267,   14,   14, 0x0a,
     338,  328,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SummaryWindow[] = {
    "SummaryWindow\0\0openPgp()\0cmd\0"
    "sendSummaryCommand(QString)\0"
    "windowSelected(uint32_t)\0,\0"
    "cellSelected(int,int)\0setDefaultsPressed()\0"
    "configReadPressed()\0refreshStatePressed()\0"
    "resetCountPressed()\0runStateActivated(QString)\0"
    "hardResetPressed()\0softResetPressed()\0"
    "pgpPressed()\0idx,field,value\0"
    "updateSummaryField(uint32_t,QString,QString)\0"
    "idx,enums\0setRunStateEnums(uint32_t,vector<QString>)\0"
};

void SummaryWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SummaryWindow *_t = static_cast<SummaryWindow *>(_o);
        switch (_id) {
        case 0: _t->openPgp(); break;
        case 1: _t->sendSummaryCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->windowSelected((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 3: _t->cellSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->setDefaultsPressed(); break;
        case 5: _t->configReadPressed(); break;
        case 6: _t->refreshStatePressed(); break;
        case 7: _t->resetCountPressed(); break;
        case 8: _t->runStateActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->hardResetPressed(); break;
        case 10: _t->softResetPressed(); break;
        case 11: _t->pgpPressed(); break;
        case 12: _t->updateSummaryField((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 13: _t->setRunStateEnums((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< vector<QString>(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SummaryWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SummaryWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SummaryWindow,
      qt_meta_data_SummaryWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SummaryWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SummaryWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SummaryWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SummaryWindow))
        return static_cast<void*>(const_cast< SummaryWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SummaryWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void SummaryWindow::openPgp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SummaryWindow::sendSummaryCommand(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SummaryWindow::windowSelected(uint32_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
