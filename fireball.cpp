#include "fireball.h"
#include <iostream>
FireBall::FireBall(const String fileName, int width, int height):SceneSprite(fileName,width,height)
{
    //Create animations from from 16 --> 23.
    this->setActualSpriteSize(.1,.1);
    this->addAnimation("firevertical","16,17,18,19,20,21,22,23",0.04);
    this->playAnimation("firevertical",16,false);
    this->speed = .4;
    this->addTag("b");
}
void FireBall::Update() {
    CoreServices *coreServices = CoreServices::getInstance();
    Number elapsed = coreServices->getCore()->getElapsed();
    this->Translate(0,speed*elapsed);
    SceneSprite::Update();
    //delete when fireball off of the screen.
    if(this->getPosition().y >= .5) {
        PhysicsScene2D *scene = (PhysicsScene2D *)this->getUserData();
        scene->removePhysicsChild(this);
        delete this;
    }
}
