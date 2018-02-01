#include "headers/Game.hpp"

#include <stdlib.h>
#include <algorithm>
#include <list>
#include <iostream>

namespace engine {
  Game* Game::gGame = NULL;
  engine::Level* Game::gLevel = NULL;
  engine::GameObjectList Game::gObjects = engine::GameObjectList();
  sf::Clock Game::gFrameClock = sf::Clock();
  sf::Clock Game::gPhysicsClock = sf::Clock();
  Game::Game(const std::string title) : mPixelMeters(25) {
    mWindowTitle = title;
    mWindow.create(sf::VideoMode(1920, 1080), mWindowTitle);
    mUpdateRate = 1.0f / 20.0f;
    mPhysicsUpdateRate = 1.0f / 500.0f;
    mMaxUpdates = 5;
    mMaxPhysicsUpdates = 500;
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
    bool collision = false;
    bool collisionDown = false;
    bool collisionUp = false;
    bool collisionRight = false;
    bool collisionLeft = false;
    sf::Event event;

    sf::Clock anUpdateClock;
    sf::Clock anPhysicsUpdateClock;
    sf::Clock anSecondCounter;

    anUpdateClock.restart();
    anPhysicsUpdateClock.restart();
    anSecondCounter.restart();
    // When do we need to update next (in milliseconds)?
    sf::Int32 anUpdateNext = anUpdateClock.getElapsedTime().asMilliseconds();
    sf::Int32 anPhysicsUpdateNext = anPhysicsUpdateClock.getElapsedTime().asMilliseconds();

    // run window loop
    sf::Uint32 frames = 0;
    while (mWindow.isOpen()) {
      mWindow.clear();
      sf::Uint32 anUpdates = 0;
      sf::Uint32 anPhysicsUpdates = 0;
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
      sf::Int32 anPhysicsUpdateTime = anPhysicsUpdateClock.getElapsedTime().asMilliseconds();

      if (gLevel != NULL) {
        GameObjectList gObjs = gLevel->getGameObjects();
        if (!lc){
          printf("Running all level things\n");
          lc = true;
        }
        // run physics updates
        while((anPhysicsUpdateTime - anPhysicsUpdateNext) >= mPhysicsUpdateRate  && anPhysicsUpdates++ < mMaxPhysicsUpdates) {
          gPhysicsClock.restart();
          for (engine::GameObject* gm : gObjs) {
            collision = false;
            collisionDown = false;
            collisionUp = false;
            collisionRight = false;
            collisionLeft = false;
            if (gm->getCollider2D() != NULL) {
              for (engine::GameObject* ogm : gObjs) {
                if (gm == ogm || !ogm->getCollider2D()) continue;
                collision = gm->getCollider2D()->intersects(*ogm->getCollider2D());
                collisionDown = collision && gm->getPosition().y < ogm->getPosition().y;
                collisionUp = collision && gm->getPosition().y > ogm->getPosition().y;
                collisionRight = collision && gm->getPosition().x < ogm->getPosition().x;
                collisionLeft = collision && gm->getPosition().x > ogm->getPosition().x;
                if (collision) {
                  gm->onCollision(ogm->getCollider2D());
                }
              }
            }
            engine::Physics2D* p2d = gm->getPhysics();
            if (!collisionDown) {
              if (p2d->hasGravity()) {
                  // printf("applying gravity\n");
                  p2d->addForce(sf::Vector2f(0.0f, (G_C * 2500 * DeltaPhysicsTime() )));
              }
              if (p2d->getVelocity().y > 0.0f) {
                gm->move(0.0f, p2d->deltaV().y * mPixelMeters);
              }
            }
            if (!collisionUp && p2d->getVelocity().y < 0) {
                gm->move(0.0f, p2d->deltaV().y  * mPixelMeters);
            }
            if (!collisionRight && p2d->getVelocity().x > 0) {
                gm->move(p2d->deltaV().x * mPixelMeters, 0.0f);

            }
            if (!collisionLeft && p2d->getVelocity().x < 0) {
                gm->move(p2d->deltaV().x * mPixelMeters, 0.0f);
            }
            if ((collisionDown && p2d->getVelocity().y > 0.0f) || (collisionUp && p2d->getVelocity().y < 0.0f)) {
              printf("reseting vertical velocity\n");
              p2d->addForce(sf::Vector2f(0, -1 * p2d->getVelocity().y));
            }
            if ((collisionRight && p2d->getVelocity().x > 0.0f) || (collisionLeft && p2d->getVelocity().x < 0.0f)) {
              printf("reseting horizontal velocity\n");
              p2d->addForce(sf::Vector2f(-1 * p2d->getVelocity().x, 0));
            }
          }
          // printf("DeltaPhysicsTime: %.32f\n", DeltaPhysicsTime());

        }
        // printf("P2d Updates: %d\n", anPhysicsUpdates);
        // run fixed updates
        while((anUpdateTime - anUpdateNext) >= mUpdateRate && anUpdates++ < mMaxUpdates) {
          for (engine::GameObject* gm : gObjs) {
            // printf("Fixed Updating GM\n");
            gm->fixedUpdate();
          }
          anUpdateNext += mUpdateRate;
        }

        // run before frame updates and then draw the new frame
        gFrameClock.restart();
        for (engine::GameObject* gm : gObjs) {
          // printf("Updating gameobject\n");
          gm->update();
          // printf("Updating gm drawable positions\n");
          gm->sprite.setPosition(gm->getPosition());
          gm->shape.setPosition(gm->getPosition());
          // printf("Drawing gameobject\n");
          gm->draw(mWindow);
        }

      }
      if (anSecondCounter.getElapsedTime().asSeconds() > 1) {
        anSecondCounter.restart();
        // printf("Velocity<%f, %f>\n", p2d->getVelocity().x, p2d->getVelocity().y);
        printf("FPS: %d\n", frames);
        printf("Physics speed: %f\n", DeltaPhysicsTime() * 205000);
        frames = 0;
      }
      mWindow.display();
      frames+=1;
    }
  }

  void Game::RunPhysicsUpdates(void) {

  }

  float Game::DeltaTime(void) {
    return gFrameClock.getElapsedTime().asSeconds();
  }

  float Game::DeltaPhysicsTime(void) {
    return gPhysicsClock.getElapsedTime().asSeconds();//.asMilliseconds() / 1000.0f;
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
