#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void){
    int k;
    scanf("%d", &k);

    string s;
    for(int i = 0; i < 2020; i++){
        s += "aiueo";
    }

    bool have_ans = false;
    for(int i = 5; i * i <= k; i++){
        if(k % i != 0){
            continue;
        }
        int n = i;
        int m = k / n;
        have_ans = true;

        for(int j = 0; j < m; j++){
            cout << s.substr(j % 5, n);
        }
        break;
    }

    if(have_ans){
        printf("\n");
    }else{
        printf("-1\n");
    }
}

