#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    char c;
    for(int i = 0; i < N; i++){
       scanf("%c", &c);
       if(c == 'Y'){
           printf("Four\n");
           return 0;
       }
    }
    printf("Three\n");
    return 0;
}
