#include <stdio.h>
#include <iostream>
#include <algorithm> 
#include <vector>
#include <list>
#include <set>
#define INF 100000000
using namespace std;

int cmp_sort(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(void){
    int N;
    cin >> N;
    vector<pair<int, int>> P;
    for(int i = 0; i < N; i++){
        int x;
        int y;
        cin >> x;
        cin >> y;
        P.push_back(make_pair(x, y));
    }

    sort(P.begin(), P.end(), cmp_sort);

    if(N == 1 || N == 2){
        printf("1\n");
        return 0;
    }

    int min_count = N - 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }
            int p = P[i].first - P[j].first;
            int q = P[i].second - P[j].second;

            int count = N;
            for(int k = 0; k < N; k++){
                for(int l = 0; l < N; l++){
                    if(k == l){
                        continue;
                    }
                    if(P[k].first - p == P[l].first &&
                            P[k].second - q == P[l].second){
                        count--;
                    }
                }
            }

            min_count = min(min_count, count);
        }
    }

    cout << min_count << endl;
}
