#ifndef RECTANGLE_COLLIDER_2D
#define RECTANGLE_COLLIDER_2D  1
#include "Collider2D.hpp"
// Write Code here
namespace engine {

  class RectangleCollider2D  {
    public:
      RectangleCollider2D(engine::GameObject* gameObject);
      virtual ~RectangleCollider2D();

      bool intersects(Collider2D collider2D);
      bool intersects(RectangleCollider2D rectangleColl2D);

      void setSize(sf::Vector2f size=sf::Vector2f(0,0));
      void setSize(float width, float height);

    private:
      RectangleCollider2D();
    
    protected:
      engine::GameObject* gameObject;
      sf::Vector2f size;
  };
}
#endif
