#include <stdio.h>

int main(void){
    long long a, b, c, k;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    scanf("%lld", &k);

    if(k % 2 != 0){
        if(b - a < -1000000000000000000 || b - a > 1000000000000000000){
            printf("Unfair\n");
        }else{
            printf("%lld\n", b - a);
        }
    }else{
        if(a - b < -1000000000000000000 || a - b > 1000000000000000000){
            printf("Unfair\n");
        }else{
            printf("%lld\n", a - b);
        }
    }
    return 0;
}
