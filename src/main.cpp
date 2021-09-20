#include <sailfishapp.h>

#include <QGuiApplication>
#include <QQuickView>
#include <QTranslator>
#include <QDir>

#include "FPSItem.h"
#include "VideoSource/VideoSource.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<FPSItem>("FPSItem", 1, 0, "FPSItem");
//    qmlRegisterType<VideoSource>("VideoSource", 1, 0, "VideoSource");

    QSharedPointer<QQuickView> view(new QQuickView(QUrl("qml/Main.qml")));
    view->showFullScreen();

    return app.exec();
}
