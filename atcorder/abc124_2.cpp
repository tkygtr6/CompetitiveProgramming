#include <stdio.h>
#include <iostream>
using namespace std;

int H[100];

int main(void){
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &H[i]);
    }

    int ans = 1;
    int mx = H[0];
    for(int i = 1; i < N; i++){
        if(mx <= H[i]){
            ans++;
            mx = H[i];
        }
    }

    printf("%d\n", ans);
}
