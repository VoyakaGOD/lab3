#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
            
        }
    }
}