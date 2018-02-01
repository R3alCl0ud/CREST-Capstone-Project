#include "headers/Collider2D.hpp"

namespace engine {

  Collider2D::Collider2D() {

  }

  Collider2D::Collider2D(engine::GameObject* gameObject) {
    this->gameObject = gameObject;
  }

  Collider2D::~Collider2D() {

  }

  bool Collider2D::intersects(Collider2D collider2D) {
    printf("c2d\n");
    return false;
  }

}
