#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int main(void){
    long long N;
    scanf("%lld", &N);

    long long sum;
    for(int i = 1; i < sqrt((long double)N); i++){
        if(N % i != 0){
            continue;
        }

        long long a = i;
        long long m = N / a - 1;
        if(a < m){
            sum += m;
        }

        a = N / i;
        m = N / a - 1;
        if(a < m){
            sum += m;
        }
    }

    printf("%lld\n", sum);
}

