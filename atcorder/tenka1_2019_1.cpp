#include <stdio.h>

int main(void){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if(A<C && C<B){
        printf("Yes\n");
        return 0;
    }
    if(A>C && C>B){
        printf("Yes\n");
        return 0;
    }

    printf("No\n");
    return 0;
}
