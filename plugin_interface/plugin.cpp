#include "plugin.h"

Plugin::Plugin() :
    name("Test"),
    signature("org.samcrow.test"),
    description("Testing is great!")
{
}

void Plugin::debug(string message) {
    message.append("\n");

    XPLMDebugString(message.c_str());
}

void Plugin::onStop() {

}

void Plugin::onDisable() {

}

int Plugin::onEnable() {
    //Return 1 to indicate that the plugin can be enabled
    return 1;
}

void Plugin::onMessageReceived(XPLMPluginID /*sender*/, long /*message*/, void * /*data*/) {

}
