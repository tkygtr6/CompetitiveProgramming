#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct Node{
    int num;
    Node* parent;
    Node* right;
    Node* left;
};

struct Node node[25];

int get_sibling(int n){
    if(!node[n].parent)
        return -1;
    struct Node *r = node[n].parent->right;
    struct Node *l = node[n].parent->left;
    if(!(r && l)){
        return -1;
    }
    if(r->num == n){
        return l->num;
    }
    if(l->num == n){
        return r->num;
    }
    return -1;
}

int calc_degree(int n){
    int num = 0;
    if(node[n].right)
        num++;
    if(node[n].left)
        num++;
    return num;
}

int calc_depth(int n){
    if(!node[n].parent)
        return 0;
    return calc_depth(node[n].parent->num) + 1;
}

int calc_height(int n){
    if((!node[n].left) && (!node[n].right)){
        return 0;
    }
    if(!node[n].left){
        return calc_height(node[n].right->num) + 1;
    }
    if(!node[n].right){
        return calc_height(node[n].left->num) + 1;
    }
    return max(calc_height(node[n].left->num), calc_height(node[n].right->num)) + 1;
}

string get_type(int n){
    if(!node[n].parent){
        return string("root");
    }
    if(calc_height(n) == 0){
        return string("leaf");
    }
    return string("internal node");
}

void output(int n){
    for(int i = 0; i < n; i++){
        printf("node %d: ", i);

        if(node[i].parent){
            printf("parent = %d, ", node[i].parent->num);
        }else{
            printf("parent = -1, ");
        }

        printf("sibling = %d, ", get_sibling(i));

        printf("degree = %d, ", calc_degree(i));

        printf("depth = %d, ", calc_depth(i));

        printf("height = %d, ", calc_height(i));

        cout << get_type(i);

        printf("\n");

    }
}

int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        node[i].parent = NULL;
        node[i].right = NULL;
        node[i].left = NULL;
    }

    for(int i = 0; i < n; i++){
        int nm, a, b;
        scanf("%d %d %d", &nm, &a, &b);

        node[nm].num = nm;

        if(a != -1){
            node[nm].left = &(node[a]);
            node[a].parent = &(node[nm]);
        }
        if(b != -1){
            node[nm].right = &(node[b]);
            node[b].parent = &(node[nm]);
        }
    }

    output(n);
}
