#include "intstack.h"

void push_int (struct Node_int **top, int a) {
    (*top)->number = a;

    (*top)->next = (Node_int *) malloc(sizeof(Node_int));

    *top = (*top)->next;

    (*top)->number = POISON;
}

int pop_int (struct Node_int **top) {

}

bool isempty_int(struct Node_int *top);
