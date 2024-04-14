#pragma once

#include "../../Entity/Enemy.hpp"
#include "../../../Controller/Manager/LayoutManager.hpp"
#include "../../../Controller/Manager/GameObjectManager.hpp"

namespace components {
    using namespace entities;
    using namespace managers;

    class EnemyBehavior : public Component {
        private:
            float fSpeed;
            std::vector<sf::Vector2f> vecTargetBases;
            std::vector<int> vecDestroyedBases;
            sf::Vector2f posTarget;
            int nTargetIndex;
            int nTotalBases;
            std::string strDeadEnd;
            float fOffset;
            bool bHoldTarget;

        public:
            EnemyBehavior(std::string strName);

        public:
            void perform();
        
        private:
            void moveToRight();
            void moveToLeft();
            void moveUpward();
            void moveDownward();
            int getRandomNumber(int nLowerbound, int nUpperbound);
            bool checkDuplicate(int nIndex);

    };
}