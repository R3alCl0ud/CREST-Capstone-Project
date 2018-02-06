#include <SFML/Graphics.hpp>

int main() {

  const float fps = 60.0f;
  const float dt = 1.0f / fps;
  float accumulator = 0.0f;
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Test");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  window.setFramerateLimit(60);
  sf::Clock gameClock= sf::Clock();
  float frameStart = gameClock.getElapsedTime().asSeconds();
  while (window.isOpen()) {
    const float currentTime = gameClock.restart().asSeconds();
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      // if (event.type == sf::Event::KeyEvent) {
      //   if (event.)
      // }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }
    accumulator += currentTime - frameStart;
    frameStart = currentTime;
    if (accumulator > 0.2f) {
      accumulator = 0.2f;
    }

    while(accumulator > dt) {
      accumulator -= dt;
    }

    const float alpha = accumulator / dt;

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
