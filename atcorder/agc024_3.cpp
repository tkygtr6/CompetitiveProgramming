#include <stdio.h>
 
#define N_MAX 2000000
int N[N_MAX];
 
bool cant_make(int n){
	if(n < N[n]){
        return true;
	}
    for(int i = 1; 0 <= n - i; i++){
        if(N[i] - N[n - i] > i){
            return true;
        }
    }
    return false;
}
 
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &N[i]);
    }
 
 
    int sum = 0;
    if(N[0] != 0){
        printf("-1\n");
        return 0;
    }
 
    for(int i = 1; i < n; i++){
        if(N[i] == 0){
        }else if (N[i] == 1){
            sum += 1;
        }else if(N[i - 1] + 1 == N[i]){
            sum += 1;
        }else{
            sum += N[i];
            if(cant_make(i)){
                printf("-1\n");
                return 0;
            }
        }
    }
    
    printf("%d\n", sum);
}
 
