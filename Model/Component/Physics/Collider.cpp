#include "Collider.hpp"

using namespace components;

Collider::Collider(std::string strName) : Component(strName, ComponentType::PHYSICS) {
    this->pListener = NULL;
    this->COffset = {0.0f, 0.0f, 0.0f, 0.0f};
    this->vecCollided = {};
    this->bCleanUp = false;

}


void Collider::perform() {}


bool Collider::isColliding(Collider* pCollider) {
    sf::FloatRect CBoundsA = this->getGlobalBounds();
    sf::FloatRect CBoundsB = pCollider->getGlobalBounds();

    return CBoundsA.intersects(CBoundsB);
}


bool Collider::hasCollided(Collider* pCollider) {
    if(this->findCollider(pCollider) != - 1) {
        return true;
    }
    return false;
}


void Collider::setCollided(Collider* pCollider, bool bCollided) {
    if(bCollided) {
        this->vecCollided.push_back(pCollider);
    }
    else {
        int nIndex = this->findCollider(pCollider);
        
        if(nIndex != - 1)
            this->vecCollided.erase(this->vecCollided.begin() + nIndex); 
    }


}


int Collider::findCollider(Collider* pCollider) {
    int nIndex = -1;

    for(int i = 0; i < vecCollided.size() && nIndex == -1; i++) {
        if(this->vecCollided[i] == pCollider)
            nIndex = i;
    }

    return nIndex;
}


void Collider::cleanCollisions() {
    this->vecCollided.clear();
}


void Collider::onCollisionEnter(Collider* pCollider) {
    if(this->pListener != NULL) {
        this->pListener->onCollisionEnter(pCollider->getOwner());
    }
}


void Collider::onCollisionExit(Collider* pCollider) {
    if(this->pListener != NULL) {
        this->pListener->onCollisionExit(pCollider->getOwner());
    }
}


void Collider::assignListener(CollisionListener* pListener) {
    this->pListener = pListener;
}


void Collider::setOffset(sf::FloatRect COffset) {

}


bool Collider::getCleanUp() {
    return this->bCleanUp;
}


void Collider::setCleanUp(bool bCleanUp) {
    this->bCleanUp = bCleanUp;
}


sf::FloatRect Collider::getGlobalBounds() {
    sf::FloatRect CBounds = this->getOwner()->getGlobalBounds();

    CBounds.left = CBounds.left + this->COffset.left;
    CBounds.top = CBounds.top + this->COffset.top;
    CBounds.width = CBounds.width + this->COffset.width;
    CBounds.height = CBounds.height + this->COffset.height;
    return CBounds;
}
