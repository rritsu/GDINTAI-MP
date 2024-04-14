#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../../Config/Settings.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class Background : public GameObject{        
        public: 
            Background(std::string strName, AnimatedTexture* pTexture);
    
        public:
            void initialize();
            std::vector<std::vector<int>> getTilePlacement();

    
    };

}
