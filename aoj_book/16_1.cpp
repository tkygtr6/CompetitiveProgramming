#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs(a - b) < EPS)

class Point{
public:
    double x, y;

    Point(double x_ = 0, double y_ = 0){
        x = x_;
        y = y_;
    }

    Point operator+ (Point p){
        return Point(x + p.x, y + p.y);
    };

    Point operator- (Point p){
        return Point(x - p.x, y - p.y);
    };

    Point operator* (double k){
        return Point(x * k, y * k);
    }

    Point operator/ (double k){
        return Point(x / k, y / k);
    }

    double norm(){
        return x * x + y * y;
    }

    double abs(){
        return sqrt(norm());
    }

    bool operator == (const Point &p) const{
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

typedef Point Vector;

double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

