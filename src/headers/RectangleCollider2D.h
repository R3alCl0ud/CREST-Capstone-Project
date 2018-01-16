#include "Collider2D.h"
#ifndef RECTANGLE_COLLIDER_2D
#define RECTANGLE_COLLIDER_2D  1
// Write Code here
namespace engine {
  class RectangleCollider2D : Collider2D {
    public:
      bool intersects(RectangleCollider2D rectangleColl2D);

    private:

  };
}
#endif
