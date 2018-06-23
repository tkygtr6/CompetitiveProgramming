#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int main(void){
    int i, j;
    scanf("%d %d", &i, &j);

    printf("%d\n", gcd(i, j));
}
