#include "intstack.h"

void push_int (struct Node_int **top, int a) {
    Node_int *next = (Node_int *) malloc(sizeof(Node_int));

    next->number = a;
    next->prev = (*top);
    next->next = NULL;

    if(*top) {
        (*top)->next = next;
    }

    (*top) = next;
}

int pop_int (struct Node_int **top) {
    int res = (*top)->number;
    Node_int *prev = (*top)->prev;

    (*top)->number = POISON;
    (*top)->prev = NULL;
    (*top)->next = NULL;

    free(*top);

    (*top) = prev;

    if(prev) {
        prev->next = NULL;
    }

    return res;
}

bool isempty_int(struct Node_int *top) {
    return top->number == POISON;
}
