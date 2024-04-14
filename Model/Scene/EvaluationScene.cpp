#include "EvaluationScene.hpp"

using namespace scenes;

EvaluationScene::EvaluationScene() : Scene(SceneTag::EVALUATION_SCENE) {}

void EvaluationScene::onLoadResources() {
    TextureManager::getInstance()->loadEvaluation();
}

void EvaluationScene::onLoadObjects() {
    this->createEvaluationScreen();
}

void EvaluationScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void EvaluationScene::createEvaluationScreen() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::EVALUATION_BACKGROUND));
    EvaluationScreen* pEvaluationScreen = new EvaluationScreen("Evaluation Screen", pTexture);
    this->registerObject(pEvaluationScreen);
}
