#ifndef CHAR_N
#define CHAR_N  1
// Include Physics lib
#include "Physics2D.h"
#include <SFML/Sprite.hpp>

namespace engine {
  class Char:GameObject {
  public:
    void changePosition(const sf::Vector2f &npos);
    double deltaX();
    double deltaY();

    // Load sprite texture from loadFromFile
    /**
    * @author Zachary Waldron
    * @param FNAME
    * @desc Loads PNG file into the sprite texture
    */
    void loadFromFile(char* FNAME) {
      this->tex.loadFromFile(FNAME);
      this->sprite.setTexture(texture)
    }

    Char();
    ~Char();

    Char(sf::IntRect bounds);
    Char(sf::IntRect bounds, sf::Color color);

    void setColor(sf::Color color);
    void setPosition(const sf::Vector2f &pos);

    void setScale(const sf::Vector2f &scale) {
      this->sprite.setScale(scale.x, scale.y);
    }

    void dynChange() {
      sf::Vector2f chng(this.pos.x + deltaX(), this.pos.y + deltaY());
    }
  private:
      // Initialize to position (0, 0)
      sf::Vector2f pos(0.0, 0.0);
      sf::Texture tex;
      sf::Sprite sprite;


      Physics2D p2d = new Physics2D();
      double initialVelocity = 0.0;

      int width = 0;

  };
}
#endif
