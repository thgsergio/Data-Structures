#ifndef D_STACK_H
#define D_STACK_H

typedef struct d_stack D_Stack;

D_Stack* ds_create(unsigned int tam);
void ds_free(D_Stack** pds);
int ds_is_empty(D_Stack* ds);
int ds_push(D_Stack *ds, int info);
int ds_pop(D_Stack *ds, int *ret);

#endif