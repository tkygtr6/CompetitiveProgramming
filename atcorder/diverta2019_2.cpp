#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int fun(int a, int b, int N){
    int sum = 0;
    for(int i = 0; a * i <= N; i++){
        if((N - a*i) % b == 0){
            sum += 1;
        }
    }

    return sum;
}

int main(void){
    int sum = 0;
    int R, G, B, N;
    scanf("%d %d %d %d", &R, &G, &B, &N);

    for(int i = 0; i * R <= N; i++){
        int f = fun(G, B, N - i * R);
        sum += f;
    }

    printf("%d\n", sum);
}
