#ifndef PHYSICS
#define PHYSICS 1
#include <SFML/Graphics/Shape.hpp>

struct Material;
struct MassData;
struct Body {
  sf::Shape* shape;
  Material material;
  MassData mass_data;
  sf::Vector2f velocity;
  sf::Vector2f force;
  double gravityScale;
};

struct MassData {
  float mass;
  float inv_mass;

};

struct Material {
  float density;
  float restitution;
};

#endif
