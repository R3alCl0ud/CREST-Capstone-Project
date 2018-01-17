#ifndef LEVEL
#define LEVEL 1
#include <SFML/Graphics.hpp>
#include "Types.h"
#include <stdlib.h>
#include <algorithm>
#include <list>

namespace engine {
  class Level {
    public:
      Level();
      virtual ~Level();
      virtual std::list<engine::GameObject*> getGameObjects();
      virtual sf::View getView();
      virtual void addGameObject(engine::GameObject* gameObject);
      virtual void draw();
      Level static *currentLevel;
    private:
      std::list<engine::GameObject*> gameObjects;
      // GameObject* gameObjects;
      sf::View view;
  };
  // Level* curLevel = 0x0;
}
#endif
