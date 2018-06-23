#include <stdio.h>

int main(void){
    char ch[4];
    for(int i = 0; i < 3; i++){
        scanf("%s", ch);
        printf("%c", ch[i]);
    }
    printf("\n");

    return 0;
}
