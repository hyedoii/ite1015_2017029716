#include <iostream>

using namespace std;

struct Point{
    int x_, y_; //멤버변수
    bool used;
    
    Point() : x_(0), y_(0) { }
    Point(const Point& p) : x_(p.x_), y_(p.y_) { }
    explicit Point(int c) : x_(c), y_(c) { }
    Point(int x, int y) : x_(x), y_(y) { }
    Point operator-() { return Point(-1 * x_, -1 * y_); }
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);


