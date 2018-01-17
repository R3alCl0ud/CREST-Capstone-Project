
#ifndef PHYSICS_2D
#define PHYSICS_2D  1
#define PI  3.14159
#define E_C   2.71828182
#define G_C   9.80

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


// Write Code here https://www.desmos.com/calculator/jy47o2j2fx
namespace engine {
  using namespace std;

  class Physics2D {
    public:
      Physics2D();
      Physics2D(float dx, float dy);
      void addForce(sf::Vector2f *pos);
      void setPrecision(int p);
      double integral(double(*f)(double x), double a, double b, int n);

    private:
      double vh, vv, mass, gravity;
      sf::Vector2f velocity = sf::Vector2f();
      float x, y, dx, dy;
      int precision = 10;
      double static normalCurve(double t) {
        return std::pow(E_C, ((t * t) * -1));
      }
      double instantInertia(sf::Vector2f &pos, double startPos, double mass, double initVelocity);

    };
}

#endif
