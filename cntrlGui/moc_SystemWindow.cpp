/****************************************************************************
** Meta object code from reading C++ file 'SystemWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SystemWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SystemWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SystemWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      35,   13,   13,   13, 0x0a,
      55,   13,   13,   13, 0x0a,
      75,   13,   13,   13, 0x0a,
      97,   13,   13,   13, 0x0a,
     117,   13,   13,   13, 0x0a,
     135,   13,   13,   13, 0x0a,
     154,   13,   13,   13, 0x0a,
     174,   13,   13,   13, 0x0a,
     201,   13,   13,   13, 0x0a,
     220,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SystemWindow[] = {
    "SystemWindow\0\0setDefaultsPressed()\0"
    "configReadPressed()\0configSavePressed()\0"
    "refreshStatePressed()\0browseDataPressed()\0"
    "openDataPressed()\0closeDataPressed()\0"
    "resetCountPressed()\0runStateActivated(QString)\0"
    "hardResetPressed()\0softResetPressed()\0"
};

void SystemWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SystemWindow *_t = static_cast<SystemWindow *>(_o);
        switch (_id) {
        case 0: _t->setDefaultsPressed(); break;
        case 1: _t->configReadPressed(); break;
        case 2: _t->configSavePressed(); break;
        case 3: _t->refreshStatePressed(); break;
        case 4: _t->browseDataPressed(); break;
        case 5: _t->openDataPressed(); break;
        case 6: _t->closeDataPressed(); break;
        case 7: _t->resetCountPressed(); break;
        case 8: _t->runStateActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->hardResetPressed(); break;
        case 10: _t->softResetPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SystemWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SystemWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SystemWindow,
      qt_meta_data_SystemWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SystemWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SystemWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SystemWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SystemWindow))
        return static_cast<void*>(const_cast< SystemWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SystemWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
