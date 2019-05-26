#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 100

using namespace std;

int main(void){
    int N, M;
    int L_max, R_min;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int L, R;
        scanf("%d %d", &L, &R);
        if(i == 0){
            L_max = L;
            R_min = R;
        }else{
            L_max = max(L, L_max);
            R_min = min(R, R_min);
        }
    }

    printf("%d\n", max(0, R_min - L_max + 1));
}
