#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/SceneManager.cpp"
#include "Controller/Manager/PhysicsManager.cpp"
#include "Controller/Manager/BoundManager.cpp"
#include "Controller/Manager/LayoutManager.cpp"
#include "Controller/Manager/ScoreManager.cpp"
#include "Controller/Manager/TimerManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"
#include "Controller/Manager/ObjectPoolManager.cpp"

#include "Controller/Game.cpp"

#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"

#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Input/SelectorInput.cpp"
#include "Model/Component/Input/EvaluationInput.cpp"

#include "Model/Component/Renderer/Renderer.cpp"

#include "Model/Component/Script/PlayerMovement.cpp"
#include "Model/Component/Script/SelectorAction.cpp"
#include "Model/Component/Script/BulletMovement.cpp"
#include "Model/Component/Script/EvaluationScript.cpp"
#include "Model/Component/Script/EnemyBehavior.cpp"

#include "Model/Component/Physics/Collider.cpp"

#include "Model/Entity/Tile.cpp"
#include "Model/Entity/Background.cpp"
#include "Model/Entity/Bound.cpp"
#include "Model/Entity/Player.cpp"
#include "Model/Entity/Enemy.cpp"
#include "Model/Entity/Selector.cpp"
#include "Model/Entity/Base.cpp"
#include "Model/Entity/EvaluationScreen.cpp"

#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Entity/PlayerBullet.cpp"

#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/GameScene.cpp"
#include "Model/Scene/EvaluationScene.cpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/GameObject.cpp"
#include "Model/Scene.cpp"
#include "Model/EmptyGameObject.cpp"

int main() {
    Game CGame;
    CGame.run();
  
    return 0;
}