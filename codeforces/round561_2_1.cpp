#include <stdio.h>
#include <iostream>
#include <string>
#define NUM 30

using namespace std;

long long nC2(int n){
    if(n == 0 || n == 1){
        return 0;
    }else if(n == 2){
        return 1;
    }

    return n * (n - 1) / 2;
}

int main(void){
    int n;
    string s;

    int a[NUM];
    for(int i = 0; i < NUM; i++){
        a[i] = 0;
    }

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> s;
        a[s[0] - 'a']++;
    }
    
    long long sum = 0;
    for(int i = 0; i < NUM; i++){
        if(a[i] == 0 || a[i] == 1 || a[i] == 2){
            continue;
        }
        int num1 = a[i] / 2;
        int num2 = a[i] - num1;

        sum += nC2(num1) + nC2(num2);
    }

    printf("%lld\n", sum);
}
