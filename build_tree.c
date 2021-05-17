#ifndef BUILD_TREE_C
#define BUILD_TREE_C
#include <stdio.h>
#include <stdlib.h>
#include  "tree.h"

void build_tree(node *root, node *tree){ //buid tree
    if(tree->leaf.b == 0 && tree->leaf.m == 0 && tree->leaf.c == 0)
        return;
    int m, c, result = 1, teste=0;
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
                    teste++;
                }    
                else{
                    insert(tree->prox, leaf, 0);
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
                }    
                else{
                    insert(tree->prox, leaf, 0);
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
                }    
                else{
                    insert(tree->prox, leaf, 0);
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
                }    
                else{
                    insert(tree->prox, leaf, 0);
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
                }    
                else{
                    insert(tree->prox, leaf, 0);
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
                }    
                else{
                    insert(tree->prox, leaf, 0);
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
                }    
                else{
                    insert(tree->prox, leaf, 0);
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
                }    
                else{
                    insert(tree->prox, leaf, 0);
                }
            }
        }
    }
    node *aux = tree;
    //node *aux2;
    while(aux != NULL){ //recursion 
        if(aux->prox != NULL){
            build_tree(root, aux->prox);
        }
        aux = aux->bro;
    }
      
}

#endif