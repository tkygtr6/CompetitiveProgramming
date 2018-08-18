// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp
//
#include <stdio.h>
#include <iostream>
using namespace std;

#define NUM 100
#define BLACK 0
#define WHITE 2
#define NIL -1
#define INF 1000000000
int A[NUM][NUM];

int V[NUM];
int color[NUM];

void init(){
    for(int i = 0; i < NUM; i++){
        color[i] = WHITE;
        V[i] = INF;
    }

}

int main(void){
    init();

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    int next_node = 0;
    int sum = 0;
    while(1){
        color[next_node] = BLACK;
        for(int i = 0; i < n; i++){
            if(A[next_node][i] == NIL){
                continue;
            }
            V[i] = min(V[i], A[next_node][i]);
        }

        next_node = NIL;
        int min_dist = INF;
        for(int i = 0; i < n; i++){
            if(color[i] == BLACK){
                continue;
            }
            if(V[i] < min_dist){
                next_node = i;
                min_dist = V[i];
            }
        }
        if(min_dist == INF){
            break;
        }else{
            sum += min_dist;
        }
    }

    printf("%d\n", sum);
}
