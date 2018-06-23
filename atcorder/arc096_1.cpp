#include <stdio.h>

int main(void){
    int a, b, c, x, y;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &x);
    scanf("%d", &y);

    int sum;
    if(x <= y){
        if(a + b >= c * 2){
            sum = b * (y - x) + c * 2 * x;
            if (b >= c * 2){
                sum = c * 2 * y;
            }
        }else{
            sum = a * x + b * y;
        }
    }else{
        if(a + b >= c * 2){
            sum = a * (x - y) + c * 2 * y;
            if(a >= c * 2){
                sum = c * 2 * x;
            }
        }else{
            sum = a * x + b * y;
        }
    }

    printf("%d\n", sum);
}
