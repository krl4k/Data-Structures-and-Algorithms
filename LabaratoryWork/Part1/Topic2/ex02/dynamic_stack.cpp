#include "dynamic_stack.h"
#include <iostream>

void init(t_stack **stack)
{
	*stack = new t_stack;
//	(*stack)->top = new t_node;  leaks!!!!!! we initialize the stack, but not its elements
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
//	if (stack)          //segfault????why????
//		return false;
	return true;
}

int top(t_stack *stack)
{
	if (!isEmpty(stack))
		return stack->top->data;
	return 0;
}

void push(t_stack **stack, int data)
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

void printStack(t_stack *stack)
{
	std::cout << "-----Info about stack--------" << std::endl;
	if (isEmpty(stack))
	{
		std::cout << "Stack is empty"<< '\n';
		return;
	}
//	if (!stack)
//	{
//		return;
//	}
	std::cout << "      size = " << size(stack) << std::endl;
	std::cout << "      top = " << top(stack) << std::endl;
	std::cout << "stack : ";
	t_node *current = stack->top;
	std::cout << std::endl;
	while (current != nullptr)
	{
		std::cout << current->data << '\n';
		current = current->next;
	}
	std::cout << "-----------------------------" << std::endl;
}


//main to check for leaks
/*
int main()
{
	t_stack *stack;
	init(&stack);

	for (int i = 0; i < 10; i++)
	{
		push(&stack, i);
	}
	for (int i = 0; i < 5; ++i)
	{
		pop(&stack);
	}
	printStack(stack);
	clear(&stack);
//	while (1);
}*/
