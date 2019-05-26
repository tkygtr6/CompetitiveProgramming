#include <stdio.h>
#include <iostream>
#include <vector>
#define NUM 101
using namespace std;

vector<int> a;

int main(void){
    int N, x;
    scanf("%d", &N);
    scanf("%d", &x);

    int a_;
    for(int i = 0; i < N; i++){
        scanf("%d", &a_);
        a.push_back(a_);
    }

    sort(a.begin(), a.end(), [](int a, int b){return a < b;});
    for(int i = 0; i < N; i++){
        printf("%d\n", a[i]);
    }

    int sum = 0;
    for(int i = 0; i < N-1; i++){
        sum += a[i];
        if(sum > x){
            printf("%d\n", i);
            return 0;
        }
    }
}
