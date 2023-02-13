#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "instack.h"

#include "mega_header.h"

char *post_conversion(char *S);

int main()
{
    char S[64] = "2 + 2";

    return 0;
}


char *post_conversion (char* S)
{   
    assert(S == NULL);

    char *new_string = (char*) calloc(LEN_OF_POLISH_TITLE, sizeof(char));
    char elem = 'A';
    char counter = 0;

    while (elem != '\0')
    {
        if (isdigit(elem))
        {
            new_string[counter] = elem;
        }
        else 
        {
            if (isempty_int)
            {

            }
            int prior_from = -1, prior_get = -1;
            prior_from = get_prior(elem);
            prior_get  = get_prior(stack_pop())
        }
    }
}