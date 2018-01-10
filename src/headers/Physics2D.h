#include <SFML/Vector2f.h>
#include <SFML/Vector3f.h>

#ifndef PHYSICS_2D
#define PHYSICS_2D  1
// Write Code here
class Physics2D {
  public:
    sf:Vector2f getPosition();
    void setPosition(Vector2f &pos=Vector2f(0,0));
    void setPosition(float x, float y);
    void addForce(Vector3f &vector3f=Vector3f(0,0,0));

  private:
};


#endif
