#include <SFML/Graphics.hpp>
// #include "headers/GameObject.h"
#include "headers/Level.h"


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Works!!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(sf::Vector2f(0,0));
  printf("%lu\n",sizeof(engine::Level));
  engine::Level level;
  level = engine::Level();
  // level.getView().setCenter(200,200);
  // float vx = 0;
  level.getView().setSize(1000,1000);
  window.setView(level.getView());
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
        if (event.type==sf::Event::KeyPressed) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            level.getView().move(-100,-100);
            window.setView(level.getView());
          }
        }
    }
    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
