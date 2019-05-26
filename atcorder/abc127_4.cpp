#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 100
using namespace std;
 
bool cmp_int(int a, int b){
    return a > b;
}
 
bool cmp_pair(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}
 
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
 
    vector<int> A(n);
    for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
        }
 
    vector<pair<int, int>> P;
    for(int i = 0; i < m; i++){
            int b, c;
            scanf("%d %d", &b, &c);
            P.push_back(make_pair(b, c));
        }
    sort(P.begin(), P.end(), cmp_pair);
 
    int count = 0;
    for(int i = 0; i < m; i++){
            int b = P[i].first;
            int c = P[i].second;
            for(int j = 0; j < b; j++){
                        A.push_back(c);
                    }
            count += b;
            if(n < count){
                        break;
                    }
        }
 
    sort(A.begin(), A.end(), cmp_int);
 
    long long sum = 0;
    for(int i = 0; i < n; i++){
            sum += A[i];
        }
 
    printf("%lld\n", sum);
}
