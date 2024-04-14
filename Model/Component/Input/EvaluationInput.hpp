#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class EvaluationInput : public GeneralInput {
        private:
            bool bEnter;

        public:
            EvaluationInput(std::string strName);

        private:
            void processKeyboardInput(bool bPressed);

        public:
            void perform();
            void resetEnter();

        public:
            bool getEnter();

    };
}