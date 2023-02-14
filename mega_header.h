#ifndef MEGA_HEADER
#define MEGA_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"
#include "stack/src/stack.hpp"

#define PROG_FILE "program.txt"
#define CONST_EXPR_FILE "constant_expressions.txt"
#define PONO_FILE "postfix_notation.txt"
#define RESULT_FILE "rez.dat"

int clipping_expressions();

void post_notation(int N);

char *post_conversion(char* S);

void calculating_value();

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

#endif //MEGA_HEADER