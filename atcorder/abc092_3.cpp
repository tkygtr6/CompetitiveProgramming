#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);

    int i;
    int A[100001];
    A[0] = 0;
    A[N] = 0;

    int sum = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i + 1]) ;
        sum += abs(A[i + 1] - A[i]);
    }
    sum += abs(A[N + 1] - A[N]);

    for(int i = 1; i <= N; i++){
        if((A[i] - A[i - 1]) * (A[i + 1] - A[i]) < 0){
            printf("%d\n", sum - min(abs(A[i] - A[i - 1]), abs(A[i + 1] - A[i])) * 2);
        }else{
            printf("%d\n", sum);
        }
    }

    return 0;
}
