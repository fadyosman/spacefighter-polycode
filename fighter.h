#ifndef FIGHTER_H
#define FIGHTER_H
#include <PolySceneSprite.h>
#include <Polycode2DPhysics.h>
#include <PolyTimer.h>
#include "fireball.h"
using namespace Polycode;
class Fighter : public SceneSprite
{
public:
    Fighter(const String fileName = "Assets/fighter.png", int width=159, int height=117);
    void moveLeft();
    void moveRight();
    void fire(PhysicsScene2D *scene);
private:
    Number moveSpeed;
    Timer *lastFireTimer;
};

#endif // FIGHTER_H
