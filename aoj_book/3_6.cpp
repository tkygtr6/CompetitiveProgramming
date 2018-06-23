#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int insertionSort(int* A, int n, int g){
    int cnt = 0;
    for(int i = g; i < n; i++){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
    return cnt;
}

int shellSort(int* A, int n){
    int cnt = 0;

    vector<int> G;
    G.push_back(1);
    while(G.back() * 3 + 1 < n){
        G.push_back(G.back() * 3 + 1);
    }
    int m = G.size();
    
    printf("%d\n", m);
    for(int i = m - 1; i >= 0; i--){
        printf("%d", G[i]);
        if(i != 0){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    for(int i = m - 1; i >= 0 ; i--){
        cnt += insertionSort(A, n, G[i]);
    }
    return cnt;
}

int main(void){
    int n;
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int cnt;
    cnt = shellSort(A, n);

    printf("%d\n", cnt);

    for(int i = 0; i < n; i++){
        printf("%d\n", A[i]);
    }
}
