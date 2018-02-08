#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "../GRTPluginMgr/grtpluginmgr.h"
#include <iostream>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    GRTPluginMgr mgr;
    std::vector<PluginConfigInfo>  pluginInfos;
    mgr.scanThePluginDirectory(pluginInfos);
    std::cout << pluginInfos.size() << std::endl;
    for(auto var : pluginInfos)
    {
        std::cout << var.PluginFilePath << " " << var.qmlFilePath << " " << var.iconFilePath << " " << std::endl;
    }
    return app.exec();
}
