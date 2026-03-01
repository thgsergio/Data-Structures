#include <stdlib.h>
#include "d_stack.h"

struct d_stack{
    int* vec;
    int i;
    int tam;
};

D_Stack* ds_create(unsigned int tam){
    D_Stack* ds = (D_Stack*) malloc(sizeof(D_Stack));
    if(!ds)
        return NULL;
    
    ds->vec = (int*) malloc(tam * sizeof(int));
    if(!ds->vec){
        free(ds);
        ds = NULL;
        return NULL;
    }
    ds->i = -1;
    ds->tam = tam;
    return ds;
}

void ds_free(D_Stack** pds){
    if(!pds)
        return;
    free((*pds)->vec);
    free(*pds);
    *pds = NULL;
}

int ds_is_empty(D_Stack* ds){
    if(!ds)
        return -1;
    return ds->i <= -1;
}

int ds_push(D_Stack* ds, int info){
    if(!ds)
        return -1;
    if(ds->i + 1 == ds->tam){
        int new_tam = (ds->tam == 0) ? 1 : ds->tam * 2;
        int* temp = (int*) realloc(ds->vec, new_tam * sizeof(int));
        if(!temp)
            return 0;
        ds->vec = temp;
        ds->tam = new_tam;
    }
    ds->i++;
    ds->vec[ds->i] = info;
    return 1;
}

int ds_pop(D_Stack* ds, int* ret){
    if(!ds || !ret)
        return -1;
    if(ds->i <= -1)
        return 0;
    *ret = ds->vec[ds->i];
    ds->i--;
    return 1;
}
