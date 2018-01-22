#ifndef CHAR_N
#define CHAR_N  1
// Include Physics lib
#include "GameObject.h"
#include <string.h>
#include <SFML/Graphics/Sprite.hpp>

namespace engine {
  class Player : public engine::GameObject {
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
    void loadFromFile(std::string FNAME) {
      this->tex.loadFromFile(FNAME);
      this->sprite.setTexture(this->tex);
    }

    Player();
    ~Player();

    Player(sf::IntRect bounds);
    Player(sf::IntRect bounds, sf::Color color);

    void setColor(sf::Color color);
    // void setPosition(const sf::Vector2f &pos);

    void setScale(const sf::Vector2f &scale) {
      this->sprite.setScale(scale.x, scale.y);
    }

    void dynChange() {
      sf::Vector2f chng(getPosition().x + deltaX(), getPosition().y + deltaY());
    }
    void update();
    void start();
  private:
      // Initialize to position (0, 0)
      // sf::Vector2f pos();
      sf::Texture tex;
      sf::IntRect bound;
      // sf::Sprite sprite;

      double initialVelocity = 0.0;

      int width = 0;

  };
}
#endif
