#include "Game.hpp"

using namespace controllers;

Game::Game() : CWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tank Battle") { 
    this->pView = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SCREEN_WIDTH , SCREEN_HEIGHT));

    SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new EvaluationScene());

    SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);
    
}

void Game::run() {
    sf::Clock CClock = sf::Clock();
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);
    sf::Time tTimeSinceLastUpdate = sf::Time::Zero;



    while (this->CWindow.isOpen()) {
        this->processEvents();
        tTimeSinceLastUpdate += CClock.restart();

        while(tTimeSinceLastUpdate > tTimePerFrame) {
            tTimeSinceLastUpdate -= tTimePerFrame;
            this->update(tTimePerFrame); 
        }

        SceneManager::getInstance()->checkLoadScene();
        this->render();
        

        if(SceneManager::getInstance()->getActiveSceneTag() == SceneTag::GAME_SCENE) {
            if(!TimerManager::getInstance()->getHasStarted()) {
                TimerManager::getInstance()->startTimer();
            }    

            sf::Time tTimer = TimerManager::getInstance()->getTimer();
            if(tTimer.asSeconds() >= 120 || ScoreManager::getInstance()->checkScore()) {  //if timer ran out or someone has already won
                //go to evaluation screen times up
                if(tTimer.asSeconds() >= 120) {
                    std::cout << std::endl << "Time's up!" << std::endl << std::endl;
                }
                SceneManager::getInstance()->loadScene(SceneTag::EVALUATION_SCENE);
            }
          
              
        }
    }

}

//listening to user's keyboard & mouse inputs
void Game::processEvents() {
    sf::Event CEvent;
    while (this->CWindow.pollEvent(CEvent)) {
        switch(CEvent.type){
            case sf::Event::Closed:
                this->CWindow.close();
                break;

            default:
                GameObjectManager::getInstance()->processEvents(CEvent);
                break;
        }
    }
}


//updates the screen based on user's input
void Game::update(sf::Time tDeltaTime) {
    GameObjectManager::getInstance()->update(tDeltaTime);    
}

//RENDER
void Game::render() {
    this->CWindow.clear();
    GameObjectManager::getInstance()->draw(&(this->CWindow));
    this->CWindow.display();
}
