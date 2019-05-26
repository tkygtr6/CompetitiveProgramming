#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 26

using namespace std;

bool cmp_pair(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b){
    pair<string, int> a_ = a.second;
    pair<string, int> b_ = b.second;
    if(a_.first == b_.first){
        return a_.second > b_.second;
    }else{
        return a_.first < b_.first;
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    vector<pair<int, pair<string, int>>> V;
    for(int i = 0; i < n; i++){
        string s;
        int p;
        cin >> s;
        cin >> p;
        V.push_back(make_pair(i + 1, make_pair(s, p)));
    }

    sort(V.begin(), V.end(), cmp_pair);

    for(int i = 0; i < V.size(); i++){
        printf("%d\n", V[i].first);
    }
}
