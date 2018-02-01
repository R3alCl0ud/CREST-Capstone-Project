#include "headers/GameObject.hpp"

namespace engine {

  GameObject::GameObject() : shape(sf::Vector2f(100, 50)) {
    this->position = sf::Vector2f(0, 0);
    this->physics2D = Physics2D(this);
    this->rotation = 0;
    // this->collider2D = NULL;
    // sf::RectangleShape rect(sf::Vector2f(100, 50));
    // shape.setSize(sf::Vector2f(100, 50));
    shape.setFillColor(sf::Color(255, 255, 255, 255));
    // this->shape = rect;
    // this->sprite = sf::Sprite();
    start();
  }

  GameObject::~GameObject() {
    // shape.~shape();
    //
    // this->getLevel()->removeGameObject(this);
  }

  float GameObject::getRotation() {
    return this->rotation;
  }

  float GameObject::getRotationAsDeg() {
    return this->rotation * 180 / M_PI;
  }

  engine::Physics2D* GameObject::getPhysics() {
    return &physics2D;
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

  void GameObject::move(float offsetX, float offsetY) {
    move(sf::Vector2f(offsetX, offsetY));
  }

  void GameObject::move(sf::Vector2f offset) {
    this->position += offset;
  }

  // void GameObject::draw(sf::RenderTarget& target) {
  //   printf("gm draw\n");
  //   target.draw(sprite);
  // }

  engine::Level* GameObject::getLevel() {
    return this->curLevel;
  }

  void GameObject::setLevel(Level* level) {
    this->curLevel = level;
  }
  engine::RectangleCollider2D* GameObject::getCollider2D() {
    return this->collider2D;
  }

}
