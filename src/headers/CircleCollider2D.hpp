#ifndef CIRCLE_COLLIDER_2D
#define CIRCLE_COLLIDER_2D 1

#include "Collider2D.hpp"
namespace engine {
  class CircleCollider2D : public engine::Collider2D {
  public:
    CircleCollider2D();
    CircleCollider2D(engine::GameObject* gameObject);
    virtual ~CircleCollider2D();

    bool intersects(engine::Collider2D* collider2D);
    bool intersects(engine::RectangleCollider2D* rectangleColl2D);
    bool intersects(engine::CircleCollider2D* circleColl2D);
    bool intersects(engine::PolygonCollider2D* polygonColl2D);

  private:
    float radius;
  };

}

#endif
