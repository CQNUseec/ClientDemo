#include "grtpluginmgr.h"
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <iostream>

GRTPluginMgr::GRTPluginMgr()
{
    std::vector<PluginConfigInfo> pluginInfos;
    scanThePluginDirectory(pluginInfos);
}

GRTPluginMgr::~GRTPluginMgr()
{

}

int GRTPluginMgr::scanThePluginDirectory(std::vector<PluginConfigInfo> &pluginInfos)
{
    auto pluginParentPath = QDir::currentPath();
    pluginParentPath += "/plugins";
    QDir pluginParentDir(pluginParentPath);
    pluginParentDir.setFilter(QDir::Dirs);
    auto fileList = pluginParentDir.entryList();
    for(auto pluginName : fileList)
    {
        if(pluginName != "." && pluginName != "..")
        {
            qDebug() << "插件" << pluginName;
            QString pluginPath = pluginParentPath + "/" + pluginName;
            QDir pluginDir(pluginPath);
            auto plugFileList = pluginDir.entryInfoList();
            PluginConfigInfo pluginInfo;
            for(auto var : plugFileList)
            {
                if(var.isFile())
                {
                    if(var.baseName() == pluginName && var.completeSuffix() == "jpg")
                    {
                        pluginInfo.iconFilePath = var.canonicalFilePath().toStdString();
                    }
                    else if(var.baseName() == pluginName && var.completeSuffix() == "dll")
                    {
                        pluginInfo.PluginFilePath = var.canonicalFilePath().toStdString();
                    }
                    else if(var.baseName() == pluginName && var.completeSuffix() == "qml")
                    {
                        pluginInfo.qmlFilePath = var.canonicalFilePath().toStdString();
                    }
                }
            }
            std::cout << pluginInfo.PluginFilePath << " " << pluginInfo.qmlFilePath << " " << pluginInfo.iconFilePath << " " << std::endl;
        }
    }
    return 1;
}
