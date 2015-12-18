#ifndef ENEMY_H
#define ENEMY_H
#include <PolySceneSprite.h>
#include <Polycode2DPhysics.h>
using namespace Polycode;
class Enemy: public SceneSprite
{
public:
    Enemy(const String fileName = "Assets/ufo.png", int width = 64, int height = 64);
    void Update();
private:
    Number speed;
};

#endif // ENEMY_H
