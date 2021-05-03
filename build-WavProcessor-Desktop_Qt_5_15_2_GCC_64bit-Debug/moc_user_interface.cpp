/****************************************************************************
** Meta object code from reading C++ file 'user_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../user_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Wav_Processor_t {
    QByteArrayData data[17];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Wav_Processor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Wav_Processor_t qt_meta_stringdata_Wav_Processor = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Wav_Processor"
QT_MOC_LITERAL(1, 14, 21), // "on_FileButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "on_LoadButton_clicked"
QT_MOC_LITERAL(4, 59, 26), // "on_DockedFiles_itemClicked"
QT_MOC_LITERAL(5, 86, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 103, 4), // "item"
QT_MOC_LITERAL(7, 108, 21), // "on_EditButton_clicked"
QT_MOC_LITERAL(8, 130, 23), // "on_RemoveButton_clicked"
QT_MOC_LITERAL(9, 154, 33), // "on_DockedFiles_currentItemCha..."
QT_MOC_LITERAL(10, 188, 7), // "current"
QT_MOC_LITERAL(11, 196, 8), // "previous"
QT_MOC_LITERAL(12, 205, 29), // "on_EditMetadataButton_clicked"
QT_MOC_LITERAL(13, 235, 30), // "on_ApplyMetadataButton_clicked"
QT_MOC_LITERAL(14, 266, 21), // "on_PlayButton_clicked"
QT_MOC_LITERAL(15, 288, 21), // "on_OpenButton_clicked"
QT_MOC_LITERAL(16, 310, 21) // "on_SaveButton_clicked"

    },
    "Wav_Processor\0on_FileButton_clicked\0"
    "\0on_LoadButton_clicked\0"
    "on_DockedFiles_itemClicked\0QListWidgetItem*\0"
    "item\0on_EditButton_clicked\0"
    "on_RemoveButton_clicked\0"
    "on_DockedFiles_currentItemChanged\0"
    "current\0previous\0on_EditMetadataButton_clicked\0"
    "on_ApplyMetadataButton_clicked\0"
    "on_PlayButton_clicked\0on_OpenButton_clicked\0"
    "on_SaveButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Wav_Processor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    2,   76,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Wav_Processor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Wav_Processor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_FileButton_clicked(); break;
        case 1: _t->on_LoadButton_clicked(); break;
        case 2: _t->on_DockedFiles_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_EditButton_clicked(); break;
        case 4: _t->on_RemoveButton_clicked(); break;
        case 5: _t->on_DockedFiles_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 6: _t->on_EditMetadataButton_clicked(); break;
        case 7: _t->on_ApplyMetadataButton_clicked(); break;
        case 8: _t->on_PlayButton_clicked(); break;
        case 9: _t->on_OpenButton_clicked(); break;
        case 10: _t->on_SaveButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Wav_Processor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Wav_Processor.data,
    qt_meta_data_Wav_Processor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Wav_Processor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Wav_Processor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Wav_Processor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Wav_Processor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
