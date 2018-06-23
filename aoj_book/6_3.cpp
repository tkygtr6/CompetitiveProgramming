#include <stdio.h>
#include <math.h>

struct dot{
    double x;
    double y;
};

void koch(struct dot d1, struct dot d2, int n){
    if(n == 0){
        return;
    }

    struct dot s;
    s.x = d1.x * 2 / 3 + d2.x * 1 / 3;
    s.y = d1.y * 2 / 3 + d2.y * 1 / 3;

    struct dot t;
    t.x = d1.x * 1 / 3 + d2.x * 2 / 3;
    t.y = d1.y * 1 / 3 + d2.y * 2 / 3;

    struct dot u;
    u.x = ((d2.x - d1.x) - sqrt(3) * (d2.y - d1.y)) / 6 + d1.x * 2 / 3 + d2.x * 1 / 3;
    u.y = (sqrt(3) * (d2.x - d1.x) + (d2.y - d1.y)) / 6 + d1.y * 2 / 3 + d2.y * 1 / 3;

    koch(d1, s, n - 1);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(s, u, n - 1);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(u, t, n - 1);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(t, d2, n - 1);
}

int main(void){
    int N;
    scanf("%d", &N);

    struct dot p1;
    p1.x = 0.0;
    p1.y = 0.0;
    struct dot p2;
    p2.x = 100.0;
    p2.y = 0.0;
        
    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(p1, p2, N);
    printf("%.8f %.8f\n", p2.x, p2.y);

    return 0;
}
