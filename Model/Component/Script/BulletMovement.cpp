#include "BulletMovement.hpp"

using namespace components;

BulletMovement::BulletMovement(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 0.001f;
    this->fTicks = 0.0f;
    this->fSpeed = 300.0f;
    this->fX = 0.0f;
    this->fY = 0.0f;
    this->fPosX = 0.0f;
    this->fPosY = 0.0f;
}

void BulletMovement::perform() {
    PoolableObject* pPoolableOwner = (PoolableObject*)this->pOwner;
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    PlayerInput* pPlayerInput = (PlayerInput*)pPlayer->findComponentByName(pPlayer->getName() + " Input");
    PlayerBullet* pOwner = (PlayerBullet*)this->pOwner;

    this->fPosX = pOwner->getSprite()->getPosition().x;
    this->fPosY = pOwner->getSprite()->getPosition().y;


    if(pPoolableOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->fTicks += this->tDeltaTime.asSeconds();
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

        if(this->fTicks > this->fFrameInterval) {
            this->fTicks = 0.0f;


            if(pPlayer->getFrameNumber() == 0 && !pOwner->getHoldPositioN()) {
                this->fX = 0.0f;
                this->fY = -fOffset;
                pOwner->setHoldPosition(true);
            }

            else if(pPlayer->getFrameNumber() == 1 && !pOwner->getHoldPositioN()) {
                this->fX = fOffset;
                this->fY = 0.0f;
                pOwner->setHoldPosition(true);
            }

            else if(pPlayer->getFrameNumber() == 2 && !pOwner->getHoldPositioN()) {
                this->fX = 0.0f;
                this->fY = fOffset;
                pOwner->setHoldPosition(true);
            }

            else if(pPlayer->getFrameNumber() == 3 && !pOwner->getHoldPositioN()) {
                this->fX = -fOffset;
                this->fY = 0.0f;
                pOwner->setHoldPosition(true);
            } 

            pOwner->getSprite()->move(this->fX,  this->fY);
        }
    }
}