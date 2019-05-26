#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#define NUM 17
 
using namespace std;
 
int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
 
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        long long sum_;
        if(i <= k - 1){
            sum_ = pow(2.0, NUM - ceill(log2((long double) k/i)));
            sum += sum_;
            //cout << ceill(log2((long double)k/i)) << endl;
        }else{
            //sum_ = pow(2.0, NUM);
            //cout << sum_ << endl;
        }
    }
 
    printf("%.16Lf\n", (long double) sum / powl(2, NUM) / n + (long double)(max(n-k+1,0))/n);
}
