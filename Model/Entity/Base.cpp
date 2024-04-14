#include "Base.hpp"

using namespace entities;

Base::Base(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->bDestroyed = false;
}

void Base::initialize() {
    this->setFrame(0);
    this->pSprite->setScale(3.0f, 3.0f);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);

}

void Base::onCollisionEnter(GameObject* pGameObject) {}

void Base::onCollisionExit(GameObject* pGameObject) {}

bool Base::getDestroyed() {
    return this->bDestroyed;
}

void Base::setDestroyed(bool bDestroyed) {
    this->bDestroyed = bDestroyed;
}

