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

class Seg{
public:
    Point p1;
    Point p2;
    Seg(Point p1_, Point p2_){
        p1 = p1_;
        p2 = p2_;
    }
};

class Circle{
public:
    Point p;
    double r;
    Circle(Point p_, double r_){
        p = p_;
        r = r_;
    }
};

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

Point project(Seg s, Point p0){
    if(s.p1 == p0){
        return p0;
    }
    if(s.p2 == p0){
        return p0;
    }
    return s.p1 + (s.p2 - s.p1) / (s.p2 - s.p1).abs() * (p0 - s.p1).abs() * getCos(s.p2 - s.p1, p0 - s.p1);
}

Point reflect(Seg s, Point p0){
    Point p = project(s, p0);
    return p0 + (p - p0) * 2;
}


#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

int counterClockwise(Point p0, Point p1, Point p2){
    Vector v1 = p1 - p0;
    Vector v2 = p2 - p0;
    if(cross(v1, v2) > EPS) return COUNTER_CLOCKWISE;
    if(cross(v1, v2) < -EPS) return CLOCKWISE;
    if(dot(v1, v2) < -EPS) return ONLINE_BACK;
    if(v1.norm() < v2.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(Seg s1, Seg s2){
    int t1 = counterClockwise(s1.p1, s1.p2, s2.p1);
    int t2 = counterClockwise(s1.p1, s1.p2, s2.p2);
    int t3 = counterClockwise(s2.p1, s2.p2, s1.p1);
    int t4 = counterClockwise(s2.p1, s2.p2, s1.p2);
    if(t1 * t2 <= 0){
        if(t3 * t4 <= 0){
            return true;
        }
    }
    return false;
}

double getDistanceLP(Seg s, Point p0){
    return (project(s, p0) - p0).abs();
}

double getDistanceSP(Seg s, Point p0){
    if(dot(s.p2 - s.p1, p0 - s.p1) < 0.0) return (p0 - s.p1).abs();
    if(dot(s.p1 - s.p2, p0 - s.p2) < 0.0) return (p0 - s.p2).abs();
    return (project(s, p0) -  p0).abs();
}

double getDistance(Seg s1, Seg s2){
    if(intersect(s1, s2)){
        return 0.0;
    }
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
                min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

Point crossPoint(Seg s1, Seg s2){
    double d1 = getDistanceLP(s2, s1.p1);
    double d2 = getDistanceLP(s2, s1.p2);

    return (s1.p2 * d1 + s1.p1 * d2) / (d1 + d2);
}

// 円と直線の交点
pair<Point, Point> getCrossPoints(Circle c, Seg s){
    double d1 = getDistanceLP(s, c.p);
    double d2 = sqrt(pow(c.r, 2) - pow(d1, 2));

    Point p1 = project(s, c.p);
    Vector v1 = s.p2 - s.p1;

    Point cp1 = p1 + v1 / v1.abs() * d2;
    Point cp2 = p1 - v1 / v1.abs() * d2;

    if(cp1.x < cp2.x){
        return make_pair(cp1, cp2);
    }else if(cp1.x > cp2.x){
        return make_pair(cp2, cp1);
    }else{
        return cp1.y < cp2.y ? make_pair(cp1, cp2) : make_pair(cp2, cp1);
    }

}

pair<Point, Point> getCrossPointsOfCircles(Circle c1, Circle c2){
    if(c1.p.x > c2.p.x){
        swap(c1, c2);
    }
    double d = (c2.p - c1.p).abs();
    double t = asin((c2.p.y - c1.p.y) / d);
    double a = acos((-pow(c2.r, 2) + pow(c1.r, 2) + pow(d, 2)) / (2 * c1.r * d));
    //printf("d: %f, t: %f, a: %f\n", d, t * (180/3.14), a * (180/3.14));
   
    Point p1 = c1.p + Point(cos(t + a), sin(t + a)) * c1.r;
    Point p2 = c1.p + Point(cos(t - a), sin(t - a)) * c1.r;

    if(p1.x < p2.x){
        return make_pair(p1, p2);
    }else if(p1.x > p2.x){
        return make_pair(p2, p1);
    }else{
        return p1.y < p2.y ? make_pair(p1, p2) : make_pair(p2, p1);
    }
}

#define N_MAX 100
#define Q_MAX 1000
#define INF 100000000

int main(){
    int n;
    scanf("%d", &n);

    Point P[N_MAX];
    for(int i = 0; i < n; i++){
        scanf("%lf %lf", &P[i].x, &P[i].y);
    }

    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        Point Q;
        scanf("%lf %lf", &Q.x, &Q.y);

        int count = 0;
        bool on_seg = false;
        for(int j = 0; j < n; j++){
            Seg side = (j == n - 1) ? Seg(P[j], P[0]) : Seg(P[j], P[j + 1]);
            if(counterClockwise(side.p1, side.p2, Q) == ON_SEGMENT){
                on_seg = true;
                break;
            }
            if(intersect(side, Seg(Q, Point(0, INF)))){
                if (counterClockwise(Q, Point(0, INF), side.p1) == ON_SEGMENT && 
                    counterClockwise(Q, Point(0, INF), side.p2) == ON_SEGMENT){
                }else{
                    count++;
                }
            }
        }
        if(on_seg){
            printf("1\n");
        }else if(count % 2 == 1){
            printf("2\n");
            printf("count: %d\n", count);
        }else{
            printf("0\n");
            printf("count: %d\n", count);
        }
    }

}


