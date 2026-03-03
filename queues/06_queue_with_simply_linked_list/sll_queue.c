#include <stdlib.h>
#include "../queue.h"

struct node{
    int info;
    struct node* prox;
};
typedef struct node Node;

struct queue{
    Node* start;
    Node* end;    
};

Queue *queue_create(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if(q == NULL) return NULL;

    q->start = q->end = NULL;
    return q;
}

void queue_free(Queue **pq){
    
}

int queue_is_empty(Queue *q){
    if(q == NULL) return -1;
    return (q->start == NULL);
}

int queue_insert(Queue *q, int info){
    if(q == NULL) return -1;

    Node* new = (Node*) malloc(sizeof(Node));
    if(new == NULL) return 0;
    new->info = info;
    new->prox = NULL;

    if(q->start == NULL){
        q->start = q->end = new;
        return 1;
    }
    q->end->prox = new;
    q->end = new;
    return 1;
}

int queue_remove(Queue *q, int *ret){
    if(q == NULL) return -1;
    
    if(q->start == q->end){
        free(q->start);
        q->start = q->end = NULL;
    }
    Node* aux = q->start;
    q->start = q->start->prox;
}
