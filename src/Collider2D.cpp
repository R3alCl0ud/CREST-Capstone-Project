#include "headers/Collider2D.hpp"

namespace engine {

  Collider2D::Collider2D() : collisions(), min(0,0), max(0,0) {

  }
  Collider2D::Collider2D(sf::Vector2f min, sf::Vector2f max) : collisions() {
    this->min = sf::Vector2f(-min.x, min.y);
    this->max = sf::Vector2f(max.x, -max.y);
  }

  Collider2D::Collider2D(engine::GameObject* gameObject) : collisions(), min(0,0), max(0,0) {
    this->gameObject = gameObject;
  }

  Collider2D::~Collider2D() {

  }

  bool Collider2D::intersects(engine::CircleCollider2D* circleColl2D) {
    return false;
  }

  bool Collider2D::intersects(engine::PolygonCollider2D* polygonColl2D){
    return false;
  }

  bool Collider2D::intersects(engine::Collider2D* collider2D) {

    sf::Vector2f mMin = getMin(),
      mMax = getMax(),
      oMin = collider2D->getMin(),
      oMax = collider2D->getMax();
    if (mMax.x < oMin.x || mMin.x > oMax.x) return false;
    if (mMax.y < oMin.y || mMin.y > oMax.y) return false;

    // No separating axis found, therefor there is at least one overlapping axis
    return true;
  }

  bool Collider2D::intersects(engine::RectangleCollider2D* rectangleColl2D) {
    return false;
  }

  engine::Collider2DList Collider2D::getCollisions(void) {
    return collisions;
  }

  void Collider2D::addCollision(Collider2D* collider2D) {
    collisions.push_back(collider2D);
  }

  void Collider2D::removeCollision(Collider2D* collider2D) {
    collisions.remove(collider2D);
  }

  bool Collider2D::hasCollision(Collider2D* collider2D) {
    for (Collider2D* coll2d : collisions) {
      if (coll2d == collider2D) return true;
    }
    return false;
  }

  sf::Vector2f Collider2D::getMin() {
    return min + gameObject->getPosition();
  }
  sf::Vector2f Collider2D::getMax() {
    return max + gameObject->getPosition();
  }
  engine::GameObject* Collider2D::getGameObject(void) {
    return gameObject;
  }

}
