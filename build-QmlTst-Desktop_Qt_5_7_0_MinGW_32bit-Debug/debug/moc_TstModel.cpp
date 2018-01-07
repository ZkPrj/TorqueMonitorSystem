/****************************************************************************
** Meta object code from reading C++ file 'TstModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QmlTst/TstModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TstModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TstModel_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TstModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TstModel_t qt_meta_stringdata_TstModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TstModel"
QT_MOC_LITERAL(1, 9, 10), // "getTorList"
QT_MOC_LITERAL(2, 20, 12), // "QList<qreal>"
QT_MOC_LITERAL(3, 33, 0), // ""
QT_MOC_LITERAL(4, 34, 11), // "getTimeSpan"
QT_MOC_LITERAL(5, 46, 10) // "getListNum"

    },
    "TstModel\0getTorList\0QList<qreal>\0\0"
    "getTimeSpan\0getListNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TstModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   29,    3, 0x02 /* Public */,
       4,    0,   30,    3, 0x02 /* Public */,
       5,    0,   31,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    QMetaType::Int,

       0        // eod
};

void TstModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TstModel *_t = static_cast<TstModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QList<qreal> _r = _t->getTorList();
            if (_a[0]) *reinterpret_cast< QList<qreal>*>(_a[0]) = _r; }  break;
        case 1: { QList<qreal> _r = _t->getTimeSpan();
            if (_a[0]) *reinterpret_cast< QList<qreal>*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->getListNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject TstModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TstModel.data,
      qt_meta_data_TstModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TstModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TstModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TstModel.stringdata0))
        return static_cast<void*>(const_cast< TstModel*>(this));
    return QObject::qt_metacast(_clname);
}

int TstModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
