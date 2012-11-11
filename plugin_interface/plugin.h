#ifndef PLUGIN_H
#define PLUGIN_H

#include <XPLMUtilities.h>
#include <string>

using namespace std;

/**
  @brief An abstract base class for an X-plane plugin

  To create a plugin, you can create a class that inherits this one.
  */
class Plugin
{
public:

    /**
      Plugin base class constructor

      Subclasses should override this to set up their stuff
      */
    Plugin();


    /**
      Get the plugin's name
      */
    string getName() {
        return name;
    }

    /**
      Get the plugin's signature, like org.samcrow.plugin_name
      */
    string getSignature() {
        return signature;
    }

    /**
      Get this plugin's description
      */
    string getDescription() {
        return description;
    }

    /*
       Events that a plugin can receive.
       These are all virtual.
       A plugin that wants to use an event should override its corresponding method.
      */

    /**
      onStop event: Called when the plugin system is about to terminate this plugin.
      Plugins should use this to deallocate their resources. The plugin will be
      deleted after this event completes.
      */
    virtual void onStop();

    /**
      onDisable event: Called when the plugin system is about to disable this plugin
      */
    virtual void onDisable();

    /**
      onEnable event: Called when the plugin system wants to enable this plugin.
      This will be called once after the plugin is created and later if the user manually
      disables and then enables the plugin.
      @return Plugin implementations should return 1 to indicate that the plugin can
      be enabled at this time, otherwise 0.
      */
    virtual int onEnable();

    /**
      onMessageReceived event: Called when this plugin receives a message from another
      plugin. See the documentation on the XPluginReceiveMessage function for more information.
      */
    virtual void onMessageReceived(XPLMPluginID sender, long message, void * data);

protected:


    /**
      Write some text to the log.txt file
      @param message The text to write. A newline will automatically be appended.
      */
    void debug(string message);

    /**
      The name of this plugin. This is sent to X-plane to display in the plugin admin.

      Individual plugins should set this value in their constructors.
      */
    string name;

    /**
      The signature of this plugin (like org.samcrow.plugin_name). This is sent to X-plane to display in the plugin admin.

      Individual plugins should set this value in their constructors.
      */
    string signature;

    /**
      The description of this plugin. This is sent to X-plane to display in the plugin admin.

      Individual plugins should set this value in their constructors.
      */
    string description;

private:

};

#endif // PLUGIN_H
