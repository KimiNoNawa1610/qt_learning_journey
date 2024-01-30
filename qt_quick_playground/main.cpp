#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controllers/system.h" // import the cpp file
#include "test.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);

    //test class for connect qml and cpp
    test m_test;

    System * m_systemHandler = new System(); // make a system handler object

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    engine.rootContext()->setContextProperty("test",&m_test);
    engine.rootContext()->setContextProperty("systemHandler",m_systemHandler); // set the context property with the m_systemHanlder

    return app.exec();
}
