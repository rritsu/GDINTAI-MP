#pragma once

#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"
#include "../../GameObject.hpp"
#include "../../Entity/Player.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp" 
#include "../../Enum/PoolTag.hpp"


#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../Enum/SceneTag.hpp"

namespace components {
    using namespace managers;
    using namespace entities;

    class PlayerMovement : public Component {
        private:
            float fSpeed;
            float fInterval;
            float fThreshold;

        public:
            PlayerMovement(std::string strName);

        public:
            void perform();
    };
}