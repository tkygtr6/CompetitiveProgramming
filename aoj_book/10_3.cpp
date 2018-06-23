#include <stdio.h>
#include <iostream>
#define NUM 10000000
#define NIL -2000000001
using namespace std;

void print(int* heap, int H){
    for(int i = 0; i < H; i++){
        printf(" %d", heap[i + 1]);
    }
    printf("\n");
}

int left(int i){
    return i * 2;
}

int right(int i){
    return i * 2 + 1;
}

int largest_(int* heap, int a, int b, int c){
    if(heap[a] < heap[b]){
        if(heap[b] < heap[c]){
            return c;
        }else{
            return b;
        }
    }else{
        if(heap[a] < heap[c]){
            return c;
        }else{
            return a;
        }
    }
}


void maxHeapify(int* heap, int i){
    int l = left(i);
    int r = right(i);
    int largest = largest_(heap, l, r, i);

    if(largest != i){
        swap(heap[i], heap[largest]);
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(int* heap, int H){
    for(int i = H / 2; i >= 1; i--){
        maxHeapify(heap, i);
    }
}

int main(void){
    int H;
    scanf("%d", &H);

    int heap[NUM];
    for(int i = 0; i < NUM; i++){
        heap[i] = NIL;
    }

    for(int i = 1; i <= H; i++){
        scanf("%d", &heap[i]);
    }

    buildMaxHeap(heap, H);

    print(heap, H);

    return 0;
}


