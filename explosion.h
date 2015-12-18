#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <PolySceneSprite.h>
#include <PolyTimer.h>
using namespace Polycode;
class Explosion : public SceneSprite
{
public:
    Explosion(const String fileName = "Assets/explosion.png", int width = 64, int height = 64);
    void Update();
private:
    Timer *animationFinished;
};

#endif // EXPLOSION_H
