#include <SFML/Graphics.hpp>
#include "headers/Level.hpp"
#include "headers/Game.hpp"

namespace engine {

    Level::Level() {
      this->view = sf::View();
      engine::Game::SetLevel(this);
    }

    Level::~Level() {
       this->gameObjects.~GameObjectList();
    }

    GameObjectList Level::getGameObjects() {
      return this->gameObjects;
    }

    void Level::addGameObject(engine::GameObject* gameObject) {
      // something something darkside
      printf("adding gameobject\n");
      this->gameObjects.push_back(gameObject);
      gameObject->setLevel(this);
      engine::Game::GetGameObjects().push_back(gameObject);
      gameObject->start();
    }

    void Level::removeGameObject(engine::GameObject* gameObject) {
      this->gameObjects.remove(gameObject);
      engine::Game::GetGameObjects().remove(gameObject);
    }

    void Level::draw() {

    }

    sf::View Level::getView() {
      return this->view;
    }
}
