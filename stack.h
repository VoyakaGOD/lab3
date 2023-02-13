#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define CANARY_PROT

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elem_t;

struct Stack {
    Elem_t* data;
    size_t Size;
    size_t capacity;
};

const Elem_t POISON = 7;
const size_t START_CAPACITY = 0x100;

struct Stack StackNew_(const char* name, const char* func, const char* file, size_t line);

void StackPush(struct Stack *stk, Elem_t value);

Elem_t StackPop(struct Stack *stk);

void StackResize(struct Stack *stk, size_t newCapacity);

void StackDtor(struct Stack *stk);

void* recalloc(void* ptr, size_t num, size_t Size);

#endif // STACK_H_INCLUDED
