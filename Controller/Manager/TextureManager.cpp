#include "TextureManager.hpp"
using namespace managers;

void TextureManager::loadMainMenu() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Main Menu/main_menu_bg.png");
    this->mapTexture[AssetType::MAIN_MENU_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Main Menu/selector.png");
    this->mapTexture[AssetType::MAIN_MENU_SELECTOR].push_back(pTexture);
}

void TextureManager::loadPlayer() {
    sf::Texture* pTexture;
    for(int i = 1; i <= 4; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Stage/Player/player" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::PLAYER].push_back(pTexture);
    }

    this->vecAssetTypes.push_back(AssetType::PLAYER);
}

void TextureManager::loadEnemy() {
    sf::Texture* pTexture;
    for(int i = 1; i <= 4; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Stage/Enemy/enemy" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::ENEMY].push_back(pTexture);
    }
    this->vecAssetTypes.push_back(AssetType::ENEMY);
}

void TextureManager::loadPlayerBullet() {
    sf::Texture* pTexture;
    for(int i = 1; i <= 4; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Stage/Player/bullet-player" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::PLAYER_BULLET].push_back(pTexture);
    }
    this->vecAssetTypes.push_back(AssetType::PLAYER_BULLET);
}

void TextureManager::loadTiles() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Stage/brickwall.png");
    this->mapTexture[AssetType::TILE].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Stage/stonewall.png");
    this->mapTexture[AssetType::TILE].push_back(pTexture);

    this->vecAssetTypes.push_back(AssetType::TILE);
}

void TextureManager::loadBase() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Stage/base.png");
    this->mapTexture[AssetType::BASE].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Stage/base_destroyed.png");
    this->mapTexture[AssetType::BASE].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::BASE); 
}


void TextureManager::loadGame() {
    this->loadTiles();
    this->loadBase();
    this->loadPlayer();
    this->loadEnemy();
    this->loadPlayerBullet();
   // this->loadEnemyBullet();
}

void TextureManager::loadEvaluation() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Evaluation/times_up.png");
    this->mapTexture[AssetType::EVALUATION_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Evaluation/player_won.png");
    this->mapTexture[AssetType::EVALUATION_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Evaluation/enemy_won.png");
    this->mapTexture[AssetType::EVALUATION_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Evaluation/draw.png");
    this->mapTexture[AssetType::EVALUATION_BACKGROUND].push_back(pTexture);

    this->vecAssetTypes.push_back(AssetType::EVALUATION_BACKGROUND);
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EType) {
    return this->mapTexture[EType];
}


//returns one of the frames
sf::Texture* TextureManager::getTextureAt(AssetType EType, int nFrame) {
    return this->mapTexture[EType][nFrame];
}

void TextureManager::unloadAll() {
    for(AssetType EType : this->vecAssetTypes) {
        std::vector<sf::Texture*> vecTextures = this->mapTexture[EType];
        for(int i = 0; i < vecTextures.size(); i++) {
            delete this->mapTexture[EType][i];

        }
    }
    this->vecAssetTypes.clear();
    this->mapTexture.clear();
}



//SINGLETON-RELATED CONTENT
TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;
TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE;
}