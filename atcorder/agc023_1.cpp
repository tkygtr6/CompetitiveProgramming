#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

#define N_MAX 200010

long long func(long long n){
    if(n == 1)
        return 0;
    return n * (n - 1) / 2;
}

int main(){
    int N;
    scanf("%d", &N);

    long long A[N_MAX + 1];

    A[0] = 0;
    for(int i = 0; i < N; i++){
        long long A_;
        scanf("%lld", &A_);
        A[i + 1] = A[i] + A_;
    }

    map<long long, int> mapTable;
    for(int i = 0; i <= N; i++){
        auto it = mapTable.find(A[i]);
        if(it == mapTable.end()){
            mapTable[A[i]] = 1;
        }else{
            it->second += 1;
        }
    }

    long long sum = 0;
    for(auto it = mapTable.begin(); it != mapTable.end(); ++it){
        cout << it->first << ' ' << it->second << endl;
        sum += func(it->second);
    }
    
    printf("%lld\n", sum);
}

