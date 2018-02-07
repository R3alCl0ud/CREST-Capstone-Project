#ifndef PHYSICS
#define PHYSICS 1
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <math.h>
#include <SFML/Graphics/Shape.hpp>

struct Material;
struct MassData;

struct AABB {
  sf::Vector2f min;
  sf::Vector2f max;
};

struct Circle {
  float radius;
  sf::Vector2f position;
};



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

struct Pair {
  Body* A;
  Body* B;
};

typedef std::list<Pair> PairList;

float DotProduct(sf::Vector2f a, sf::Vector2f b);

bool AABBvsAABB(AABB a, AABB b) {
  // Exit with no intersection if found separated along an axis
  if(a.max.x < b.min.x || a.min.x > b.max.x) return false;
  if(a.max.y < b.min.y || a.min.y > b.max.y) return false;

  // No separating axis found, therefor there is at least one overlapping axis
  return true;
}

bool CirclevsCircle(Circle a, Circle b) {
  float r  = a.radius + b.radius;
  r *= r;
  return r < powf(a.position.x + b.position.x, 2) + powf(a.position.y + b.position.y, 2);
}


#endif
