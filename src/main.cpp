#include <SFML/Graphics.hpp>
#include "headers/Game.hpp"
#include "headers/Level.hpp"
#include "headers/Player.hpp"
#include "headers/Types.hpp"
#include "headers/RectangleCollider2D.hpp"

class Platform : public engine::GameObject {
  public:
    Platform() {
      engine::RectangleCollider2D* rect = new engine::RectangleCollider2D(this);
      rect->setSize(sf::Vector2f(1000, 50));
      this->collider2D = rect;
    }
    void setSize(float width, float height) {
      shape.setSize(sf::Vector2f(width, height));
      shape.setOrigin(width / 2, height / 2);
    }
};

class TestLevel : public engine::Level {
  public:
    TestLevel() {
      engine::Player* player = new engine::Player;
      Platform* plat = new Platform;
      plat->setSize(1000, 50);
      plat->setPosition(0, 245);
      addGameObject(player);
      addGameObject(plat);
    }
};

int main() {
  engine::Game game("Testing Game");

  TestLevel tl = TestLevel();

  return game.run();
}
