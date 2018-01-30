#ifndef GAMEOBJECT
#define GAMEOBJECT 1

#include <SFML/Graphics.hpp>
#include "Physics2D.hpp"
#include "Collider2D.hpp"
namespace engine {
  class GameObject {
    public:

      sf::Sprite sprite;
      sf::RectangleShape shape;
      sf::Text* text;
      // sf::VertexArray vertices;

      GameObject();
      virtual ~GameObject();
      virtual void update();
      virtual void fixedUpdate();
      virtual void start();
      engine::Level* getLevel();
      sf::Vector2f getPosition();
      float getRotation();
      float getRotationAsDeg();
      engine::Physics2D getPhysics();
      void setLevel(Level* level);
      void setPosition(float x, float y);
      void setPosition(sf::Vector2f pos);
      void setRotation(float angle);
      void setRotationAsDeg(float angle);
      void rotateAsDeg(float angle);
      void rotate(float);
      void move(float x, float y);
      void move(sf::Vector2f pos);
      virtual void draw(sf::RenderTarget& target) {
        printf("gm draw\n");
        if (sprite.getTexture() != NULL) {
          target.draw(sprite);
          return;
        }
        target.draw(shape);
      }
    protected:
      sf::Vector2f position;
      engine::Physics2D physics2D;
      engine::Level* curLevel;
      float rotation;
      engine::Collider2D* collider2D;
    private:
  };
}
#endif
