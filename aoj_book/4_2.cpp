#include <stdio.h>
#include <stdlib.h>

bool is_operator(char* s){
    if(s[0] == '+' || s[0] == '-' || s[0] == '*'){
        return true;
    }else{
        return false;
    }
}

int pop(int* A, int* cnt){
    (*cnt)--;
    return A[*cnt];
}

void push(int* A, int* cnt, int value){
    A[*cnt] = value;
    (*cnt)++;
}

int main(void){
    int A[200];
    char s[20];
    int cnt = 0;

    while(scanf("%s", s) != -1){
        if(is_operator(s)){
            int a = pop(A, &cnt);
            int b = pop(A, &cnt);
            if(s[0] == '+'){
                push(A, &cnt, b + a);
            }else if(s[0] == '-'){
                push(A, &cnt, b - a);
            }else if(s[0] == '*'){
                push(A, &cnt, b * a);
            }
        }else{
            push(A, &cnt, atoi(s));
        }
    }
    printf("%d\n", A[0]);
}
