#ifndef TREE_C
#define TREE_C
#include <stdio.h> 
#include <stdlib.h>
#include "tree.h"

 
node *new_node(){ //create a new node 
    node *new = (node *) malloc (sizeof(node));
    new->prox = NULL;
    new->bro = NULL;   
    return new;
}

void print_tree(node *root){ //print the tree by breadth first search 
    int verification = 0;
    if(root == NULL)
        return;
    else{
        if(root->bro == NULL)
            printf("\t(%d,%d,%d)", root->leaf.b, root->leaf.m, root->leaf.c); //imprimo o nó raiz
        else
        {
            if(root->bro->bro == NULL)
                printf("    (%d,%d,%d)   ", root->leaf.b, root->leaf.m, root->leaf.c);
            else
                printf("(%d,%d,%d)\t", root->leaf.b, root->leaf.m, root->leaf.c);
        }

        
        node *aux = root->bro;
        while(aux != NULL){ //print all brothers
            
            printf("(%d,%d,%d)\t", aux->leaf.b, aux->leaf.m, aux->leaf.c);
            
            aux = aux->bro;
        }

        printf("\n\n");
        aux = root;
        while(aux != NULL){ // recursion 
            if(aux->prox!= NULL){
                print_tree(aux->prox);
            }
            aux = aux->bro;
        }
    }
}

void insert(node *root, leafs states, int brother){ //insert node in the tree
    node *new = new_node();
    new->leaf = states;
    if(brother){ //if the brother have  children
        root->prox = new;
    } else{ // go to the empty position
        if(root->bro == NULL){
            root->bro = new;
        }
        else{
            node *aux = root->bro;
            while(aux->bro != NULL){
                aux = aux->bro;
            }
            aux->bro = new;
        }
    }
}

void verification_loop(node *root, leafs state, int *result){ // check if the tree have loop (repeated states)
    if(root == NULL)
        return;
    else{
        if(root->leaf.c == state.c && root->leaf.m == state.m && root->leaf.b == state.b){
            *result  = 0;
        }
        node *aux = root->bro;
        while(aux != NULL){
            if(aux->leaf.c == state.c && aux->leaf.m == state.m && aux->leaf.b == state.b){
                *result  = 0;
            }
            if(aux->prox != NULL)
                verification_loop(aux->prox, state, result);
            aux = aux->bro;
        }

        if(root->prox != NULL)
            verification_loop(root->prox, state, result);
    }
}

int verification_valid(leafs state){// check if is a valid state

    if(state.m == 3 || state.m == 0)  //valid states
        return 1;
    else if(state.m == 2 && state.c == 2)
        return 1;
    else if(state.m == 1 && state.c ==1)
        return 1;
    else
        return 0;  // all the other states are invalids 
}

void clean(node *root){
    if(root){
        clean(root->bro);
        clean(root->prox);
        free(root);
    }
}

#endif

