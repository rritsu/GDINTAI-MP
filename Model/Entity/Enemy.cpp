#include "Enemy.hpp"

using namespace entities;

Enemy::Enemy(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
	this->bTopBounds = false;
    this->bLeftBounds = false;
    this->bBottomBounds = false;
    this->bRightBounds = false;
    this->bWallBounds = false;
    this->bBaseBounds = false;
    this->bBulletBounds = false; 
    this->bTopWallCollide = false;
    this->bLeftWallCollide = false;
    this->bBottomWallCollide = false;
    this->bRightWallCollide = false;
    this->bHasDestroyed = false;
}

void Enemy::initialize() {
    this->spawn();

	EnemyBehavior* pBehavior = new EnemyBehavior(this->strName + " Behavior");
	this->attachComponent(pBehavior);


    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}

void Enemy::spawn() {
    int nSize = SCALE_SIZE * BLOCK_SIZE;
    sf::Vector2f vecSpawn(8, 0);
    this->pSprite->setPosition(vecSpawn.x * nSize, vecSpawn.y * nSize);
    this->setFrame(2);
    this->pSprite->setScale(SCALE_SIZE, SCALE_SIZE);
}

void Enemy::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Player Bullet") {
       this->spawn();
       ScoreManager::getInstance()->incrementPlayerKills();
    }

    if(pGameObject->getName() == "Top Border") {
        this->bTopBounds = true;
       // std::cout << "enter top border" << std::endl;
    }
    
    if(pGameObject->getName() == "Left Border") {
        this->bLeftBounds = true;
    //    std::cout << "enter left border" << std::endl;
    }

    if(pGameObject->getName() == "Bottom Border") {
        this->bBottomBounds = true;
      //  std::cout << "enter bottom border" << std::endl;
    }

    if(pGameObject->getName() == "Right Border") {
        this->bRightBounds = true;
     //   std::cout << "enter right border" << std::endl;
    }

    if(pGameObject->getName() == "Top Wall Bound") {
        this->bTopWallCollide = true;
     //  std::cout << "enter top wall" << std::endl;
    }

    if(pGameObject->getName() == "Left Wall Bound") {
        this->bLeftWallCollide = true;
     //   std::cout << "enter left wall" << std::endl;
    }

    if(pGameObject->getName() == "Bottom Wall Bound") {
        this->bBottomWallCollide = true;
     //  std::cout << "enter bottom wall" << std::endl;
    }

    if(pGameObject->getName() == "Right Wall Bound") {
        this->bRightWallCollide = true;
      //  std::cout << "enter right wall" << std::endl;
    }

    if(pGameObject->getName() == "Player Base") {
        pGameObject->setFrame(1);
        Base* pBase = (Base*)pGameObject;

        if(!pBase->getDestroyed()) {
            ScoreManager::getInstance()->incrementEnemyScore();
            pBase->setDestroyed(true);
            this->bHasDestroyed = true;
        }
    } 
}

void Enemy::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border") {
     //   std::cout << "exit top border" << std::endl;
        this->bTopBounds = false;
    }

    if(pGameObject->getName() == "Left Border") {
       // std::cout << "exit left border" << std::endl;
        this->bLeftBounds = false;
    }

    if(pGameObject->getName() == "Bottom Border") {
     //   std::cout << "exit bottom border" << std::endl;
        this->bBottomBounds = false;
    }

    if(pGameObject->getName() == "Right Border")  {
   //     std::cout << "exit right border" << std::endl;
        this->bRightBounds = false;
    }

    if(pGameObject->getName() == "Top Wall Bound") {
        this->bTopWallCollide = false;
       // std::cout << "exit top wall" << std::endl;
    }

    if(pGameObject->getName() == "Left Wall Bound") {
        this->bLeftWallCollide = false;
     //   std::cout << "exit left wall" << std::endl;
    }

    if(pGameObject->getName() == "Bottom Wall Bound") {
        this->bBottomWallCollide = false;
	//	std::cout << "exit Bottom wall" << std::endl;
    }

    if(pGameObject->getName() == "Right Wall Bound") {
        this->bRightWallCollide = false;
      //  std::cout << "exit right wall" << std::endl;
    }
}


bool Enemy::getTopBounds() {
    return this->bTopBounds;
}

bool Enemy::getLeftBounds() {
    return this->bLeftBounds;
}

bool Enemy::getBottomBounds() {
    return this->bBottomBounds;
}

bool Enemy::getRightBounds() {
    return this->bRightBounds;
}

bool Enemy::getWallBounds() {
    return this->bWallBounds;
}

bool Enemy::getBaseBounds() {
    return this->bBaseBounds;
}

bool Enemy::getBulletBounds() {
    return this->bBulletBounds;
}

bool Enemy::getTopWallCollide() {
    return this->bTopWallCollide;
}

bool Enemy::getLeftWallCollide() {
     return this->bLeftWallCollide;   
}

bool Enemy::getBottomWallCollide() {
    return this->bBottomWallCollide; 
}

bool Enemy::getRightWallCollide() {
    return this->bRightWallCollide; 
}

bool Enemy::getHasDestroyed() {
    return this->bHasDestroyed;
}

void Enemy::setHasDestroyed(bool bHasDestroyed) {
    this->bHasDestroyed = this->bHasDestroyed;
}