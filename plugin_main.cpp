#include <stdio.h>
#include <string.h>
#include <XPLMUtilities.h>
#include <XPLMDataAccess.h>

#include "challenger604plugin.h"

/**
  The plugin.
  */
static Plugin * plugin;


PLUGIN_API int XPluginStart(
                        char *		outName,
                        char *		outSig,
                        char *		outDesc)
{
    //Init the plugin
    plugin = new Challenger604Plugin();

    //Get the plugin's information
    strcpy(outName, plugin->getName().c_str());
    strcpy(outSig, plugin->getSignature().c_str());
    strcpy(outDesc, plugin->getDescription().c_str());

    return 1;
}

PLUGIN_API void	XPluginStop(void)
{
    plugin->onStop();
    delete plugin;
}


PLUGIN_API void XPluginDisable(void)
{
    plugin->onDisable();
}

PLUGIN_API int XPluginEnable(void)
{
    return plugin->onEnable();
}

PLUGIN_API void XPluginReceiveMessage(
                    XPLMPluginID	inFromWho,
                    long			inMessage,
                    void *			inParam)
{
    plugin->onMessageReceived(inFromWho, inMessage, inParam);
}

