#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "mega_header.h"

void calculating_value() 
{
    stack_t stack = {};
    stack_init(&stack, 4);
    FILE *in_file = fopen(PONO_FILE, "r");
    FILE *out_file = fopen(RESULT_FILE, "w");
    char sym = 0;
    int a = 0, b = 0;

    while ((sym = getc(in_file)) != EOF)
    {
        if (isdigit(sym))
        {
            stack_push(&stack, sym - '0');
        }
        else 
        {
            switch (sym) 
            {                
                case '+':
                    b = stack_pop(&stack);
                    a = stack_pop(&stack);
                    stack_push(&stack, a + b);
                    break;

                case '-':
                    b = stack_pop(&stack);
                    a = stack_pop(&stack);
                    stack_push(&stack, a - b);
                    break;

                case '*':
                    b = stack_pop(&stack);
                    a = stack_pop(&stack);
                    stack_push(&stack, a * b);
                    break;

                case '/':
                    b = stack_pop(&stack);
                    a = stack_pop(&stack);
                    stack_push(&stack, a / b);
                    break;

                case '^':
                    b = stack_pop(&stack);
                    a = stack_pop(&stack);
                    stack_push(&stack, pow(a, b));
                    break;

                case '\n':
                    fprintf(out_file, "%d\n", stack_pop(&stack));
                    break;
            
                default:
                    printf("ERROR: unknown symbol: %c\n", sym);
                    break;
            }
        }
    }

    fclose(in_file);
    fclose(out_file);
}
