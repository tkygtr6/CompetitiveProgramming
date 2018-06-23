#include <stdio.h>
#include <iostream>
using namespace std;
#define N_MAX 100
#define W_MAX 10000
int DP[N_MAX + 1][W_MAX + 1];

int main(void){
    int N, W;
    scanf("%d", &N);
    scanf("%d", &W);

    int v[N_MAX];
    int w[N_MAX];
    for(int i = 1; i <= N; i++){
        scanf("%d", &v[i]);
        scanf("%d", &w[i]);
    }

    for(int i = 0; i <= W; i++){
        DP[0][i] = 0;
    }

    for(int j = 0; j <= N; j++){
        DP[j][0] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= W; j++){
            if(j - w[i] >= 0){
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            }else{
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= W; j++){
            //printf("DP[%d][%d] = %d\n", i, j, DP[i][j]);
        }
    }


    printf("%d\n", DP[N][W]);
    
}
