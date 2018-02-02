#ifndef COLLIDER_2D
#define COLLIDER_2D  1

// include stuff here
#include <SFML/System/Vector2.hpp>
#include "Types.hpp"
#include "GameObject.hpp"
// Write Code here
namespace engine {
  class Collider2D {
    public:
      Collider2D();
      Collider2D(sf::Vector2f min, sf::Vector2f max);
      Collider2D(engine::GameObject* gameObject);
      virtual ~Collider2D();
      // intersection checkers
      virtual bool intersects(Collider2D* collider2D);
      virtual bool intersects(engine::RectangleCollider2D* rectangleColl2D);
      virtual bool intersects(engine::CircleCollider2D* circleColl2D);
      virtual bool intersects(engine::PolygonCollider2D* polygonColl2D);

      bool hasCollision(Collider2D* collider2D);
      engine::Collider2DList getCollisions(void);

      void addCollision(engine::Collider2D* collider2D);
      void removeCollision(engine::Collider2D* collider2D);
      engine::GameObject* getGameObject(void);
    private:
      sf::Vector2f min, max;
      sf::Vector2f getMin();
      sf::Vector2f getMax();
    protected:
      engine::GameObject* gameObject;
      engine::Collider2DList collisions; // used to track the state of collisions
  };
}
#endif
