#include "EnemyBehavior.hpp"

using namespace components;

EnemyBehavior::EnemyBehavior(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 200.0f;
    this->vecTargetBases = LayoutManager::getInstance()->getPlayerBasePlacement();
    this->vecDestroyedBases = {};
    this->nTargetIndex = this->getRandomNumber(1, 3);
    this->nTotalBases = 3;
    this->strDeadEnd = "";
    this->bHoldTarget = false;
}

void EnemyBehavior::perform() {
    Enemy* pEnemy = (Enemy*)GameObjectManager::getInstance()->findObjectByName("Enemy");
    sf::Sprite* pEnemySprite = pEnemy->getSprite();
    
    float fX = pEnemy->getSprite()->getPosition().x;
    float fY = pEnemy->getSprite()->getPosition().y;

   if(pEnemy->getHasDestroyed() == false && this->bHoldTarget == false) {
        int nIndex = -1;
        do{
            nIndex = this->getRandomNumber(1, 3);
        }while(this->checkDuplicate(this->nTargetIndex));
        
        this->nTargetIndex = nIndex;
        this->posTarget = this->vecTargetBases[nIndex];
        this->bHoldTarget = true;
        std::cout << this->nTargetIndex << std::endl; 

   }
   else if (pEnemy->getHasDestroyed()){
        this->vecDestroyedBases.push_back(this->nTargetIndex);
        this->nTotalBases -= 1;
        this->bHoldTarget = false;
        pEnemy->setHasDestroyed(false);
   }

    float fBaseX = this->posTarget.x * GRID_SIZE;
    float fBaseY = this->posTarget.y * GRID_SIZE; 

    this->fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

    if(fX < fBaseX && this->strDeadEnd != "Right") {
        if(!pEnemy->getRightBounds() && !pEnemy->getLeftWallCollide()) {
            this->moveToRight();
            pEnemy->setFrame(1);
            
        }
        else {
            this->moveToLeft();
            this->strDeadEnd = "Right";
        }
    }

    else if(fY < fBaseY && this->strDeadEnd != "Bottom") {
        if(!pEnemy->getBottomBounds() && !pEnemy->getTopWallCollide()) {
            this->moveDownward();
            pEnemy->setFrame(2);
            
        }
        else {
            std::cout << "hello" << std::endl;
            this->moveUpward();
            this->strDeadEnd = "Bottom";
        }
    }

    else if(fX > fBaseX && this->strDeadEnd != "Left") {
        if(!pEnemy->getLeftBounds() && !pEnemy->getRightWallCollide()) {
            this->moveToLeft();
            pEnemy->setFrame(3);
            
        }
        else {
            this->moveToRight();
            this->strDeadEnd = "Left";
        }
    }

    else if(fY > fBaseY && this->strDeadEnd != "Top") {
        if(!pEnemy->getTopBounds() && !pEnemy->getBottomWallCollide()) {
            this->moveUpward();
            pEnemy->setFrame(0);
            
        }
        else {
            this->moveDownward();
            this->strDeadEnd = "Top";
        }
    }
}

int EnemyBehavior::getRandomNumber(int nLowerbound, int nUpperbound) {
    int nRet = rand() % (nUpperbound - nLowerbound + 1);
    return nRet;
}

void EnemyBehavior::moveToRight() {
    sf::Sprite* pEnemySprite = this->getOwner()->getSprite();
    pEnemySprite->move(1.0f * this->fOffset, 0.0f);
}

void EnemyBehavior::moveToLeft() {
    sf::Sprite* pEnemySprite = this->getOwner()->getSprite();
    pEnemySprite->move(-1.0f * this->fOffset, 0.0f);
}

void EnemyBehavior::moveUpward() {
    sf::Sprite* pEnemySprite = this->getOwner()->getSprite();
    pEnemySprite->move(0.0f, -1.0f * this->fOffset);
}

void EnemyBehavior::moveDownward() {
    sf::Sprite* pEnemySprite = this->getOwner()->getSprite();
    pEnemySprite->move(0.0f, 1.0f * this->fOffset);
}


bool EnemyBehavior::checkDuplicate(int nIndex) {
    for(int i = 0; i < this->vecDestroyedBases.size(); i++) {
        if(this->vecDestroyedBases[i] == nIndex)
            return true;
    }
    return false;
}