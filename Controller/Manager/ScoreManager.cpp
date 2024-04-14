#include "ScoreManager.hpp"

using namespace managers;

void ScoreManager::incrementPlayerKills() {
    this->nPlayerKills += 1;
    std::cout << "Player has gained a kill point!" << std::endl;
    std::cout << "Player Kills: " << this->nPlayerKills << std::endl << std::endl;
}

void ScoreManager::incrementPlayerScore() {
    this->nPlayerScore += 1;
    std::cout << "Player has destroyed one of the Enemy's bases " << std::endl;
    std::cout << "Player Score: " << this->nPlayerScore << std::endl << std::endl;
}

void ScoreManager::incrementEnemyKills() {
    this->nEnemyKills += 1;
    std::cout << "Enemy has gained a kill point!" << std::endl;
    std::cout << "Enemy Kills: " << this->nEnemyKills << std::endl << std::endl;
}

void ScoreManager::incrementEnemyScore() {
    this->nEnemyScore += 1;
    std::cout << "Enemy has destroyed one of the Player's bases " << std::endl;
    std::cout << "Enemy Score: " << this->nEnemyScore << std::endl << std::endl;
}

int ScoreManager::determineWinner() {
    int nWinner;
    std::string strWinner = "";

    if(this->nPlayerScore > this->nEnemyScore) {
        nWinner = 1;
    }
    else if(this->nPlayerScore < this->nEnemyScore) {
        nWinner = 2;
    }
    else if(this->nPlayerScore == this->nEnemyScore) {
        if(this->nPlayerKills > this->nEnemyKills) {
            nWinner = 1;
        }
        else if(this->nPlayerKills < this->nEnemyKills) {
            nWinner = 2;
        }
        else if(this->nPlayerKills == this->nEnemyKills) {
            nWinner = 3;
        }
            
    }

    return nWinner;
}

void ScoreManager::resetScore() {
    this->nPlayerKills = 0;
    this->nPlayerScore = 0;
    this->nEnemyKills = 0;
    this->nEnemyScore = 0;
}

int ScoreManager::getPlayerKills() {
    return this->nPlayerKills;
}

int ScoreManager::getPlayerScore() {
    return this->nPlayerScore;
}

int ScoreManager::getEnemyKills() {
    return this->nEnemyKills;
}

int ScoreManager::getEnemyScore() {
    return this->nEnemyScore;
}

bool ScoreManager::checkScore() {
    if(this->nPlayerScore >= 3 || this->nEnemyScore >= 3)
        return true;
    return false;
}


//SINGLETON-RELATED CONTENT
ScoreManager* ScoreManager::P_SHARED_INSTANCE = NULL;
ScoreManager::ScoreManager() {
    this->nPlayerKills = 0;
    this->nPlayerScore = 0;
    this->nEnemyKills = 0;
    this->nEnemyScore = 0;
}

ScoreManager::ScoreManager(const ScoreManager&) {}

ScoreManager* ScoreManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ScoreManager();

    return P_SHARED_INSTANCE;
}