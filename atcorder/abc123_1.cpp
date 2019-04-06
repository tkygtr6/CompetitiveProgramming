#include <stdio.h>
#define NUM 5

int main(void){
    int a[NUM];
    int k;
    for(int i = 0; i < 5; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);

    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if (a[j] - a[i] > k){
                printf(":(\n");
                return 0;
            }
        }
    }

    printf("Yay!\n");
    return 0;
}
