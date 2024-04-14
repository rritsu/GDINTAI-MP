#pragma once

#include <SFML/Graphics.hpp>

#include "../Component.hpp"
#include "../../Entity/Selector.hpp"
#include "../Input/SelectorInput.hpp"
#include "../Renderer/Renderer.hpp"
#include "../../Scene/GameScene.hpp"
#include "../../../Controller/Manager/SceneManager.hpp"

namespace components {
    using namespace entities;
    using namespace managers;
    using namespace scenes;

    class SelectorAction : public Component {
        public:
            SelectorAction(std::string strName);
        
        public:
            void perform();

    };
}