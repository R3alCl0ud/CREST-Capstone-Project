#ifndef GAME
#define GAME 1

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Level.hpp"
#include "Types.hpp"
#include <string.h>

namespace engine {
  class Game {
  public:
    std::string mWindowTitle;
    sf::RenderWindow mWindow;
    sf::Uint16 mPixelMeters;

    Game(const std::string title = "Game");
    virtual ~Game();
    static Game* GetGame(void);
    static Level* GetLevel(void);
    static void SetLevel(engine::Level* level);
    static GameObjectList GetGameObjects(void);
    /**
     * Returns the time since the last frame was drawn
     */
    static float DeltaTime(void);
    /**
     * Returns the time since the last physics update
     */
    static float DeltaPhysicsTime(void);
    int run(void);
  protected:
    void GameLoop(void);
    void RunPhysicsUpdates(void);
  private:
    float mUpdateRate;
    int mMaxUpdates;
    int mMaxPhysicsUpdates;
    float mPhysicsUpdateRate;
    static sf::Clock gFrameClock;
    static sf::Clock gPhysicsClock;
    static Game* gGame;
    static engine::Level* gLevel;
    static GameObjectList gObjects;
  };
}

#endif
