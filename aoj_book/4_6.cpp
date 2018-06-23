#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(void){
    stack<int> S1;
    stack<pair<int, int>> S2;
    char ch;
    int sum = 0;
    for(int i = 0; cin >> ch; i++){
        if(ch == '\\'){
            S1.push(i);
        }else if(ch == '/'){
            if(!S1.empty()){
                sum += i - S1.top();
                S1.pop();
            }
        }
    }
    
    printf("%d\n", sum);

    return 0;
}
