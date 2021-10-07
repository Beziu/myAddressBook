/****************************************************************************
** Meta object code from reading C++ file 'ContactDialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/ContactDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ContactDialog_t {
    const uint offsetsAndSize[42];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ContactDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ContactDialog_t qt_meta_stringdata_ContactDialog = {
    {
QT_MOC_LITERAL(0, 13), // "ContactDialog"
QT_MOC_LITERAL(14, 11), // "refreshData"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 3), // "key"
QT_MOC_LITERAL(31, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(52, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(71, 23), // "on_textName_textChanged"
QT_MOC_LITERAL(95, 4), // "arg1"
QT_MOC_LITERAL(100, 26), // "on_textSurname_textChanged"
QT_MOC_LITERAL(127, 25), // "on_textPhone1_textChanged"
QT_MOC_LITERAL(153, 25), // "on_textPhone2_textChanged"
QT_MOC_LITERAL(179, 24), // "on_textEmail_textChanged"
QT_MOC_LITERAL(204, 22), // "on_textPLZ_textChanged"
QT_MOC_LITERAL(227, 23), // "on_textCity_textChanged"
QT_MOC_LITERAL(251, 25), // "on_textStreet_textChanged"
QT_MOC_LITERAL(277, 34), // "on_calendarWidget_selectionCh..."
QT_MOC_LITERAL(312, 24), // "on_checkBirthday_toggled"
QT_MOC_LITERAL(337, 7), // "checked"
QT_MOC_LITERAL(345, 25), // "on_listGroups_itemClicked"
QT_MOC_LITERAL(371, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(388, 4) // "item"

    },
    "ContactDialog\0refreshData\0\0key\0"
    "on_btnCancel_clicked\0on_btnSave_clicked\0"
    "on_textName_textChanged\0arg1\0"
    "on_textSurname_textChanged\0"
    "on_textPhone1_textChanged\0"
    "on_textPhone2_textChanged\0"
    "on_textEmail_textChanged\0"
    "on_textPLZ_textChanged\0on_textCity_textChanged\0"
    "on_textStreet_textChanged\0"
    "on_calendarWidget_selectionChanged\0"
    "on_checkBirthday_toggled\0checked\0"
    "on_listGroups_itemClicked\0QListWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  101,    2, 0x08,    3 /* Private */,
       5,    0,  102,    2, 0x08,    4 /* Private */,
       6,    1,  103,    2, 0x08,    5 /* Private */,
       8,    1,  106,    2, 0x08,    7 /* Private */,
       9,    1,  109,    2, 0x08,    9 /* Private */,
      10,    1,  112,    2, 0x08,   11 /* Private */,
      11,    1,  115,    2, 0x08,   13 /* Private */,
      12,    1,  118,    2, 0x08,   15 /* Private */,
      13,    1,  121,    2, 0x08,   17 /* Private */,
      14,    1,  124,    2, 0x08,   19 /* Private */,
      15,    0,  127,    2, 0x08,   21 /* Private */,
      16,    1,  128,    2, 0x08,   22 /* Private */,
      18,    1,  131,    2, 0x08,   24 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void ContactDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContactDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refreshData((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 1: _t->on_btnCancel_clicked(); break;
        case 2: _t->on_btnSave_clicked(); break;
        case 3: _t->on_textName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_textSurname_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_textPhone1_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_textPhone2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_textEmail_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_textPLZ_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_textCity_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_textStreet_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_calendarWidget_selectionChanged(); break;
        case 12: _t->on_checkBirthday_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_listGroups_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ContactDialog::*)(const qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ContactDialog::refreshData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ContactDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ContactDialog.offsetsAndSize,
    qt_meta_data_ContactDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ContactDialog_t
, QtPrivate::TypeAndForceComplete<ContactDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const qint64, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>


>,
    nullptr
} };


const QMetaObject *ContactDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ContactDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ContactDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ContactDialog::refreshData(const qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
