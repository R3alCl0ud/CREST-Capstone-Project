#ifndef GAME
#define GAME 1

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Level.hpp"
#include "Types.hpp"
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
    static void SetLevel(engine::Level* level);
    static GameObjectList GetGameObjects(void);

    int run(void);
  protected:
    void GameLoop(void);
  private:
    float mUpdateRate;

    static Game* gGame;
    static engine::Level* gLevel;
    static GameObjectList gObjects;
  };
}

#endif
