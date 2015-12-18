#include <iostream>
#include "game.h"
#include <PolycodeView.h>
using namespace std;
using namespace  Polycode;
int main()
{
    PolycodeView *view = new PolycodeView("Space Fighter",true);
    Game fighter(view);
    while(fighter.update()) {

    }
    delete view;
    return 0;
}
