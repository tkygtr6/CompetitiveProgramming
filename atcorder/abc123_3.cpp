#include <stdio.h>
#define ll long long
#define NUM 5

int main(void){
    ll N;
    ll a[NUM];
    scanf("%lld", &N);
    for(int i = 0; i < 5; i++){
        scanf("%lld", &a[i]);
    }

    ll min_;
    min_ = a[0];
    for(int i = 1; i < 5; i++){
        min_  = a[i] < min_ ? a[i] : min_;
    }

    ll ans = 4 + N / min_;
    if (N % min_ != 0){
        ans += 1;
    }
    
    printf("%lld\n", ans);
    return 0;
}
