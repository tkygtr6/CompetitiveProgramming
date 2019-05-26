#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 51

using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);

    char s[NUM];

    cin >> s;
    
    s[k-1] = s[k-1] - 'A' + 'a';

    printf("%s\n", s);
}
