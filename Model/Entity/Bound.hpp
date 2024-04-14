#pragma once

#include "../GameObject.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"
#include "../Enum/BoundType.hpp"

namespace entities {
    using namespace components;
    using namespace interfaces;
    using namespace managers;

    class Bound : public GameObject, public CollisionListener{
        private:
            sf::FloatRect CBounds;
            BoundType EType;

        public:
            Bound(std::string strName, BoundType EType, sf::FloatRect CBounds);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            sf::FloatRect getGlobalBounds();
            BoundType getBoundType();

    };
}