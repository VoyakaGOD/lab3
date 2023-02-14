#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h> 
#include "stack.h"
#include "mega_header.h"
#include "general_debug.h"

char *post_conversion(char *S);

static int get_prior(int elem);

int main()
{
    char S[64] = "(6-3)^2-9";

    // printf("got address %p\n", post_conversion(S));
    // char *new_str = post_conversion(S);
    // DBG; 
    printf("%s\n", post_conversion(S));
    return 0;
}


char *post_conversion (char* S)
{   
    assert(S != NULL);
    stack_t stack = {};
    STACK_INIT(stack, 10);

    char *new_string = (char*) calloc(LEN_OF_POLISH_TITLE, sizeof(char));
    int counter = 0;
    int S_counter = 0;
    char elem = S[S_counter++];

    while (elem != '\0')
    {
        printf("%c = %d\n", elem, elem);

        if (isdigit(elem))
        {
            new_string[counter++] = elem;
        }
        else
        {
            if (stack.size == 0)
            {
                stack_push(&stack, elem);
            }
            else
            {
                int prior_get = -1, prior_peek = -1;
                prior_get = get_prior(elem);
                prior_peek  = get_prior(stack_peek(&stack));

                if (prior_get > prior_peek)                     //op > op in stack
                {
                    stack_push(&stack, elem);
                }
                else if (elem == '(')
                {
                    stack_push(&stack, elem);
                }
                else if (elem == ')')                           // handle brackets
                {
                    elem = stack_pop(&stack);
                    while (stack.size > 0 && elem != '(')
                    {
                        new_string[counter++] = elem;
                        elem = stack_pop(&stack);
                    }

                }   
                else                                            //op <= op in stack
                {
                    while (prior_get <= prior_peek && stack.size > 0)
                    {
                        new_string[counter++] = stack_pop(&stack);
                        prior_peek  = get_prior(stack_peek(&stack));
                    }
                    stack_push(&stack, elem);
                }
                
            }
        }

        elem = S[S_counter++];
    }

    while (stack.size > 0)
    {
        new_string[counter++] = stack_pop(&stack);
    }

    stack_release(&stack);
    return new_string;
}

int get_prior(int elem)
{
    switch(elem)
    {
        case '+':
        case '-':
            return Sum_Sub_Prior;
            break;
        case '*':
        case '/':
            return Mult_Div_Prior;
            break;
        case '^':
            return Degree_Prior;
            break;
        case '(':
            return Bracket_Prior;
            break;
    }

    return -1;
}