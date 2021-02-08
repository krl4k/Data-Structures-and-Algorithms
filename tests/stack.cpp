#include "stack.h"

static void push(t_stack *stack, int new_elem)
{
	if (stack)
	{
		if (stack->size == SIZE)
		{
			std::cout << "Stack is full" << std::endl;
			return;
		}
		stack->array[stack->size] = new_elem;
		stack->size++;
	}
}

static void print(t_stack *stack)
{
	std::cout << "Stack:" << std::endl;
	for (int i = stack->size - 1; i >= 0; i--)
	{
		std::cout << stack->array[i] << std::endl;
	}
}

void init_stack(t_stack **stack)
{
	(*stack) = new t_stack;
	(*stack)->size = 0;
	(*stack)->push = &push;
	(*stack)->print = &print;
	std::cout << "Stack inited!" << std:: endl;
}