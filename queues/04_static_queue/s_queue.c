#include <stdlib.h>
#include "s_queue.h"

#define MAX_TAM 10

struct s_queue{
    int vec[MAX_TAM];
    int inicio;
    int tam;
};

S_Queue* sq_create(){
    S_Queue* sq = (S_Queue*) malloc(sizeof(S_Queue));
    if(!sq)
        return NULL;
    sq->inicio = 0;
    sq->tam = 0;
    return sq;
}

void sq_free(S_Queue** psq){
    if(!psq)
        return;
    free(*psq);
    *psq = NULL;
}

int sq_is_empty(S_Queue* sq){
    if(!sq)
        return -1;
    return (sq->tam == 0);
}

int sq_insert(S_Queue* sq, int info){
    if(!sq)
        return -1;
    
}

int sq_remove(S_Queue* sq, int* ret){
    if (!sq)
        return -1;
    
}
