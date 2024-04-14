#include "Selector.hpp"
using namespace entities;

Selector::Selector(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    Background* pBackground = (Background*)GameObjectManager::getInstance()->findObjectByName("Background");
    this->fDefaultY = 490.0f;
}

void Selector::initialize() {
    this->pSprite->setScale(3.0f, 3.0f);
    this->pSprite->setPosition(210.0f, this->fDefaultY);

    SelectorInput* pInput = new SelectorInput(this->strName + " Input");
    this->attachComponent(pInput);

    SelectorAction* pAction = new SelectorAction(this->strName + " Action");
    this->attachComponent(pAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

float Selector::getDefaultY() {
    return this->fDefaultY;
}