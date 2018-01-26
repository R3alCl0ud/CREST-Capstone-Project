#ifndef ENGINE_TYPES
#define ENGINE_TYPES 1

// includes
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <list>
#include "Space.hpp"

namespace engine {

  // using things
  using namespace std;

  // forward declarations
  class Game;
  class GameObject;
  class Level;
  class Collider2D;
  class Physics2D;
  class RectangleCollider2D;

  // typedefs
  typedef std::list<GameObject*> GameObjectList;

}

#endif
