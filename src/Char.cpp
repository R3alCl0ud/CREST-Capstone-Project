#include "headers/Char.h"

namespace engine {
  // public functions:
  Char::Char() {
    // Create a default rectangle bounds
    this->bound = sf::IntRect(10, 10, 50, 30);
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
  }

  Char::Char(sf::IntRect bounds) {
    this->bound = bounds;
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
  }

  Char::Char(sf::IntRect bounds, sf::Color color) {
    this->bound = bounds;
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(color);
  }

  // default deconstructor
  Char::~Char() {}

  void Char::setColor(sf::Color color) {
    this->sprite.setColor(color);
  }

  double deltaX() {
    this->p2d.dx();
  }

  double deltaY() {
    this->p2d.dy();
  }
}
