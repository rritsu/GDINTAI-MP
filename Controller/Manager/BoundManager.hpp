#pragma once

#include "unordered_map"
#include "../../Model/Enum/BoundType.hpp"
#include "../../Model/Entity/Bound.hpp"


namespace managers {
    using namespace entities;

    class BoundManager {
        private:
            std::unordered_map<BoundType, Bound*> mapBounds;
            std::vector<Bound*> vecBounds;

        public:
            void registerBound(Bound* pBound);
            void deleteAllBounds();
            bool checkIfRegistered(GameObject* pBound);
            int getTotalBounds();
            


        //SINGLETON-RELATED CONTENT
        private:
            static BoundManager* P_SHARED_INSTANCE;
        
        private:
            BoundManager();
            BoundManager(const BoundManager&);
            BoundManager& operator = (const BoundManager&);
        
        public:
            static BoundManager* getInstance();

    };
}