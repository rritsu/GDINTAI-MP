#include "Tile.hpp"

using namespace entities;

Tile::Tile(std::string strName, AnimatedTexture* pTexture, int nFrame) : GameObject(strName, pTexture) {
    this->nFrame = nFrame;
}

void Tile::initialize() {
  //  if(this->nFrame == 4) 
     //   this->nFrame = 1;
    this->setFrame(this->nFrame);
    this->pSprite->setScale(sf::Vector2f(3.0, 3.0f));

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}


void Tile::onCollisionEnter(GameObject* pGameObject) {}

void Tile::onCollisionExit(GameObject* pGameObject) {}