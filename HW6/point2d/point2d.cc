#include <iostream>
#include "point2d.h"

using namespace std;

Point operator+(const Point& lhs, const Point& rhs){
    Point result = *new Point(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
    return result;
}
Point operator-(const Point& lhs, const Point& rhs){
    Point result = *new Point(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
    return result;
}
Point operator*(const Point& lhs, const Point& rhs){
    Point result = *new Point(lhs.x_ * rhs.x_, lhs.y_ * rhs.y_);
    return result;
}
