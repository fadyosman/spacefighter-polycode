#include "enemy.h"

Enemy::Enemy(const String fileName, int width, int height) : SceneSprite(fileName,width,height)
{
    this->setActualSpriteSize(.09,.09);
    this->addAnimation("ufo","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14",0.04);
    this->playAnimation("ufo",0,false);
    this->speed = .4;
    this->addTag("e");
}
void Enemy::Update() {
    CoreServices *coreServices = CoreServices::getInstance();
    Number elapsed = coreServices->getCore()->getElapsed();
    this->Translate(0,-speed*elapsed);
    SceneSprite::Update();
    //delete when fireball off of the screen.
    if(this->getPosition().y <= -.5) {
        PhysicsScene2D *scene = (PhysicsScene2D *)this->getUserData();
        scene->removePhysicsChild(this);
        delete this;
    }
}
