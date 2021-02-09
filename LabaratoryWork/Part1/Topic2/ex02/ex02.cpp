#include "dynamic_stack.h"
#include <iostream>

int main(void)
{
	t_stack *stack = nullptr;

//	init(&stack);
	int op_num;
	while (1)
	{
		std::cout << "----------------------" << std::endl;
		std::cout << "|Add Elem in Stack: 1|" << std::endl;
		std::cout << "|Pop Elem in Stack: 2|" << std::endl;
		std::cout << "|Print Stack:       3|" << std::endl;
		std::cout << "|Void Check Stack:  4|" << std::endl;
		std::cout << "|Exit:              5|" << std::endl;
		std::cout << "|Enter a number:  ";
		std::cin >> op_num;
		std::cout << "---------------------|" << std::endl;
		switch (op_num)
		{
			case (1):
				std::cout << "Enter elem to add: ";
				int new_elem;
				std::cin >> new_elem;
				push(&stack, new_elem);
				break;
			case 2:
				pop(&stack);
				break;
			case 3:
				printStack(stack);
				break;
			case 4:
				if (isEmpty(stack))
					std::cout << "Stack is empty!" << std::endl;
				else
					std::cout << "Stack not empty!" << std::endl;
				break;
			case 5:
				clear(&stack);
				std::cout << "Clear Stack!" << std::endl;
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
	return 0;
}
