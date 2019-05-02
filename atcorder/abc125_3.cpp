#include <stdio.h>
#define NUM 100010

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    if(a == 0){
        return b;
    }
    if(a < b){
        return gcd(a, b%a);
    }else{
        return gcd(b, a%b);
    }
}

int main(void){
    int N;
    int A[NUM];
    int L[NUM];
    int R[NUM];
    int L_R[NUM];

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    L[0] = A[0];
    for(int i = 1; i < N; i++){
        L[i] = gcd(L[i-1], A[i]);
    }

    R[N-1] = A[N-1];
    for(int i = N - 2; i >= 0; i--){
        R[i] = gcd(A[i], R[i+1]);
    }
    
    L_R[0] = R[1];
    L_R[N-1] = L[N-2];
    for(int i = 1; i < N - 1; i++){
        L_R[i] = gcd(L[i-1], R[i+1]);
    }

    int m = L_R[0];
    for(int i = 0; i < N; i++){
        m = m < L_R[i] ? L_R[i]:m;
    }

    printf("%d\n", m);
}
