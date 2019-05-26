#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int A, B;
    scanf("%d %d", &A, &B);

    int ans = A + (A - 1);
    ans = max(ans, A+B);
    ans = max(ans, B + (B-1));

    printf("%d\n", ans);
}
