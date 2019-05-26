#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <stack>
#define NUM 100010
#define NIL -1

using namespace std;

stack<int> S;
vector<pair<int,int>> w[NUM];
array<long long, NUM> d;

void init(){
    for(int i = 0; i < NUM; i++){
        d[i] = NIL;
    }
}

int main(void){
    init();
    int N;
    scanf("%d\n", &N);

    for(int i = 1; i <= N-1; i++){
        int u_, v_, w_;
        scanf("%d %d %d", &u_, &v_, &w_);
        w[u_].push_back(make_pair(v_, w_));
        w[v_].push_back(make_pair(u_, w_));
    }

    d[1] = 0;
    S.push(1);
    while(S.size()){
        int num = S.top(); S.pop();
        //printf("num: %d\n", num);
        for(int i = 0; i < w[num].size(); i++){
            if(d[w[num][i].first] == NIL){
                S.push(w[num][i].first);
                d[w[num][i].first] = d[num] + w[num][i].second;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        //printf("%d\n", d[i]);
        if(d[i] % 2 == 0){
            printf("0\n");
        }else{
            printf("1\n");
        }
    }

}
