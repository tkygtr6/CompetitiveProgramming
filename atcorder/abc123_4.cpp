#include <stdio.h>
#include <iostream>
#include <vector>
#define ll long long
#define NUM 1001
#define NUM_ 3001
using namespace std;

ll A[NUM];
ll B[NUM];
ll C[NUM];
ll AB[NUM*NUM];
ll ABC[NUM_*NUM];
int X, Y, Z, K;

void init(){
    for(int i = 0; i < NUM; i++){
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
    }
}

int main(void){
    scanf("%d", &X);
    scanf("%d", &Y);
    scanf("%d", &Z);
    scanf("%d", &K);

    for(int i = 0; i < X; i++){
        scanf("%lld", &A[i]);
    }
    for(int i = 0; i < Y; i++){
        scanf("%lld", &B[i]);
    }
    for(int i = 0; i < Z; i++){
        scanf("%lld", &C[i]);
    }

    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            AB[Y*i+j] = A[i] + B[j];
        }
    }

    sort(&AB[0], &AB[X*Y], [](ll x, ll y) {return x > y;});
    sort(&C[0], &C[Z], [](ll x, ll y) {return x > y;});

    for(int i = 0; i < K; i++){
        for(int j = 0; j < Z; j++){
            ABC[Z*i+j] = AB[i] + C[j];
        }
    }

    sort(&ABC[0], &ABC[K*Z], [](ll x, ll y) {return x > y;});

    for(int i = 0; i < K; i++){
        printf("%lld\n", ABC[i]);
    }
}
