#ifndef LIST_HEADER
#define LIST_TYPE char
#define LIST_TO_STR "%c"
#define LIST_ERR_VALUE '!'

#include <stdio.h>
#include <stdlib.h>

struct list_node;
typedef struct list_node list_node_t;

struct list_node
{
    LIST_TYPE value;
    list_node_t *next;
};

typedef struct 
{
    list_node_t *head;
} list_t;

list_t *list_create();

void list_append_forward(list_t *list, LIST_TYPE item);

void list_append_backward(list_t *list, LIST_TYPE item);

void list_append_before_value(list_t *list, LIST_TYPE value, LIST_TYPE item);

void list_append_after_value(list_t *list, LIST_TYPE value, LIST_TYPE item);

void list_remove_head(list_t *list);

void list_remove_tail(list_t *list);

void list_remove_value(list_t *list, LIST_TYPE value);

LIST_TYPE list_get_value_from_tail(list_t *list, int index);

void list_print(list_t *list, FILE *stream);

void list_free(list_t *list);

#endif //LIST_HEADER