#include <stdio.h>

bool isPrime(int x){
    if(x == 2){
        return true;
    }else if(x == 3){
        return true;
    }else{
        for(int j = 2; j * j <= x; j++){
            if(x % j == 0) return false;
        }
        return true;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int count = 0;
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        if(isPrime(num)){
            count++;
        }
    }

    printf("%d\n", count);
}
