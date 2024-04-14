#include "Bound.hpp"

using namespace entities;

Bound::Bound(std::string strName, BoundType EType, sf::FloatRect CBounds) : GameObject(strName, NULL) {
    this->CBounds = CBounds;
    this->EType = EType;
}

void Bound::initialize() {
    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}

void Bound::onCollisionEnter(GameObject* pGameObject) {}

void Bound::onCollisionExit(GameObject* pGameObject) {}

sf::FloatRect Bound::getGlobalBounds() {
    return this->CBounds;
}

BoundType Bound::getBoundType() {
    return this->EType;
}