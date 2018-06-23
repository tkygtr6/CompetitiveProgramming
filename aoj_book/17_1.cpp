#include <stdio.h>
#include <iostream>
#define M 20
#define N 50000
#define INF 100000000
using namespace std;

int DP[M + 1][N + 1];

int main(void){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int C[M + 1];
    for(int i = 1; i <= m; i++){
        scanf("%d", &C[i]);
    }

    for(int j = 1; j <= n; j++){
        DP[0][j] = INF;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(j - C[i] == 0){
                DP[i][j] = 1;
            }else if(j - C[i] > 0){
                DP[i][j] = min(DP[i][j - C[i]] + 1, DP[i - 1][j]);
            }else{
                DP[i][j] = DP[i - 1][j];
            }
            //printf("DP[%d][%d]: %d\n", i, j, DP[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        //printf("%d\n", DP[1][i]);
    }

    printf("%d\n", DP[m][n]);

}
