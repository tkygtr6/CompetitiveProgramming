#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void){
    int A_, B_;
    scanf("%d", &A_);
    scanf("%d", &B_);

    string A = to_string(A_);
    string B = to_string(B_);

    string A_cycle = "";
    A_cycle += A[0];
    A_cycle += A[1];
    A_cycle += A[2];
    A_cycle += A[1];
    A_cycle += A[0];
    int A_cycle_int = stoi(A_cycle);

    string B_cycle = "";
    B_cycle += B[0];
    B_cycle += B[1];
    B_cycle += B[2];
    B_cycle += B[1];
    B_cycle += B[0];
    int B_cycle_int = stoi(B_cycle);

    int ans = B_cycle_int / 100 - A_cycle_int / 100;
    if(A_ > A_cycle_int){
        ans -= 1;
    }
    if(B_ >= B_cycle_int){
        ans += 1;
    }
    printf("%d\n", ans);
}
