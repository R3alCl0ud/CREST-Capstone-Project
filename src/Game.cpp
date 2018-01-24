#include "headers/Game.hpp"

#include <stdlib.h>
#include <algorithm>
#include <list>
#include <iostream>

namespace engine {
  Game* Game::gGame = NULL;
  engine::Level* Game::gLevel = NULL;
  engine::GameObjectList Game::gObjects = engine::GameObjectList();
  Game::Game(const std::string title) {
    mWindowTitle = title;
    mWindow.create(sf::VideoMode(800, 800), mWindowTitle);
    mUpdateRate = 1.0f / 20.0f;
    gGame = this;
  }

  Game::~Game() {

  }

  int Game::run(void) {
    this->GameLoop();
    return 0;
  }

  void Game::GameLoop(void) {
    bool lc = false;
    sf::Event event;

    sf::Clock anUpdateClock;

    anUpdateClock.restart();

    // When do we need to update next (in milliseconds)?
    sf::Int32 anUpdateNext = anUpdateClock.getElapsedTime().asMilliseconds();
    while (mWindow.isOpen()) {
      mWindow.clear();
      sf::Uint32 anUpdates = 0;

      while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          mWindow.close();
        } else if (event.type == sf::Event::KeyPressed) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            mWindow.close();
          }
        }
      }
      sf::Int32 anUpdateTime = anUpdateClock.getElapsedTime().asMilliseconds();
      if (gLevel != NULL) {
        GameObjectList gObjs = gLevel->getGameObjects();
        if (!lc){
          printf("Running all level things\n");
          lc = true;
        }
        while((anUpdateTime - anUpdateNext) >= mUpdateRate && anUpdates++ < 5) {
          for (engine::GameObject* gm : gObjs) {
            printf("Fixed Updating GM\n");
            gm->fixedUpdate();
            gm->sprite.setPosition(gm->getPosition());
            gm->shape.setPosition(gm->getPosition());
            // gm->text->setPosition(gm->getPosition());
          }
          anUpdateNext += mUpdateRate;
        }
        // for (engine::GameObject* gm : gObjs)

        for (engine::GameObject* gm : gObjs) {
          // try {
          //   engine::GameObject* gm = (engine::GameObject*) vgm;
            printf("Updating gameobject\n");
            gm->update();
            printf("Drawing gameobject\n");
            gm->draw(mWindow);
          //
          //   continue;
          // } catch (std::exception) {
          //
          // }


        }
      }
      // window.draw(shape);
      mWindow.display();
    }
  }

  engine::Level* Game::GetLevel(void) {
    return gLevel;
  }

  Game* Game::GetGame(void) {
    return gGame;
  }

  GameObjectList Game::GetGameObjects(void) {
    return gObjects;
  }

  void Game::SetLevel(engine::Level* level) {
    gLevel = level;
    // gObjects = level->getGameObjects();
  }
}
