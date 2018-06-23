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

bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0.0);
}

bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0.0);
}
;
double getCos(Vector a, Vector b){
    return dot(a, b) / (a.abs() * b.abs());
}

double dist(Point p1, Point p2){
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

Point projection(Point p1, Point p2, Point p0){
    if(p1 == p0){
        return p0;
    }
    if(p2 == p0){
        return p0;
    }
    return p1 + (p2 - p1) / (p2 - p1).abs() * (p0 - p1).abs() * getCos(p2 - p1, p0 - p1);
}

int main(){
    int xp1, yp1, xp2, yp2;
    scanf("%d", &xp1);
    scanf("%d", &yp1);
    scanf("%d", &xp2);
    scanf("%d", &yp2);

    Point p1 = Point(xp1, yp1);
    Point p2 = Point(xp2, yp2);

    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        int xp0, yp0;
        scanf("%d", &xp0);
        scanf("%d", &yp0);

        Point p = projection(p1, p2, Point(xp0, yp0));
        printf("%.10f %.10f\n", p.x, p.y);
    }
}

