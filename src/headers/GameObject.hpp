#ifndef GAMEOBJECT
#define GAMEOBJECT 1

#include <SFML/Graphics.hpp>
#include "Physics2D.hpp"
// #include "Types.hpp"
#include "Collider2D.hpp"
// #include "RectangleCollider2D.hpp"
namespace engine {
  class GameObject {
    public:

      sf::Sprite sprite;
      sf::RectangleShape shape;
      sf::Text text;
      // sf::VertexArray vertices;

      GameObject();
      // virtual methods
      virtual ~GameObject();
      virtual void update();
      virtual void fixedUpdate();
      virtual void start();
      // default collider2Ds
      virtual void onCollision(engine::Collider2D* collider2D) { }
      virtual void onCollisionEnter(engine::Collider2D* collider2D) { }
      virtual void onCollisionExit(engine::Collider2D* collider2D) { }
      // RectangleCollider2Ds
      virtual void onCollision(engine::RectangleCollider2D* collider2D) { }
      virtual void onCollisionEnter(engine::RectangleCollider2D* collider2D) { }
      virtual void onCollisionExit(engine::RectangleCollider2D* collider2D) { }
      // CircleCollider2Ds
      virtual void onCollision(engine::CircleCollider2D* circleCollider2D) { }
      virtual void onCollisionEnter(engine::CircleCollider2D* circleCollider2D) { }
      virtual void onCollisionExit(engine::CircleCollider2D* circleCollider2D) { }
      // PolygonCollider2Ds
      virtual void onCollision(engine::PolygonCollider2D* polygonCollider2D) { }
      virtual void onCollisionEnter(engine::PolygonCollider2D* polygonCollider2D) { }
      virtual void onCollisionExit(engine::PolygonCollider2D* polygonCollider2D) { }

      virtual void draw(sf::RenderTarget& target) {
        // printf("gm draw\n");
        if (sprite.getTexture() != NULL) {
          target.draw(sprite);
          return;
        }
        target.draw(shape);
      }

      // getters
      engine::Level* getLevel();
      sf::Vector2f getPosition();
      float getRotation();
      float getRotationAsDeg();
      engine::Physics2D* getPhysics();
      engine::Collider2D* getCollider2D();

      // setters
      void setLevel(Level* level);
      void setPosition(float x, float y);
      void setPosition(sf::Vector2f pos);
      void setRotation(float angle);
      void setRotationAsDeg(float angle);

      // transformations
      void rotateAsDeg(float angle);
      void rotate(float);
      void move(float x, float y);
      void move(sf::Vector2f pos);

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
