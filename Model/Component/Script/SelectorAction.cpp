#include "SelectorAction.hpp"
using namespace components;

SelectorAction::SelectorAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void SelectorAction::perform() {
    Selector* pOwner = (Selector*)this->pOwner;
    SelectorInput* pInput = (SelectorInput*)pOwner->findComponentByName(pOwner->getName() + " Input");

    Renderer* pRenderer = (Renderer*)pOwner->findComponentByName(pOwner->getName() + " Renderer");

    float fX = pOwner->getSprite()->getPosition().x;
    float fY = pOwner->getDefaultY();

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->getEnter()) {
            if(fY == pOwner->getSprite()->getPosition().y) {    //play game
                SceneManager::getInstance()->registerScene(new GameScene());
                SceneManager::getInstance()->loadScene(SceneTag::GAME_SCENE);
            }
            else{  //quit program
                sf::RenderWindow* pWindow = pRenderer->getWindow();
                pWindow->close();
            }
            
        }

        if(pInput->getUp()) {
            pOwner->getSprite()->setPosition(fX, fY);
        }

        if(pInput->getDown()) {
            pOwner->getSprite()->setPosition(fX, fY + 135.0f);
        }
    }
    
}
