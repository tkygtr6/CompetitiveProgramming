#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define NUM 10000
int v_num, e_num;
vector<int> V[NUM];
int d[NUM];
queue<int> Q;

void init(){
    for(int i = 0; i < v_num; i++){
        d[i] = 0;
    }

    for(int i = 0; i < e_num; i++){
        int s, t;
        scanf("%d", &s);
        scanf("%d", &t);
        V[s].push_back(t);
        d[t]++;
    }

    for(int i = 0; i < v_num; i++){
        if(d[i] == 0)
            Q.push(i);
    }
}

void t_sort(){
    while(!Q.empty()){
        int f = Q.front(); Q.pop();
        printf("%d\n", f);
        for(int i = 0; i < V[f].size(); i++){
            d[V[f][i]]--;
            if (d[V[f][i]] == 0){
                Q.push(V[f][i]);
            }
        }
    }
}

int main(void){
    scanf("%d", &v_num);
    scanf("%d", &e_num);

    init();

    t_sort();
}

