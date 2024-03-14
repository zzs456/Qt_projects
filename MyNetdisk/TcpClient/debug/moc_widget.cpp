/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidgetENDCLASS = QtMocHelpers::stringData(
    "Widget",
    "RegisterRespondSignal",
    "",
    "PDU*",
    "LoginRespondSignal",
    "ShowAllOnlineUsersSignal",
    "FindUserSignal",
    "AddFriendSignal",
    "DelFriendSignal",
    "ConSuccess",
    "do_Register",
    "do_Login",
    "recvMsg",
    "do_Show",
    "do_ShowOnlineUsers",
    "do_FindUser",
    "do_AddUser",
    "do_FlushFriend",
    "do_DelFriend",
    "do_PrivateChat",
    "do_PrivateChatMsg",
    "do_GroupChat",
    "do_CreateDir",
    "do_FlushDir",
    "do_DelDir",
    "do_DelFile",
    "do_Rename",
    "do_EnterDir",
    "do_ReturnFatherDir",
    "do_MoveFile",
    "do_SelectDest",
    "do_UploadFile",
    "do_UploadFileData",
    "do_DownloadFile",
    "do_ShareFileConfirm",
    "do_ShareFileToFriends",
    "QStringList&"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {
    uint offsetsAndSizes[74];
    char stringdata0[7];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[19];
    char stringdata5[25];
    char stringdata6[15];
    char stringdata7[16];
    char stringdata8[16];
    char stringdata9[11];
    char stringdata10[12];
    char stringdata11[9];
    char stringdata12[8];
    char stringdata13[8];
    char stringdata14[19];
    char stringdata15[12];
    char stringdata16[11];
    char stringdata17[15];
    char stringdata18[13];
    char stringdata19[15];
    char stringdata20[18];
    char stringdata21[13];
    char stringdata22[13];
    char stringdata23[12];
    char stringdata24[10];
    char stringdata25[11];
    char stringdata26[10];
    char stringdata27[12];
    char stringdata28[19];
    char stringdata29[12];
    char stringdata30[14];
    char stringdata31[14];
    char stringdata32[18];
    char stringdata33[16];
    char stringdata34[20];
    char stringdata35[22];
    char stringdata36[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidgetENDCLASS_t qt_meta_stringdata_CLASSWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 21),  // "RegisterRespondSignal"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 4),  // "PDU*"
        QT_MOC_LITERAL(35, 18),  // "LoginRespondSignal"
        QT_MOC_LITERAL(54, 24),  // "ShowAllOnlineUsersSignal"
        QT_MOC_LITERAL(79, 14),  // "FindUserSignal"
        QT_MOC_LITERAL(94, 15),  // "AddFriendSignal"
        QT_MOC_LITERAL(110, 15),  // "DelFriendSignal"
        QT_MOC_LITERAL(126, 10),  // "ConSuccess"
        QT_MOC_LITERAL(137, 11),  // "do_Register"
        QT_MOC_LITERAL(149, 8),  // "do_Login"
        QT_MOC_LITERAL(158, 7),  // "recvMsg"
        QT_MOC_LITERAL(166, 7),  // "do_Show"
        QT_MOC_LITERAL(174, 18),  // "do_ShowOnlineUsers"
        QT_MOC_LITERAL(193, 11),  // "do_FindUser"
        QT_MOC_LITERAL(205, 10),  // "do_AddUser"
        QT_MOC_LITERAL(216, 14),  // "do_FlushFriend"
        QT_MOC_LITERAL(231, 12),  // "do_DelFriend"
        QT_MOC_LITERAL(244, 14),  // "do_PrivateChat"
        QT_MOC_LITERAL(259, 17),  // "do_PrivateChatMsg"
        QT_MOC_LITERAL(277, 12),  // "do_GroupChat"
        QT_MOC_LITERAL(290, 12),  // "do_CreateDir"
        QT_MOC_LITERAL(303, 11),  // "do_FlushDir"
        QT_MOC_LITERAL(315, 9),  // "do_DelDir"
        QT_MOC_LITERAL(325, 10),  // "do_DelFile"
        QT_MOC_LITERAL(336, 9),  // "do_Rename"
        QT_MOC_LITERAL(346, 11),  // "do_EnterDir"
        QT_MOC_LITERAL(358, 18),  // "do_ReturnFatherDir"
        QT_MOC_LITERAL(377, 11),  // "do_MoveFile"
        QT_MOC_LITERAL(389, 13),  // "do_SelectDest"
        QT_MOC_LITERAL(403, 13),  // "do_UploadFile"
        QT_MOC_LITERAL(417, 17),  // "do_UploadFileData"
        QT_MOC_LITERAL(435, 15),  // "do_DownloadFile"
        QT_MOC_LITERAL(451, 19),  // "do_ShareFileConfirm"
        QT_MOC_LITERAL(471, 21),  // "do_ShareFileToFriends"
        QT_MOC_LITERAL(493, 12)   // "QStringList&"
    },
    "Widget",
    "RegisterRespondSignal",
    "",
    "PDU*",
    "LoginRespondSignal",
    "ShowAllOnlineUsersSignal",
    "FindUserSignal",
    "AddFriendSignal",
    "DelFriendSignal",
    "ConSuccess",
    "do_Register",
    "do_Login",
    "recvMsg",
    "do_Show",
    "do_ShowOnlineUsers",
    "do_FindUser",
    "do_AddUser",
    "do_FlushFriend",
    "do_DelFriend",
    "do_PrivateChat",
    "do_PrivateChatMsg",
    "do_GroupChat",
    "do_CreateDir",
    "do_FlushDir",
    "do_DelDir",
    "do_DelFile",
    "do_Rename",
    "do_EnterDir",
    "do_ReturnFatherDir",
    "do_MoveFile",
    "do_SelectDest",
    "do_UploadFile",
    "do_UploadFileData",
    "do_DownloadFile",
    "do_ShareFileConfirm",
    "do_ShareFileToFriends",
    "QStringList&"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  212,    2, 0x06,    1 /* Public */,
       4,    1,  215,    2, 0x06,    3 /* Public */,
       5,    1,  218,    2, 0x06,    5 /* Public */,
       6,    1,  221,    2, 0x06,    7 /* Public */,
       7,    1,  224,    2, 0x06,    9 /* Public */,
       8,    1,  227,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  230,    2, 0x08,   13 /* Private */,
      10,    2,  231,    2, 0x08,   14 /* Private */,
      11,    2,  236,    2, 0x08,   17 /* Private */,
      12,    0,  241,    2, 0x08,   20 /* Private */,
      13,    0,  242,    2, 0x08,   21 /* Private */,
      14,    0,  243,    2, 0x08,   22 /* Private */,
      15,    1,  244,    2, 0x08,   23 /* Private */,
      16,    1,  247,    2, 0x08,   25 /* Private */,
      17,    0,  250,    2, 0x08,   27 /* Private */,
      18,    1,  251,    2, 0x08,   28 /* Private */,
      19,    1,  254,    2, 0x08,   30 /* Private */,
      20,    2,  257,    2, 0x08,   32 /* Private */,
      21,    1,  262,    2, 0x08,   35 /* Private */,
      22,    1,  265,    2, 0x08,   37 /* Private */,
      23,    0,  268,    2, 0x08,   39 /* Private */,
      24,    1,  269,    2, 0x08,   40 /* Private */,
      25,    1,  272,    2, 0x08,   42 /* Private */,
      26,    2,  275,    2, 0x08,   44 /* Private */,
      27,    1,  280,    2, 0x08,   47 /* Private */,
      28,    0,  283,    2, 0x08,   49 /* Private */,
      29,    1,  284,    2, 0x08,   50 /* Private */,
      30,    1,  287,    2, 0x08,   52 /* Private */,
      31,    2,  290,    2, 0x08,   54 /* Private */,
      32,    0,  295,    2, 0x08,   57 /* Private */,
      33,    2,  296,    2, 0x08,   58 /* Private */,
      34,    1,  301,    2, 0x08,   61 /* Private */,
      35,    2,  304,    2, 0x08,   63 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 36, QMetaType::QString,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'RegisterRespondSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PDU *, std::false_type>,
        // method 'LoginRespondSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PDU *, std::false_type>,
        // method 'ShowAllOnlineUsersSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PDU *, std::false_type>,
        // method 'FindUserSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PDU *, std::false_type>,
        // method 'AddFriendSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PDU *, std::false_type>,
        // method 'DelFriendSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PDU *, std::false_type>,
        // method 'ConSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_Register'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_Login'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'recvMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_Show'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_ShowOnlineUsers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_FindUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_AddUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_FlushFriend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_DelFriend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_PrivateChat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_PrivateChatMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_GroupChat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_CreateDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_FlushDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_DelDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_DelFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_Rename'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_EnterDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_ReturnFatherDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_MoveFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_SelectDest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_UploadFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'do_UploadFileData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_DownloadFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_ShareFileConfirm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'do_ShareFileToFriends'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RegisterRespondSignal((*reinterpret_cast< std::add_pointer_t<PDU*>>(_a[1]))); break;
        case 1: _t->LoginRespondSignal((*reinterpret_cast< std::add_pointer_t<PDU*>>(_a[1]))); break;
        case 2: _t->ShowAllOnlineUsersSignal((*reinterpret_cast< std::add_pointer_t<PDU*>>(_a[1]))); break;
        case 3: _t->FindUserSignal((*reinterpret_cast< std::add_pointer_t<PDU*>>(_a[1]))); break;
        case 4: _t->AddFriendSignal((*reinterpret_cast< std::add_pointer_t<PDU*>>(_a[1]))); break;
        case 5: _t->DelFriendSignal((*reinterpret_cast< std::add_pointer_t<PDU*>>(_a[1]))); break;
        case 6: _t->ConSuccess(); break;
        case 7: _t->do_Register((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->do_Login((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->recvMsg(); break;
        case 10: _t->do_Show(); break;
        case 11: _t->do_ShowOnlineUsers(); break;
        case 12: _t->do_FindUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->do_AddUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->do_FlushFriend(); break;
        case 15: _t->do_DelFriend((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->do_PrivateChat((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->do_PrivateChatMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 18: _t->do_GroupChat((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->do_CreateDir((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->do_FlushDir(); break;
        case 21: _t->do_DelDir((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->do_DelFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->do_Rename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->do_EnterDir((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->do_ReturnFatherDir(); break;
        case 26: _t->do_MoveFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->do_SelectDest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->do_UploadFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 29: _t->do_UploadFileData(); break;
        case 30: _t->do_DownloadFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 31: _t->do_ShareFileConfirm((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 32: _t->do_ShareFileToFriends((*reinterpret_cast< std::add_pointer_t<QStringList&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(PDU * );
            if (_t _q_method = &Widget::RegisterRespondSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(PDU * );
            if (_t _q_method = &Widget::LoginRespondSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget::*)(PDU * );
            if (_t _q_method = &Widget::ShowAllOnlineUsersSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Widget::*)(PDU * );
            if (_t _q_method = &Widget::FindUserSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Widget::*)(PDU * );
            if (_t _q_method = &Widget::AddFriendSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Widget::*)(PDU * );
            if (_t _q_method = &Widget::DelFriendSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void Widget::RegisterRespondSignal(PDU * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::LoginRespondSignal(PDU * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget::ShowAllOnlineUsersSignal(PDU * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Widget::FindUserSignal(PDU * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Widget::AddFriendSignal(PDU * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Widget::DelFriendSignal(PDU * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
