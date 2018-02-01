#include "headers/RectangleCollider2D.hpp"


namespace engine {


  RectangleCollider2D::RectangleCollider2D() : size(0,0) {

  }

  RectangleCollider2D::RectangleCollider2D(engine::GameObject* gameObject) : size(0,0) {
    this->gameObject = gameObject;
  }

  RectangleCollider2D::~RectangleCollider2D() {

  }
  bool RectangleCollider2D::intersects(Collider2D collider2D) {
    printf("rc2d\n");
    if (typeid(collider2D) == typeid(RectangleCollider2D)) return intersects(*dynamic_cast<RectangleCollider2D*>(&collider2D));

    return false;
  }

  bool RectangleCollider2D::intersects(RectangleCollider2D rectColl2D) {
    sf::Vector2f dist = rectColl2D.gameObject->getPosition() - gameObject->getPosition();
    if (dist.x < 0) dist.x *= -1;
    if (dist.y < 0) dist.y *= -1;
    if (dist.x > (size.x + rectColl2D.size.x) / 2 || dist.y > (size.y + rectColl2D.size.y) / 2) {
      return false;
    }

    return true;
  }

  void RectangleCollider2D::setSize(sf::Vector2f size) {
    this->size = size;
  }

  void RectangleCollider2D::setSize(float width, float height) {
    setSize(sf::Vector2f(width, height));
  }
}
