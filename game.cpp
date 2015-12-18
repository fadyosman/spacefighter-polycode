#include "game.h"
#include "fireball.h"
#include <iostream>
#include "enemy.h"
#include "explosion.h"
//Main game class.
Game::Game(PolycodeView *view)
{
    core = new POLYCODE_CORE(view, 800,600,false,true,0,0,90, 0, true);
    CoreServices::getInstance()->getResourceManager()->addDirResource("Assets", false);
    scene = new PhysicsScene2D(0.1, 50);
    scene->addEventListener(this, PhysicsScene2DEvent::EVENT_NEW_SHAPE_COLLISION);
    scene->addEventListener(this, PhysicsScene2DEvent::EVENT_END_SHAPE_COLLISION);
    core->getInput()->addEventListener(this,InputEvent::EVENT_KEYDOWN);
    core->getInput()->addEventListener(this,InputEvent::EVENT_KEYUP);
    SceneSprite *bg = new SceneSprite("Assets/bg6.png",1600,1200);
    bg->setActualSpriteSize(1.6,1.2);
    //bg->setPosition(-0.5,0.5);
    scene->addChild(bg);
    //scene->addChild((Entity *)fireball);
    fighter = new Fighter();
    fighter->setPosition(0,-.45);
    fighter->setActualSpriteSize(.1,.1);
    gameOverSprite = new SceneSprite("Assets/gameOver.png",618,618);
    gameOverSprite->setActualSpriteSize(.5,.5);
    scene->addCollisionChild(fighter,PhysicsScene2DEntity::ENTITY_RECT);
    lastEnemyTimer = new Timer(true, 250);
    lastEnemyTimer->addEventListener(this,Timer::EVENT_TRIGGER);
}

bool Game::update() {
    if(dir == 1) {
        fighter->moveLeft();
    }
    if(dir == -1) {
        fighter->moveRight();
    }
    if (fire) {
        fighter->fire(scene);
    }
    return core->updateAndRender();
}

void Game::handleEvent(Event *e) {
    if(e->getDispatcher() == core->getInput()) {
        if(fighter == 0) {
            return;
        }
        InputEvent *inputEvent = (InputEvent*)e;
        switch(e->getEventCode()) {
        case InputEvent::EVENT_KEYDOWN:
            switch (inputEvent->keyCode()) {
            case KEY_LEFT:
                dir = 1;
                break;
            case KEY_RIGHT:
                dir = -1;
                break;
            case KEY_SPACE:
                fire = true;
                break;
            case KEY_ESCAPE:
                core->Shutdown();
            }
            break;
        case InputEvent::EVENT_KEYUP:
            switch (inputEvent->key) {
            case KEY_LEFT:
            case KEY_RIGHT:
                dir = 0;
                break;
            case KEY_SPACE:
                fire=false;
                break;
            default:
                break;
            }
            break;
        }
    }
    if(e->getDispatcher() == scene) {
        PhysicsScene2DEvent *pe = (PhysicsScene2DEvent*)e;
        switch(e->getEventCode()) {
        case PhysicsScene2DEvent::EVENT_NEW_SHAPE_COLLISION:
            //Check colliding type.
            if(pe->entity1->getTagAtIndex(0) == "f") {
                if(pe->entity2->getTagAtIndex(0) == "e"){
                    scene->removePhysicsChild(pe->entity1);
                    this->createExplosion(pe->entity1->getPosition());
                    //delete pe->entity1;
                    fighter = 0;
                    scene->removePhysicsChild(pe->entity2);
                    this->createExplosion(pe->entity2->getPosition());
                    scene->addChild(gameOverSprite);
                 }
            }
            if(pe->entity1->getTagAtIndex(0) == "e") {
                if(pe->entity2->getTagAtIndex(0) == "f"){
                    scene->removePhysicsChild(pe->entity1);
                    this->createExplosion(pe->entity1->getPosition());
                    scene->removePhysicsChild(pe->entity2);
                    this->createExplosion(pe->entity2->getPosition());
                    //delete pe->entity2;
                    fighter = 0;
                    scene->addChild(gameOverSprite);
                 }
            }
            if(pe->entity1->getTagAtIndex(0) == "b") {
                if(pe->entity2->getTagAtIndex(0) == "e"){
                    scene->removePhysicsChild(pe->entity1);
                    scene->removePhysicsChild(pe->entity2);
                    this->createExplosion(pe->entity2->getPosition());
                }
            }
            if(pe->entity1->getTagAtIndex(0) == "e") {
                if(pe->entity2->getTagAtIndex(0) == "b"){
                    scene->removePhysicsChild(pe->entity1);
                    scene->removePhysicsChild(pe->entity2);
                    this->createExplosion(pe->entity2->getPosition());
                }
            }
            break;
        }
    }
    if(e->getDispatcher() == lastEnemyTimer && e->getEventCode() == Timer::EVENT_TRIGGER) {
        Enemy *enemy = new Enemy();
        scene->addCollisionChild(enemy,PhysicsScene2DEntity::ENTITY_RECT);
        Number pos = -0.5 + RANDOM_NUMBER;
        enemy->setPosition(pos,.5);
        enemy->setUserData(scene);
    }
}
void Game::createExplosion(Vector3 pos) {
    Explosion *exp = new Explosion();
    exp->setPosition(pos);
    scene->addChild(exp);
    exp->setUserData(scene);
}

Game::~Game() {

}
