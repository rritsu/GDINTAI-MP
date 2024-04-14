#include "PlayerInput.hpp"
using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName){
    this->bMovingLeft = false;
    this->bMovingRight = false;
    this->bMovingUp = false;
    this->bMovingDown = false;
    this->bFire = false;
}

void PlayerInput::perform() {
    switch(this->CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyboardInput(this->CEvent.key.code, true);
            break;

        case sf::Event::KeyReleased:
            this->processKeyboardInput(this->CEvent.key.code, false);
            break;

        default:
            break;
    }
}

void PlayerInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey){
        case sf::Keyboard::W:
            this->bMovingUp = bPressed;
            break;

        case sf::Keyboard::A:
            this->bMovingLeft = bPressed;
            break;

        case sf::Keyboard::S:
            this->bMovingDown = bPressed;
            break;

        case sf::Keyboard::D:
            this->bMovingRight = bPressed;
            break;

        case sf::Keyboard::Space:
            this->bFire = bPressed;
            break;

    //    case sf::Keyboard::Q:
    //        this->btest = bPressed;
    //        break;
        
        default:
            break;
    }
}

void PlayerInput::resetFire() {
    this->bFire = false;
}

bool PlayerInput::getMovingLeft() {
    return this->bMovingLeft;
}

void PlayerInput::setMovingLeft(bool bMovingLeft) {
    this->bMovingLeft = bMovingLeft;
}

bool PlayerInput::getMovingRight() {
    return this->bMovingRight;
}

void PlayerInput::setMovingRight(bool bMovingRight) {
    this->bMovingRight = bMovingRight;
}

bool PlayerInput::getMovingUp() {
    return this->bMovingUp;
}

void PlayerInput::setMovingUp(bool bMovingUp) {
    this->bMovingUp = bMovingUp;
}

bool PlayerInput::getMovingDown() {
    return this->bMovingDown;
}

void PlayerInput::setMovingDown(bool bMovingDown) {
    this->bMovingDown = bMovingDown;
}

bool PlayerInput::getFire() {
    return this->bFire;
}

void PlayerInput::setFire(bool bFire) {
    this->bFire = bFire;
}