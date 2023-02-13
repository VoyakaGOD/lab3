#ifndef MEGA_HEADER
#define MEGA_HEADER

#include <stdio.h>
#include <stdlib.h>

#define LEN_OF_POLISH_TITLE 256

typedef struct ELEM
{
    int value;
    int type;
    int prior
}Elem;

typedef enum Type
{
    Num           = 1,
    Op            = 2,
    Open_Bracket  = 3,
    Close_Bracket = 4
};

typedef enum Prior
{
    Num           = 1,
    Sum_Sub       = 2,
    Mult_Div      = 3,
    Degree        = 4,
    Bracket       = 0
};

void post_notation (int N);

char *post_conversion (char* S);  

#endif //MEGA_HEADER