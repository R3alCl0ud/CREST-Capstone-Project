#include <SFML/Graphics.hpp>
#include "headers/Level.h"

namespace engine {
    Level::Level() {
      this->view = sf::View();
    }

    Level::~Level() {
       this->gameObjects.~list<GameObject*>();
    }

    std::list<engine::GameObject*> Level::getGameObjects() {
      return this->gameObjects;
    }

    void Level::addGameObject(engine::GameObject* gameObject) {
      // something something darkside
      this->gameObjects.push_back(gameObject);
    }

    void Level::draw() {

    }
    sf::View Level::getView() {
      return this->view;
    }
    // Level* static Level::getCurrentLevel() {
    //   return _currentLevel;
    // }
    //
    // void static Level::setCurrentlLevel(Level* level) {
    //   _currentLevel = level;
    // }
}
