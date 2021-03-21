#include "dynamic_stack.h"
#include <iostream>

void init(t_stack **stack)
{
	*stack = new t_stack;
	(*stack)->size = 0;
}

int size(t_stack *stack)
{
	if (stack)
		return stack->size;
	return 0;
}

bool isEmpty(t_stack *stack)
{
	if (size(stack) > 0)
		return false;
	return true;
}

t_t_node *top(t_stack *stack)
{
	if (!isEmpty(stack))
		return stack->top->data;
	return nullptr;
}

void push(t_stack **stack, t_t_node *data)
{
	if (*stack == nullptr)
		init(stack);
	t_node *new_elem = new t_node;
	new_elem->data = data;
	if (isEmpty(*stack))
	{
		(*stack)->top = new_elem;
		new_elem->next = nullptr;
		(*stack)->size = 0;
	}
	else
	{
		new_elem->next = (*stack)->top;
		(*stack)->top = new_elem;
	}
	(*stack)->size++;
}

void pop(t_stack **stack)
{
	if(size(*stack) > 0)
	{
		t_node *oldTop = (*stack)->top;
		(*stack)->top = oldTop->next;
		delete oldTop;
		oldTop = nullptr;
		(*stack)->size--;
	}
}

void clear(t_stack **stack)
{
	if (!*stack)
		return;
	while (!isEmpty(*stack))
		pop(stack);
	delete *stack;
	*stack = nullptr;
}