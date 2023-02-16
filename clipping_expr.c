#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mega_header.h"

int clipping_expressions()
{
    FILE *program = fopen(PROG_FILE, "r");
    FILE *expr    = fopen(CONST_EXPR_FILE, "w");
    int num_lines = 0;

    list_t *list = list_create();

    int cur_sym = fgetc(program);
    while(cur_sym != EOF)
    {
        if (cur_sym == '=')
        {
            num_lines++;
            
            cur_sym = fgetc(program);
            while(cur_sym != EOF &&cur_sym != ';')
            {
                list_append_backward(list, cur_sym);
                cur_sym = fgetc(program);
            }

            char *str_to_files = list_to_str(list);
            list_free(list);

            fprintf(expr, "%s\n", str_to_files);
            free(str_to_files);
        }
        cur_sym = fgetc(program);
    }


    list_free;
    free(list);
    fclose(program);
    fclose(expr);
    return num_lines;
}