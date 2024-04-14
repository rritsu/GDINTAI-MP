#pragma once

#include <string>
#include "../../Model/GameObject.hpp"

namespace managers {
    using namespace models;

    class TimerManager {
        private:
            sf::Clock CTimer;
            sf::Time tTimer;
            bool bHasStarted;

        public:
            void startTimer();
            void checkTimer();

        public:
            sf::Time getTimer();
            bool getHasStarted();
            void setHasStarted(bool bHasStarted);


        //SINGLETON-RELATED CONTENT
        private:
            static TimerManager* P_SHARED_INSTANCE;
        
        private:
            TimerManager();
            TimerManager(const TimerManager&);
            TimerManager& operator = (const TimerManager&);

        public:
            static TimerManager* getInstance();
            static void initialize();
    };
}