#include <stdio.h>
#define NUM 200010

int main(void){
    int N;
    char S[NUM];
    int o_count = 0;
    int x_count = 0;
    int o[NUM];
    int x[NUM];
    
    scanf("%d", &N);
    scanf("%s", S);

    for(int i = 0; i < N; i++){
        if(S[i] == '#'){
            x_count++;
        }
        x[i] = x_count;
    }

    for(int i = N - 1; 0 <= i; i--){
        if(S[i] == '.'){
            o_count++;
        }
        o[i] = o_count;
    }

    int ans = N;
    for(int i = 0; i <= N; i++){
        int ans_;
        if(i == 0){
            ans_ = o[i];
        }
        if(i == N){
            ans_ = x[i];
        }
        ans_ = x[i - 1] + o[i];
        if(ans_ < ans){
            ans = ans_;
        }
    }

    printf("%d\n", ans);
}
