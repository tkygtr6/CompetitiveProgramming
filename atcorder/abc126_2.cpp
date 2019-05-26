#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    char s[10];
    scanf("%s", s);

    int i1 = (s[0] -'0') * 10 + (s[1] - '0');
    int i2 = (s[2] -'0') * 10 + (s[3] - '0');

    if(1 <= i1 && i1 <= 12){
        if(1 <= i2 && i2 <= 12){
            printf("AMBIGUOUS\n");
        }else{
            printf("MMYY\n");
        }
    }else{
        if(1 <= i2 && i2 <= 12){
            printf("YYMM\n");
        }else{
            printf("NA\n");
        }
    }
}
