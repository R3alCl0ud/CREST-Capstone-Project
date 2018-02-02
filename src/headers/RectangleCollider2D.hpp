#ifndef RECTANGLE_COLLIDER_2D
#define RECTANGLE_COLLIDER_2D  1
#include "Collider2D.hpp"


// Write Code here
namespace engine {

  class RectangleCollider2D : public Collider2D {
    public:
      RectangleCollider2D(engine::GameObject* gameObject);
      virtual ~RectangleCollider2D();

      bool intersects(engine::Collider2D* collider2D);
      bool intersects(RectangleCollider2D* rectangleColl2D);
      bool intersects(engine::CircleCollider2D* circleColl2D);
      bool intersects(engine::PolygonCollider2D* polygonColl2D);

      void setSize(sf::Vector2f size=sf::Vector2f(0,0));
      void setSize(float width, float height);


    private:
      RectangleCollider2D();

    protected:
      // engine::GameObject* gameObject;
      sf::Vector2f size; // stores the width and the height of the rectangle


  };
}
#endif
