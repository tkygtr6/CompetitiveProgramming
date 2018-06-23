#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001

struct Node{
    int num;
    struct Node *parent;
    struct Node *left_child;
    struct Node *right_bro;
};

struct Node node[MAX];

int calc_depth(int num){
    if (node[num].parent == NULL){
        return 0;
    }
    return calc_depth(node[num].parent->num) + 1;
}

void calc_type(int num, char* s){
    if(node[num].parent == NULL){
        strcpy(s, "root");
        return;
    }
    if(node[num].left_child == NULL){
        strcpy(s, "leaf");
        return;
    }
    strcpy(s, "internal node");
    return;
}

void print_children(int num){
    struct Node *nd = node[num].left_child;
    bool is_first = true;
    while(nd){
       if(is_first){
           printf("%d", nd->num);
           is_first = false;
       }else{
           printf(", %d", nd->num);
       }
       nd = nd->right_bro;
    }
}


void output(int n){
    for(int i = 0; i < n; i++){
        printf("node %d: ", i);

        if(node[i].parent != NULL){
            printf("parent = %d, ", node[i].parent->num);
        }else{
            printf("parent = -1, ");
        }

        printf("depth = %d, ", calc_depth(i));
        
        char s[30];
        calc_type(i, s);
        printf("%s, ", s);

        printf("[");
        print_children(i);
        printf("]\n");
    }

    return;
}

int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        node[i].num = i;
        node[i].parent = NULL;
        node[i].left_child = NULL;
        node[i].right_bro = NULL;
    }

    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        int left_child_node_num = -1;
        int child_node_num;

        int node_num;
        scanf("%d", &node_num);
        for(int j = 0; j < node_num; j++){
            scanf("%d", &child_node_num);
            if (j == 0){
                node[num].left_child = &(node[child_node_num]);
            }
            if(left_child_node_num != -1){
                node[left_child_node_num].right_bro = &(node[child_node_num]);
            }
            node[child_node_num].parent = &(node[num]);
            left_child_node_num = child_node_num;
        }
    }

    output(n);

    return 0;
}
