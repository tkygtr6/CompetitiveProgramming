#include <stdio.h>

int main(void){
    char a[100][100];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 50; j++){
            a[j][i] = '.';
        }
        for(int j = 50; j < 100; j++){
            a[j][i] = '#';
        }
    }

    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);

    for(int i = 0; i < B - 1; i++){
        a[(i / 50) * 2][(i % 50) * 2] = '#';
    }
    for(int i = 0; i < A - 1; i++){
        a[99 - (i / 50) * 2][(i % 50) * 2] = '.';
    }

    printf("100 100\n");
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
