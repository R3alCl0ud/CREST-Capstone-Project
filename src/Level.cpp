#include "headers/Level.h"
#include <SFML/Graphics.hpp>

namespace engine {
    class GameObject;
    Level::Level() {
      gameObjects = calloc(100, 72);
      view = sf::View();
    }
    Level::~Level() {
      for (int i =0;gameObjects[i];i++) {
        delete gameObjects[i];
      }
    }
}
