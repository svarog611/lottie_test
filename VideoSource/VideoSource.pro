TARGET = VideoSource
include($$PWD/../NgiPlugin.pri)

QT += qml quick multimedia

uri = NgiPlugin

DEPENDPATH += \
    $$INCLUDEPATH

SOURCES += \
    VideoSource.cpp \
    VideoSource_plugin.cpp \
    ImageVideoBuffer.cpp \

HEADERS += \
    VideoSource.h \
    VideoSource_plugin.h \
    ImageVideoBuffer.h \

DISTFILES = qmldir
