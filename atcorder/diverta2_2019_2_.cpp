#include <stdio.h>
#include <iostream>
#include <algorithm> 
#include <vector>
#include <set>
#define INF 100000000
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<long long> x(N);
    vector<long long> y(N);
    for(int i = 0; i < N; i++){
        scanf("%lld %lld", &x[i], &y[i]);
    }

    if(N == 1){
        printf("1\n");
        return 0;
    }

    int min_count = N;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            long long t = y[j] - y[i];
            long long s = x[j] - x[i];
            if(t == 0 && s == 0){
                continue;
            }
            set<long long> S;
            for(int k = 0; k < N; k++){
                S.insert(t * x[k] - s * y[k]);
            }
            min_count = min(min_count, (int)S.size());
        }
    }

    cout << min_count << endl;
}
