#include "../queue.h"

Queue *queue_create();
void queue_free(Queue **pq);
int queue_is_empty(Queue *q);
int queue_insert(Queue *q, int info);
int queue_remove(Queue *q, int *ret);
