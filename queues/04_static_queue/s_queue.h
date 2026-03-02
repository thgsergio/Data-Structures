#ifndef S_QUEUE_H
#define S_QUEUE_H

typedef struct s_queue S_Queue;

S_Queue* sq_create();
void sq_free(S_Queue** psq);
int sq_is_empty(S_Queue* sq);
int sq_insert(S_Queue* sq, int info);
int sq_remove(S_Queue* sq, int* ret);

#endif