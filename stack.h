#ifndef STACK_HEADER
#define STACK_HEADER

#include "prog_log.h"
#include <stdlib.h>

typedef int elem_t;

// static const elem_t STACK_POISON = 0x00BADFAD;

#define STACK_INIT(stack, capacity) stack_init(&stack, capacity);

#define STACK_DUMP(stack) fprintf(log_file, "%s() at %s(%d):\n", __FUNC__, __FILE__, __LINE__); stack_dump(&stack)

extern size_t stack_dump_data_size;



enum stack_error
{
    STACK_NULL_PTR = 1,
    STACK_NULL_DATA = 2,
    STACK_NEGATIVE_CAPACITY = 4,
    STACK_NEGATIVE_SIZE = 8,
    STACK_OVERFLOW = 16,
    STACK_BAD_ALLOC = 32,
    STACK_GET_ITEM_FROM_EMPTY = 64,
    STACK_BAD_RESIZE = 128
};

typedef struct
{
    size_t capacity;
    size_t size;
    elem_t *data;
} stack_t;

/// @brief get code of errors occurred in last called stack function
/// @return errors
int stack_get_last_errors();

/// @brief get code of errors in stack
/// @param[in] stack pointer to the instance
/// @return errors
int stack_verify(stack_t *stack);

/// @brief init stack and alloc memory for data, use STACK_INIT instead
/// @param[in] stack pointer to the instance
/// @param[in] capacity size of alloced memory
/// @param[in] origin info about origin of stack
void stack_init(stack_t *stack, size_t capacity);

/// @brief frees memory for data and nulls fields of stack
/// @param[in] stack pointer to the instance
void stack_release(stack_t *stack);

/// @brief change stack capacity
/// @param[in] stack pointer to the instance
/// @param[in] capacity new value of capacity
void stack_resize(stack_t *stack, size_t capacity);

/// @brief add item on top of the stack
/// @param[in] stack pointer to the instance
/// @param[in] item new item
void stack_push(stack_t *stack, elem_t item);

/// @brief get item from top of the stack
/// @param[in] stack pointer to the instance
/// @return top item
elem_t stack_peek(stack_t *stack);

/// @brief get and remove item from top of the stack
/// @param[in] stack pointer to the instance
/// @return top item
elem_t stack_pop(stack_t *stack);

/// @brief writes description of errors to the file
/// @param[in] file pointer to the file
void stack_print_errors(FILE *file);

/// @brief writes all possible information of stack instance
/// @param[in] stack pointer to the instance
void stack_dump(stack_t *stack);

#endif //STACK_HEADER