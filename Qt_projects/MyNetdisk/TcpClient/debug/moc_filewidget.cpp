/****************************************************************************
** Meta object code from reading C++ file 'filewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filewidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSFileWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFileWidgetENDCLASS = QtMocHelpers::stringData(
    "FileWidget",
    "CreateDirSignal",
    "",
    "FlushDirSignal",
    "DelDirSignal",
    "RenameSignal",
    "EnterDir",
    "ReturnFatherDir",
    "DelFileSignal",
    "MoveFileSignal",
    "SelectDestFileSignal",
    "UploadFileSignal",
    "DownloadFileSignal",
    "ShareFileSignal",
    "ShareFileToFriendsSignal",
    "QStringList&",
    "on_m_createDir_clicked",
    "on_m_flushFile_clicked",
    "on_m_deleteDir_clicked",
    "on_m_renameDir_clicked",
    "on_m_showList_itemDoubleClicked",
    "QListWidgetItem*",
    "on_m_return_clicked",
    "on_m_deleteFile_clicked",
    "on_m_moveFile_clicked",
    "on_m_selectFile_clicked",
    "on_m_uploadFile_clicked",
    "on_m_downloadFile_clicked",
    "on_m_shareFile_clicked",
    "do_ShareFileToFriendSignal"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFileWidgetENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[9];
    char stringdata7[16];
    char stringdata8[14];
    char stringdata9[15];
    char stringdata10[21];
    char stringdata11[17];
    char stringdata12[19];
    char stringdata13[16];
    char stringdata14[25];
    char stringdata15[13];
    char stringdata16[23];
    char stringdata17[23];
    char stringdata18[23];
    char stringdata19[23];
    char stringdata20[32];
    char stringdata21[17];
    char stringdata22[20];
    char stringdata23[24];
    char stringdata24[22];
    char stringdata25[24];
    char stringdata26[24];
    char stringdata27[26];
    char stringdata28[23];
    char stringdata29[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFileWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFileWidgetENDCLASS_t qt_meta_stringdata_CLASSFileWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "FileWidget"
        QT_MOC_LITERAL(11, 15),  // "CreateDirSignal"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 14),  // "FlushDirSignal"
        QT_MOC_LITERAL(43, 12),  // "DelDirSignal"
        QT_MOC_LITERAL(56, 12),  // "RenameSignal"
        QT_MOC_LITERAL(69, 8),  // "EnterDir"
        QT_MOC_LITERAL(78, 15),  // "ReturnFatherDir"
        QT_MOC_LITERAL(94, 13),  // "DelFileSignal"
        QT_MOC_LITERAL(108, 14),  // "MoveFileSignal"
        QT_MOC_LITERAL(123, 20),  // "SelectDestFileSignal"
        QT_MOC_LITERAL(144, 16),  // "UploadFileSignal"
        QT_MOC_LITERAL(161, 18),  // "DownloadFileSignal"
        QT_MOC_LITERAL(180, 15),  // "ShareFileSignal"
        QT_MOC_LITERAL(196, 24),  // "ShareFileToFriendsSignal"
        QT_MOC_LITERAL(221, 12),  // "QStringList&"
        QT_MOC_LITERAL(234, 22),  // "on_m_createDir_clicked"
        QT_MOC_LITERAL(257, 22),  // "on_m_flushFile_clicked"
        QT_MOC_LITERAL(280, 22),  // "on_m_deleteDir_clicked"
        QT_MOC_LITERAL(303, 22),  // "on_m_renameDir_clicked"
        QT_MOC_LITERAL(326, 31),  // "on_m_showList_itemDoubleClicked"
        QT_MOC_LITERAL(358, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(375, 19),  // "on_m_return_clicked"
        QT_MOC_LITERAL(395, 23),  // "on_m_deleteFile_clicked"
        QT_MOC_LITERAL(419, 21),  // "on_m_moveFile_clicked"
        QT_MOC_LITERAL(441, 23),  // "on_m_selectFile_clicked"
        QT_MOC_LITERAL(465, 23),  // "on_m_uploadFile_clicked"
        QT_MOC_LITERAL(489, 25),  // "on_m_downloadFile_clicked"
        QT_MOC_LITERAL(515, 22),  // "on_m_shareFile_clicked"
        QT_MOC_LITERAL(538, 26)   // "do_ShareFileToFriendSignal"
    },
    "FileWidget",
    "CreateDirSignal",
    "",
    "FlushDirSignal",
    "DelDirSignal",
    "RenameSignal",
    "EnterDir",
    "ReturnFatherDir",
    "DelFileSignal",
    "MoveFileSignal",
    "SelectDestFileSignal",
    "UploadFileSignal",
    "DownloadFileSignal",
    "ShareFileSignal",
    "ShareFileToFriendsSignal",
    "QStringList&",
    "on_m_createDir_clicked",
    "on_m_flushFile_clicked",
    "on_m_deleteDir_clicked",
    "on_m_renameDir_clicked",
    "on_m_showList_itemDoubleClicked",
    "QListWidgetItem*",
    "on_m_return_clicked",
    "on_m_deleteFile_clicked",
    "on_m_moveFile_clicked",
    "on_m_selectFile_clicked",
    "on_m_uploadFile_clicked",
    "on_m_downloadFile_clicked",
    "on_m_shareFile_clicked",
    "do_ShareFileToFriendSignal"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFileWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  170,    2, 0x06,    1 /* Public */,
       3,    0,  173,    2, 0x06,    3 /* Public */,
       4,    1,  174,    2, 0x06,    4 /* Public */,
       5,    2,  177,    2, 0x06,    6 /* Public */,
       6,    1,  182,    2, 0x06,    9 /* Public */,
       7,    0,  185,    2, 0x06,   11 /* Public */,
       8,    1,  186,    2, 0x06,   12 /* Public */,
       9,    1,  189,    2, 0x06,   14 /* Public */,
      10,    1,  192,    2, 0x06,   16 /* Public */,
      11,    2,  195,    2, 0x06,   18 /* Public */,
      12,    2,  200,    2, 0x06,   21 /* Public */,
      13,    1,  205,    2, 0x06,   24 /* Public */,
      14,    2,  208,    2, 0x06,   26 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    0,  213,    2, 0x08,   29 /* Private */,
      17,    0,  214,    2, 0x08,   30 /* Private */,
      18,    0,  215,    2, 0x08,   31 /* Private */,
      19,    0,  216,    2, 0x08,   32 /* Private */,
      20,    1,  217,    2, 0x08,   33 /* Private */,
      22,    0,  220,    2, 0x08,   35 /* Private */,
      23,    0,  221,    2, 0x08,   36 /* Private */,
      24,    0,  222,    2, 0x08,   37 /* Private */,
      25,    0,  223,    2, 0x08,   38 /* Private */,
      26,    0,  224,    2, 0x08,   39 /* Private */,
      27,    0,  225,    2, 0x08,   40 /* Private */,
      28,    0,  226,    2, 0x08,   41 /* Private */,
      29,    1,  227,    2, 0x08,   42 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 15, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject FileWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSFileWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFileWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFileWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FileWidget, std::true_type>,
        // method 'CreateDirSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'FlushDirSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DelDirSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'RenameSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'EnterDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ReturnFatherDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DelFileSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'MoveFileSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SelectDestFileSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'UploadFileSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'DownloadFileSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ShareFileSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ShareFileToFriendsSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_m_createDir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_flushFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_deleteDir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_renameDir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_showList_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_m_return_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_deleteFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_moveFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_selectFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_uploadFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_downloadFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_m_shareFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_ShareFileToFriendSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList &, std::false_type>
    >,
    nullptr
} };

void FileWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->CreateDirSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->FlushDirSignal(); break;
        case 2: _t->DelDirSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->RenameSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->EnterDir((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->ReturnFatherDir(); break;
        case 6: _t->DelFileSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->MoveFileSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->SelectDestFileSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->UploadFileSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 10: _t->DownloadFileSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->ShareFileSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->ShareFileToFriendsSignal((*reinterpret_cast< std::add_pointer_t<QStringList&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 13: _t->on_m_createDir_clicked(); break;
        case 14: _t->on_m_flushFile_clicked(); break;
        case 15: _t->on_m_deleteDir_clicked(); break;
        case 16: _t->on_m_renameDir_clicked(); break;
        case 17: _t->on_m_showList_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 18: _t->on_m_return_clicked(); break;
        case 19: _t->on_m_deleteFile_clicked(); break;
        case 20: _t->on_m_moveFile_clicked(); break;
        case 21: _t->on_m_selectFile_clicked(); break;
        case 22: _t->on_m_uploadFile_clicked(); break;
        case 23: _t->on_m_downloadFile_clicked(); break;
        case 24: _t->on_m_shareFile_clicked(); break;
        case 25: _t->do_ShareFileToFriendSignal((*reinterpret_cast< std::add_pointer_t<QStringList&>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileWidget::*)(QString );
            if (_t _q_method = &FileWidget::CreateDirSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)();
            if (_t _q_method = &FileWidget::FlushDirSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString );
            if (_t _q_method = &FileWidget::DelDirSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString , QString );
            if (_t _q_method = &FileWidget::RenameSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString );
            if (_t _q_method = &FileWidget::EnterDir; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)();
            if (_t _q_method = &FileWidget::ReturnFatherDir; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString );
            if (_t _q_method = &FileWidget::DelFileSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString );
            if (_t _q_method = &FileWidget::MoveFileSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString );
            if (_t _q_method = &FileWidget::SelectDestFileSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString , qint64 );
            if (_t _q_method = &FileWidget::UploadFileSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString , QString );
            if (_t _q_method = &FileWidget::DownloadFileSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QString );
            if (_t _q_method = &FileWidget::ShareFileSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (FileWidget::*)(QStringList & , QString );
            if (_t _q_method = &FileWidget::ShareFileToFriendsSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    }
}

const QMetaObject *FileWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFileWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FileWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void FileWidget::CreateDirSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileWidget::FlushDirSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FileWidget::DelDirSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileWidget::RenameSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FileWidget::EnterDir(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FileWidget::ReturnFatherDir()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FileWidget::DelFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void FileWidget::MoveFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void FileWidget::SelectDestFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void FileWidget::UploadFileSignal(QString _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void FileWidget::DownloadFileSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void FileWidget::ShareFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void FileWidget::ShareFileToFriendsSignal(QStringList & _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
