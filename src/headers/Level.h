#ifndef LEVEL
#define LEVEL 1
#include <SFML/Graphics.hpp>
namespace engine {
  // int CurLevel = 0;
  class GameObject;
  class Level {
    public:
      Level();
      virtual ~Level();
      virtual GameObject* getGameObjects();
      virtual sf::View getView();
      virtual void addGameObject(GameObject gameObject);
    private:
      GameObject* gameObjects;
      sf::View view;
  };
  Level* curLevel = 0x0;
}
#endif
