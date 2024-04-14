#pragma once

#include "../Component.hpp"
#include "../GeneralInput.hpp"

namespace components {
    class SelectorInput : public GeneralInput {
        private:
            bool bEnter;
            bool bUp;
            bool bDown;

        public:
            SelectorInput(std::string strName);
        
        public:
            void perform();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool getEnter();
            bool getUp();
            bool getDown();
            
    };
}