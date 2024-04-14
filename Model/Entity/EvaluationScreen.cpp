#include "EvaluationScreen.hpp"

using namespace entities;

EvaluationScreen::EvaluationScreen(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->bTimesUp = false;
}

void EvaluationScreen::initialize() {
    if(bTimesUp) {
        this->setFrame(0);
    }
    else {
        int nWinnerFrame = ScoreManager::getInstance()->determineWinner();
        this->setFrame(nWinnerFrame);
    }


    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    EvaluationInput* pInput = new EvaluationInput(this->strName + " Input");
    this->attachComponent(pInput);

    EvaluationScript* pScript = new EvaluationScript(this->strName + " Script");
    this->attachComponent(pScript);
}

bool EvaluationScreen::getTimesUp() {
    return this->bTimesUp;
}

void EvaluationScreen::setTimesUp(bool bTimesUp) {
    this->bTimesUp = bTimesUp;
}   