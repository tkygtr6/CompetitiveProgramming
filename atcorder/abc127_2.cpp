#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 100

using namespace std;

long long r, D;

long long calc(long long x){
    return x * r - D;
}

int main(void){
    long long x;
    scanf("%lld %lld %lld", &r, &D, &x);

    for(int i = 0; i < 10; i++){
        x = calc(x);
        printf("%lld\n", x);
    }
}
