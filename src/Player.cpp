#include "headers/Player.hpp"
#include "headers/Game.hpp"

namespace engine {
  // public functions:
  Player::Player() {
    // Create a default rectangle bounds
    this->bound = sf::IntRect(10, 10, 50, 30);
    // load default texture
    // loadFromFile("src/images/DiscLoader.png");

    // set bounds and color
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
    shape.setSize(sf::Vector2f(50, 125));
    shape.setOrigin(25, 62.5);
    RectangleCollider2D* rect = new engine::RectangleCollider2D(this);
    rect->setSize(sf::Vector2f(50, 125));
    this->collider2D = rect;
    physics2D.useGravity(true);
  }

  Player::Player(sf::IntRect bounds) {
    this->bound = bounds;
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
  }

  Player::Player(sf::IntRect bounds, sf::Color color) {
    this->bound = bounds;
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(color);
  }

  void Player::draw(sf::RenderTarget& target) {
    // printf("player draw\n");
    target.draw(this->shape);
  }

  // default deconstructor
  Player::~Player() {}

  void Player::start() {
    // this->physics2D.addForce(sf::Vector2f(0.2, 0));
  }

  void Player::fixedUpdate() {
    // printf("player fixed\n");
    // engine::Physics2D px = getPhysics();

    // this->move(this->physics2D.deltaV() * (float) 25);
  }

  void Player::onCollision(engine::RectangleCollider2D* collider2D) {
    // printf("Player collided with something\n");
  }

  void Player::update() {
    // physics2D.addForce(sf::Vector2f(0, G_C) * (float)engine::Game::DeltaTime());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      move(0.5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      move(0, -0.5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      move(-0.5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      move(0, 0.5);
    }
    engine::Game* g = engine::Game::GetGame();
    sf::View view = g->mWindow.getView();
    view.setCenter(this->getPosition());
    g->mWindow.setView(view);
  }

  void Player::setColor(sf::Color color) {
    this->sprite.setColor(color);
  }

  double Player::deltaX() {
    return (double) this->physics2D.deltaX();
  }

  double Player::deltaY() {
    return (double) this->physics2D.deltaY();
  }


}
