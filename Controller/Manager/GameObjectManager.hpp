#pragma once

#include "unordered_map"
#include "../../Model/GameObject.hpp"


namespace managers {
    using namespace models;

    class GameObjectManager {
        private:
            std::unordered_map<std::string, GameObject*> mapGameObjects;
            std::vector<GameObject*> vecGameObjects;
        
        public:
            void processEvents(sf::Event CEvent);
            void update(sf::Time tDeltaTime);
            void draw(sf::RenderWindow* pWindow);

            void addObject(GameObject* pGameObject);
            GameObject* findObjectByName(std::string strName);
            void deleteObject(GameObject* pGameObject);
            void deleteAllObjects();

        public:
            int getActiveObjectSize();


        //SINGLETON-RELATED CONTENT
        private:
            static GameObjectManager* P_SHARED_INSTANCE;
        
        private:
            GameObjectManager();
            GameObjectManager(const GameObjectManager&);
            GameObjectManager& operator = (const GameObjectManager&);
        
        public:
            static GameObjectManager* getInstance();
        
    };
}