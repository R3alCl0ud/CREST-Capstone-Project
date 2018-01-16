#include "headers/Physics2D.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define PI  3.14159
#define E   2.71828182

// Gravitational Constant
#define G 9.80
// https://www.desmos.com/calculator/5xew1bmpgo

// Inertia: https://www.desmos.com/calculator/dro8kssov6

using namespace std;

public:
void Physics2D::addForce(const sf::Vector3f &pos) {
  pos.x += cos(pos.z);
  pos.y += sin(pos.z);
}

void Physics2D::setPrecision(int p) this->precision = p;

double Physics2D::integral(double(*f)(double x), double a, double b, int n) {
  double step = (b - a) / n;  // Creates width of each rectangle
  double area = 0.0; // signed
  for (int i = 0; i < n; i++) {
    area += f(a + (i + 0.5) * step) * step; // Sum of each rectangle
  }

  return area;
}

private:
  int precision = 10; // Default precision
  double velocity = 0.0;
  double normalCurve(t) {
    return std::pow(E, ((t * t) * -1));
  }

  // Returns new velocity at given moment given the total mass
  double Physics2D::istantInertia(sf::Vector2f &pos, double startPos, double mass, double initVelocity) {
    double input = (double)pos.x - (startPos + mass) ;
    double intPart = this->integral(normalCurve, input, 0, (input * sqrt(2) / (2 * mass)), this->precision);
    return ((intPart * (-2 * sqrt(PI / 2))) + (1 / 2)) / initVelocity;
  }
