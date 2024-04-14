#pragma once

#include <SFML/Graphics.hpp>

#include "../Model/AnimatedTexture.hpp"

#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"
#include "Manager/SceneManager.hpp"
#include "Manager/TimerManager.hpp"

#include "../Model/Scene/MainMenuScene.hpp"
#include "../Model/Scene/GameScene.hpp"
#include "../Model/Scene/EvaluationScene.hpp"

#include "../Config/Settings.hpp"

namespace controllers {
    using namespace models;
    using namespace managers;
    using namespace entities;
    using namespace scenes;

    class Game {
        private: 
            sf::View* pView;
            sf::RenderWindow CWindow;

        public:
            Game();

        public:
            void run();

        private:
            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
    };
}