#include "PlayerBullet.hpp"
using namespace poolables;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Player* pPlayer) : PoolableObject(PoolTag::PLAYER_BULLET, strName, pTexture) {
    this->pPlayer = pPlayer;
}

void PlayerBullet::initialize() {
    this->centerOrigin();
    this->pSprite->setScale(3.0f, 3.0f);

    BulletMovement* pMovement = new BulletMovement(this->strName + " Movement");
    this->attachComponent(pMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
}

void PlayerBullet::onActivate() {
    float fX = this->pPlayer->getSprite()->getPosition().x;
    float fY = this->pPlayer->getSprite()->getPosition().y;
    float fWidth = this->pPlayer->getWidth();
    float fHeight = this->pPlayer->getHeight();


    if(this->pPlayer->getFrameNumber() == 0) {
        this->pSprite->setPosition(fX + fWidth + fWidth/2, fY - 5.0f);
        this->setFrame(0);
    }
    
    else if(this->pPlayer->getFrameNumber() == 1) {;
        this->pSprite->setPosition(fX + fWidth*3 + fWidth/2 - 5.0f, fY + fHeight*2 + 3.0f);
        this->setFrame(1);
    }

    else if(this->pPlayer->getFrameNumber() == 2) {
        this->pSprite->setPosition(fX + fWidth + fWidth/2, fY + fHeight*3 + fHeight/2);
        this->setFrame(2);
    }

    else if(this->pPlayer->getFrameNumber() == 3) {
        this->pSprite->setPosition(fX - fWidth - fWidth/2, fY + fHeight + fHeight + 3.0f);
        this->setFrame(3);
    }

    Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
    PhysicsManager::getInstance()->trackCollider(pCollider);

}

void PlayerBullet::onRelease() {
    Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
}

PoolableObject* PlayerBullet::clone() {
    PoolableObject* pPoolableObject = new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pPlayer);
    return pPoolableObject;
}


void PlayerBullet::onCollisionEnter(GameObject* pGameObject) {} 

void PlayerBullet::onCollisionExit(GameObject* pGameObject) {
    Bound* pBound = (Bound*)pGameObject;

    bool bCheck = BoundManager::getInstance()->checkIfRegistered(pGameObject);
    if(bCheck) {
        ObjectPoolManager::getInstance()->getPool(this->getTag())->releasePoolable(this);
        this->bHoldPosition = false;
    }

    if(pGameObject->getName() == "Enemy") {
        ObjectPoolManager::getInstance()->getPool(this->getTag())->releasePoolable(this);
        this->bHoldPosition = false;
    }
} 

bool PlayerBullet::getHoldPositioN() {
    return this->bHoldPosition;
}

void PlayerBullet::setHoldPosition(bool bHoldPosition) {
    this->bHoldPosition = bHoldPosition;
}