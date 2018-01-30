
#ifndef PHYSICS_2D
#define PHYSICS_2D  1
#define PI  3.14159
#define E_C   2.71828182
#define G_C   9.80

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include "Types.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <iostream>


// Write Code here https://www.desmos.com/calculator/jy47o2j2fx
namespace engine {
  using namespace std;

  class Physics2D {
    public:
      Physics2D();
      Physics2D(GameObject* parent);
      Physics2D(float dx, float dy);
      void addForce(sf::Vector2f *pos, engine::Space space=engine::World);
      void setPrecision(int p);
      double integral(double(*f)(double x), double a, double b, int n);
      float deltaX();
      float deltaY();
      double instantInertia(sf::Vector2f &pos, double startPos, double mass, double initVelocity, double deltaTime =  1);
      double jump(double initVelocity, double ntime, double mass);
    private:
      engine::GameObject* parent;
      double vh, vv, mass, gravity;
      sf::Vector2f velocity; // velocity in meters / second
      float x, y, _dx, _dy;
      int precision;
      double static normalCurve(double t) {
        return std::pow(E_C, ((t * t) * -1));
      }

    };
}

#endif
