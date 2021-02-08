
#include "stack.h"

int main()
{
	t_stack *stack;

	init_stack(&stack);

	for (int i = 0; i < 10; i++)
	{
		stack->push(stack, i);
	}

	stack->print(stack);
}
