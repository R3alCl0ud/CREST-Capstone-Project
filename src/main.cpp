#include <SFML/Graphics.hpp>
#include "headers/Game.hpp"
#include "headers/Level.hpp"
#include "headers/Player.hpp"
#include "headers/Types.hpp"
#include "headers/RectangleCollider2D.hpp"

class Platform : public engine::GameObject {
  public:
    engine::RectangleCollider2D* mRect;
    Platform() {
      mRect = new engine::RectangleCollider2D(this);
      // rect->setSize(sf::Vector2f(2000, 100));
      shape.setOutlineColor(sf::Color(150,150,150));
      shape.setOutlineThickness(-10.0f);
      this->collider2D = mRect;
    }
    void setSize(float width, float height) {
      shape.setSize(sf::Vector2f(width, height));
      shape.setOrigin(width / 2, height / 2);
      mRect->setSize(sf::Vector2f(width, height));
    }
};

class TestLevel : public engine::Level {
  public:
    TestLevel() {
      engine::Player* player = new engine::Player;
      Platform* plat = new Platform;
      plat->setSize(2000, 100);
      plat->setPosition(0, 124.5f);
      addGameObject(player);
      addGameObject(plat);
    }
};

int main() {
  engine::Game game("A Terrible Physics Simulation");

  TestLevel tl = TestLevel();

  return game.run();
}
