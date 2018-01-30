#include "headers/Physics2D.hpp"

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
  Physics2D::~Physics2D() {
    try {
      delete &this->x;
      delete &this->y;
      delete &this->_dx;
      delete &this->_dy;
      delete &this->velocity;
      delete &this->precision;
    } catch (std::exception e) {
      std::cout << "Couldn't delete PHYSICS values" << std::endl;
    }
  }

  Physics2D::Physics2D() {
    this->x = 0;
    this->y = 0;
    this->_dx = 0;
    this->_dy = 0;
    this->velocity = sf::Vector2f();
    this->precision = 10;
  }

  // Use this when there is an initial velocity on the object
  Physics2D::Physics2D(float dx, float dy) {
    this->x = 0;
    this->y = 0;
    this->_dx = dx;
    this->_dy = dy;
    this->velocity = sf::Vector2f();
    this->precision = 10;
  }

  void Physics2D::addForce(sf::Vector2f *pos, engine::Space space) {
    if (space == engine::World) {
      this->velocity.x += pos->x;
      this->velocity.y += pos->y;
    } else {
      // this
    }
  }

  void Physics2D::setPrecision(int p) {
    this->precision = p;
  }

  float Physics2D::deltaX() { return this->_dx; }
  float Physics2D::deltaY() { return this->_dy; }

  double Physics2D::integral(double(*f)(double x), double a, double b, int n) {
    double step = (b - a) / n;  // Creates width of each rectangle
    double area = 0.0; // signed
    for (int i = 0; i < n; i++) {
      area += f(a + (i + 0.5) * step) * step; // Sum of each rectangle
    }

    return area;
  }

  /* Returns new velocity, for jump to work properly re-draw after calling
  * then call the function again with the same initial velocity, only changing
  * the time variable */
  // https://www.desmos.com/calculator/myun2fov50 Parabolic physics
  double Physics2D::jump(double initVelocity, double ntime, double mass) {
    double coef = initVelocity / mass;
    double numerator = (ntime + sqrt(2));
    return 0.0;
  }

// private:
  int precision = 10; // Default precision
  double velocity = 0.0;

  // Returns new velocity at given moment given the total mass
  double Physics2D::instantInertia(sf::Vector2f &pos, double startPos, double mass, double initVelocity, double deltaTime) {
    double input = ((double)pos.x / 75.0) - (startPos + mass) ;
    double intPart = this->integral(*normalCurve, 0.0, (input * sqrt(2) / (2 * mass)), this->precision);
    return ((intPart * ((-2 * deltaTime) * sqrt(PI / 2))) + (1 / 2)) / initVelocity;
  }
}
