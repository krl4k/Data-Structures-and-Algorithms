#include <iostream>
#define SIZE 10

typedef struct s_stack
{
	int array[SIZE];
	int size;
	void (*push)(struct  s_stack *stack, int new_elem);
	void (*print)(struct  s_stack *stack);
}               t_stack;

void init_stack(t_stack **stack);
