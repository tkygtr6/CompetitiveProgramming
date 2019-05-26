#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

char s[100010];

int main(void){
    scanf("%s", s);

    int ans = 0;
    for(int i = 0; s[i] != '\0'; i++){
        int s_ = (i%2)?'0':'1';
        if(s[i] == s_){
            ans++;
        }
    }

    printf("%d\n", min(ans, (int)strlen(s)-ans));
}
