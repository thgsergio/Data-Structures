#include <stdio.h>
#include "ll_stack.h"

int main(){
    int tam = 20;
    LL_Stack* lls = lls_create();
    for(int i = 0; i < tam; i++){
        if(!lls_push(&lls, i)){
            printf("Line %d could not be done: out of capacity\n", i+1);
            continue;
        }
        printf("Value %d stored in line %d\n", i, i+1);
    }
        
    printf("\nValues:\n");
    for(int i = 0; i < tam; i++){
        int value;
        if(!lls_pop(&lls, &value)){
            printf("There's no value stored\n");
            continue;
        }
        printf("%d. %d\n", i+1, value);
    }
    if(lls_is_empty(lls)){
        printf("\nEmpty\n");
    }
    else{
        printf("\nNot empty\n");
    }
    lls_free(&lls);
    return 0;
}