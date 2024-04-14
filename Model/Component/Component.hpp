#pragma once

#include <SFML/Graphics.hpp>

#include "../GameObject.hpp"
#include "../Enum/ComponentType.hpp"

//review forward declaration
namespace models {
    class GameObject; /* [NOTE] : Forward declaration. This is a Reading Assignment. */
}

namespace components {
    using namespace models;

    class Component {
        protected:
            GameObject* pOwner;
            ComponentType EType;
            std::string strName;
            sf::Time tDeltaTime;

        public:
            Component(std::string strName, ComponentType EType);
            virtual ~Component(); //normal/italicized destructor 
             
        public:
            void attachOwner(GameObject* pOwner);
            void detachOwner();
        
        public:
            virtual void perform() = 0;

        public:
            GameObject* getOwner();
            ComponentType getType();
            std::string getName();
            void setDeltaTime(sf::Time tDeltaTime);


    };


}