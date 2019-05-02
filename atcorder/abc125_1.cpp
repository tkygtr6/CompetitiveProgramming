#include <stdio.h>

int main(void){
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);

    float now = 0.0;
    int sum = 0;
    while(now + a <= (float)t + 0.5){
        now += a;
        sum += b;
    }

    printf("%d\n", sum);

    return 0;
}
