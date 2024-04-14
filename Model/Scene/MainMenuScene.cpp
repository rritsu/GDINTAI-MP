#include "MainMenuScene.hpp"
using namespace scenes;

MainMenuScene::MainMenuScene() : Scene(SceneTag::MAIN_MENU_SCENE) {}

void MainMenuScene::onLoadResources() {
   TextureManager::getInstance()->loadMainMenu();
}

void MainMenuScene::onLoadObjects() {
   this->createBackground();
   this->createSelector();
}

void MainMenuScene::onUnloadResources() {
   TextureManager::getInstance()->unloadAll();
}


void MainMenuScene::createSelector() {
   AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MAIN_MENU_SELECTOR));
   Selector* pSelector = new Selector("Selector", pTexture);
   this->registerObject(pSelector);
}

void MainMenuScene::createBackground() {
   AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MAIN_MENU_BACKGROUND));
   Background* pBackground = new Background("Background", pTexture);
   this->registerObject(pBackground);
}