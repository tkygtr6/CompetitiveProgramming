#include<iostream>
#include<algorithm>
using namespace std;

void output(int* A, int N){
    for(int i = 0; i < N; i++){
        printf("%d", A[i]);
        if (i < N - 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

void insertionSort(int *A, int N){
    for(i = 1; i < N; i++){
        int v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] ){

        }
    }
}

int main(){
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    inserionSort(A, N);
    return 0;
}
