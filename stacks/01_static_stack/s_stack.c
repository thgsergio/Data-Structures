#include <stdlib.h>
#include "s_stack.h"
#define MAX_TAM 10

struct s_stack{
    int vec[MAX_TAM];
    int i;
};

S_Stack* ss_create(){
    S_Stack* ss = (S_Stack*) malloc(sizeof(S_Stack));
    if(!ss) return NULL;

    ss->i = -1;
    return ss;
}

void ss_free(S_Stack** pss){
    if(!pss) return;
    free(*pss);
    *pss = NULL;
}

int ss_push(S_Stack* ss, int info){
    if(!ss)
        return -1;
    if(ss->i + 1 >= MAX_TAM)
        return 0;
    ss->i++;
    ss->vec[ss->i] = info;
    return 1;
}

int ss_pop(S_Stack* ss, int* ret){
    if(!ss || !ret)
        return -1;
    if(ss->i <= -1)
        return 0;
    *ret = ss->vec[ss->i];
    ss->i--;
    return 1;
}

int ss_is_empty(S_Stack* ss){
    if(!ss)
        return -1;
    return ss->i <= -1;
}
