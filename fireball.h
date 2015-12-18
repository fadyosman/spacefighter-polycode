#ifndef FIREBALLS_H
#define FIREBALLS_H
#include <PolySceneSprite.h>
#include <Polycode2DPhysics.h>
using namespace Polycode;

class FireBall : public SceneSprite
{
public:
    FireBall(const String fileName = "Assets/fireball.png", int width = 64, int height = 64);
    //Remove itself if it's out of the screen.
    void Update();
private:
    Number speed;
};

#endif // FIREBALLS_H
