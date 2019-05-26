#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 100

using namespace std;

vector<int> int2vec(long long num, int n){
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back(num % 2);
        num = num / 2;
    }
    /*
    for(int i = 0; i < v.size(); i++){
        printf("%d", v[i]);
    }
    printf("\n");
    */
    return v;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> K(m);
    for(int i = 0; i < m; i++){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int s;
            scanf("%d", &s);
            K[i].push_back(s - 1);
        }
    }

    vector<int> P;
    for(int i = 0; i < m; i++){
        int p;
        scanf("%d", &p);
        P.push_back(p);
    }

    long long pow_2_n = 1;
    for(int i = 0; i < n; i++){
        pow_2_n *= 2;
    }

    long long cnt = 0;
    for(long long i = 0; i < pow_2_n; i++){
        vector<int> v = int2vec(i, n);
        bool all_light = true;
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int l = 0; l < K[j].size(); l++){
                sum += v[K[j][l]];
            }
            if(sum % 2 != P[j]){
                all_light = false;
            }
        }
        if(all_light){
            cnt++;
        }
    }

    printf("%lld\n", cnt);
}
