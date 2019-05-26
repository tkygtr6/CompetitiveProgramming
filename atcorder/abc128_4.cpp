#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 100

using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> D(n);
    for(int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        D[i] = v;
    }

    int max_value = 0;
    for(int i = 0; i <= k; i++){
        for(int j = 0; i + j <= k; j++){
            if(i + j > n){
                continue;
            }

            vector<int> v;
            for(int t = 0; t < i; t++){
                v.push_back(D[t]);
            }
            for(int t = 0; t < j; t++){
                v.push_back(D[D.size() - t - 1]);
            }

            if(v.size() != 0){
                sort(v.begin(), v.end());
            }

            for(int l = 0; i + j + l <= k; l++){
                if(i + j < l){
                    continue;
                }
                int value = 0;
                for(int t = l; t < v.size(); t++){
                    value += v[t];
                }
                max_value = max(max_value, value);
                //printf("value %d\n", value);
            }
        }
    }

    printf("%d\n", max_value);
}
