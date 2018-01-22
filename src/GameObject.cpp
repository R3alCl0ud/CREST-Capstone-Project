#include "headers/GameObject.h"

namespace engine {

  GameObject::GameObject() {
    this->position = sf::Vector2f(0, 0);
    this->physics2D = Physics2D(this);
    this->rotation = 0;
  }

  GameObject::~GameObject() {
    // this->getLevel()->removeGameObject(this);
  }

  float GameObject::getRotation() {
    return this->rotation;
  }

  float GameObject::getRotationAsDeg() {
    return this->rotation * 180 / M_PI;
  }

  void GameObject::setRotation(float angle) {
    this->rotation = angle;
    this->rotation = std::fmod(this->rotation, (2 * M_PI));
  }

  void GameObject::setPosition(float x, float y) {
    this->position = sf::Vector2f(x,y);
  }

  void GameObject::setPosition(sf::Vector2f position) {
    this->position = position;
  }
  // void GameObject::setRotation(float angle) {
  //   this->rotation = (angle % 360) * M_PI  / 180.0;
  // }

  void GameObject::rotateAsDeg(float angle) {
    this->rotation += angle * M_PI / 180.0;
    this->rotation = std::fmod(this->rotation, (2 * M_PI));
  }

  sf::Vector2f GameObject::getPosition() {
    return this->position;
  }

  void GameObject::update() {

  }

  void GameObject::fixedUpdate() {

  }
  void GameObject::start() {
    
  }

  engine::Level* GameObject::getLevel() {
    return this->curLevel;
  }

  void GameObject::setLevel(Level* level) {
    this->curLevel = level;
  }

}
