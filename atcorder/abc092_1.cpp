#include <stdio.h>
#include <iostream>

int main(void){
    int A, B, C, D;

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);

    int sum = 0;
    if (A < B){
        sum += A;
    }else{
        sum += B;
    }
    if(C < D){
        sum += C;
    }else{
        sum += D;
    }

    printf("%d\n", sum);

    return 0;
}
