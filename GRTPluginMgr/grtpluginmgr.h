#ifndef GRTPLUGINMGR_H
#define GRTPLUGINMGR_H

#if defined(GRTPLUGINMGR_LIBRARY)
#  define GRTPLUGINMGRSHARED_EXPORT __declspec(dllexport)
#else
#  define GRTPLUGINMGRSHARED_EXPORT __declspec(dllimport)
#endif

class GRTPLUGINMGRSHARED_EXPORT GRTPluginMgr
{

public:
    GRTPluginMgr();
};

#endif // GRTPLUGINMGR_H
