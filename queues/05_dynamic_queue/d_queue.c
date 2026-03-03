#include <stdlib.h>
#include "../queue.h"

#define INITIAL_TAM 10

struct queue{
    int* vec;
    int inicio;
    int n;
    int tam;
};

Queue *queue_create(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if(!q)
        return NULL;
    q->vec = (int*) malloc(INITIAL_TAM * sizeof(int));
    if(!q->vec){
        free(q);
        q = NULL;
        return NULL;
    }
    q->tam = INITIAL_TAM;
    q->inicio = 0;
    q->n = 0;
    return q;
}

void queue_free(Queue **pq){
    if(!pq)
        return;
    free((*pq)->vec);
    free(*pq);
    *pq = NULL;
}

int queue_is_empty(Queue *q){
    if(!q)
        return -1;
    return (q->n == 0);
}

int queue_insert(Queue *q, int info){
    if(!q)
        return -1;
    if(q->n == q->tam){
        int new_tam = q->tam * 2;
        int* temp = realloc(q->vec, new_tam * sizeof(int));
        if(!temp)
            return 0;
        q->vec = temp;
        q->vec[q->n] = info;
        q->n++;
    }
}
int queue_remove(Queue *q, int *ret);
