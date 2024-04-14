#include "Player.hpp"
using namespace entities;


Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
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
}

void Player::initialize() {
    this->spawn();

    PlayerInput* pInput = new PlayerInput(this->strName + " Input");
    this->attachComponent(pInput);

    PlayerMovement* pMovement = new PlayerMovement(this->strName + " Movement");
    this->attachComponent(pMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}

void Player::spawn() {
    int nSize = SCALE_SIZE * BLOCK_SIZE;
    sf::Vector2f vecSpawn(8, 16);
    this->pSprite->setPosition(vecSpawn.x * nSize + 5.0f, vecSpawn.y * nSize);
    this->setFrame(0);
    this->pSprite->setScale(SCALE_SIZE, SCALE_SIZE);
}

void Player::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border") {
        this->bTopBounds = true;
     //   std::cout << "enter top border" << std::endl;
    }
    
    if(pGameObject->getName() == "Left Border") {
        this->bLeftBounds = true;
    //    std::cout << "enter left border" << std::endl;
    }

    if(pGameObject->getName() == "Bottom Border") {
        this->bBottomBounds = true;
     //   std::cout << "enter bottom border" << std::endl;
    }

    if(pGameObject->getName() == "Right Border") {
        this->bRightBounds = true;
      //  std::cout << "enter right border" << std::endl;
    }

    if(pGameObject->getName() == "Top Wall Bound") {
        this->bTopWallCollide = true;
      // std::cout << "enter top wall" << std::endl;
    }

    if(pGameObject->getName() == "Left Wall Bound") {
        this->bLeftWallCollide = true;
      //  std::cout << "enter left wall" << std::endl;
    }

    if(pGameObject->getName() == "Bottom Wall Bound") {
        this->bBottomWallCollide = true;
     //  std::cout << "enter bottom wall" << std::endl;
    }

    if(pGameObject->getName() == "Right Wall Bound") {
        this->bRightWallCollide = true;
       // std::cout << "enter right wall" << std::endl;
    }

    if(pGameObject->getName() == "Enemy Base") {
        pGameObject->setFrame(1);
        Base* pBase = (Base*)pGameObject;

        if(!pBase->getDestroyed()) {
            ScoreManager::getInstance()->incrementPlayerScore();
            pBase->setDestroyed(true);
        }
    } 
}

void Player::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border") {
      //  std::cout << "exit top border" << std::endl;
        this->bTopBounds = false;
    }

    if(pGameObject->getName() == "Left Border") {
      //  std::cout << "exit left border" << std::endl;
        this->bLeftBounds = false;
    }

    if(pGameObject->getName() == "Bottom Border") {
     //   std::cout << "exit bottom border" << std::endl;
        this->bBottomBounds = false;
    }

    if(pGameObject->getName() == "Right Border")  {
     //   std::cout << "exit right border" << std::endl;
        this->bRightBounds = false;
    }

    if(pGameObject->getName() == "Top Wall Bound") {
        this->bTopWallCollide = false;
      //  std::cout << "exit top wall" << std::endl;
    }

    if(pGameObject->getName() == "Left Wall Bound") {
        this->bLeftWallCollide = false;
     //   std::cout << "exit left wall" << std::endl;
    }

    if(pGameObject->getName() == "Bottom Wall Bound") {
        this->bBottomWallCollide = false;
//std::cout << "exit Bottom wall" << std::endl;
    }

    if(pGameObject->getName() == "Right Wall Bound") {
        this->bRightWallCollide = false;
       // std::cout << "exit right wall" << std::endl;
    }
}



bool Player::getTopBounds() {
    return this->bTopBounds;
}

bool Player::getLeftBounds() {
    return this->bLeftBounds;
}

bool Player::getBottomBounds() {
    return this->bBottomBounds;
}

bool Player::getRightBounds() {
    return this->bRightBounds;
}

bool Player::getWallBounds() {
    return this->bWallBounds;
}

bool Player::getBaseBounds() {
    return this->bBaseBounds;
}

bool Player::getBulletBounds() {
    return this->bBulletBounds;
}

bool Player::getTopWallCollide() {
    return this->bTopWallCollide;
}

bool Player::getLeftWallCollide() {
     return this->bLeftWallCollide;   
}

bool Player::getBottomWallCollide() {
    return this->bBottomWallCollide; 
}

bool Player::getRightWallCollide() {
    return this->bRightWallCollide; 
}

