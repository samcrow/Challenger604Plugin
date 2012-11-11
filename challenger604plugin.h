#ifndef CHALLENGER604PLUGIN_H
#define CHALLENGER604PLUGIN_H

#include "plugin_interface/plugin.h"

#include <messagewindow.h>

using namespace PPL;

/**
  The main class for the Challenger 604 plugin
  */
class Challenger604Plugin : public Plugin
{
public:
    Challenger604Plugin();

    void onStop();
    int onEnable();

private:

};

#endif // CHALLENGER604PLUGIN_H
