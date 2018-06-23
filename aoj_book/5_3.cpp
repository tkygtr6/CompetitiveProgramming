#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int get_middle(int head, int tail){
    if((tail - head) % 2){
        return (tail + head) / 2;
    }else{
        return (tail + head + 1) / 2;
    }
}

bool binary_search(int* s, int num, int head, int tail){
    if (head == tail){
        if(s[head] == num){
            return true;
        }else{
            return false;
        }
    }else if(tail - head == 1){
        if(s[head] == num || s[tail] == num){
            return true;
        }else{
            return false;
        }
    }
    int middle = get_middle(head, tail);
    if(s[middle] == num){
        return true;
    }else if(s[middle] > num){
        return binary_search(s, num, head, middle - 1);
    }else if(s[middle] < num){
        return binary_search(s, num, middle + 1, tail);
    }
    printf("error\n");
    return false;
}      

int main(void){
    int n;
    scanf("%d", &n);

    int s[100000];
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }

    int q;
    scanf("%d", &q);

    int t[50000];
    for(int i = 0; i < q; i++){
       scanf("%d", &t[i]);
    }

    int cnt = 0;
    for(int i = 0; i < q; i++){
        if(binary_search(s, t[i], 0, n - 1)){
            cnt++;
        }
    }

    printf("%d\n", cnt);
}

