/****************************************************************************
** Meta object code from reading C++ file 'GroupsWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/GroupsWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GroupsWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GroupsWindow_t {
    const uint offsetsAndSize[28];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GroupsWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GroupsWindow_t qt_meta_stringdata_GroupsWindow = {
    {
QT_MOC_LITERAL(0, 12), // "GroupsWindow"
QT_MOC_LITERAL(13, 12), // "windowClosed"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 14), // "const QWidget*"
QT_MOC_LITERAL(42, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(66, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(89, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(115, 23), // "on_actionEdit_triggered"
QT_MOC_LITERAL(139, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(166, 11), // "QModelIndex"
QT_MOC_LITERAL(178, 5), // "index"
QT_MOC_LITERAL(184, 15), // "updateGroupView"
QT_MOC_LITERAL(200, 10), // "closeEvent"
QT_MOC_LITERAL(211, 12) // "QCloseEvent*"

    },
    "GroupsWindow\0windowClosed\0\0const QWidget*\0"
    "on_actionExit_triggered\0on_actionNew_triggered\0"
    "on_actionDelete_triggered\0"
    "on_actionEdit_triggered\0"
    "on_tableView_doubleClicked\0QModelIndex\0"
    "index\0updateGroupView\0closeEvent\0"
    "QCloseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupsWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   65,    2, 0x08,    3 /* Private */,
       5,    0,   66,    2, 0x08,    4 /* Private */,
       6,    0,   67,    2, 0x08,    5 /* Private */,
       7,    0,   68,    2, 0x08,    6 /* Private */,
       8,    1,   69,    2, 0x08,    7 /* Private */,
      11,    0,   72,    2, 0x08,    9 /* Private */,
      12,    1,   73,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,

       0        // eod
};

void GroupsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GroupsWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->windowClosed((*reinterpret_cast< const QWidget*(*)>(_a[1]))); break;
        case 1: _t->on_actionExit_triggered(); break;
        case 2: _t->on_actionNew_triggered(); break;
        case 3: _t->on_actionDelete_triggered(); break;
        case 4: _t->on_actionEdit_triggered(); break;
        case 5: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->updateGroupView(); break;
        case 7: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GroupsWindow::*)(const QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GroupsWindow::windowClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GroupsWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_GroupsWindow.offsetsAndSize,
    qt_meta_data_GroupsWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GroupsWindow_t
, QtPrivate::TypeAndForceComplete<GroupsWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QWidget *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *GroupsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GroupsWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GroupsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void GroupsWindow::windowClosed(const QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
