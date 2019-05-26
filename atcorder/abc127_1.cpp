#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 100

using namespace std;

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);

    if(13 <= a){
        printf("%d\n", b);
    }else if(6 <= a){
        printf("%d\n", b / 2);
    }else{
        printf("0\n");
    }
}
