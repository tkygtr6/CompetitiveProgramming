#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct card{
    char mark;
    char value;
}card;

void printout_array(card* A, int N){
    for(int i = 0; i < N; i++){
        printf("%c", A[i].mark);
        printf("%c", A[i].value);
        if(i != N - 1){ printf(" ");
        }else{
            printf("\n");
        }
    }
}

int bubbleSort(card* A, int N){
    int flag = 1;
    int count = 0;
    while(flag){
        flag = 0;
        for(int j = 1; j < N; j++){
            if(A[j].value < A[j - 1].value){
                swap(A[j], A[j - 1]);
                flag = 1;
                count += 1;
            }
        }
    }
    return count;
}

int selectionSort(card* A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j].value < A[minj].value){
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

bool is_stable(card *A, card *B, int N){
    vector<string> arr;
    for(int i = 0; i < 9; i++){
        string s = "";
        arr.push_back(s);
    }

    for(int i = 0; i < N; i++){
        arr[int(A[i].value - '0')].push_back(A[i].mark);
    }
    for(int i = N - 1; i >= 0 ; i--){
        if(B[i].mark != arr[B[i].value - '0'].back()){
            return false;
        }else{
            arr[B[i].value - '0'].pop_back();
        }
    }
    return true;
}

int main(void){
    int N;
    scanf("%d", &N);

    card A[N];
    for(int i = 0; i < N; i++){
        char s[10];
        scanf("%s", s);
        A[i].mark = s[0];
        A[i].value = s[1];
    }

    card B[N];
    for(int i = 0; i < N; i++){
        B[i].mark = A[i].mark;
        B[i].value = A[i].value;
    }

    card C[N];
    for(int i = 0; i < N; i++){
        C[i].mark = A[i].mark;
        C[i].value = A[i].value;
    }

    bubbleSort(B, N);
    selectionSort(C, N);

    printout_array(B, N);
    if(is_stable(A, B, N)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

    printout_array(C, N);
    if(is_stable(A, C, N)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

    return 0;
}

