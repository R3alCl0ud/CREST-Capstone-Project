#include <SFML/Graphics.hpp>
#include "headers/Level.h"

namespace engine {
    Level::Level() {
      this->gameObjects = (GameObject*)calloc(100, sizeof(GameObject*));
      this->view = sf::View();
    }

    Level::~Level() {
      delete this->gameObjects;
    }

    GameObject* Level::getGameObjects() {
      return this->gameObjects;
    }

    void Level::addGameObject(engine::GameObject* gameObject) {
      // something something darkside
    }

    void Level::draw() {

    }
    sf::View Level::getView() {
      return this->view;
    }

}
