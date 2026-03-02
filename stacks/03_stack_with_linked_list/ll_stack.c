#include <stdlib.h>
#include "ll_stack.h"

struct ll_stack{
    int info;
    struct ll_stack* prox;
};

LL_Stack* lls_create(){
    return NULL;
}

void lls_free(LL_Stack** plls){
    if(!plls || !(*plls))
        return;

    while((*plls) != NULL){
        LL_Stack* aux = (*plls)->prox;
        free(*plls);
        *plls = aux;
    }
}

int lls_is_empty(LL_Stack* lls){
    return (lls == NULL);
}

int lls_push(LL_Stack** plls, int info){
    if(!plls)
        return -1;
    LL_Stack* new = (LL_Stack*) malloc(sizeof(LL_Stack));
    if(!new)
        return 0;
    new->info = info;
    new->prox = *plls;
    *plls = new;
    return 1;
}

int lls_pop(LL_Stack** plls, int* ret){
    if(!plls || !ret)
        return -1;
    if(!(*plls))
        return 0;
    *ret = (*plls)->info;
    LL_Stack* aux = (*plls)->prox;
    free(*plls);
    *plls = aux;
    return 1;
}