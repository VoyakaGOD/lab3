#ifndef ZALUPAEZHA_STACK_H
#define ZALUPAEZHA_STACK_H

#include <stdlib.h>

struct Node_int{
    int  number;
    struct Node_int *next;
};

const int POISON = 0xDEADF00D;

void push_int (struct Node_int **top, int a);

int pop_int (struct Node_int **top);

bool isempty_int(struct Node_int *top);

#endif //ZALUPAEZHA_STACK_H

