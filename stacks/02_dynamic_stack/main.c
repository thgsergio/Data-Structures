#include <stdio.h>
#include "d_stack.h"

int main(){
    int tam = 23;
    D_Stack* ds = ds_create(tam);
    for(int i = 0; i < tam; i++){
        if(!ds_push(ds, i)){
            printf("Line %d could not be done: out of capacity\n", i+1);
            continue;
        }
        printf("Value %d stored in line %d\n", i, i+1);
    }
        
    printf("\nValues:\n");
    for(int i = 0; i < tam; i++){
        int value;
        if(!ds_pop(ds, &value)){
            printf("There's no value stored\n");
            continue;
        }
        printf("%d. %d\n", i+1, value);
    }
    if(ds_is_empty(ds)){
        printf("\nEmpty\n");
    }
    else{
        printf("\nNot empty\n");
    }
    ds_free(&ds);
    return 0;
}