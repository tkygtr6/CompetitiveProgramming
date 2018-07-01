#include <stdio.h>
#include <iostream>
#include <vector>
#define ll long long
#define NUM 200010

using namespace std;

int main(void){
    vector<long long> v;
    ll N;
    scanf("%lld", &N);

    ll sum = 0;
    for(ll i = 0; i < N; i++){
        ll A;
        scanf("%lld", &A);
        sum += A;
        v.push_back(A - (i + 1) + N);
    }

    sort(v.begin(), v.end());

    ll sum1 = 0;
    ll sum2 = 0;

    ll middle1 = N / 2 - 1;
    ll middle2 = N / 2;

    for(int i = 0; i < N; i++){
        sum1 += abs(v[i] - v[middle1]);
        sum2 += abs(v[i] - v[middle2]);
    }

    printf("%lld\n", min(sum1, sum2));

}
