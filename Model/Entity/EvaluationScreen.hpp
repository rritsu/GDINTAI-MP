#pragma once

#include "../GameObject.hpp"
#include "../Component/Input/EvaluationInput.hpp"
#include "../Component/Script/EvaluationScript.hpp"
#include "../../Controller/Manager/ScoreManager.hpp"

namespace entities {
    using namespace models;
    using namespace components;
    using namespace managers;

    class EvaluationScreen : public GameObject {
        private:
            bool bTimesUp;
        
        public:
            EvaluationScreen(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();

        public:
            bool getTimesUp();
            void setTimesUp(bool bTimesUp);
    };
}