#include <stdlib.h>
#include "../queue.h"

struct node{
    int info;
    struct node* ante;
    struct node* prox;
};
typedef struct node Node;

struct queue{
    Node* start;
    Node* end;    
};

Queue* queue_create(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if(!q)
        return NULL;
    q->start = NULL;
    q->end = NULL;
    return q;
}

void queue_free(Queue** pq){
    if(!pq)
        return;
    while((*pq)->start != NULL){
        Queue* aux = (*pq)->start->prox;
        free((*pq)->start);
        (*pq)->start = aux;
    }
    *pq = NULL;
}

int queue_is_empty(Queue *q){
    if(!q)
        return NULL;
    return (q->start == NULL);
}

int queue_insert(Queue *q, int info){
    if(!q)
        return -1;
    Node* new = (Node*) malloc(sizeof(Node));
    if(!new)
        return 0;
    new->info = info;
    new->prox = NULL;
    if(q->end != NULL){
        q->end->prox = new;
        new->ante = q->end;
    }
    else{
        q->start = new;
        new->ante = NULL;
    }
    q->end = new;
    return 1;
}


int queue_remove(Queue *q, int *ret){
    if (!q || !ret)
        return -1;
    if(q->start == NULL)
        return 0;
    Node* aux;
    if(q->start == q->end){
        aux->ante = NULL;
        aux->prox = NULL;
        q->start = NULL;
        q->end = NULL;
        free(aux);
        aux = NULL;
        return 1;
    }

    *ret = q->start->info;
    aux = q->start;

    q->start = aux->prox;
    
    aux->prox->ante = NULL;
    aux->ante = NULL;
    aux->prox = NULL;
    free(aux);
    aux = NULL;
    return 1;
}