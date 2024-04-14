#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Background.hpp"
#include "../Component/Input/SelectorInput.hpp"
#include "../Component/Script/SelectorAction.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../../Controller/Manager/GameObjectManager.hpp"

namespace entities {
    using namespace models;
    using namespace entities;
    using namespace components;
    using namespace managers;

    class Selector : public GameObject {
        public:
            float fDefaultY;

        public:
            Selector(std::string strName, AnimatedTexture* pTexture);
        
        public:
            void initialize();

        public:
            float getDefaultY();
    };
}