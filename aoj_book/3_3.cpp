#include <stdio.h>
#include <iostream>
using namespace std;

void printout_array(int* A, int N){
    for(int i = 0; i < N; i++){
        printf("%d", A[i]);
        if(i != N - 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

int bubbleSort(int* A, int N){
    int flag = 1;     
    int count = 0;
    while(flag){
        flag = 0;
        for(int j = 1; j < N; j++){
            if(A[j] < A[j - 1]){
                swap(A[j], A[j - 1]);
                flag = 1;
                count += 1;
            }
        }
    }
    return count;
}

int main(void){
    int N;
    scanf("%d", &N);

    int array[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &array[i]);
    }
    
    int count = bubbleSort(array, N);
    printout_array(array, N);
    printf("%d\n", count);

}
