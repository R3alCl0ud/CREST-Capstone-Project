#ifndef COLLIDER_2D
#define COLLIDER_2D  1

// include stuff here
#include <SFML/System/Vector2.hpp>
#include "Types.hpp"
#include "GameObject.hpp"
// Write Code here
namespace engine {
  class Collider2D {
    public:
      virtual ~Collider2D();
      virtual bool intersects(Collider2D collider2D);

    private:

    protected:
      engine::GameObject* gameObject;
  };
}
#endif
