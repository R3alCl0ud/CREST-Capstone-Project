#ifndef GAMEOBJECT
#define GAMEOBJECT 1

#include <SFML/Graphics.hpp>
#include "Physics2D.h"

namespace engine {

  class GameObject {
    public:
      GameObject();
      virtual ~GameObject();
      void update();
      void start();
      engine::Physics2D getPhysics();
      sf::Vector2f getPosition();
      void setPosition();
      float getRotation();
      float getRotationAsDeg();
      void setRotation(float angle);
      void setRotationAsDeg(float angle);
      void rotateAsDeg(float angle);
      void rotate(float);
    private:
      sf::Vector2f position;
      engine::Physics2D physics2D;
      float rotation;
  };
}
#endif
