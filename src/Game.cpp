#include "headers/Game.hpp"

#include <stdlib.h>
#include <algorithm>
#include <list>
#include <iostream>
#include <string>
#include <sstream>

namespace engine {
  Game* Game::gGame = NULL;
  engine::Level* Game::gLevel = NULL;
  engine::GameObjectList Game::gObjects = engine::GameObjectList();
  sf::Clock Game::gFrameClock = sf::Clock();
  sf::Clock Game::gPhysicsClock = sf::Clock();
  sf::Uint16 Game::gPixelMeters = 75;
  Game::Game(const std::string title)  {
    mWindowTitle = title;
    mWindow.create(sf::VideoMode(1920, 1080), mWindowTitle);
    mWindow.setFramerateLimit(60);
    mUpdateRate = 1.0f / 20.0f;
    mPhysicsUpdateRate = 1.0f / 300000.0f;
    mMaxUpdates = 5;
    mMaxPhysicsUpdates = 5000;
    gGame = this;
  }

  Game::~Game() {
    // mWindowTitle.~string();
    // gObjects.~GameObjectList();
    // gFrameClock.~Clock();
    // gPhysicsClock.~Clock();
    gGame = NULL;
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

    // game Stats
    int FPS = 0;
    sf::Uint32 frames = 0;
    sf::Font textFont;
    textFont.loadFromFile("src/fonts/arial.ttf");
    sf::Text textPS("FPS: ", textFont);
    // sf::Text textVel("Velocity: <0.0, 0.0>", textFont);
    // sf::Text textPos("Position: (0.0, 0.0)", textFont);
    textPS.setFont(textFont);
    textPS.setCharacterSize(64);
    textPS.setStyle(sf::Text::Bold);
    textPS.setFillColor(sf::Color::White);
    // textVel.setFont(textFont);
    // textVel.setCharacterSize(64);
    // textVel.setStyle(sf::Text::Bold);
    // textVel.setFillColor(sf::Color::White);
    // textPos.setFont(textFont);
    // textPos.setCharacterSize(64);
    // textPos.setStyle(sf::Text::Bold);
    // textPos.setFillColor(sf::Color::White);

    engine::RectangleCollider2D* rect2D = NULL;
    engine::CircleCollider2D* circle2D = NULL;
    engine::PolygonCollider2D* poly2D = NULL;

    // run window loop
    while (mWindow.isOpen()) {
      mWindow.clear(); // sf::Color::Green
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
          gPhysicsClock.restart(); // reset clock before loop resets or ends
          for (engine::GameObject* gm : gObjs) {
            collision = false;
            collisionDown = false;
            collisionUp = false;
            collisionRight = false;
            collisionLeft = false;
            rect2D = NULL;
            circle2D = NULL;
            poly2D = NULL;
            if (gm->getCollider2D() != NULL) {
              for (engine::GameObject* ogm : gObjs) {
                if (gm == ogm || !ogm->getCollider2D()) continue;
                if ((rect2D = dynamic_cast<engine::RectangleCollider2D*>(ogm->getCollider2D()))) collision = gm->getCollider2D()->intersects(rect2D);
                else if ((circle2D = dynamic_cast<engine::CircleCollider2D*>(ogm->getCollider2D()))) collision = gm->getCollider2D()->intersects(circle2D);
                else if ((poly2D = dynamic_cast<engine::PolygonCollider2D*>(ogm->getCollider2D()))) collision = gm->getCollider2D()->intersects(poly2D);
                else collision = gm->getCollider2D()->intersects(ogm->getCollider2D());
                collisionDown = collision && gm->getPosition().y < ogm->getPosition().y;
                collisionUp = collision && gm->getPosition().y > ogm->getPosition().y;
                collisionRight = collision && gm->getPosition().x < ogm->getPosition().x;
                collisionLeft = collision && gm->getPosition().x > ogm->getPosition().x;
                if (collision) {
                  gm->onCollision(ogm->getCollider2D());
                  if (rect2D) gm->onCollision(rect2D);
                  if (!gm->getCollider2D()->hasCollision(ogm->getCollider2D())) {
                    gm->onCollisionEnter(ogm->getCollider2D());
                    // if ()
                    gm->getCollider2D()->addCollision(ogm->getCollider2D());
                  }
                } else if (!collision && gm->getCollider2D()->hasCollision(ogm->getCollider2D())) {
                  gm->onCollisionExit(ogm->getCollider2D());
                  gm->getCollider2D()->removeCollision(ogm->getCollider2D());
                }
              }
            }
            engine::Physics2D* p2d = gm->getPhysics();
            sf::Vector2f velocity = p2d->getVelocity();
            if (!collisionDown) {
              if (p2d->hasGravity()) {
                  // printf("applying gravity\n");
                  p2d->addForce(sf::Vector2f(0.0f, (G_C * 2 * mPhysicsUpdateRate /*DeltaPhysicsTime()*/)));
              }
              velocity = p2d->getVelocity();
              if (velocity.y > 0.0f) {
                gm->move(0.0f, p2d->deltaV().y * gPixelMeters);
              }
            } else {
              if (velocity.x > 0.0f) {
                p2d->addForce(sf::Vector2f(-0.8f * (velocity.x) * DeltaPhysicsTime(), 0.0f)); // * DeltaPhysicsTime()
              }
              velocity = p2d->getVelocity();
              if (velocity.x < 0.0f) {
                p2d->addForce(sf::Vector2f(-0.8f * (velocity.x) * DeltaPhysicsTime(), 0.0f)); // * DeltaPhysicsTime()
              }
            }
            velocity = p2d->getVelocity();
            if (!collisionUp && velocity.y < 0) {
                gm->move(0.0f, p2d->deltaV().y * gPixelMeters);
            }
            if (!collisionRight && velocity.x > 0) {
                gm->move(p2d->deltaV().x * gPixelMeters, 0.0f);

            }
            if (!collisionLeft && velocity.x < 0) {
                gm->move(p2d->deltaV().x * gPixelMeters, 0.0f);
            }
            velocity = p2d->getVelocity();
            if (collisionDown && velocity.y > 0.0f) {
              // gm->move(0.0f, p2d->deltaV().y * -gPixelMeters);
              // printf("reseting vertical velocity\n");
              p2d->addForce(sf::Vector2f(0, -1 * velocity.y));
            }
            velocity = p2d->getVelocity();
            if  (collisionUp && velocity.y < 0.0f){
              p2d->addForce(sf::Vector2f(0, -1 * velocity.y));
            }
            velocity = p2d->getVelocity();
            if (collisionRight && velocity.x > 0.0f && !collisionDown && !collisionUp) {
              printf("reseting horizontal velocity\n");
              p2d->addForce(sf::Vector2f(-1 * velocity.x, 0));
            }
            velocity = p2d->getVelocity();
            if (collisionLeft && velocity.x < 0.0f && !collisionDown && !collisionUp) {
              printf("reseting horizontal velocity\n");
              p2d->addForce(sf::Vector2f(-1 * velocity.x, 0));
            }
          }

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

      if (anSecondCounter.getElapsedTime().asSeconds() > 0.25f) {
        // printf("Velocity<%f, %f>\n", p2d->getVelocity().x, p2d->getVelocity().y);
        printf("FPS: %d, DeltaTime: %f\n", FPS = frames * 4, DeltaTime());
        // printf("Physics speed: %f\n", DeltaPhysicsTime() * 205000);
        anSecondCounter.restart();
        frames = 0;
      }
      if (FPS == 0) FPS = 1.0f / DeltaTime();
      std::ostringstream tframes;
      tframes.precision(2);
      tframes.width(7);
      tframes << "FPS: " << std::fixed << FPS;
      textPS.setString(tframes.str());
      // textVel.setString("Velocity: <" + ());
      textPS.setPosition(mWindow.getView().getCenter() - sf::Vector2f(970, 500));
      // textVel.setPosition(mWindow.getView().getCenter() - sf::Vector2f(940, 430));
      // textPos.setPosition(mWindow.getView().getCenter() - sf::Vector2f(940, 360));
      mWindow.draw(textPS);
      // mWindow.draw(textVel);
      // mWindow.draw(textPos);
      mWindow.display();
      gFrameClock.restart(); // reset FrameClock as the last frame has just been drawn
      frames+=1;
    }
  }

  void Game::RunPhysicsUpdates(void) {

  }

  float Game::DeltaTime(void) {
    return gFrameClock.getElapsedTime().asSeconds();
  }

  float Game::DeltaPhysicsTime(void) {
    //return gPhysicsClock.getElapsedTime().asSeconds();//.asMilliseconds() / 1000.0f;
    return gGame->mPhysicsUpdateRate;
  }

  sf::Uint16 Game::GetPixelMeters(void) {
    return gPixelMeters;
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
