#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    if(N == 10 || N == 100 || N == 1000 || N == 10000 || N == 100000){
        printf("10\n");
    }else{
        printf("%d\n", N/10000 + (N%10000)/1000 + (N%1000)/100 + (N%100)/10 + (N%10));
    }

    return 0;
}
