#include "headers/GameObject.h"

namespace engine {
  GameObject::GameObject() {
    this->position = sf::Vector2f(0, 0);
    this->physics2D = engine::Physics2D();
    this->rotation = 0;
  }
  
  GameObject::~GameObject() {

  }

  void GameObject::update() {

  }

}
