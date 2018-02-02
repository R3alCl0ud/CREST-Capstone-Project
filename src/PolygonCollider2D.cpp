#include "headers/PolygonCollider2D.hpp"
#include "headers/CircleCollider2D.hpp"

namespace engine {
  PolygonCollider2D::PolygonCollider2D() {

  }

  PolygonCollider2D::PolygonCollider2D(engine::GameObject* gameObject) {
    this->gameObject = gameObject;
  }

  PolygonCollider2D::~PolygonCollider2D() {

  }

  bool PolygonCollider2D::intersects(engine::Collider2D* collider2D) {
    // printf("%s\n", typeid(collider2D).name());
    // if (dynamic_cast<engine::RectangleCollider2D*>(collider2D)) return intersects(dynamic_cast<engine::RectangleCollider2D*>(collider2D));
    // if (dynamic_cast<engine::CircleCollider2D*>(collider2D)) return intersects(dynamic_cast<engine::CircleCollider2D*>(collider2D));
    // if (dynamic_cast<engine::PolygonCollider2D*>(collider2D)) return intersects(dynamic_cast<engine::PolygonCollider2D*>(collider2D));


    return false;
  }
  bool PolygonCollider2D::intersects(engine::CircleCollider2D* collider2D) {
    // float r = radius + collider2D->radius;
    // r *= r;
    // return r < (gameObject->getPosition().x + collider2D->gameObject->getPosition().x)^2 + (gameObject->getPosition().y + collider2D->gameObject->getPosition().y)^2;
    return false;
  }
  bool PolygonCollider2D::intersects(engine::RectangleCollider2D* collider2D) {return false;}
  bool PolygonCollider2D::intersects(engine::PolygonCollider2D* collider2D) {return false;}
}
