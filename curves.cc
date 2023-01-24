#include "curves.h"

std::pair<double, double> Circle::Point(double value) {
  double x = radius_ * cos(value);
  double y = radius_ * sin(value);
  return std::make_pair(x, y);
}

std::pair<double, double> Circle::Derivative(double value) {
  double dx = -radius_ * sin(value);
  double dy = radius_ * cos(value);
  return std::make_pair(dx, dy);
}

std::pair<double, double> Ellipse::Point(double value) {
  double x = a_ * cos(value);
  double y = b_ * sin(value);
  return std::make_pair(x, y);
}

std::pair<double, double> Ellipse::Derivative(double value) {
  double dx = -a_ * sin(value);
  double dy = b_ * cos(value);
  return std::make_pair(dx, dy);
}

std::pair<double, double> Helix::Point(double value) {
  double x = a_ * cos(value);
  double y = b_ * sin(value);
  double z = c_ * cos(value);
  return std::make_pair(x, y);
}

std::pair<double, double> Helix::Derivative(double value) {
  double dx = -a_ * sin(value);
  double dy = b_ * cos(value);
  double dz = c_ * sin(value);
  return std::make_pair(dx, dy);
}

std::vector<Circle*> getCircles(std::vector<Curve*>& curves) {
  std::vector<Circle*> circles;
  for (auto& curve : curves) {
    Circle* circle = dynamic_cast<Circle*>(curve);
    if (circle != nullptr) {
      circles.push_back(circle);
    }
  }
  return circles;
}

void sortCircles(std::vector<Circle*>& circles) {
std::sort(circles.begin(), circles.end(), [](Circle* c1, Circle* c2) {
  return c1->getRadius() < c2->getRadius();
});
}

double sumRadii(std::vector<Circle*>& circles) {
  double sum = 0;
  for(auto circle : circles) {
    sum += circle->getRadius();
  }
  return sum;
}
