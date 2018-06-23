#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define ll long long


/*
int main(void){
    double min_ = 1000000000000000;

    for(ll k = 10000; k > 0; k--){
        ll i = k * 10000000000 + 9999999999;

        ll s = 0;
        ll t = i % 100000;
        s += (t/100000)%10 + (t/10000)%10 + (t/1000)%10 + (t/100)%10 + (t/10)%10 + t%10;
        t = (i/100000) % 100000;
        s += (t/100000)%10 + (t/10000)%10 + (t/1000)%10 + (t/100)%10 + (t/10)%10 + t%10;
        t = (i/10000000000) % 100000;
        s += (t/100000)%10 + (t/10000)%10 + (t/1000)%10 + (t/100)%10 + (t/10)%10 + t%10;
        t = (i/1000000000000000) % 100000;
        s += (t/100000)%10 + (t/10000)%10 + (t/1000)%10 + (t/100)%10 + (t/10)%10 + t%10;

        if(i/(double)s <= min_){
            min_ = i/(double)s;
            printf("n/s:%f\t n: %lld\t s: %lld\n", min_, k, s);
        }
    }
}

*/

vector<long long> v;

int main(void){
    for(int i = 1; i <= 9; i++){
        v.push_back(i);
    }

    for(int i = 1; i <= 9; i++){
        v.push_back(i*10 + 9);
    }

    for(int i = 1; i <= 9; i++){
        for(int j = i + 1; j <= (i + 1) * 10; j++){
            v.push_back(j * pow(10, i + 1) - 1);
        }
    }

    for(int i = 11; i <= 100; i++){
        v.push_back(i * pow(10, 11) - 1);
    }

    for(int i = 11; i <= 110; i++){
        v.push_back(i * pow(10, 12) - 1);
    }

    for(int i = 12; i <= 101; i++){
        v.push_back(i * pow(10, 13) - 1);
    }


    int K;
    scanf("%d", &K);

    for(int i = 0; i < K; i++){
        printf("%lld\n", v[i]);
    }
}
