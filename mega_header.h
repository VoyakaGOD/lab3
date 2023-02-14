#ifndef MEGA_HEADER
#define MEGA_HEADER

#include <stdio.h>
#include <stdlib.h>

#define LEN_OF_POLISH_TITLE 256

typedef struct ELEM
{
    int value;
    int type;
    int prior;
} Elem;

enum Type
{
    Num           = 1,
    Op            = 2,
    Open_Bracket  = 3,
    Close_Bracket = 4
};

enum Prior
{
    Num_Prior       = 1,
    Sum_Sub_Prior   = 2,
    Mult_Div_Prior  = 3,
    Degree_Prior    = 4,
    Bracket_Prior   = 0
};

void post_notation (int N);

char *post_conversion (char* S);  

#endif //MEGA_HEADER