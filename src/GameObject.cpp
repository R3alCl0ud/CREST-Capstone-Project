#include "headers/GameObject.h"

namespace engine {
  float GameObject::getRotation() {
    return this->rotation;
  }

  float GameObject::getRotationAsDeg() {
    return this->rotation * 180 / M_PI;
  }

  void GameObject::setRotation(float angle) {
    this->rotation = angle;
    this->rotation %= 2 * M_PI;
  }

  void GameObject::setRotation(float angle) {
    this->rotation = (angle % 360) * M_PI  / 180.0;
  }

  void GameObject::rotateAsDeg(float angle) {
    this->rotation += angle * M_PI / 180.0;
    this->rotation %= 2 * M_PI;
  }

  GameObject::GameObject() {
    this->position = sf::Vector2f(0, 0);
    this->physics2D = Physics2D(this);
    this->rotation = 0;
  }

  GameObject::~GameObject() {

  }

  void GameObject::update() {

  }

}
