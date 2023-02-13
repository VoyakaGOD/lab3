#include "mega_header.h"
#include "list/list.h"

char *to_str(list_t *list)
{
    int len = 0;
    int i = 0;
    list_node_t *current = list->head;
    while(current)
    {
        len++;
        current = current->next;
    }
    current = list->head;
    char *string = (char *)calloc(sizeof(char), len + 1);
    while(current)
    {
        string[i] = current->value;
        i++;
        current = current->next;
    }
}

void post_notation(int N)
{
    list_t *input = list_create();
    FILE *input_file = fopen(CONST_EXPR_FILE, "r");
    FILE *output_file = fopen(PONO_FILE, "w");
    int c = 0;
    while(c != EOF)
    {
        c = fgetc(input_file);
        if (c == '\n' || c == EOF || (N--) == 0)
        {
            char *s = to_str(input);
            fputs(post_conversion(s), output_file);
            free(s);
            list_free(input);
        }
        else
        {
            list_append_backward(input, c);
        }
    }

    free(out_data);
    fclose(input_file);
    fclose(output_file);
}