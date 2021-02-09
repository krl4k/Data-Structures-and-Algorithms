#ifndef STACK_H
#define STACK_H
#include <iostream>

#define SIZE 256

typedef struct s_stack
{
	int array[SIZE];
	int size;
}               t_stack;

void init_stack(t_stack **stack);

bool is_empty(t_stack *stack);
bool is_full(t_stack *stack);

int size(t_stack *stack);

void push(t_stack *stack, int new_elem);
void pop(t_stack *stack);
void print(t_stack *stack);

#endif
