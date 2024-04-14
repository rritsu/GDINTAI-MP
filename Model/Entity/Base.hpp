#pragma once

#include "../GameObject.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"

namespace entities {
    using namespace models;
    using namespace components;
    using namespace managers;
    using namespace interfaces;

    class Base : public GameObject, public CollisionListener {
        private:
            bool bDestroyed;
        
        public:
            Base(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            bool getDestroyed();
            void setDestroyed(bool bDestroyed);

    };
}