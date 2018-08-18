// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B&lang=jp
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define NUM 100
#define BLACK 0
#define WHITE 1
#define INF 100000000
#define NIL -1

vector<pair<int,int>> A[NUM];
int V[NUM];
int color[NUM];

void init(){
    for(int i = 0; i < NUM; i++){
        V[i] = INF;
        color[i] = WHITE;
    }
}

int main(void){
    init();

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int u, k;
        scanf("%d", &u);
        scanf("%d", &k);

        for(int j = 0; j < k; j++){
            int v, c;
            scanf("%d", &v);
            scanf("%d", &c);
            A[u].push_back(make_pair(v, c));
        }
    }

    int next_node = 0;
    V[0] = 0;
    while(1){
        color[next_node] = BLACK;
        for(int i = 0; i < A[next_node].size(); i++){
            int v = A[next_node][i].first;
            int c = A[next_node][i].second;
            V[v] = min(V[v], V[next_node] + c);
        }

        next_node = NIL;
        int min_dist = INF;
        for(int i = 0; i < n; i++){
            if(color[i] == BLACK){
                continue;
            }
            if(V[i] < min_dist){
                min_dist = V[i];
                next_node = i;
            }
        }

        if(next_node == NIL){
            break;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d %d\n", i, V[i]);
    }
}
