#include <stdio.h>


int main(void){
    char S[100];
    int K;
    int N;

    scanf("%d", &N);
    scanf("%s", S);
    scanf("%d", &K);

    for(int i = 0; i < N; i++){
        if(S[i] == S[K-1]){
            printf("%c", S[K-1]);
        }else{
            printf("*");
        }
    }

    printf("\n");
    return 0;
}
