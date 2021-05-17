#ifndef TREE_H
#define TREE_H

typedef struct Leafes{
    int m;  //missionary (amount left to cross)
    int c;  //cannibals  
    int b;  //boat  (1 - start margin and 0 - end margin)
}leafs;

typedef struct Node{ 
    leafs leaf;  // state or permutation
    struct Node *prox;  
    struct Node *bro; //node brother ( same deep)
}node;

typedef struct Head{
    node *first;  // root node
}head;


node *new_node();

void print_tree(node *root);

void insert(node *root, leafs states, int brother_insert);

void verification_loop(node *root, leafs state, int *result);;

int verification_valid(leafs state);

void clean(node *root);

void build_tree(node *root, node *tree);

//----------------------------

void iterative_deepening(node *root, node *tree, int deep_max, int deep, int *finish);

void print_deep(node *root);

#endif