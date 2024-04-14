#include "EvaluationInput.hpp"

using namespace components;

EvaluationInput::EvaluationInput(std::string strName) : GeneralInput(strName) {
    this->bEnter = false;
}

void EvaluationInput::perform() {
    switch(this->CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyboardInput(true);
            break;
        
        case sf::Event::KeyReleased:
            this->processKeyboardInput(false);
            break;

        default:
            break;
    }
}

void EvaluationInput::processKeyboardInput(bool bPressed) {
    switch(this->CEvent.key.code) {
        case sf::Keyboard::Enter:
            this->bEnter = bPressed;
            break;

        default:
            break;
    }
}

void EvaluationInput::resetEnter() {
    this->bEnter = false;
}

bool EvaluationInput::getEnter() {
    return this->bEnter;
}


