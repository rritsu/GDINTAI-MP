#pragma once

#include "../../Entity/EvaluationScreen.hpp"
#include "../Input/EvaluationInput.hpp"
#include "../../../Controller/Manager/ScoreManager.hpp"
#include "../../../Controller/Manager/TimerManager.hpp"
#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../../Controller/Manager/PhysicsManager.hpp"
#include "../../../Controller/Manager/BoundManager.hpp"

namespace components {
    using namespace entities;
    using namespace managers;

    class EvaluationScript : public Component {
        public:
            EvaluationScript(std::string strName);
        
        public:
            void perform();
    };

}