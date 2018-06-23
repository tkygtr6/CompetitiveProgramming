#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int key; Node *parent;
    Node *left;
    Node *right;
};

struct Node *NIL, *root;

void init(){
    root = NIL;
}

void insert(Node* z){
    struct Node* y = NIL; // xの親
    struct Node* x = root;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;

    if(y == NIL){
        root = z;
    }
    else if(z->key < y->key){
        y->left = z; 
    }else{
        y->right = z;
    }
}

struct Node* find_number(Node* x, int num){
    if(x == NIL){
        return NIL;
    }
    if(x->key == num){
        return x;
    }
    if(x->key < num){
        return find_number(x->right, num);
    }
    return find_number(x->left, num);
}

void delete_node_with_no_child(struct Node* x){
    if(x == NIL){
        return;
    }
    if(x->parent == NIL){
        free(x);
        return;
    }
    if(x->parent->left == x){
        x->parent->left = NIL;
        free(x);
        return;
    }
    if(x->parent->right == x){
        x->parent->right = NIL;
        free(x);
        return;
    }
    return;
}

void delete_node_with_one_child(struct Node* x){
    struct Node* parent_node = x->parent;
    struct Node* children_node;
    if(x->left == NIL){
        children_node = x->right;
    }else if(x->right == NIL){
        children_node = x->left;
    }else{
        printf("error in delete_node_with_one_child(type 0)");
        return;
    }

    if(parent_node->right == x){
        parent_node->right = children_node; 
    }else if(parent_node->left == x){
        parent_node->left = children_node;
    }else{
        printf("error in delete_node_with_one_child(type 1)");
        return;
    }

    children_node->parent = parent_node;
    free(x);
    return;
}

struct Node* get_minimum(struct Node* x){
    if(x->left == NIL){
        return x;
    }
    return get_minimum(x->left);
}

struct Node* get_next_node(struct Node* x){
    if(x->right != NIL){
        return get_minimum(x->right);
    }

    struct Node* y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void delete_number(int num);

void delete_node_with_two_children(struct Node* x){
    struct Node* next_node = get_next_node(x);
    int key = next_node->key;

    delete_number(key);
    x->key = key;
}

int get_children_num(struct Node* x){
    if (x->right == NIL && x->left == NIL)
        return 0;
    if(x->right != NIL && x->left != NIL)
        return 2;
    return 1;
}

void delete_number(int num){
    struct Node* x = find_number(root, num);
    switch(get_children_num(x)){
        case 0:
            delete_node_with_no_child(x);
            break;
        case 1:
            delete_node_with_one_child(x);
            break;
        case 2:
            delete_node_with_two_children(x);
            break;
    }
     return;
}

void print_node_inorder(Node* x){
    if(x == NIL){
        return;
    }
    print_node_inorder(x->left);
    printf(" %d", x->key);
    print_node_inorder(x->right);
}

void print_node_pre(Node* x){
    if(x == NIL){
        return;
    }
    printf(" %d", x->key);
    print_node_pre(x->left);
    print_node_pre(x->right);
}

void print_(){
    print_node_inorder(root);
    printf("\n");
    print_node_pre(root);
    printf("\n");
}

int main(void){
    void init();
    
    int m;
    scanf("%d", &m);

    string com;

    for(int i = 0; i < m; i++){
        cin >> com;
        if(com == "insert"){
            struct Node* n;
            n = (struct Node*)malloc(sizeof(struct Node));
            n->right = NIL;
            n->left = NIL;
            n->parent = NIL;
            scanf("%d", &n->key);
            insert(n);
        }else if(com == "print"){
            print_();
        }else if(com == "find"){
            int num;
            scanf("%d", &num);
            if(find_number(root, num) != NIL){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else if(com == "delete"){
            int num;
            scanf("%d", &num);
            delete_number(num);
        }else{
            printf("invalid command");
            cout << com;
        }
    }

    return 0;
}
