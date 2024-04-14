#include "GameScene.hpp"
using namespace scenes;

GameScene::GameScene() : Scene(SceneTag::GAME_SCENE) {}

void GameScene::onLoadResources() {
    TextureManager::getInstance()->loadGame();
}

void GameScene::onLoadObjects() {
    this->createNullObject();
    this->createTiles();
    this->createBases();
    this->createBorders();
    this->createVerticalWalls();
    this->createHorizontalWalls();
    this->createPlayer();
    this->createEnemy();
    this->createPlayerObjectPools();
}

void GameScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void GameScene::createNullObject() {
    EmptyGameObject* pHolder = new EmptyGameObject("Physics Manager Holder");
    PhysicsManager::getInstance()->initialize("Physics Manager", pHolder);
    this->registerObject(pHolder);
}


void GameScene::createTiles() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TILE));
    std::vector<std::vector<int>> vecPlacement = LayoutManager::getInstance()->getTilePlacement();
    int nSize = SCALE_SIZE * BLOCK_SIZE;

    for(int nRow = 0; nRow < GRID_WIDTH; nRow++) {
        for(int nCol = 0; nCol < GRID_HEIGHT; nCol++) {
            int nFrame = vecPlacement[nRow][nCol];

            if(nFrame == 1 || nFrame == 2) {
                Tile* pTile = new Tile("Wall", pTexture, nFrame-1);
                pTile->getSprite()->setPosition(nCol * nSize, nRow * nSize);
                this->registerObject(pTile);
            }
        }
    }
}

void GameScene::createBases() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BASE));
    int nSize = SCALE_SIZE * BLOCK_SIZE;

    //create enemy bases
    std::vector<sf::Vector2f> vecPlacement = LayoutManager::getInstance()->getEnemyBasePlacement();
    for(int i = 0; i < vecPlacement.size(); i++) {
        float fX = vecPlacement[i].x;
        float fY = vecPlacement[i].y;

        Base* pBase = new Base("Enemy Base", pTexture);
        pBase->getSprite()->setPosition(fX * nSize, fY * nSize);
        this->registerObject(pBase);
    }

    //create player bases
    vecPlacement = LayoutManager::getInstance()->getPlayerBasePlacement();
    for(int i = 0; i < vecPlacement.size(); i++) {
        float fX = vecPlacement[i].x;
        float fY = vecPlacement[i].y;

        Base* pBase = new Base("Player Base", pTexture);
        pBase->getSprite()->setPosition(fX * nSize, fY * nSize);
        this->registerObject(pBase);
    }
}

void GameScene::createVerticalWalls() {
    std::vector<sf::Vector2f> vecWallPoints = LayoutManager::getInstance()->getVerticalWallPoints();
    std::vector<int> vecNumBlocks = LayoutManager::getInstance()->getVerticalNumBlocks();
 
    float fSize = SCALE_SIZE * BLOCK_SIZE;

    for(int i = 0; i < vecWallPoints.size(); i++) {
        float fX = vecWallPoints[i].x * fSize;
        float fY = vecWallPoints[i].y * fSize;
        int nBlocks = vecNumBlocks[i];

        float COffset = 3.0f;

        sf::FloatRect CRect = sf::FloatRect(fX + COffset, fY + COffset, fSize - COffset, 0.1f);
        Bound* pBound = new Bound("Top Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);
        
        CRect = sf::FloatRect(fX + COffset, fY + COffset, 0.1f, (fSize * nBlocks) - COffset);
        pBound = new Bound("Left Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);

        CRect = sf::FloatRect(fX + COffset, fY - COffset + (fSize * nBlocks), fSize - COffset, 0.1f);
        pBound = new Bound("Bottom Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);

        CRect = sf::FloatRect(fX + fSize - COffset, fY + COffset, 0.1f, (fSize * nBlocks) - COffset);
        pBound = new Bound("Right Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);
    }
}


void GameScene::createHorizontalWalls() {
    std::vector<sf::Vector2f> vecWallPoints = LayoutManager::getInstance()->getHorizontalWallPoints();
    std::vector<int> vecNumBlocks = LayoutManager::getInstance()->getHorizontalNumBlocks();
 
    float fSize = SCALE_SIZE * BLOCK_SIZE;

    for(int i = 0; i < vecWallPoints.size(); i++) {
        float fX = vecWallPoints[i].x * fSize;
        float fY = vecWallPoints[i].y * fSize;
        int nBlocks = vecNumBlocks[i];

        float fOffset = 3.0f;

        sf::FloatRect CRect = sf::FloatRect(fX + fOffset, fY + fOffset, (fSize * nBlocks) - fOffset, 0.1f);
        Bound* pBound = new Bound("Top Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);

        CRect = sf::FloatRect(fX + fOffset, fY + fOffset, 0.1f, fSize - fOffset);
        pBound = new Bound("Left Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);


        CRect = sf::FloatRect(fX + fOffset, fY + fSize - fOffset * 2, (fSize * nBlocks) - fOffset, 0.1f); 
        pBound = new Bound("Bottom Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);

        CRect = sf::FloatRect(fX + (fSize * nBlocks) - fOffset, fY + fOffset, 0.1f, fSize - fOffset);
        pBound = new Bound("Right Wall Bound", BoundType::WALL, CRect);
        this->registerObject(pBound);
        BoundManager::getInstance()->registerBound(pBound);
    }

}


void GameScene::createBackGround() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::GAME_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}

void GameScene::createBorders() {
    float fOffset = 100.0f;

    sf::FloatRect CRect = sf::FloatRect(0.0f, 0.0f - fOffset, SCREEN_WIDTH, fOffset);
    Bound* pBound = new Bound("Top Border", BoundType::BORDER, CRect);
    this->registerObject(pBound);
    BoundManager::getInstance()->registerBound(pBound);

    CRect = sf::FloatRect(0.0f - fOffset, 0.0f, fOffset, SCREEN_HEIGHT);
    pBound = new Bound("Left Border", BoundType::BORDER, CRect);
    this->registerObject(pBound);
    BoundManager::getInstance()->registerBound(pBound);

    CRect = sf::FloatRect(0.0f, SCREEN_HEIGHT, SCREEN_WIDTH, fOffset);
    pBound = new Bound("Bottom Border", BoundType::BORDER, CRect);
    this->registerObject(pBound);
    BoundManager::getInstance()->registerBound(pBound);

    CRect = sf::FloatRect(SCREEN_WIDTH, 0.0f, fOffset, SCREEN_HEIGHT);
    pBound = new Bound("Right Border", BoundType::BORDER, CRect);
    this->registerObject(pBound);
    BoundManager::getInstance()->registerBound(pBound); 
}


void GameScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
}

void GameScene::createEnemy() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ENEMY));
    Enemy* pEnemy = new Enemy("Enemy", pTexture);
    this->registerObject(pEnemy);
}

void GameScene::createPlayerObjectPools() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER_BULLET));
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    GameObjectPool* pBulletpool = new GameObjectPool(PoolTag::PLAYER_BULLET, 5, new PlayerBullet("Player Bullet", pTexture, pPlayer));
    pBulletpool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pBulletpool);
}

void GameScene::createEnemyObjectPools() {

}

