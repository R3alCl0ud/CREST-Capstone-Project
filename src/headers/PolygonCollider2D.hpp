#ifndef POLYGON_COLLIDER_2D
#define POLYGON_COLLIDER_2D 1

#include "Collider2D.hpp"
namespace engine {
  class PolygonCollider2D : public engine::Collider2D {
    public:
      PolygonCollider2D();
      PolygonCollider2D(engine::GameObject* gameObject);
      virtual ~PolygonCollider2D();
      bool intersects(engine::Collider2D* collider2D);
      bool intersects(engine::RectangleCollider2D* rectangleColl2D);
      bool intersects(engine::CircleCollider2D* circleColl2D);
      bool intersects(engine::PolygonCollider2D* polygonColl2D);
  };

}

#endif
