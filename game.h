#ifndef SPACEFIGHTER_H
#define SPACEFIGHTER_H
#include <Polycode.h>
#include <PolycodeView.h>
#include <Polycode2DPhysics.h>
#include <PolySceneSprite.h>
#include "fighter.h"
using namespace  Polycode;
class Game : EventHandler
{
public:
    Game(PolycodeView *view);
    ~Game();
    bool update();
    void handleEvent(Event *e);
private:
    Core *core;
    PhysicsScene2D *scene;
    Fighter *fighter;
    Timer *lastEnemyTimer;
    SceneSprite *gameOverSprite;
    int dir;
    bool fire;
    void createExplosion(Vector3 pos);
};

#endif // SPACEFIGHTER_H
