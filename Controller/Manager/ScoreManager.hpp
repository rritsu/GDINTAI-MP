#pragma once

#include <iostream>

namespace managers {
    class ScoreManager {
        public:
            int nPlayerKills;
            int nPlayerScore;
            int nEnemyKills;
            int nEnemyScore;

        public:
            void incrementPlayerKills();
            void incrementPlayerScore();
            void incrementEnemyKills();
            void incrementEnemyScore();
            bool checkScore();
            int determineWinner();
            void resetScore();

        public:
            int getPlayerKills();
            int getPlayerScore();
            int getEnemyKills();
            int getEnemyScore();


        //SINGLETON-RELATED CONTENT
        private:
            static ScoreManager* P_SHARED_INSTANCE;
        
        private:
            ScoreManager();
            ScoreManager(const ScoreManager&);
            ScoreManager& operator = (const ScoreManager&);
        
        public:
            static ScoreManager* getInstance();
    };
}