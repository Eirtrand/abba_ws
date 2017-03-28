#-------------------------------------------------
#
# Project created by QtCreator 2011-04-16T10:27:39
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = features
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += /Users/xa4a/merc/diploma/asift/ASIFT_png/libasift.dylib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_features2d \
    -lopencv_calib3d \
    -lopencv_flann

INCLUDEPATH = /Users/xa4a/merc/diploma/asift/ASIFT_png

SOURCES += main.cpp \
    settings.cpp \
    detector_matcher.cpp \
    asift.cpp \
    common.cpp \
    asift_opencv.cpp

OTHER_FILES += \
    features.pro.user

HEADERS += \
    settings.h \
    detector_matcher.h \
    asift.h \
    common.h \
    asift_opencv.h

INCLUDEPATH += ~/OpenCV/opencv-3.2.0/include/opencv
                ~/OpenCV/opencv-3.2.0/include/opencv2
                ~/OpenCV/opencv-3.2.0/include/
