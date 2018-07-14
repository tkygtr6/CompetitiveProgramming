#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);

    int A[100];
    int sum = 0;
    int count = 1;
    scanf("%d", &A[0]);

    for(int i = 1; i < N; i++){
       scanf("%d", &A[i]);
       if(A[i] == A[i - 1]){
           count++;
       }else{
           sum += count / 2;
           count = 1;
       }
    }
    sum += count / 2;

    printf("%d\n", sum);

    return 0;
}

