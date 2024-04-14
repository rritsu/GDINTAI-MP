#pragma once

#include "iostream"
#include "vector"
#include "../../Model/Component/Physics/Collider.hpp"
#include "../../Model/Enum/ComponentType.hpp"
#include "../../Model/Component/Component.hpp"

namespace managers {
    using namespace components;

    class PhysicsManager : public Component {
        private:
            std::vector<Collider*> vecTrackedColliders;
            std::vector<Collider*> vecUntrackedColliders;

        public:
            void perform();
            void trackCollider(Collider* pCollider);
            void untrackCollider(Collider* pCollider);
            void cleanUp();
            void deleteTrackedColliders();
            int getTotalTracked();

        private:
            int findTrackedCollider(Collider* pCollider);


        //SINGLETON-RELATED CONTENT      
        private:
            static PhysicsManager* P_SHARED_INSTANCE;

        private:
            PhysicsManager(std::string strName);
            PhysicsManager(const PhysicsManager&);
            PhysicsManager& operator = (const PhysicsManager&);

        public:
            static void initialize(std::string strName, GameObject* pHolder);
            static PhysicsManager* getInstance();
            static void destroy();
    };
}

        