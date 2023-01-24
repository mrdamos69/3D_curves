#ifndef CURVES_H
#define CURVES_H

#define PI 3.14159265358979323846;

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

class Curve {
 public:
  virtual std::pair<double, double> Point(double value) = 0;
  virtual std::pair<double, double> Derivative(double value) = 0;
};

class Circle : public Curve {
 public:
  Circle(double radius) : radius_(radius) {}
  std::pair<double, double> Point(double value) override;
  std::pair<double, double> Derivative(double value) override;
  double getRadius() { return radius_; }

 private:
  double radius_;
};

class Ellipse : public Curve {
 public:
  Ellipse(double a, double b) : a_(a), b_(b) {}
  std::pair<double, double> Point(double value) override;
  std::pair<double, double> Derivative(double value) override;
 private:
  double a_, b_;
};

class Helix : public Curve {
 public:
  Helix(double a, double b, double c) : a_(a), b_(b), c_(c) {}
  std::pair<double, double> Point(double value) override;
  std::pair<double, double> Derivative(double value) override;
 private:
  double a_, b_, c_;
};

#endif  // CURVES_H
