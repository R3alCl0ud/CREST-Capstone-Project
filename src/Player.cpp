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
    shape.setSize(sf::Vector2f(50, 200));
    shape.setOrigin(25, 100);
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
    printf("player draw\n");
    target.draw(this->shape);
  }

  // default deconstructor
  Player::~Player() {}

  void Player::start() {
    // this->loadFromFile("images/DiscLoader.png");
  }

  void Player::fixedUpdate() {

  }

  void Player::update() {
    // physics2D.addForce(sf::Vector2f(0, G_C) * (float)engine::Game::DeltaTime());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      move(2, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      move(0, -2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      move(-2, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      move(0, 2);
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
