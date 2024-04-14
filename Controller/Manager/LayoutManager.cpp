#include "LayoutManager.hpp"

using namespace managers;

std::vector<std::vector<int>> LayoutManager::getTilePlacement() {
    std::vector<std:: vector<int>> vecPlacement
    { 
    //  0   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16    
        {0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0},    // 0
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},    // 1
        {2, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 2},    // 2
        {2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2},    // 3
        {2, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 2},    // 4
        {2, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 2},    // 5
        {2, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 2},    // 6
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},    // 7
        {2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2},    // 8
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},    // 9
        {2, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 2},    // 10
        {2, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 2},    // 11
        {2, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 2},    // 12
        {2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2},    // 13
        {2, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 2},    // 14
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},    // 15
        {0, 0, 0, 0, 2, 2, 2, 0, 3, 0, 2, 2, 2, 0, 0, 0, 0},    // 16   
    }; 
    
    return vecPlacement;
}

std::vector<sf::Vector2f> LayoutManager::getVerticalWallPoints() {
    //sf::Vector2f(Column, Row)
    std::vector<sf::Vector2f> vecWallPoints {
        sf::Vector2f(2, 1),
        sf::Vector2f(2, 10),
        sf::Vector2f(4, 1),
        sf::Vector2f(4, 10),
        sf::Vector2f(6, 3),
        sf::Vector2f(6, 11),
        sf::Vector2f(8, 2),
        sf::Vector2f(8, 13),
        sf::Vector2f(10, 3),
        sf::Vector2f(10, 11),
        sf::Vector2f(12, 1),
        sf::Vector2f(12, 10),
        sf::Vector2f(14, 1),
        sf::Vector2f(14, 10),
        sf::Vector2f(0, 2),
        sf::Vector2f(16, 2)
    };
    return vecWallPoints;
}

std::vector<int> LayoutManager::getVerticalNumBlocks() {
    std::vector<int> vecNumBlocks {
        6,
        6,
        6,
        6,
        3,
        3,
        2,
        2,
        3,
        3,
        6,
        6,
        6,
        6,
        13,
        13
    };

    return vecNumBlocks;
}

std::vector<sf::Vector2f> LayoutManager::getHorizontalWallPoints() {
    std::vector<sf::Vector2f> vecWallPoints {
        sf::Vector2f(4, 0),
        sf::Vector2f(4, 16),
        sf::Vector2f(10, 0),
        sf::Vector2f(10, 16),
        sf::Vector2f(6, 8),
        sf::Vector2f(10, 8 ),
        sf::Vector2f(8, 6),
        sf::Vector2f(8, 10)
    };
    return vecWallPoints;
}

std::vector<int> LayoutManager::getHorizontalNumBlocks() {
    std::vector<int> vecNumBlocks {
        3,
        3,
        3,
        3,
        1,
        1,
        1,
        1
    };

    return vecNumBlocks;
}

std::vector<sf::Vector2f> LayoutManager::getEnemyBasePlacement() {
    std::vector<sf::Vector2f> vecPlacement {
        sf::Vector2f(0, 0),
        sf::Vector2f(8, 0),
        sf::Vector2f(16, 0),
    };
    return vecPlacement;
}

std::vector<sf::Vector2f> LayoutManager::getPlayerBasePlacement() {
    std::vector<sf::Vector2f> vecPlacement {
        sf::Vector2f(0, 16),
        sf::Vector2f(8, 16),
        sf::Vector2f(16, 16)
    };
    return vecPlacement;
}


//SINGLETON-RELATED CONTENT      
LayoutManager* LayoutManager::P_SHARED_INSTANCE = NULL;
LayoutManager::LayoutManager() {}
LayoutManager::LayoutManager(const LayoutManager&) {}

LayoutManager* LayoutManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new LayoutManager();
    }
    return P_SHARED_INSTANCE;
}