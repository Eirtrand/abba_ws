#-------------------------------------------------
#
# Project created by QtCreator 2013-03-01T10:10:05
#
#-------------------------------------------------

QT       += core gui\



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_System2
TEMPLATE = app

pkg-config opencv --cflags --libs
        mainwindow.cpp \
    segmentation_techniques.cpp \
    histogram_segmentation.cpp \
    hole_detection.cpp \
    growth_detection.cpp \
    colorspaces.cpp \
    tweaking.cpp \
    image_enhancement.cpp

HEADERS  += mainwindow.h \
    segmentation_techniques.h \
    histogram_segmentation.h \
    hole_detection.h \
    growth_detection.h \
    colorspaces.h \
    tweaking.h \
    image_enhancement.h

FORMS    += mainwindow.ui

INCLUDEPATH += ~/OpenCV/opencv-3.2.0/include/opencv
                ~/OpenCV/opencv-3.2.0/include/opencv2
                ~/OpenCV/opencv-3.2.0/include/





LIBS += `pkg-config --libs opencv`
INCLUDEPATH += "/usr/local/include/"