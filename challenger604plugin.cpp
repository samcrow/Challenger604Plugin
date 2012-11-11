#include "challenger604plugin.h"

using namespace PPL;

Challenger604Plugin::Challenger604Plugin()
{
    //Init
    name = "Challenger 604 Systems";
    signature = "org.samcrow.challenger604";
    description = "Challenger 604 systems simulation plugin";

    debug("Challenger 604 systems plugin starting up");



}

int Challenger604Plugin::onEnable() {

    MessageWindow * window = new MessageWindow(300, 200, "Ponies!", "Twilight Sparkle is the best pony!", false);
    window->display();

    return 1;
}

void Challenger604Plugin::onStop() {

}
