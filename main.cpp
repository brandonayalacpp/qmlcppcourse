#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include <message.h>


void TestInvoke(QObject* rootObject)
{
    QVariant return_value;
    QVariant msg = "this is a c++ parameter ";
    QMetaObject::invokeMethod(rootObject,
                              "javaScriptFunction",
                               Q_RETURN_ARG(QVariant, return_value),
                              Q_ARG(QVariant, msg));

    qDebug() << "some value: " << return_value;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Message message;
    auto root_context = engine.rootContext();
    root_context->setContextProperty("MessageClass", &message);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto root_object = engine.rootObjects().first();
    TestInvoke(root_object);
    return app.exec();
}
