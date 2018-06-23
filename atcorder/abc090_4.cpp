#include <stdio.h>

int main(void){
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if((i + 1) % (j + 1) > K){
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
}
