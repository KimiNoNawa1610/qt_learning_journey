#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include<controllers/system.h> // import the cpp file

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    System m_systemHandler; // make a system handler object

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

    QQmlContext * context (engine.rootContext()); // get the context of the engine
    context->setContextProperty("systemHandler",&m_systemHandler); // set the context property with the m_systemHanlder

    return app.exec();
}
