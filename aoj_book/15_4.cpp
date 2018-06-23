#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define NUM 100000
#define NIL -1
#define INF 1000000000
#define BLACK 0
#define WHITE 1
int node_num;
vector<pair<int, int>> V[NUM];
int d[NUM];
int color[NUM];

pair<int, int> get_most_distant(int n){
    for(int i = 0; i < node_num; i++){
        color[i] = WHITE;
    }

    queue<int> Q;
    Q.push(n);
    d[n] = 0;
    color[n] = BLACK;

    while(!Q.empty()){
        int target = Q.front(); Q.pop();
        for(int i = 0; i < V[target].size(); i++){
            pair<int, int> next_node = V[target][i];
            if(color[next_node.first] == BLACK)
                continue;
            d[next_node.first] = d[target] + next_node.second;
            Q.push(next_node.first);
            color[target] = BLACK;
        }
    }

    int max_index = NIL;
    int max_value = -INF;
    for(int i = 0; i < node_num; i++){
        if(d[i] > max_value){
            max_index = i;
            max_value = d[i];
        }
    }


    return make_pair(max_index, max_value);
}

int main(void){
    scanf("%d", &node_num);

    for(int i = 0; i < node_num - 1; i++){
        int s, t, w;
        scanf("%d", &s);
        scanf("%d", &t);
        scanf("%d", &w);
        V[s].push_back(make_pair(t, w));
        V[t].push_back(make_pair(s, w));
    }

    pair<int, int> dist_node = get_most_distant(0);
    //printf("%d %d\n",dist_node.first, dist_node.second);
    printf("%d\n", get_most_distant(dist_node.first).second);

    return 0;
}
