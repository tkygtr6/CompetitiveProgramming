// WA

#include <stdio.h>
#include <iostream>
#define NUM 200010
#define ll long long
#define INF 1000000000

using namespace std;

ll calc_diff(ll a1, ll a2, ll a3, ll a4){
    ll min_ = min(min(a1, a2), min(a3, a4));
    ll max_ = max(max(a1, a2), max(a3, a4));
    return max_ - min_;
}

int main(void){
    ll N;
    scanf("%lld", &N);
    ll sum[NUM];
    for(ll i = 0; i < N; i++){
        ll A;
        scanf("%lld", &A);
        if(i == 0){
            sum[i] = A;
        }else{
            sum[i] = sum[i - 1] + A;
        }
    }

    ll ans = INF;

    /*
    for(int i = 0; i < N; i++){
        printf("%lld ", sum[i]);
    }
    printf("\n");
    */

    for(ll i = 1; i <= N - 3; i++){
        auto a1_1 = lower_bound(sum, sum + i - 1, sum[i] / 2);
        auto a1_0 = a1_1 - 1;
        if(*a1_0 == 0){
            a1_0 = a1_1;
        }
        auto a1_2 = a1_1 + 1;
        if(*a1_2 == sum[i]){
            a1_2 = a1_1;
        }

        auto a3_1 = lower_bound(sum + i + 1, sum + N - 2, (sum[i] + sum[N - 1])/2);
        auto a3_0 = a3_1 - 1;
        if(*a3_0 == sum[i]){
            a3_0 = a3_1;
        }
        auto a3_2 = a3_1 + 1;
        if(*a3_2 == 0){
            a3_2 = a3_1;
        }


        //printf("%lld %lld %lld [%lld] %lld %lld %lld\n", *a1_0, *a1_1, *a1_2, sum[i], *a3_0, *a3_1, *a3_2);

        ans = min(ans, calc_diff(*a1_0, sum[i] - *a1_0, *a3_0 - sum[i], sum[N-1] - *a3_0));
        ans = min(ans, calc_diff(*a1_1, sum[i] - *a1_1, *a3_0 - sum[i], sum[N-1] - *a3_0));
        ans = min(ans, calc_diff(*a1_2, sum[i] - *a1_2, *a3_0 - sum[i], sum[N-1] - *a3_0));
        ans = min(ans, calc_diff(*a1_0, sum[i] - *a1_0, *a3_1 - sum[i], sum[N-1] - *a3_1));
        ans = min(ans, calc_diff(*a1_1, sum[i] - *a1_1, *a3_1 - sum[i], sum[N-1] - *a3_1));
        ans = min(ans, calc_diff(*a1_2, sum[i] - *a1_2, *a3_1 - sum[i], sum[N-1] - *a3_1));
        ans = min(ans, calc_diff(*a1_0, sum[i] - *a1_0, *a3_2 - sum[i], sum[N-1] - *a3_2));
        ans = min(ans, calc_diff(*a1_1, sum[i] - *a1_1, *a3_2 - sum[i], sum[N-1] - *a3_2));
        ans = min(ans, calc_diff(*a1_2, sum[i] - *a1_2, *a3_2 - sum[i], sum[N-1] - *a3_2));
    }

    printf("%lld\n", ans);
}
