#include <stdio.h>
#include <iostream>
using namespace std;

void output_array(int* A, int N){
    for(int i = 0; i < N; i++){
        printf("%d", A[i]);
        if(i != N - 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

int selectionSort(int* A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if (i != minj){
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}


int main(void){
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    int count = selectionSort(A, N);
    output_array(A, N);
    printf("%d\n", count);
}
