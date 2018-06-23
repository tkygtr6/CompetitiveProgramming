#include <stdio.h>
#define NUM 100000

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);

    int x;
    for(int i = 0; i < N; i++){
        int A;
        scanf("%d", &A);
        if(A == 1){
            x = i;
            break;
        }
    }

    int a = x;
    int b = N - a - 1;

    int t = (N - 1) / (K - 1);
    int s = (N - 1) % (K - 1);
    int ans;

    if(s == 0){
        ans = t;
    }else{
        ans = t + 1;
    }

    printf("%d\n", ans);
}
