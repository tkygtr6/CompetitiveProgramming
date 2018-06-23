#include <stdio.h>
#include <iostream>
#include <queue>
#define NUM 100
#define NIL -1
using namespace std;

int V[NUM + 1][NUM + 1];
int dist[NUM + 1];
int node_num;
int t;
int pos;
queue<int> Q;

void init(){
    int V[NUM + 1][NUM + 1];
    for(int i = 1; i <= NUM; i++){
        for(int j = 1; j <= NUM; j++){
            V[i][j] = 0;
        }
    }

    for(int i = 0; i <= NUM; i++) {
        dist[i] = NIL;
    }
    
    t = 0;
}

void get_adj(){
    scanf("%d", &node_num);

    for(int i = 0; i < node_num; i++){
        int num1;
        scanf("%d", &num1);

        int n;
        scanf("%d", &n);

        int num2;
        for(int j = 0; j < n; j++){
            scanf("%d", &num2);
            V[num1][num2] = 1;
        }
    }
}

void touchNextNode(int n){
    t += 1;
    for(int i = 1; i <= node_num; i++){
        if(V[n][i] == 1 && dist[i] == NIL){
            Q.push(i);
            dist[i] = dist[n] + 1;
        }
    }
    Q.pop();
}

void BFS(){
    Q.push(1);
    dist[1] = t;
    touchNextNode(1);
    
    while(Q.size()){
        int pos = Q.front();
        touchNextNode(pos);
    }
}

int main(void){
    init();
    get_adj();
    BFS();
    
    for(int i = 1; i <= node_num; i++){
        printf("%d %d\n", i, dist[i]);
    }

}
