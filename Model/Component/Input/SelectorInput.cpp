#include "SelectorInput.hpp"
using namespace components;

SelectorInput::SelectorInput(std::string strName) : GeneralInput(strName) {
    this->bEnter = false;
    this->bUp = false;
    this->bDown = false;
}

void SelectorInput::perform() {
    switch(this->CEvent.type) {
        case sf::Event::KeyPressed:
            processKeyInput(true);
            break;

        case sf::Event::KeyReleased:
            processKeyInput(false);
            break;

        default:
            break;

    }
}

void SelectorInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key CKey = this->CEvent.key.code;

    switch(CKey) {
        case sf::Keyboard::Enter:
            this->bEnter = bPressed;
            break;

        case sf::Keyboard::W:
            this->bUp = bPressed;
            break;

        case sf::Keyboard::S:
            this->bDown = bPressed;
            break;

        default:
            break;
    }
}

bool SelectorInput::getEnter() {
    return this->bEnter;
}

bool SelectorInput::getUp() {
    return this->bUp;
}

bool SelectorInput::getDown() {
    return this->bDown;
}