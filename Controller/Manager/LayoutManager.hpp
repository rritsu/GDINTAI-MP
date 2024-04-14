#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace managers {
    class LayoutManager {
        public:
            std::vector<std::vector<int>> getTilePlacement();
            std::vector<sf::Vector2f> getVerticalWallPoints();
            std::vector<int> getVerticalNumBlocks();
            std::vector<sf::Vector2f> getHorizontalWallPoints();
            std::vector<int> getHorizontalNumBlocks();
            std::vector<sf::Vector2f> getEnemyBasePlacement();
            std::vector<sf::Vector2f> getPlayerBasePlacement();


        //SINGLETON-RELATED CONTENT
        private:
            static LayoutManager* P_SHARED_INSTANCE;
        
        private:
            LayoutManager();
            LayoutManager(const LayoutManager&);
            LayoutManager& operator = (const LayoutManager&);
        
        public:
            static LayoutManager* getInstance();
    };
}