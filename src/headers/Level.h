#ifndef LEVEL
#define LEVEL 1
#include <SFML/Graphics.hpp>
#include "Types.h"
#include <stdlib.h>

namespace engine {
  class Level {
    public:
      Level();
      virtual ~Level();
      virtual GameObject* getGameObjects();
      virtual sf::View getView();
      virtual void addGameObject(GameObject* gameObject);
      virtual void draw();
    private:
      std::list<GameObject> gameObjects;
      // GameObject* gameObjects;
      sf::View view;
  };
  // Level* curLevel = 0x0;
}
#endif
