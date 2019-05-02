#include <stdio.h>
#define NUM 21

int main(void){
    int N;
    int V[NUM], C[NUM];
    scanf("%d", &N);

    int sum = 0;
    for(int i = 0 ; i < N; i++){
        scanf("%d", &V[i]);
    }
    for(int i = 0 ; i < N; i++){
        scanf("%d", &C[i]);
    }
    for(int i = 0 ; i < N; i++){
        int cost = V[i] - C[i];
        if(cost > 0){
            sum += cost;
        }
    }

    printf("%d\n", sum);
}
