/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ventanaprincipal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaPrincipal_t {
    QByteArrayData data[16];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(1, 17, 16), // "senyalBolaMuerta"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "slotTemporizador"
QT_MOC_LITERAL(4, 52, 14), // "slotListaBolas"
QT_MOC_LITERAL(5, 67, 14), // "slotTablaBolas"
QT_MOC_LITERAL(6, 82, 16), // "slotControlBolas"
QT_MOC_LITERAL(7, 99, 17), // "slotPosicionBolas"
QT_MOC_LITERAL(8, 117, 18), // "slotGuardarPartida"
QT_MOC_LITERAL(9, 136, 17), // "slotCargarPartida"
QT_MOC_LITERAL(10, 154, 14), // "slotBolaImagen"
QT_MOC_LITERAL(11, 169, 5), // "Bola*"
QT_MOC_LITERAL(12, 175, 18), // "slotEliminarImagen"
QT_MOC_LITERAL(13, 194, 16), // "slotTablaNombres"
QT_MOC_LITERAL(14, 211, 14), // "slotNombreBola"
QT_MOC_LITERAL(15, 226, 16) // "slotAbrirDNombre"

    },
    "VentanaPrincipal\0senyalBolaMuerta\0\0"
    "slotTemporizador\0slotListaBolas\0"
    "slotTablaBolas\0slotControlBolas\0"
    "slotPosicionBolas\0slotGuardarPartida\0"
    "slotCargarPartida\0slotBolaImagen\0Bola*\0"
    "slotEliminarImagen\0slotTablaNombres\0"
    "slotNombreBola\0slotAbrirDNombre"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   82,    2, 0x0a /* Public */,
       4,    0,   83,    2, 0x0a /* Public */,
       5,    0,   84,    2, 0x0a /* Public */,
       6,    0,   85,    2, 0x0a /* Public */,
       7,    0,   86,    2, 0x0a /* Public */,
       8,    0,   87,    2, 0x0a /* Public */,
       9,    0,   88,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    0,   94,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VentanaPrincipal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->senyalBolaMuerta((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotTemporizador(); break;
        case 2: _t->slotListaBolas(); break;
        case 3: _t->slotTablaBolas(); break;
        case 4: _t->slotControlBolas(); break;
        case 5: _t->slotPosicionBolas(); break;
        case 6: _t->slotGuardarPartida(); break;
        case 7: _t->slotCargarPartida(); break;
        case 8: _t->slotBolaImagen((*reinterpret_cast< Bola*(*)>(_a[1]))); break;
        case 9: _t->slotEliminarImagen(); break;
        case 10: _t->slotTablaNombres(); break;
        case 11: _t->slotNombreBola(); break;
        case 12: _t->slotAbrirDNombre(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Bola* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VentanaPrincipal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VentanaPrincipal::senyalBolaMuerta)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VentanaPrincipal::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_VentanaPrincipal.data,
    qt_meta_data_VentanaPrincipal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void VentanaPrincipal::senyalBolaMuerta(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
