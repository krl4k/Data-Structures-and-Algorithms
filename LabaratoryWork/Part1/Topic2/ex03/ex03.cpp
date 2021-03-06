#include "../ex02/dynamic_stack.h"
#include <iostream>

int menu()
{
	int op_num;
	std::cout << "----------------------" << std::endl;
	std::cout << "|Add Elem in Stack: 1|" << std::endl;
	std::cout << "|Pop Elem in Stack: 2|" << std::endl;
	std::cout << "|Print Stack:       3|" << std::endl;
	std::cout << "|Void Check Stack:  4|" << std::endl;
	std::cout << "|Exit:              5|" << std::endl;
	std::cout << "|Enter a number:  ";
	std::cin >> op_num;
	std::cout << "---------------------|" << std::endl;
	return op_num;
}

void	push_random(t_stack **stack, int count_elem)
{
	/* initialize random seed: */
	std::cout << "Enter a range of numbers: " << std::endl;
	int range;
	std::cin >> range;
	srand (time(NULL));
	for (int i = 0; i < count_elem; i++)
	{
		push(stack, rand() % range + 1);
	}
}


int main(void)
{
	t_stack *stack = nullptr;

//	init(&stack);
	int op_num;
	while (1)
	{
		op_num = menu();
		switch (op_num)
		{
			case (1):
				int op;
				std::cout << "1 to enter randomly, 2 to enter a number" << std::endl;
				std::cout << "Enter: ";
				std::cin >> op;
				switch(op)
				{
					case 1:
						std::cout << "Enter count elem to add: ";
						int count_elem;
						std::cin >> count_elem;
						push_random(&stack, count_elem);
						break;
					case 2:
						std::cout << "Enter elem to add: ";
						int new_elem;
						std::cin >> new_elem;
						push(&stack, new_elem);
						break;
				}
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
