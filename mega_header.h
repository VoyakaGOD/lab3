#ifndef MEGA_HEADER
#define MEGA_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"
#include "stack/src/stack.hpp"

#define PROG_FILE "program.txt"
#define CONST_EXPR_FILE "constant_expression.txt"
#define PONO_FILE "postfix_notation.txt"
#define RESULT_FILE "rez.dat"

int clipping_expressions();

void post_notation(int N);

char *post_conversion(char* S);

void сalculating_value();

#endif //MEGA_HEADER