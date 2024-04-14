#include "Background.hpp"
using namespace entities;

Background::Background(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture){}

void Background::initialize() {
    this->pSprite->setOrigin(this->getWidth(), this->getHeight());
    this->pSprite->setPosition(SCREEN_WIDTH, SCREEN_HEIGHT);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

std::vector<std::vector<int>> Background::getTilePlacement() {
    return {};
}