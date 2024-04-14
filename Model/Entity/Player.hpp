#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Script/PlayerMovement.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../Entity/Base.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"
#include "../../Controller/Manager/ScoreManager.hpp"
#include "../../Config/Settings.hpp"

namespace entities{
    using namespace models;
    using namespace interfaces;
    using namespace entities;
    using namespace components;
    using namespace managers;

    class Player : public GameObject, public CollisionListener{
        private:
            bool bTopBounds;
            bool bLeftBounds;
            bool bBottomBounds;
            bool bRightBounds;
            bool bWallBounds;
            bool bBaseBounds;
            bool bBulletBounds;
            bool bTopWallCollide;
            bool bLeftWallCollide;
            bool bBottomWallCollide;
            bool bRightWallCollide;


        public:
            Player(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
            void spawn();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            bool getTopBounds();
            bool getLeftBounds();
            bool getBottomBounds();
            bool getRightBounds();
            bool getWallBounds();
            bool getBaseBounds();
            bool getBulletBounds();
            bool getTopWallCollide();
            bool getLeftWallCollide();
            bool getBottomWallCollide();
            bool getRightWallCollide();            

    };

}