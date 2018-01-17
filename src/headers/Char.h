#ifndef CHAR_N
#define CHAR_N  1
// Include Physics lib
#include "Physics2D.h"

class {
public:
  void changePosition(const sf::Vector2f &npos);
  double deltaX();
  double deltaY();

  void dynChange() {
    sf::Vector2f chng(this.pos.x + deltaX(), this.pos.y + deltaY());
  }
private:
    // Initialize to position (0, 0)
    sf::Vector2f pos(0.0, 0.0);

    Physics2D p2d = new Physics2D();

    int width = 0;

};

#endif
