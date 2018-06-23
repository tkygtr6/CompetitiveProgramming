#include <stdio.h>

int main(void){
    long int N, M;
    scanf("%ld", &N);
    scanf("%ld", &M);

    if(M > 2 && N > 2){
        printf("%ld\n", (M - 2) * (N - 2));
    }else if(M == 1 && N == 1){
        printf("1\n");
    }else if(M == 1 && N > 2){
        printf("%ld\n", N - 2);
    }else if(N == 1 && M > 2){
        printf("%ld\n", M - 2);
    }else{
        printf("0\n");
    }
    return 0;
}
