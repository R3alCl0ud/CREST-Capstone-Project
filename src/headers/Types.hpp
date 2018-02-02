#ifndef ENGINE_TYPES
#define ENGINE_TYPES 1

// includes
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <math.h>
#include "Space.hpp"
#include <SFML/System/Vector2.hpp>

namespace engine {

  // using things
  using namespace std;

  // forward declarations
  class Game;
  class GameObject;
  class Level;
  class Physics2D;
  class Collider2D;
  class CircleCollider2D;
  class RectangleCollider2D;
  class PolygonCollider2D;

  // typedefs
  typedef std::list<GameObject*> GameObjectList;
  typedef std::list<Collider2D*> Collider2DList;
  typedef std::list<RectangleCollider2D*> RectangleCollider2DList;
  typedef std::list<sf::Vector2f> Vector2fList;
}

#endif
