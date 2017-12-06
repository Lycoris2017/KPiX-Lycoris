/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   12,   11,   11, 0x05,
      50,   46,   11,   11, 0x05,
      71,   46,   11,   11, 0x05,
      99,   91,   11,   11, 0x05,
     150,  134,   11,   11, 0x05,
     205,  195,   11,   11, 0x05,
     248,   11,   11,   11, 0x05,
     263,  258,   11,   11, 0x05,
     282,   11,   11,   11, 0x05,
     304,  295,   11,   11, 0x05,
     336,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     353,   11,   11,   11, 0x08,
     370,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,
     408,   11,   11,   11, 0x08,
     426,   11,   11,   11, 0x08,
     445,   11,   11,   11, 0x08,
     465,  463,   11,   11, 0x08,
     494,   11,   11,   11, 0x08,
     518,   11,   11,   11, 0x08,
     545,   11,   11,   11, 0x08,
     575,   11,   11,   11, 0x08,
     607,   11,   11,   11, 0x08,
     623,  620,   11,   11, 0x08,
     660,  463,   11,   11, 0x08,
     682,   11,   11,   11, 0x08,
     700,   46,   11,   11, 0x0a,
     725,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0host,port\0openServer(QString,int)\0"
    "cmd\0sendCommand(QString)\0sendConfig(QString)\0"
    "cfg,cmd\0sendConfigCommand(QString,QString)\0"
    "idx,field,value\0"
    "updateSummaryField(uint32_t,QString,QString)\0"
    "idx,enums\0setRunStateEnums(uint32_t,vector<QString>)\0"
    "openPgp()\0path\0addPgpRow(QString)\0"
    "addPgpDone()\0id,value\0"
    "updatePgpField(QString,QString)\0"
    "lostConnection()\0openPgpPressed()\0"
    "lostConnectionSlot()\0cfgReadPressed()\0"
    "cfgWritePressed()\0cfgVerifyPressed()\0"
    "statReadPressed()\0,\0helpPressed(QString,QString)\0"
    "commandPressed(QString)\0"
    "createDescription(QString)\0"
    "createCommand(CommandHolder*)\0"
    "createVariable(VariableHolder*)\0"
    "createDone()\0,,\0updateVariable(bool,QString,QString)\0"
    "updateDone(bool,bool)\0gotError(QString)\0"
    "externalCommand(QString)\0"
    "windowSelected(uint32_t)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendConfigCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->updateSummaryField((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->setRunStateEnums((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< vector<QString>(*)>(_a[2]))); break;
        case 6: _t->openPgp(); break;
        case 7: _t->addPgpRow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->addPgpDone(); break;
        case 9: _t->updatePgpField((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->lostConnection(); break;
        case 11: _t->openPgpPressed(); break;
        case 12: _t->lostConnectionSlot(); break;
        case 13: _t->cfgReadPressed(); break;
        case 14: _t->cfgWritePressed(); break;
        case 15: _t->cfgVerifyPressed(); break;
        case 16: _t->statReadPressed(); break;
        case 17: _t->helpPressed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 18: _t->commandPressed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->createDescription((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->createCommand((*reinterpret_cast< CommandHolder*(*)>(_a[1]))); break;
        case 21: _t->createVariable((*reinterpret_cast< VariableHolder*(*)>(_a[1]))); break;
        case 22: _t->createDone(); break;
        case 23: _t->updateVariable((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 24: _t->updateDone((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 25: _t->gotError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->externalCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->windowSelected((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::openServer(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendCommand(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sendConfig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sendConfigCommand(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::updateSummaryField(uint32_t _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::setRunStateEnums(uint32_t _t1, vector<QString> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::openPgp()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainWindow::addPgpRow(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::addPgpDone()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void MainWindow::updatePgpField(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::lostConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}
QT_END_MOC_NAMESPACE
