#include "fighter.h"
#include "fireball.h"
Fighter::Fighter(const String fileName, int width, int height):SceneSprite(fileName,width,height)
{
    this->addAnimation("idle","1,2,3,4",0.04);
    this->playAnimation("idle",0,false);
    this->moveSpeed = .5;
    lastFireTimer = new Timer(false,50);
    this->addTag("f");
}

void Fighter::moveLeft() {
    if(this->getPosition().x >= -.6) {
        CoreServices *coreServices = CoreServices::getInstance();
        Number elapsed = coreServices->getCore()->getElapsed();
        this->Translate(-moveSpeed *elapsed,0);
    }
}
void Fighter::moveRight() {
    if(this->getPosition().x <= .6) {
        CoreServices *coreServices = CoreServices::getInstance();
        Number elapsed = coreServices->getCore()->getElapsed();
        this->Translate(moveSpeed *elapsed,0);
    }
}
void Fighter::fire(PhysicsScene2D *scene) {
    //Add the fire to the scene don't worry about deletion.
    if (lastFireTimer->getElapsedf() > .2) {
        FireBall *fireball = new FireBall();
        fireball->setPosition(this->getPosition() + Vector3(0,.05,0));
        fireball->setUserData(scene);
        scene->addCollisionChild(fireball,PhysicsScene2DEntity::ENTITY_CAPSULE);
        lastFireTimer->Reset();
    }
}
