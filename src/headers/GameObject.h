#include <SFML/Graphics.hpp>
#include "Physics2D.h"

#ifndef GAMEOBJECT
#define GAMEOBJECT 1
class GameObject {
public:
  GameObject() {
    this->position=sf::Vector2f(0,0);
  }
  void update();
  void start();
  Physics2D getPhysics();
  sf::Vector2f getPosition();
private:
  sf::Vector2f position;
};

#endif
