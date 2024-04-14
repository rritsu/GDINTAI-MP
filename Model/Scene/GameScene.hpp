#pragma once

#include "../Scene.hpp"
#include "../EmptyGameObject.hpp"
#include "../Entity/Tile.hpp"
#include "../Entity/Background.hpp"
#include "../Entity/Bound.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/Base.hpp"
#include "../Pooling/Entity/PlayerBullet.hpp"
#include "../Entity/Enemy.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Pooling/GameObjectPool.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../Controller/Manager/BoundManager.hpp"
#include "../../Controller/Manager/LayoutManager.hpp"

namespace scenes {
    using namespace models;
    using namespace entities;
    using namespace poolables;
    using namespace managers;

    class GameScene : public Scene {
        private:
            std::vector<sf::Vector2f> vecVerticalWallPoints;
            std::vector<int> vecVerticalBlocks;
            std::vector<sf::Vector2f> vecHorizontalWallPoints;
            std::vector<int> vecHorizontalBlocks;

        public: 
            GameScene();
        
        private:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();

        private:
            void createNullObject();
            void createTiles();
            void createBases();
            void createBackGround();
            void createBorders();
            void createPlayer();
            void createEnemy();
            void createPlayerObjectPools();
            void createEnemyObjectPools();
            void createVerticalWalls();
            void createHorizontalWalls();

    };
}