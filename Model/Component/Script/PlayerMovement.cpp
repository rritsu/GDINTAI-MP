#include "PlayerMovement.hpp"

using namespace components;

PlayerMovement::PlayerMovement(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 200.0f;
    this->fThreshold = 1.5f;
    this->fInterval = this->fThreshold;
}

void PlayerMovement::perform() {
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    PlayerInput* pPlayerInput = (PlayerInput*)pPlayer->findComponentByName(this->getOwner()->getName() + " Input");
    sf::Sprite* pSprite = pPlayer->getSprite();
    
    if(pPlayerInput == NULL || pSprite == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->fInterval += this->tDeltaTime.asSeconds();

            if(pPlayerInput->getMovingUp() && !pPlayer->getTopBounds() && !pPlayer->getBottomWallCollide()) {
                pSprite->move(0.0f, -1.0f * this->fSpeed * tDeltaTime.asSeconds());
                pPlayer->setFrame(0);
            }

            else if(pPlayerInput->getMovingLeft() && !pPlayer->getLeftBounds() && !pPlayer->getRightWallCollide()){
                pSprite->move(-1.0f * this->fSpeed * tDeltaTime.asSeconds(), 0.0f);
                pPlayer->setFrame(3);
            }

            else if(pPlayerInput->getMovingDown() && !pPlayer->getBottomBounds() && !pPlayer->getTopWallCollide()){
                pSprite->move(0.0f, 1.0f * this->fSpeed * tDeltaTime.asSeconds());
                pPlayer->setFrame(2);
            }

            else if(pPlayerInput->getMovingRight() && !pPlayer->getRightBounds() && !pPlayer->getLeftWallCollide()){
                pSprite->move(1.0f * this->fSpeed * tDeltaTime.asSeconds(), 0.0f);
                pPlayer->setFrame(1);
            }
        
            if(pPlayerInput->getFire()) {
                if(this->fInterval >= this->fThreshold) {
                    pPlayerInput->resetFire();
                    ObjectPoolManager::getInstance()->getPool(PoolTag::PLAYER_BULLET)->requestPoolable();
                    this->fInterval = 0.0f;
                }
                
            }

    }   
}
