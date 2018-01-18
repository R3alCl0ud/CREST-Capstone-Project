#ifndef GAME
#define GAME 1

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Types.h"
#include <string.h>

namespace engine {
  class Game {
  public:
    std::string windowTitle;
    sf::RenderWindow window;

    Game(const std::string title = "Game");
    virtual ~Game();
    static Game* GetGame(void);
    static Level* GetLevel(void);
    static void SetLevel(engine::Level* level);
  protected:
    void GameLoop(void);
  private:
    float mUpdateRate;

    static Game* gGame;
    static engine::Level* gLevel;
  };
}

#endif
