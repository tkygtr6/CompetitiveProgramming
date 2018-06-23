#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct Node{
    int key;
    Node *prev, *next;
}Node;

Node* nil = (Node*)malloc(sizeof(Node));

void initialize(void){
    nil -> key = -1;
    nil -> prev = nil;
    nil -> next = nil;
}

void insert(int value){
    Node* n = (Node*)malloc(sizeof(Node));
    nil->next->prev = n;
    n->key = value;
    n->prev = nil;
    n->next = nil->next;
    nil->next = n;
}

void delete_(int value){
    Node* n = nil->next;
    while(1){
        if(n == nil){
            break;
        }
        if(n->key == value){
            Node* n_prev = n->prev;
            Node* n_next = n->next;
            n->prev->next = n_next;
            n->next->prev = n_prev;
            free(n);
            break;
        }
        n = n->next;
    }
}

void deleteFirst(){
    Node* n = nil->next;
    n->next->prev = nil;
    nil->next = n->next;
    free(n);
}

void deleteLast(){
    Node* n = nil->prev;
    n->prev->next = nil;
    nil->prev = n->prev;
    free(n);
}

void print_elements(){
    bool is_first = true;
    Node* n = nil->next;
    while(n != nil){
        if(is_first){
            is_first = false;
        }else{
            printf(" ");
        }
        printf("%d", n->key);
        n = n->next;
    }
    printf("\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    initialize();
    
    for(int i = 0; i < n; i++){
        char s[20];
        int value;
        scanf("%s", s);
        string s_ = s;

        if(s_ == "insert"){
            scanf("%d", &value);
            insert(value);
        }else if(s_ == "delete"){
            scanf("%d", &value);
            delete_(value);
        }else if(s_ == "deleteFirst"){
            deleteFirst();
        }else if(s_ == "deleteLast"){
            deleteLast();
        }
    }
    print_elements();
}
