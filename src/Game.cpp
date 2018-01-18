#include "headers/Game.h"

namespace engine {
  Game* Game::gGame = NULL;
  engine::Level* Game::gLevel = NULL;
  Game::Game(const std::string title) {
    windowTitle = title;
    window.create(sf::VideoMode(800, 800), windowTitle);
    mUpdateRate(1.0f / 20.0f);
    gGame = this;
  }
  Game::~Game() {

  }

  void Game::GameLoop(void) {
    sf::Event event;

    sf::Clock anUpdateClock;

    anUpdateClock.restart();

    // When do we need to update next (in milliseconds)?
    sf::Int32 anUpdateNext = anUpdateClock.getElapsedTime().asMilliseconds();
    while (window.isOpen()) {
      window.clear();
      Uint32 anUpdates = 0;

      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        } else if (event.type == sf::Event::KeyPressed) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
          }
        }
      }
      sf::Int32 anUpdateTime = anUpdateClock.getElapsedTime().asMilliseconds();
      if (gLevel != NULL) {
        while((anUpdateTime - anUpdateNext) >= mUpdateRate && anUpdates++ < 5) {
          for (engine::GameObject* gm : gLevel->getGameObjects()) {
            gm->fixedUpdate();
          }
        }
      }
      // window.draw(shape);
      window.display();
    }
  }

  engine::Level* Game::GetLevel(void) {
    return gLevel;
  }

  Game* Game::GetGame(void) {
    return gGame;
  }
  void Game::SetLevel(engine::Level* level) {
    gLevel = level;
  }
}
