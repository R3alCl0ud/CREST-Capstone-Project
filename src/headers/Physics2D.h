#include <SFML/Graphics.hpp>

#ifndef PHYSICS_2D
#define PHYSICS_2D  1
// Write Code here
class Physics2D {
  public:
    sf::Vector2f getPosition();
    void setPosition(const sf::Vector2f &pos=sf::Vector2f(0,0));
    void setPosition(float x, float y);
    void addForce(const sf::Vector3f &vector3f=sf::Vector3f(0,0,0));

  private:
};


#endif
