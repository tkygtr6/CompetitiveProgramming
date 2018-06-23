#include <stdio.h>

int n, q;
int A[20];

bool solve(int index, int target){
    if(target == 0){
        return true;
    }else if(target < 0){
        return false;
    }

    if(index == 0){
        if(target == A[0]){
            return true;
        }else{
            return false;
        }
    }

    if(solve(index - 1, target - A[index])){
        return true;
    }
    if(solve(index - 1, target)){
        return true;
    }
    return false;
}

int main(void){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int m;
        scanf("%d", &m);
        if(solve(n - 1, m)){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }

    return 0;
}
