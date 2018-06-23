#include <stdio.h>
#include <iostream>
#define NUM 100000

int x[NUM];
int y[NUM];
int memo[NUM];

int culc_height(int p, int D){
    if(memo[p] == -1){
        if(p <= D){
            memo[p] = 0;
        }else{
            memo[p] = culc_height(p - D, D) + abs(x[p] - x[p - D]) + abs(y[p] - y[p - D]);
        }
    }
    return memo[p];;
}

int main(void){
    for(int i = 0; i < NUM; i++){
            memo[i] = -1;
    }

    int H;
    int W;
    int D;
    scanf("%d", &H);
    scanf("%d", &W);
    scanf("%d", &D);

    int a;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &a);
            x[a] = j;
            y[a] = i;
        }
    }

    int Q;
    scanf("%d", &Q);

    for(int i = 0; i < Q; i++){
        int L, R;
        scanf("%d", &L);
        scanf("%d", &R);
        printf("%d\n", culc_height(R, D) - culc_height(L, D));
    }
}
