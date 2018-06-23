#include <stdio.h>
#include <iostream>

int main(void){
    int n;
    scanf("%d", &n);

    int s[10000];
    for(int i = 0; i < n; i++){
       scanf("%d", &s[i]);
    }

    int q;
    scanf("%d", &q);

    int t[10000];
    for(int i = 0; i < q; i++){
       scanf("%d", &t[i]);
    }
   
    int cnt = 0;
    for(int i = 0; i < q; i++){
        for(int j = 0; j < n; j++){
            if (t[i] == s[j]){
                cnt += 1;
                break;
            }
        }
    }

    printf("%d\n", cnt);
}
