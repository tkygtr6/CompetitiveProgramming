#include <stdio.h>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    long long n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        long long  a_;
        cin >> a_;
        a[i] = max(a_, a_ * (-1));
    }

    sort(a.begin(), a.end());
    long long sum = 0;
    for(int i = 0; i < n; i++){
        auto itr = upper_bound(a.begin() + i + 1, a.end(), a[i] * 2);
        sum += max((int)distance(a.begin() + i + 1, itr), 0);
    }

    printf("%lld\n", sum);
}
