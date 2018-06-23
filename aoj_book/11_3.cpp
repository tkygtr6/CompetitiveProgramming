#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int LCS(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    int dp[l1 + 1][l2 + 1];
    for(int i = 0; i < l1 + 1; i++){
        for(int j = 0; j < l2 + 1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[l1][l2];
}

int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1;
        cin >> s2;
        printf("%d\n", LCS(s1, s2));
    }


    return 0;
}
