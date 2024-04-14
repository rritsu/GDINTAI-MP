#pragma once

#include "../../../Config/Settings.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"
#include "../Component.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../Entity/Player.hpp"
#include "../../Pooling/Entity/PlayerBullet.hpp"
#include "../Input/PlayerInput.hpp"

namespace components {
    using namespace models;
    using namespace poolables;
    using namespace managers;
    using namespace entities;

    class BulletMovement : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            float fSpeed;
            float fX;
            float fY;
            float fPosX;
            float fPosY;

        public:
            BulletMovement(std::string strName);

        public:
            void perform();
    };
}
