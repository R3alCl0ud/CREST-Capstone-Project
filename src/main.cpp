#include <SFML/Graphics.hpp>
#include "headers/GameObject.h"



int main() {
  sf::RenderWindow window(sf::VideoMode(800,800), "SFML Works!!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  printf("%lu\n",sizeof(engine::GameObject));
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
