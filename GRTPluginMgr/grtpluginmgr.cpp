#include "grtpluginmgr.h"
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <iostream>

GRTPluginMgr::GRTPluginMgr()
{
//    std::vector<PluginConfigInfo> pluginInfos;
//    scanThePluginDirectory(pluginInfos);
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
            std::cout << "plugin: " << pluginName.toStdString() << std::endl;
            QString pluginPath = pluginParentPath + "/" + pluginName;
            QDir pluginDir(pluginPath);
            auto plugFileList = pluginDir.entryInfoList();
            PluginConfigInfo pluginInfo;
            bool hasInfo = false;
            for(auto var : plugFileList)
            {
                if(var.isFile())
                {
                    if(var.baseName() == pluginName && var.completeSuffix() == "jpg")
                    {
                        pluginInfo.iconFilePath = var.canonicalFilePath().toStdString();
                        hasInfo = true;
                    }
                    else if(var.baseName() == pluginName && var.completeSuffix() == "dll")
                    {
                        pluginInfo.PluginFilePath = var.canonicalFilePath().toStdString();
                        hasInfo = true;
                    }
                    else if(var.baseName() == pluginName && var.completeSuffix() == "qml")
                    {
                        pluginInfo.qmlFilePath = var.canonicalFilePath().toStdString();
                        hasInfo = true;
                    }
                }
            }
            if(hasInfo)
            {
                std::cout << pluginInfo.PluginFilePath << " " << pluginInfo.qmlFilePath << " " << pluginInfo.iconFilePath << " " << std::endl;
                pluginInfos.push_back(pluginInfo);
            }
        }
    }
    return 1;
}
