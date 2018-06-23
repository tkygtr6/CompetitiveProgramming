#include <stdio.h>
#include <iostream>
using namespace std;

#define NUM 200010
int A[NUM];

int sum(int a, int b){
    int ans = 0;
    for(int i = a; i <= b; i++){
        ans += A[i];
    }

    return ans;
}

int bit(int a, int b){
    int ans = A[a] ^ A[a + 1];
    for(int i = a + 2; i <= b; i++){
        ans = ans ^ A[i];
    }
    return ans;
}

int S[NUM];

int main(void){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < N; i++){
        S[i] = -1;
    }

    int a = 0;
    int b = 1;

    while(1){
        printf("%d %d %d %d\n", a, b, sum(a, b), bit(a, b));
        if(sum(a, b) == bit(a, b)){
            //printf("%d %d %d\n", a, b, sum(a, b));
            printf("OK\n");
            S[a] = b;
            if (b != N - 1){
                b++;
            }else{
                a++;
            }
        }else{
            if(a + 1 == b){
                a++;
                b++;
            }else{
                a++;
            }
        }
        if(a == N - 1 || b == N){
            break;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == -1){
            continue;
        }
        cnt +=  S[i] - i;
        printf("S[%d]: %d\n", i, S[i]);
    }

    printf("%d\n", cnt + N);
}
