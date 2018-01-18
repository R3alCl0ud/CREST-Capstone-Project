#include <SFML/Graphics.hpp>
#include "headers/Level.h"


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Works!!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(sf::Vector2f(200,0));
  printf("%lu\n",sizeof(engine::Level));
  engine::Level curLevel = engine::Level();
  engine::Level* level = &curLevel;
  // level.getView().setCenter(200,200);
  // float vx = 0;
  level->getView().setSize(1000,1000);
  window.setView(level->getView());
  sf::Event event;
  while (window.isOpen()) {
    window.clear();
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type==sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          sf::View v = window.getView();
          v.move(-5,0);
          window.setView(v);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
          window.close();
        }
      }
    }
    window.draw(shape);
    window.display();
  }

  return 0;
}
