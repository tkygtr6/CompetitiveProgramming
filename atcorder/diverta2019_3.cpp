#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define NUM 10010
using namespace std;

int main(void){
    int a_end = 0;
    int b_end = 0;
    int ab_end = 0;
    int sum = 0;

    int N;
    scanf("%d", &N);

    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    for(int i = 0; i < N; i++){
        if(S[i][0] == 'B'){
            if(S[i][S[i].size()-1] == 'A'){
                ab_end++;
            }else{
                b_end++;
            }
        }else{
            if(S[i][S[i].size()-1] == 'A'){
                a_end++;
            }else{

            }
        }
        for(int j = 0; j < S[i].size() - 1; j++){
            if (S[i][j] == 'A' && S[i][j + 1] == 'B'){
                sum++;
            }
        }
    }

    if(ab_end != 0){
        sum += ab_end - 1;
        if(a_end >= 1){
            sum++;
            a_end--;
        }
        if(b_end >= 1){
            sum++;
            b_end--;
        }
        sum += min(a_end, b_end);
    }else{
        sum += min(a_end, b_end);
    }

    printf("%d\n", sum);
}

