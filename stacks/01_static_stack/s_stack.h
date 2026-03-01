#ifndef S_STACK_H
#define S_STACK_H

typedef struct s_stack S_Stack;

S_Stack* ss_create();
void ss_free(S_Stack** pss);
int ss_push(S_Stack* ss, int info);
int ss_pop(S_Stack* ss, int* ret);
int ss_is_empty(S_Stack* ss);

#endif