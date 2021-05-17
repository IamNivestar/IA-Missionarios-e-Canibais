//Amaury Mario Ribeiro Neto 
//Antonio Pereira de Souza Junior


#ifndef MAIN_C
#define MAIN_C

#include <stdio.h> 
#include <stdlib.h>
#include "tree.h"

int main() {
    
    //create a initial state
    head List;
    leafs l;
    l.m = 3;
    l.c = 3;
    l.b = 1;

    int sair=0, escolha;
    do{
        printf("\n-----------Missionaries and Cannibals Problem-------\n\n");
        int escolha;
        printf("1)Busca em Largura\n");
        printf("2)Iterative Deepening Search\n");
        printf("3)Sair\n\n");
        scanf("%d",&escolha);

        switch(escolha){
            case 1:
                printf("\n-----------Tree----------\n\n");
                List.first = new_node();  //nó inicial ( raiz)
                List.first->leaf = l;
                build_tree(List.first, List.first);               
                print_tree(List.first);
                clean(List.first);
                break;

            case 2:
                printf("\nIterative Deepening Search\n");
                int finish = 0;             
                for(int i = 1; finish != 1; i++){
                    printf("\n -----Profundidade %d ------\n\n",i+1);
                    List.first = new_node();  //nó inicial ( raiz)
                    List.first->leaf = l;
                    iterative_deepening(List.first, List.first, i, 0, &finish);
                    print_deep(List.first);
                    printf("\n");
                    clean(List.first);
                }
                break;
            case 3:
                printf("Closed\n");
                sair = 1;
                break;
            default:
                printf("Invalid Choice! please try again\n");
                break;
        }
        

    }while(sair == 0);
    
    return 0;
    
}


#endif
