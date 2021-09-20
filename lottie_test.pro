debug: TARGET = lottie_testd
release: TARGET = lottie_test

QT     += core dbus qml quick multimedia
CONFIG += sailfishapp c++11

DESTDIR = $$PWD/build

LIBS += \
    -L$$DESTDIR$$ \
#    -lrlottie
    -lQt5Bodymovin

SOURCES += \
    VideoSource/ImageVideoBuffer.cpp \
#    VideoSource/VideoSource.cpp \
#    VideoSource/VideoSource_plugin.cpp \
    src/FPSItem.cpp \
    src/main.cpp


HEADERS += \
    VideoSource/ImageVideoBuffer.h \
#    VideoSource/VideoSource.h \
#    VideoSource/VideoSource_plugin.h \
    src/FPSItem.h


OTHER_FILES += \
    qml/Main.qml

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172 256x256

DISTFILES += \
    VideoSource/qmldir \
    qml/FirstPage.qml \
    qml/LottieImage.qml \
    qml/SecondPage.qml
