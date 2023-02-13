#include "list.h"

list_t *list_create()
{
    list_t *list = (list_t *)calloc(sizeof(list), 1);
    return list;
}

void list_append_forward(list_t *list, LIST_TYPE item)
{
    list_node_t *node = (list_node_t *)calloc(sizeof(list_node_t), 1);
    node->next = list->head;
    node->value = item;
    list->head = node;
}

void list_append_backward(list_t *list, LIST_TYPE item)
{
    if(!list->head)
    {
        list_append_forward(list, item);
        return;
    }

    list_node_t *current = list->head;
    while(1)
    {
        if(!current->next)
            break;
        current = current->next;
    }
    list_node_t *node = (list_node_t *)calloc(sizeof(list_node_t), 1);
    node->next = NULL;
    node->value = item;
    current->next = node;
}

void list_append_before_value(list_t *list, LIST_TYPE value, LIST_TYPE item)
{
    list_node_t *current = list->head;
    if(!current)
        return;
    if(current->value == value)
    {
        list_append_forward(list, item);
        return;
    }
    while(current && current->next)
    {
        if(current->next->value == value)
        {
            list_node_t *node = (list_node_t *)calloc(sizeof(list_node_t), 1);
            node->next = current->next;
            node->value = item;
            current->next = node;
            break;
        }
        current = current->next;
    }
}

void list_append_after_value(list_t *list, LIST_TYPE value, LIST_TYPE item)
{
    list_node_t *current = list->head;
    if(!current)
        return;
    while(current)
    {
        if(current->value == value)
        {
            list_node_t *node = (list_node_t *)calloc(sizeof(list_node_t), 1);
            node->next = current->next;
            node->value = item;
            current->next = node;
            break;
        }
        current = current->next;
    }
}

void list_remove_head(list_t *list)
{
    if(!list || !list->head)
        return;
    list_node_t *item = list->head;
    list->head = list->head->next;
    free(item);
}

void list_remove_tail(list_t *list)
{
    if(!list || !list->head)
        return;
    list_node_t *current = list->head;
    while(current->next && current->next->next)
        current = current->next;
    list_node_t *item = current->next;
    current->next = NULL;
    free(item);
}

void list_remove_value(list_t *list, LIST_TYPE value)
{
    list_node_t *current = list->head;
    if(!current)
        return;
    if(current->value == value)
    {
        list_remove_head(list);
        return;
    }
    while(current && current->next)
    {
        if(current->next->value == value)
        {
            list_node_t *item = current->next;
            current->next = current->next->next;
            free(item);
            break;
        }
        current = current->next;
    }
}

LIST_TYPE list_get_value_from_tail(list_t *list, int index)
{
    if(!list->head)
        return LIST_ERR_VALUE;
    list_node_t *current = list->head;
    list_node_t *pioneer = list->head;
    while(pioneer->next && index > 0)
    {
        pioneer = pioneer->next;
        index--;
    }
    if(index > 0)
        return LIST_ERR_VALUE;
    while(pioneer->next)
    {
        pioneer = pioneer->next;
        current = current->next;
    }
    return current->value;
}

void list_print(list_t *list, FILE *stream)
{
    fprintf(stream, "[");
    list_node_t *current = list->head;
    while(current)
    {
        fprintf(stream, LIST_TO_STR, current->value);
        if(current->next)
            fprintf(stream, ", ");
        current = current->next;
    }
    fprintf(stream, "]");
}

void list_free(list_t *list)
{
    if(!list)
        return;
    list_node_t *current = list->head;
    while(current)
    {
        list_node_t *next = current->next;
        free(current);
    }
    list->head = NULL;
}