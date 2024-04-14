#pragma once

#include "../PoolableObject.hpp"
#include "../../Entity/Player.hpp"
#include "../../Component/Script/BulletMovement.hpp"
#include "../../Interface/CollisionListener.hpp"
#include "../../../Controller/Manager/BoundManager.hpp"

namespace poolables {
    using namespace entities;
    using namespace components;
    using namespace interfaces;

    class PlayerBullet : public PoolableObject, public CollisionListener {
        private:
            Player* pPlayer;
            bool bHoldPosition;

        public:
            PlayerBullet(std::string strName, AnimatedTexture* pTexture, Player* pPlayer);
        
        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            bool getHoldPositioN();
            void setHoldPosition(bool bHoldPosition);

    };
}