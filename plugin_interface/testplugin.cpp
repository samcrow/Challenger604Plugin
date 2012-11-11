#include "testplugin.h"

TestPlugin::TestPlugin()
{
    name = "Test plugin";
    signature = "org.samcrow.test_plugin";
    description = "Test plugin for testing";
    debug("Test plugin starting.");
}
