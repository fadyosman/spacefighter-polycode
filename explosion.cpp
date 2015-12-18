#include "explosion.h"

Explosion::Explosion(const String fileName, int width, int height):SceneSprite(fileName,width,height)
{
    this->addAnimation("idle","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15",0.04);
    this->playAnimation("idle",0,false);
    this->setActualSpriteSize(.1,.1);
    //The .64 is calculated by multiplying number of frames with the 0.04 which is time per frame.
    animationFinished = new Timer(false,.64);
    this->addTag("f");
}
void Explosion::Update() {
    if(animationFinished->getElapsedf() < .64) {
        SceneSprite::Update();
    } else {
        //Remove the
        this->parentEntity->removeChild(this);
        delete this;
    }
}
