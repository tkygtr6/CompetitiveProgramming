#include <stdio.h>
#include <iostream>

#define MAX 200000

int sum_time = 0;

typedef struct process{
    char name[20];
    int time;
}process;

process q[MAX];
int head = 0;
int tail = 0;
bool is_full = false;
bool is_empty = false;

void enqueue(process p){
    is_empty = false;
    q[tail] = p;
    if(tail == MAX - 1){
        tail = 0;
    }else{
        tail += 1;
    }
    if(tail == head){
        is_full = true;
    }
}


process dequeue(){
    process p;
    if(head == MAX - 1){
        p = q[head];
        head = 0;
    }else{
        p = q[head];
        head += 1;
    }
    if(head == tail){
        is_empty = true;
    }
    return p;
}

int main(void){
    int n, quantum;
    scanf("%d %d", &n, &quantum);
    
    for(int i = 0; i < n; i++){
        process p;
        scanf("%s %d", p.name, &p.time);
        enqueue(p);
    }

    while(!is_empty){
        process p = dequeue();
        if(p.time > quantum){
            sum_time += quantum;
            p.time -= quantum;
            enqueue(p);
        }else{
            sum_time += p.time;
            printf("%s %d\n", p.name, sum_time);
        }
    }
}

