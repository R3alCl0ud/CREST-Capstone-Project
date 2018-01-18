#include "headers/Physics2D.h"

namespace engine {

using namespace std;

Physics2D::Physics2D(engine::GameObject* parent) {
  this->parent = parent;
  this->velocity = sf::Vector2f();
  this->precision = 10;
}
// https://www.desmos.com/calculator/5xew1bmpgo

// Inertia: https://www.desmos.com/calculator/dro8kssov6

// using namespace std;

// public:
Physics2D::Physics2D() {
  this->x = 0;
  this->y = 0;
  this->dx = 0;
  this->dy = 0;
  this->velocity = sf::Vector2f();
  this->precision = 10;
}

// Use this when there is an initial velocity on the object
Physics2D::Physics2D(float dx, float dy) {
  this->x = 0;
  this->y = 0;
  this->dx = dx;
  this->dy = dy;
  this->velocity = sf::Vector2f();
  this->precision = 10;
}

void Physics2D::addForce(sf::Vector2f *pos) {
  this->velocity.x += pos->x;
  this->velocity.y += pos->y;
}

void Physics2D::setPrecision(int p) {
  this->precision = p;
}

double Physics2D::integral(double(*f)(double x), double a, double b, int n) {
  double step = (b - a) / n;  // Creates width of each rectangle
  double area = 0.0; // signed
  for (int i = 0; i < n; i++) {
    area += f(a + (i + 0.5) * step) * step; // Sum of each rectangle
  }

  return area;
}

// private:
  int precision = 10; // Default precision
  double velocity = 0.0;


  // Returns new velocity at given moment given the total mass
  double Physics2D::instantInertia(sf::Vector2f &pos, double startPos, double mass, double initVelocity) {
    double input = (double)pos.x - (startPos + mass) ;
    double intPart = this->integral(*normalCurve, 0.0, (input * sqrt(2) / (2 * mass)), this->precision);
    return ((intPart * (-2 * sqrt(PI / 2))) + (1 / 2)) / initVelocity;
  }
}
