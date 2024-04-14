#include "BoundManager.hpp"

using namespace managers;

void BoundManager::registerBound(Bound* pBound) {
    this->mapBounds[pBound->getBoundType()] == pBound;
    this->vecBounds.push_back(pBound);
}

bool BoundManager::checkIfRegistered(GameObject* pBound) {
    bool bCheck = false;
    for(Bound* pBoundTemp : this->vecBounds) {
        if(pBoundTemp == pBound)
            bCheck = true;
    }
    return bCheck;
}

void BoundManager::deleteAllBounds() {
    this->vecBounds.clear();
    this->mapBounds.clear();
}

int BoundManager::getTotalBounds() {
    return this->vecBounds.size();
}



//SINGLETON-RELATED CONTENT      
BoundManager* BoundManager::P_SHARED_INSTANCE = NULL;
BoundManager::BoundManager() {}
BoundManager::BoundManager(const BoundManager&) {}

BoundManager* BoundManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new BoundManager();
    }
    return P_SHARED_INSTANCE;
}