#include "EvaluationScript.hpp"

using namespace components;

EvaluationScript::EvaluationScript(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void EvaluationScript::perform() {
    EvaluationScreen* pOwner = (EvaluationScreen*)this->pOwner;
    EvaluationInput* pInput = (EvaluationInput*)pOwner->findComponentByName(pOwner->getName() + " Input");

    if(pInput != NULL) {
        if(pOwner->getFrameNumber() == 0 && pInput->getEnter()) {
            pInput->resetEnter();
            int nWinnerFrame = ScoreManager::getInstance()->determineWinner();
            pOwner->setFrame(nWinnerFrame);
            std::cout << "time's up" << std::endl;
        }
        else if(pInput->getEnter()) {
            pInput->resetEnter();
            ScoreManager::getInstance()->resetScore();
            TimerManager::getInstance()->setHasStarted(false);
            PhysicsManager::getInstance()->deleteTrackedColliders();
            BoundManager::getInstance()->deleteAllBounds();
            SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);
        }
    }
}