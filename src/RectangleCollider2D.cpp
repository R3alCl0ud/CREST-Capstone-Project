#include "headers/RectangleCollider2D.hpp"


namespace engine {


  RectangleCollider2D::RectangleCollider2D() : size(0, 0) {

  }

  RectangleCollider2D::RectangleCollider2D(engine::GameObject* gameObject) : size(0, 0) {
    this->gameObject = gameObject;
  }

  RectangleCollider2D::~RectangleCollider2D() {
    // delete collisions;
  }


  bool RectangleCollider2D::intersects(Collider2D* collider2D) {
    // printf("%s\n", typeid(collider2D).name());
    // if (dynamic_cast<engine::RectangleCollider2D*>(collider2D)) return intersects(dynamic_cast<engine::RectangleCollider2D*>(collider2D));
    // if (dynamic_cast<engine::CircleCollider2D*>(collider2D)) return intersects(dynamic_cast<engine::CircleCollider2D*>(collider2D));
    // if (dynamic_cast<engine::PolygonCollider2D*>(collider2D)) return intersects(dynamic_cast<engine::PolygonCollider2D*>(collider2D));

    return false;
  }

bool RectangleCollider2D::intersects(RectangleCollider2D* rectColl2D) {
  sf::Vector2f dist = rectColl2D->gameObject->getPosition() - gameObject->getPosition();
  if (dist.x < 0) dist.x *= -1;
  if (dist.y < 0) dist.y *= -1;
  if (dist.x > (size.x + rectColl2D->size.x) / 2 || dist.y > (size.y + rectColl2D->size.y) / 2) {
    return false;
  }
  if (rectColl2D->gameObject->getPosition().y > gameObject->getPosition().y) {
    gameObject->move(sf::Vector2f(0.0f, 1.0f * (dist.y - ((size.y + rectColl2D->size.y) / 2) )));
  }
  return true;
}

  bool RectangleCollider2D::intersects(engine::CircleCollider2D* circleColl2D) {
    return false;
  }

  bool RectangleCollider2D::intersects(engine::PolygonCollider2D* polygonColl2D){
    return false;
  }

  void RectangleCollider2D::setSize(sf::Vector2f size) {
    this->size = size;
  }

  void RectangleCollider2D::setSize(float width, float height) {
    setSize(sf::Vector2f(width, height));
  }
}
