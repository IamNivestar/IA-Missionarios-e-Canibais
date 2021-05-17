#ifndef ITERATIVE_DEEPENIG_C
#define ITERATIVE_DEEPENIG_C

#include <stdio.h>
#include <stdlib.h>
#include  "tree.h"

void iterative_deepening(node *root, node *tree, int deep_max, int deep, int *finish){ //travels the tree using
    if(tree->leaf.b == 0 && tree->leaf.m == 0 && tree->leaf.c == 0){
        *finish = 1;
        return;
    }
    if(deep == deep_max)
        return;
    int m, c, result = 1;
    m = tree->leaf.m;
    c = tree->leaf.c;
    leafs leaf;
    leaf = tree->leaf;

    if(tree->leaf.b == 1){//if the boat is on the initial margin
        if(m - 2 >= 0){ //if is possible travel two missionaries 
            leaf.m -= 2;
            leaf.b = 0;
            verification_loop(root, leaf, &result); // check if these permutation already happend
            
            if(verification_valid(leaf) && result){ //verification if these permutation is valid
                insert(tree, leaf, 1); //insert the node in the tree
                iterative_deepening(root, tree->prox, deep_max, deep+1, finish);

            }
            leaf = tree->leaf;
            result = 1;
        }
        if(m - 1 >= 0 && c - 1 >= 0){
            leaf.m -= 1;
            leaf.c  -= 1;
            leaf.b = 0;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }
                else if(tree->prox != NULL && tree == root){
                    insert(tree->prox, leaf, 0);
                    node *aux = tree->prox;
                    while(aux->bro != NULL)
                        aux = aux->bro;
                    iterative_deepening(root, aux, deep_max, deep+1, finish);
                }    
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
            leaf = tree->leaf;
            result = 1;
        }        if(c - 2 >= 0){
            leaf.c -= 2;
            leaf.b = 0;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }
                else if(tree->prox != NULL && tree == root){
                    insert(tree->prox, leaf, 0);
                    node *aux = tree->prox;
                    while(aux->bro != NULL)
                        aux = aux->bro;
                    iterative_deepening(root, aux, deep_max, deep+1, finish);
                }       
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
            leaf = tree->leaf;
            result = 1;
        }
        if(m - 1 >= 0){
            leaf.m -= 1;
            leaf.b = 0;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }
                else if(tree->prox != NULL && tree == root){
                    insert(tree->prox, leaf, 0);
                    node *aux = tree->prox;
                    while(aux->bro != NULL)
                        aux = aux->bro;
                    iterative_deepening(root, aux, deep_max, deep+1, finish);
                }       
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
            leaf = tree->leaf;
            result = 1;
        }
        if(c - 1 >= 0){
            leaf.c -= 1;
            leaf.b = 0;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }
                else if(tree->prox != NULL && tree == root){
                    insert(tree->prox, leaf, 0);
                    node *aux = tree->prox;
                    while(aux->bro != NULL)
                        aux = aux->bro;
                    iterative_deepening(root, aux, deep_max, deep+1, finish);
                }       
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
        }
    } else { //if the boat is on the opposite margin
        if(m + 2 <= 3){ //check if is possible travel with two missionaries
            leaf.m += 2;
            leaf.b = 1;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                insert(tree, leaf, 1);
                iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
            }
            leaf = tree->leaf;
            result = 1;
        }
        if(m + 1 <= 3 && c + 1 <= 3){
            leaf.m += 1;
            leaf.c  += 1;
            leaf.b = 1;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }    
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
            leaf = tree->leaf;
            result = 1;
        }
        if(c + 2 <= 3){
            leaf.c += 2;
            leaf.b = 1;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }    
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
            leaf = tree->leaf;
            result = 1;
        }
        if(m + 1 <= 3){
            leaf.m += 1;
            leaf.b = 1;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }    
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
            leaf = tree->leaf;
            result = 1;
        }
        if(c + 1 <= 3){
            leaf.c += 1;
            leaf.b = 1;
            verification_loop(root, leaf, &result);
            if(verification_valid(leaf) && result){
                if(tree->prox == NULL){
                    insert(tree, leaf, 1);
                    iterative_deepening(root, tree->prox, deep_max, deep+1, finish);
                }    
                else{
                    insert(tree, leaf, 0);
                    iterative_deepening(root, tree->bro, deep_max, deep, finish);
                }
            }
        }
    }
}

void print_deep(node *root){ //print the tree by breadth first search 
    if(root == NULL)
        return;
    else{
        printf("%d %d %d\t", root->leaf.b, root->leaf.m, root->leaf.c); //imprimo o nó raiz
        node *aux = root->bro;
        while(aux != NULL){ //print all brothers
            printf("%d %d %d\t", aux->leaf.b, aux->leaf.m, aux->leaf.c);
            aux = aux->bro;
        }
        aux = root;
        printf("\n");
        while(aux != NULL){ // recursion 
            if(aux->prox!= NULL){
                print_deep(aux->prox);
            }
        aux = aux->bro;
        }
    }
}


#endif