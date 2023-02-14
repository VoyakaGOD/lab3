#include "mega_header.h"

void post_notation(int N)
{
    list_t *input = list_create();
    FILE *input_file = fopen(CONST_EXPR_FILE, "r");
    FILE *output_file = fopen(PONO_FILE, "w");
    int c = 0;
    while(c != EOF && N > 0)
    {
        c = fgetc(input_file);
        if (c == '\n' || c == EOF)
        {
            char *s = list_to_str(input);
            printf(list_to_str(input));
            fputs(post_conversion(s), output_file);
            fputs("\n", output_file);
            free(s);
            list_free(input);
            N--;
        }
        else
        {
            list_append_backward(input, c);
        }
    }

    fclose(input_file);
    fclose(output_file);
}