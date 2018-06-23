#include <stdio.h>
#include <iostream>
using namespace std;

#define H_MAX 1400
#define W_MAX 1400
#define NIL -1

int H, W;
int DP[H_MAX + 1][W_MAX + 1];
int TILE[H_MAX + 1][W_MAX + 1];

int main(){
    scanf("%d", &H);
    scanf("%d", &W);

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            scanf("%d", &TILE[i][j]);
        }
    }

    for(int i = 0; i <= H; i++){
        TILE[i][0] = 0;
    }
    for(int j = 0; j <= W; j++){
        TILE[0][j] = 0;
    }

    int m = 0;
    for(int k = 2; k <= H + W; k++){
        for(int i = 1; i <= H && 1 <= k - i; i++){
            if(W < k - i) continue;
            if(TILE[i][k - i] == 1){
                DP[i][k - i] = 0;
            }else{
                DP[i][k - i] = min(DP[i - 1][k - i], min(DP[i - 1][k - i - 1], DP[i][k - i - 1])) + 1;
            }
            m = max(m, DP[i][k - i]);
        }
    }

    /*
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }
    */

    printf("%d\n", m * m);
}
