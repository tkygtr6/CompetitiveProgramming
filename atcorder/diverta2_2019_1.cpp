#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);

    if(K == 1){
        printf("0\n");
    }else{
        printf("%d\n", N - K);
    }
    return 0;
}
