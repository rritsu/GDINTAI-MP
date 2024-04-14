#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bMovingLeft;
            bool bMovingRight;
            bool bMovingUp;
            bool bMovingDown;
            bool bFire;
        
        public:
            PlayerInput(std::string strName);

        public:
            void perform();
            void resetFire();

        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);
        
        public:
            bool getMovingLeft();
            void setMovingLeft(bool bMovingLeft);
            bool getMovingRight();
            void setMovingRight(bool bMovingRight);
            bool getMovingUp();
            void setMovingUp(bool bMovingUp);
            bool getMovingDown();
            void setMovingDown(bool bMovingDown);
            bool getFire();
            void setFire(bool bFire);

    };

    
}
