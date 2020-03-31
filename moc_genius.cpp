/****************************************************************************
** Meta object code from reading C++ file 'simon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "genius.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'genius.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Genius_t {
    QByteArrayData data[12];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Genius_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Genius_t qt_meta_stringdata_Genius = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Genius"
QT_MOC_LITERAL(1, 7, 14), // "_passouDeNivel"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "_perdeuNoNivel"
QT_MOC_LITERAL(4, 38, 16), // "handleBotaoVerde"
QT_MOC_LITERAL(5, 55, 19), // "handleBotaoVermelho"
QT_MOC_LITERAL(6, 75, 18), // "handleBotaoAmarelo"
QT_MOC_LITERAL(7, 94, 15), // "handleBotaoAzul"
QT_MOC_LITERAL(8, 110, 17), // "handlBotaoIniciar"
QT_MOC_LITERAL(9, 128, 15), // "iniciaNovoNivel"
QT_MOC_LITERAL(10, 144, 12), // "reiniciaJogo"
QT_MOC_LITERAL(11, 157, 9) // "startGame"

    },
    "Genius\0_passouDeNivel\0\0_perdeuNoNivel\0"
    "handleBotaoVerde\0handleBotaoVermelho\0"
    "handleBotaoAmarelo\0handleBotaoAzul\0"
    "handlBotaoIniciar\0iniciaNovoNivel\0"
    "reiniciaJogo\0startGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Genius[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void Genius::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Genius *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_passouDeNivel(); break;
        case 1: _t->_perdeuNoNivel(); break;
        case 2: _t->handleBotaoVerde(); break;
        case 3: _t->handleBotaoVermelho(); break;
        case 4: _t->handleBotaoAmarelo(); break;
        case 5: _t->handleBotaoAzul(); break;
        case 6: _t->handlBotaoIniciar(); break;
        case 7: _t->iniciaNovoNivel(); break;
        case 8: _t->reiniciaJogo(); break;
        case 9: _t->startGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Genius::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Genius::_passouDeNivel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Genius::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Genius::_perdeuNoNivel)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Genius::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Genius.data,
    qt_meta_data_Genius,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Genius::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Genius::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Genius.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Genius::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Genius::_passouDeNivel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Genius::_perdeuNoNivel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
