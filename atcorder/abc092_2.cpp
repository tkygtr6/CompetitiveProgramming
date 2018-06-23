#include <stdio.h>

int main(void){
    int N, D, X;
    scanf("%d", &N);
    scanf("%d", &D);
    scanf("%d", &X);

    for(int i = 0; i < N; i++){
        int A;
        scanf("%d", &A);

        X += (D - 1) / A + 1;
    }

    printf("%d\n", X);

    return 0;
}
