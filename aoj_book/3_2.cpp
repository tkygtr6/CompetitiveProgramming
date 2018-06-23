#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void printout_array(int* A, int N){
   string str = "";
   for(int i = 0; i < N; i++){
       str += to_string(A[i]);
       if(i != N - 1){
           str += " ";
       }
   }
   cout << str << "\n";
}

void insertionSort(int* A, int N){
    for(int i = 1; i < N; i++){
        int v = A[i];
        int j = i - 1;
        while( j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printout_array(A, N);
    } 
}


int main(){
    int N;
    scanf("%d", &N);

    int array[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &array[i]);
    }
    printout_array(array, N);
    insertionSort(array, N);
}
