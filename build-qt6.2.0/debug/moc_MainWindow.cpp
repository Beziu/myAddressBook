/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 33), // "on_actionImportContacts_trigg..."
QT_MOC_LITERAL(45, 0), // ""
QT_MOC_LITERAL(46, 29), // "on_actionGroupsEdit_triggered"
QT_MOC_LITERAL(76, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(103, 11), // "QModelIndex"
QT_MOC_LITERAL(115, 5), // "index"
QT_MOC_LITERAL(121, 22), // "on_actionEnd_triggered"
QT_MOC_LITERAL(144, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(167, 23), // "on_actionEdit_triggered"
QT_MOC_LITERAL(191, 27), // "on_textSearch_returnPressed"
QT_MOC_LITERAL(219, 15), // "updateTableView"
QT_MOC_LITERAL(235, 3), // "cid"
QT_MOC_LITERAL(239, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(265, 33), // "on_actionBirthdaysTable_trigg..."
QT_MOC_LITERAL(299, 21), // "on_boxGroup_activated"
QT_MOC_LITERAL(321, 14), // "onWindowClosed"
QT_MOC_LITERAL(336, 14), // "const QWidget*"
QT_MOC_LITERAL(351, 31) // "on_boxGroup_currentIndexChanged"

    },
    "MainWindow\0on_actionImportContacts_triggered\0"
    "\0on_actionGroupsEdit_triggered\0"
    "on_tableView_doubleClicked\0QModelIndex\0"
    "index\0on_actionEnd_triggered\0"
    "on_actionNew_triggered\0on_actionEdit_triggered\0"
    "on_textSearch_returnPressed\0updateTableView\0"
    "cid\0on_actionDelete_triggered\0"
    "on_actionBirthdaysTable_triggered\0"
    "on_boxGroup_activated\0onWindowClosed\0"
    "const QWidget*\0on_boxGroup_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    1,   94,    2, 0x08,    3 /* Private */,
       7,    0,   97,    2, 0x08,    5 /* Private */,
       8,    0,   98,    2, 0x08,    6 /* Private */,
       9,    0,   99,    2, 0x08,    7 /* Private */,
      10,    0,  100,    2, 0x08,    8 /* Private */,
      11,    1,  101,    2, 0x08,    9 /* Private */,
      13,    0,  104,    2, 0x08,   11 /* Private */,
      14,    0,  105,    2, 0x08,   12 /* Private */,
      15,    1,  106,    2, 0x08,   13 /* Private */,
      16,    1,  109,    2, 0x08,   15 /* Private */,
      18,    1,  112,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionImportContacts_triggered(); break;
        case 1: _t->on_actionGroupsEdit_triggered(); break;
        case 2: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_actionEnd_triggered(); break;
        case 4: _t->on_actionNew_triggered(); break;
        case 5: _t->on_actionEdit_triggered(); break;
        case 6: _t->on_textSearch_returnPressed(); break;
        case 7: _t->updateTableView((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 8: _t->on_actionDelete_triggered(); break;
        case 9: _t->on_actionBirthdaysTable_triggered(); break;
        case 10: _t->on_boxGroup_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onWindowClosed((*reinterpret_cast< const QWidget*(*)>(_a[1]))); break;
        case 12: _t->on_boxGroup_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
