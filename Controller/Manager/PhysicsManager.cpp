#include "PhysicsManager.hpp"
using namespace managers;


void PhysicsManager::perform() {
    for(int i = 0; i < this->vecTrackedColliders.size(); i++) {
        Collider* pColliderA = this->vecTrackedColliders[i];

        for(int j = i + 1; j < this->vecTrackedColliders.size(); j++) {
            Collider* pColliderB = this->vecTrackedColliders[j];

            if(pColliderA != pColliderB) {
                if(pColliderA->isColliding(pColliderB) && !pColliderA->hasCollided(pColliderB) && !pColliderB->hasCollided(pColliderA)) {
                    pColliderA->setCollided(pColliderB, true);
                    pColliderB->setCollided(pColliderA, true);

                    pColliderA->onCollisionEnter(pColliderB);
                    pColliderB->onCollisionEnter(pColliderA);

                 //   std::cout << "collide enter" << std::endl;
                }

                else if(!pColliderA->isColliding(pColliderB) && pColliderA->hasCollided(pColliderB) && pColliderB->hasCollided(pColliderA)) {
                    pColliderA->setCollided(pColliderB, false);
                    pColliderB->setCollided(pColliderA, false);

                    pColliderA->onCollisionExit(pColliderB);
                    pColliderB->onCollisionExit(pColliderA);

                 //   std::cout << "collide exit" << std::endl;
                }
            }  
        }
    }
 
    this->cleanUp();
}




void PhysicsManager::trackCollider(Collider* pCollider) {
    pCollider->cleanCollisions();
    this->vecTrackedColliders.push_back(pCollider);
}


void PhysicsManager::untrackCollider(Collider* pCollider) {
    this->vecUntrackedColliders.push_back(pCollider);
}


void PhysicsManager::cleanUp() {
    Collider* pCollider = NULL;
    int nIndex = -1;

    for(Collider* pCollider : this->vecTrackedColliders) {
        if(pCollider->getCleanUp())
            this->vecUntrackedColliders.push_back(pCollider);
    }

    for(int i = 0; i < this->vecUntrackedColliders.size(); i++) {
        pCollider = this->vecUntrackedColliders[i];
        nIndex = findTrackedCollider(pCollider);

        if(nIndex != -1) 
            this->vecTrackedColliders.erase(this->vecTrackedColliders.begin() + nIndex);
    }

    this->vecUntrackedColliders.clear();
}


int PhysicsManager::findTrackedCollider(Collider* pCollider) {
    int nIndex = -1;

    for(int i = 0; i < this->vecTrackedColliders.size() && nIndex == -1; i++) {
        if(pCollider == this->vecTrackedColliders[i])
            nIndex = i;
    }

    return nIndex;
}

void PhysicsManager::deleteTrackedColliders() {
    std::vector<Collider*> vecColliders = this->vecTrackedColliders;

    for(int i = 0; i < vecColliders.size(); i++) {
        delete this->vecTrackedColliders[i];
    }

    this->vecTrackedColliders.clear();
    this->vecUntrackedColliders.clear();
}
    
int PhysicsManager::getTotalTracked() {
    return this->vecTrackedColliders.size();
}



//SINGLETON-RELATED CONTENT      
PhysicsManager* PhysicsManager::P_SHARED_INSTANCE = NULL;

PhysicsManager::PhysicsManager(std::string strName) : Component(strName, ComponentType::SCRIPT){}
PhysicsManager::PhysicsManager(const PhysicsManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

PhysicsManager* PhysicsManager::getInstance(){
    return P_SHARED_INSTANCE;
}

void PhysicsManager::initialize(std::string strName, GameObject* pHolder) {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new PhysicsManager(strName);
        pHolder->attachComponent(P_SHARED_INSTANCE);
    }
}

void PhysicsManager::destroy() {
    delete P_SHARED_INSTANCE;
}