/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Final System/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[549];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "process_frame"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 34, 20), // "b4_tweak_input_image"
QT_MOC_LITERAL(5, 55, 9), // "runCamera"
QT_MOC_LITERAL(6, 65, 8), // "runImage"
QT_MOC_LITERAL(7, 74, 8), // "runVideo"
QT_MOC_LITERAL(8, 83, 18), // "on_Capture_clicked"
QT_MOC_LITERAL(9, 102, 18), // "on_No_Mode_clicked"
QT_MOC_LITERAL(10, 121, 25), // "on_Hole_Detection_clicked"
QT_MOC_LITERAL(11, 147, 27), // "on_Growth_detection_clicked"
QT_MOC_LITERAL(12, 175, 41), // "on_Dilation_horizontalSlider_..."
QT_MOC_LITERAL(13, 217, 5), // "value"
QT_MOC_LITERAL(14, 223, 41), // "on_Gaussian_horizontalSlider_..."
QT_MOC_LITERAL(15, 265, 39), // "on_Capture_clean_net_pushButt..."
QT_MOC_LITERAL(16, 305, 36), // "on_Webcam_source_radioButton_..."
QT_MOC_LITERAL(17, 342, 35), // "on_Image_source_radioButton_c..."
QT_MOC_LITERAL(18, 378, 35), // "on_Video_source_radioButton_c..."
QT_MOC_LITERAL(19, 414, 24), // "on_actionPause_triggered"
QT_MOC_LITERAL(20, 439, 31), // "on_actionDont_Process_triggered"
QT_MOC_LITERAL(21, 471, 13), // "display_frame"
QT_MOC_LITERAL(22, 485, 11), // "input_image"
QT_MOC_LITERAL(23, 497, 15), // "processed_image"
QT_MOC_LITERAL(24, 513, 15), // "segmented_image"
QT_MOC_LITERAL(25, 529, 19) // "hole_detected_image"

    },
    "MainWindow\0process_frame\0\0cv::Mat\0"
    "b4_tweak_input_image\0runCamera\0runImage\0"
    "runVideo\0on_Capture_clicked\0"
    "on_No_Mode_clicked\0on_Hole_Detection_clicked\0"
    "on_Growth_detection_clicked\0"
    "on_Dilation_horizontalSlider_valueChanged\0"
    "value\0on_Gaussian_horizontalSlider_valueChanged\0"
    "on_Capture_clean_net_pushButton_clicked\0"
    "on_Webcam_source_radioButton_clicked\0"
    "on_Image_source_radioButton_clicked\0"
    "on_Video_source_radioButton_clicked\0"
    "on_actionPause_triggered\0"
    "on_actionDont_Process_triggered\0"
    "display_frame\0input_image\0processed_image\0"
    "segmented_image\0hole_detected_image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x0a /* Public */,
       5,    0,  102,    2, 0x0a /* Public */,
       6,    0,  103,    2, 0x0a /* Public */,
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    1,  109,    2, 0x08 /* Private */,
      14,    1,  112,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,
      20,    0,  120,    2, 0x08 /* Private */,
      21,    4,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,   22,   23,   24,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->process_frame((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->runCamera(); break;
        case 2: _t->runImage(); break;
        case 3: _t->runVideo(); break;
        case 4: _t->on_Capture_clicked(); break;
        case 5: _t->on_No_Mode_clicked(); break;
        case 6: _t->on_Hole_Detection_clicked(); break;
        case 7: _t->on_Growth_detection_clicked(); break;
        case 8: _t->on_Dilation_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_Gaussian_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_Capture_clean_net_pushButton_clicked(); break;
        case 11: _t->on_Webcam_source_radioButton_clicked(); break;
        case 12: _t->on_Image_source_radioButton_clicked(); break;
        case 13: _t->on_Video_source_radioButton_clicked(); break;
        case 14: _t->on_actionPause_triggered(); break;
        case 15: _t->on_actionDont_Process_triggered(); break;
        case 16: _t->display_frame((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< cv::Mat(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
