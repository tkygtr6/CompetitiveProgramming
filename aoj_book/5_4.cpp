#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#define NUM1 2000000
#define NUM2 1999997
using namespace std;

int str2num(char s){
    if(s == 'A'){
        return 1;
    }else if(s == 'C'){
        return 2;
    }else if(s == 'G'){
        return 3;
    }else if(s == 'T'){
        return 4;
    }
    return 100;
}

char num2str(int n){
    if(n == 1){
        return 'A';
    }else if(n == 2){
        return 'C';
    }else if(n == 3){
        return 'G';
    }else if(n == 4){
        return 'T';
    }
    return 'T';
}

int str2hash(string s){
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        num += str2num(s[i]) * pow(5, i);
    }
    return num;
}

string hash2str(int num){
    string s = "";
    while(num){
        s.push_back(num2str(num % 5));
        num = num / 5;
    }
    return s;
}

void insert_number(int num, int* h1){
    int k = 0;
    while(k < NUM1){
        if(h1[(num % NUM1 + k * ((num + 1) % NUM2)) % NUM1] == num){
            return;
        }else if(h1[(num % NUM1 + k * ((num + 1) % NUM2)) % NUM1] == -1){
            h1[(num % NUM1 + k * ((num + 1) % NUM2)) % NUM1] = num;
            return;
        }else{
            k++;
        }
    }
    printf("error: %d\n", num);
    return;
}

bool in_number(int num, int* h1){
    int k = 0;
    while(k < NUM1){
        if(h1[(num % NUM1 + k * ((num + 1) % NUM2)) % NUM1] == num){
            //printf("%d\n", (num % NUM1 + k * ((num + 1) % NUM2)) % NUM1);
            return true;
        }else if(h1[(num % NUM1 + k * ((num + 1) % NUM2)) % NUM1] == -1){
            return false;
        }else{
            k++;
        }
    }
    return false;
}


int main(void){
    int n;
    scanf("%d", &n);

    int h1[NUM1];
    for(int i = 0; i < NUM1; i++){
        h1[i] = -1;
    }

    char command[10];
    char c_char[13];
    for(int i = 0; i < n; i++){
       scanf("%s %s", command, c_char);
       if(command[0] == 'i'){
           string s_ = c_char;
           insert_number(str2hash(s_), h1);
       }else{
           string s_ = c_char;
           if(in_number(str2hash(s_), h1)){
               printf("yes\n");
           }else{
               printf("no\n");
           }
       }
    }
}
