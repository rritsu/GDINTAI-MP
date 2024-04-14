#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/EvaluationScreen.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    using namespace models;

    class EvaluationScene : public Scene {
        public:
            EvaluationScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();   
        
        private:
            void createEvaluationScreen();
    };
}
