#include "headers/RectangleCollider2D.hpp"

namespace engine {


  RectangleCollider2D::RectangleCollider2D() : size(0,0) {

  }

  RectangleCollider2D::RectangleCollider2D(engine::GameObject* gameObject) : size(0,0) {
    this->gameObject = gameObject;
  }

  RectangleCollider2D::~RectangleCollider2D() {
    // this->gameObject = NULL;
  }

  bool RectangleCollider2D::intersects(RectangleCollider2D rectColl2D) {
    sf::Vector2f dist = rectColl2D.gameObject->getPosition() - gameObject->getPosition();
    if (dist.x < 0) dist.x *= -1;
    if (dist.y < 0) dist.y *= -1;
    if (dist.x > size.x || dist.y > size.y)
      return false;

    return true;
  }

  void RectangleCollider2D::setSize(sf::Vector2f size) {
    this->size = size;
  }

  void RectangleCollider2D::setSize(float width, float height) {
    setSize(sf::Vector2f(width, height));
  }
}
