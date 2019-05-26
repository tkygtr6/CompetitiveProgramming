#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
#define NUM 100010

char s[NUM];
vector<int> v0;
vector<int> v1;

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    scanf("%s", s);
    
    if(s[0] == '1'){
        v0.push_back(0);
    }else{
        v0.push_back(-1);
        v1.push_back(-1);
    }

    int before = s[0];
    for(int i = 1; i < N; i++){
        if(before == '0' && s[i] == '1'){
            v0.push_back(i);
        }
        if(before == '1' && s[i] == '0'){
            v1.push_back(i-1);
        }
        before = s[i];
    }

    if(s[N-1] == '1'){
        v1.push_back(N-1);
    }else{
        v0.push_back(N);
        v1.push_back(N);
    }

    int ans = 0;
    for(int i = 0; i+K < v0.size(); i++){
        ans = max(ans, v1[i+K]-v0[i]+1);
    }
    printf("%d\n", ans);

    /*
    for(int i = 0; i < v0.size(); i++){
        printf("%d ", v0[i]);
    }
    printf("\n");
    for(int i = 0; i < v1.size(); i++){
        printf("%d ", v1[i]);
    }
    printf("\n");
    */
}
