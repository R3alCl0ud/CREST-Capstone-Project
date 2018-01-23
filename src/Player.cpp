#include "headers/Player.hpp"
#include "headers/Game.hpp"

namespace engine {
  // public functions:
  Player::Player() {
    // Create a default rectangle bounds
    this->bound = sf::IntRect(10, 10, 50, 30);


    // load default texture
    this->loadFromFile("src/images/DiscLoader.png");

    // set bounds and color
    this->sprite.setTextureRect(this->bound);
    // this->sprite.setColor(sf::Color(255, 255, 255, 255));
    this->sprite.setPosition(0,0);


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

  // default deconstructor
  Player::~Player() {}

  void Player::update() {
    engine::Game* g = engine::Game::GetGame();
    sf::View view = g->window.getView();
    view.setCenter(this->getPosition());
    g->window.setView(view);
  }

  void Player::setColor(sf::Color color) {
    this->sprite.setColor(color);
  }

  double Player::deltaX() {
    return (double) this->physics2D.dx();
  }

  double Player::deltaY() {
    return (double) this->physics2D.dy();
  }

  void Player::start() {
    // this->loadFromFile("images/DiscLoader.png");
  }
}
