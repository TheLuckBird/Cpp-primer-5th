/****************************************************************************
** Meta object code from reading C++ file 'worldlistwea.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtWeatherForecast-main/worldlistwea.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worldlistwea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWorldListWeaENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWorldListWeaENDCLASS = QtMocHelpers::stringData(
    "WorldListWea",
    "BackButton",
    "",
    "setData",
    "text",
    "sendIsland",
    "on_pushButton_2_clicked",
    "on_listWidget_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_stateWidget_itemDoubleClicked",
    "on_listBtn_clicked",
    "getTemp",
    "temp",
    "city",
    "type"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWorldListWeaENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[13];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[5];
    char stringdata5[11];
    char stringdata6[24];
    char stringdata7[32];
    char stringdata8[17];
    char stringdata9[5];
    char stringdata10[33];
    char stringdata11[19];
    char stringdata12[8];
    char stringdata13[5];
    char stringdata14[5];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWorldListWeaENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWorldListWeaENDCLASS_t qt_meta_stringdata_CLASSWorldListWeaENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "WorldListWea"
        QT_MOC_LITERAL(13, 10),  // "BackButton"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 7),  // "setData"
        QT_MOC_LITERAL(33, 4),  // "text"
        QT_MOC_LITERAL(38, 10),  // "sendIsland"
        QT_MOC_LITERAL(49, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(73, 31),  // "on_listWidget_itemDoubleClicked"
        QT_MOC_LITERAL(105, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(122, 4),  // "item"
        QT_MOC_LITERAL(127, 32),  // "on_stateWidget_itemDoubleClicked"
        QT_MOC_LITERAL(160, 18),  // "on_listBtn_clicked"
        QT_MOC_LITERAL(179, 7),  // "getTemp"
        QT_MOC_LITERAL(187, 4),  // "temp"
        QT_MOC_LITERAL(192, 4),  // "city"
        QT_MOC_LITERAL(197, 4)   // "type"
    },
    "WorldListWea",
    "BackButton",
    "",
    "setData",
    "text",
    "sendIsland",
    "on_pushButton_2_clicked",
    "on_listWidget_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_stateWidget_itemDoubleClicked",
    "on_listBtn_clicked",
    "getTemp",
    "temp",
    "city",
    "type"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWorldListWeaENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    1,   63,    2, 0x06,    2 /* Public */,
       5,    1,   66,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   69,    2, 0x08,    6 /* Private */,
       7,    1,   70,    2, 0x08,    7 /* Private */,
      10,    0,   73,    2, 0x08,    9 /* Private */,
      11,    0,   74,    2, 0x08,   10 /* Private */,
      12,    3,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject WorldListWea::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSWorldListWeaENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWorldListWeaENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWorldListWeaENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WorldListWea, std::true_type>,
        // method 'BackButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendIsland'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_listWidget_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_stateWidget_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_listBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getTemp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void WorldListWea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorldListWea *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->BackButton(); break;
        case 1: _t->setData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sendIsland((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 5: _t->on_stateWidget_itemDoubleClicked(); break;
        case 6: _t->on_listBtn_clicked(); break;
        case 7: _t->getTemp((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WorldListWea::*)();
            if (_t _q_method = &WorldListWea::BackButton; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WorldListWea::*)(QString );
            if (_t _q_method = &WorldListWea::setData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WorldListWea::*)(QString );
            if (_t _q_method = &WorldListWea::sendIsland; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *WorldListWea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorldListWea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWorldListWeaENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WorldListWea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void WorldListWea::BackButton()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WorldListWea::setData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorldListWea::sendIsland(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
