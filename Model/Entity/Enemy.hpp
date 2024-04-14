#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Base.hpp"
#include "../Component/Script/EnemyBehavior.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../../Config/Settings.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"
#include "../../Controller/Manager/ScoreManager.hpp"

namespace entities {
    using namespace models;
    using namespace entities;
    using namespace components;
    using namespace managers;

    class Enemy : public GameObject, public CollisionListener{
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
            bool bHasDestroyed;

        public:
            Enemy(std::string strName, AnimatedTexture* pTexture);

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
            bool getHasDestroyed();
            void setHasDestroyed(bool bHasDestroyed);
    };
}
