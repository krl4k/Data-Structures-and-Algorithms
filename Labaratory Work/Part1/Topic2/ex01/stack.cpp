#include "stack.h"

bool is_empty(t_stack *stack)
{
	if (stack)
	{
		if(stack->size == 0)
			return true;
	}
	return false;
}

bool is_full(t_stack *stack)
{
	if (stack)
	{
		if(stack->size == SIZE)
			return true;
	}
	return false;
}

int size(t_stack *stack)
{
	if (stack)
	{
		return stack->size;
	}
	return 0;
}

void push(t_stack *stack, int new_elem)
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

void pop(t_stack *stack)
{
	if (stack)
	{
		stack->array[stack->size] = 0;
		stack->size--;
	}
}


void init_stack(t_stack **stack)
{
	(*stack) = new t_stack;
	(*stack)->size = 0;
	std::cout << "Stack inited!" << std:: endl;
}

void print(t_stack *stack)
{
	std::cout << "Stack:" << std::endl;
	for (int i = stack->size - 1; i >= 0; i--)
	{
		std::cout << stack->array[i] << std::endl;
	}
}
