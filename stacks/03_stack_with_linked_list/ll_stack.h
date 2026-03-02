#ifndef SLL_STACK_H
#define SLL_STACK_H

typedef struct ll_stack LL_Stack;

LL_Stack* lls_create();
void lls_free(LL_Stack** plls);
int lls_is_empty(LL_Stack* lls);
int lls_push(LL_Stack **plls, int info);
int lls_pop(LL_Stack **plls, int *ret);

#endif