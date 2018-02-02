#ifndef GAME
#define GAME 1

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Level.hpp"
#include "Types.hpp"
#include "RectangleCollider2D.hpp"
#include "CircleCollider2D.hpp"
#include "PolygonCollider2D.hpp"
#include <string.h>

namespace engine {
  class Game {
  public:
    std::string mWindowTitle;
    sf::RenderWindow mWindow;


    Game(const std::string title = "Game");
    virtual ~Game();
    static Game* GetGame(void);
    static Level* GetLevel(void);
    static GameObjectList GetGameObjects(void);
    /**
     * Returns the time since the last frame was drawn
     */
    static float DeltaTime(void);
    /**
     * Returns the time since the last physics update
     */
    static float DeltaPhysicsTime(void);
    static sf::Uint16 GetPixelMeters(void);

    static void SetLevel(engine::Level* level);
    int run(void);
  protected:
    void GameLoop(void);
    void RunPhysicsUpdates(void);
  private:
    float mUpdateRate;
    int mMaxUpdates;
    int mMaxPhysicsUpdates;
    float mPhysicsUpdateRate;
    static sf::Uint16 gPixelMeters;
    static sf::Clock gFrameClock;
    static sf::Clock gPhysicsClock;
    static Game* gGame;
    static engine::Level* gLevel;
    static GameObjectList gObjects;
  };
}

#endif
