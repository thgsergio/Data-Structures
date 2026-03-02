#include <stdlib.h>
#include "../queue.h"

#define MAX_TAM 10

struct queue{
    int vec[MAX_TAM];
    int inicio;
    int n;
};

Queue* queue_create(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if(!q)
        return NULL;
    q->inicio = 0;
    q->n = 0;
    return q;
}

void queue_free(Queue** pq){
    if(!pq)
        return;
    free(*pq);
    *pq = NULL;
}

int queue_is_empty(Queue* q){
    if(!q)
        return -1;
    return (q->n == 0);
}

int queue_insert(Queue* q, int info){
    if(!q)
        return -1;
    if(q->n == MAX_TAM)
        return 0;
    int i = (q->n + q->inicio) % MAX_TAM;
    q->vec[i] = info;
    q->n++;
}

int queue_remove(Queue* q, int* ret){
    if (!q)
        return -1;
    if(q->n == 0)
        return 0;
    *ret = q->vec[q->inicio];
    q->inicio = (q->inicio + 1) % MAX_TAM;
    q->n--;
    return 1;
}
