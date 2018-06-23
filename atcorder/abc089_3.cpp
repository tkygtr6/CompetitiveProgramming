#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int num[5];
    for(int i = 0; i < 5; i++){
        num[i] = 0;
    }

    char name[11];
    for(int i = 0; i < N; i++){
        scanf("%s", name);
        switch(name[0]){
            case 'M':
                num[0]++;
                break;
            case 'A':
                num[1]++;
                break;
            case 'R':
                num[2]++;
                break;
            case 'C':
                num[3]++;
                break;
            case 'H':
                num[4]++;
                break;
        }
    }
    
    long int sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 5; k++){
                sum += num[i] * num[j] * num[k];
            }
        }
    }

    printf("%lu\n", sum);
    return 0;
}
