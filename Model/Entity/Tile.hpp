#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"

namespace entities {    
    using namespace models;
    using namespace components;
    using namespace interfaces;
    using namespace managers;

    class Tile : public GameObject, public CollisionListener{
        private:
            int nFrame;

        public:
            Tile(std::string strName, AnimatedTexture* pTexture, int nFrame);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

    };


}