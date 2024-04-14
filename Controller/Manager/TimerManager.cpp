#include "TimerManager.hpp"
using namespace managers;


void TimerManager::startTimer() {
    this->CTimer.restart();
    this->bHasStarted = true;
}

void TimerManager::checkTimer() {
    if(this->getTimer().asSeconds() <= 10) {
        if((int)this->getTimer().asSeconds() / 10 <= 1) 
            std::cout << (int)this->getTimer().asSeconds() << "..." << std::endl;
    }
}

sf::Time TimerManager::getTimer() {
    this->tTimer = CTimer.getElapsedTime();
    return this->tTimer;
}

bool TimerManager::getHasStarted() {
    return this->bHasStarted;
}

void TimerManager::setHasStarted(bool bHasStarted) {
    this->bHasStarted = bHasStarted;
}



//SINGLETON-RELATED CONTENT
TimerManager* TimerManager::P_SHARED_INSTANCE = NULL;

TimerManager::TimerManager() {
    this->tTimer = sf::Time::Zero;
    this->bHasStarted = false;
    this->CTimer = sf::Clock();
}


TimerManager::TimerManager(const TimerManager& CObject) {}

TimerManager* TimerManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TimerManager();
    return P_SHARED_INSTANCE;
}
