#include <stdio.h>
#include "s_stack.h"

int main(){
    int tam = 13;
    S_Stack* ss = ss_create();
    for(int i = 0; i < tam; i++){
        if(!ss_push(ss, i)){
            printf("Line %d could not be done: out of capacity\n", i+1);
            continue;
        }
        printf("Value %d stored in line %d\n", i, i+1);
    }
        
    printf("\nValues:\n");
    for(int i = 0; i < tam; i++){
        int value;
        if(!ss_pop(ss, &value)){
            printf("There's no value stored\n");
            continue;
        }
        printf("%d. %d\n", i+1, value);
    }
    if(ss_is_empty(ss)){
        printf("\nEmpty\n");
    }
    else{
        printf("\nNot empty\n");
    }
    ss_free(&ss);
    return 0;
}