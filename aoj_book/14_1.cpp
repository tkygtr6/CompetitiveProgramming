#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define N_MAX 10000
#define NIL -1

struct Node{
    int value;
    int parent;
};

struct Node node[N_MAX];

void init(int n){
    for(int i = 0; i <= n; i++){
        node[i].value = i;
        node[i].parent = NIL;
    }
}

int find(int x){
    struct Node target_node = node[x];
    vector<int> v;
    while(target_node.parent != NIL){
        v.push_back(target_node.value);
        target_node = node[target_node.parent];
    }

    for(int i = 0; i < v.size(); i++){
        node[v[i]].parent = target_node.value;
    }

    return target_node.value;
}

void unite(int x, int y){
    if(find(x) != find(y)){
        node[find(x)].parent = y;
    }
}

void same(int x, int y){
    if(find(x) == find(y)){
        printf("1\n");
    }else{
        printf("0\n");
    }
}

int main(void){
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);

    init(n);

    for(int i = 0; i < q; i++){
        int com, x, y;
        scanf("%d", &com);
        scanf("%d", &x);
        scanf("%d", &y);

        if(com == 0){
            unite(x, y);
        }else{
            same(x, y);
        }
    }

}
