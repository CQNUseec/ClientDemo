#ifndef GRTPLUGINMGR_H
#define GRTPLUGINMGR_H
#include <map>
#include <vector>
#include <string>
#if defined(GRTPLUGINMGR_LIBRARY)
#  define GRTPLUGINMGRSHARED_EXPORT __declspec(dllexport)
#else
#  define GRTPLUGINMGRSHARED_EXPORT __declspec(dllimport)
#endif
struct PluginConfigInfo
{
    int             index;
    std::string     iconFilePath;
    std::string     qmlFilePath;
    std::string     PluginFilePath;
};
class QPluginLoader;
class GRTPLUGINMGRSHARED_EXPORT GRTPluginMgr
{

public:
    GRTPluginMgr();
    ~GRTPluginMgr();
    int loadPlugin(std::string filePath);
    int scanThePluginDirectory(std::vector<PluginConfigInfo> &pluginInfos);
private:
    std::map<std::string, QPluginLoader*>   m_plugins;
};

#endif // GRTPLUGINMGR_H
