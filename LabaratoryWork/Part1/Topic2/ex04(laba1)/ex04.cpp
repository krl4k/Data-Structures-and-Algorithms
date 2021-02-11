#include "dynamic_stack.h"
#include <iostream>
#include <string>
#include <random>


int is_valid_input(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if(!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char *get_s_number()
{
//	std::cout << "Enter";
	std::string s;
	std::cin >> s;
	const char *num = s.c_str();
	if (is_valid_input(num))
	{
		return (char *)num;
	}
	else
		return nullptr;
}

int get_int_number(char *num)
{
	int n = atoi(num);
	return (n);
}

int menu()
{
	int op_num;
	std::string str;

	std::cout << "----------------------" << std::endl;
	std::cout << "|Add Elem in Stack: 1|" << std::endl;
	std::cout << "|Pop Elem in Stack: 2|" << std::endl;
	std::cout << "|Print Stack:       3|" << std::endl;
	std::cout << "|Void Check Stack:  4|" << std::endl;
	std::cout << "|Exit:              5|" << std::endl;
	std::cout << "|Enter a number:  ";
	std::cin >> str;
	std::cout << "---------------------|" << std::endl;
	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}

void push_random(t_stack **stack, int count_elem)
{
	/* initialize random seed: */
	std::cout << "Enter a range of numbers: ";
	char *range = get_s_number();
	int r;
	if (!range)
	{
		std::cout << "Bad Input" << std::endl;
		return;
	}
	else
	{
		r = get_int_number(range);
	}
	srand(time(NULL));
	for (int i = 0; i < count_elem; i++)
	{
		push(stack, rand() % r + 1);
	}
}

/*
* 	stack1   get
* 	stack2   put
*/

void moving_tops(t_stack **stack1, t_stack **stack2)
{
	if (!*stack1)
	{
		return;
	}
	if (!*stack2)
		init(stack2);
	if (!(*stack1)->top)
	{
		std::cout << "Stack is empty!" << std::endl;
		return;
	}
	if ((*stack1)->top)
	{
		t_node *temp = (*stack1)->top;
		(*stack1)->top = temp->next;
		temp->next = nullptr;
		(*stack1)->size--;
		if (isEmpty(*stack2))
			(*stack2)->top = temp;
		else
		{
			temp->next = (*stack2)->top;
			(*stack2)->top = temp;
		}
		(*stack2)->size++;
	}
}

int main(void)
{
	t_stack *stack = nullptr;
	t_stack *stack2 = nullptr;
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	int op_num;
	char *num;
	int n;
	while (1)
	{
		op_num = menu();
		switch(op_num)
		{
			case (1):
				std::cout << "1 to enter randomly, 2 to enter a number, 3 from the top of the helper stack" << std::endl;
				std::cout << "Enter: ";
				if (!(num = get_s_number()))
				{
					std::cout << "Bad input!" << std::endl;
					break;
				}
				n = get_int_number(num);
				switch(n)
				{
					case 1:
						std::cout << "Enter count elem to add: ";
						if (!(num = get_s_number()))
						{
							std::cout << "Bad input!" << std::endl;
							break;
						}
						n = get_int_number(num);
						push_random(&stack, n);
						break;
					case 2:
						std::cout << "Enter elem to add: ";
						if (!(num = get_s_number()))
						{
							std::cout << "Bad input" << std::endl;
							break;
						}
						n = get_int_number(num);
						push(&stack, n);
						break;
					case 3:
						moving_tops(&stack2, &stack);
						break;
					default:
						std::cout << "Try again!" << std::endl;
				}
				break;
			case 2:
				std::cout << "Are you sure???\n";
				std::cout << "Can put this item on the top of the helper stack?\n";
				std::cout << "1 - add a helper to the stack\n"
							 "2 - really delete\n";
				std::cout << "Enter: ";
				if (!(num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				n = get_int_number(num);
				switch(n)
				{
					case 1:
						moving_tops(&stack, &stack2);
						break;
					case 2:
						pop(&stack);
						break;
					default:
						std::cout << "Try again!" << std::endl;

				}
				break;
			case 3:
				std::cout << "1 - mainStack.\n2 - handlerStack!" << std::endl;
				std::cout << "Enter: ";
				if (!(num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				n = get_int_number(num);
				switch(n)
				{
					case 1:
						printStack(stack);
						break;
					case 2:
						printStack(stack2);
						break;
					default:
						std::cout << "Try again!" << std::endl;

				}
				break;
			case 4:
				if (isEmpty(stack))
					std::cout << "Stack is empty!" << std::endl;
				else
					std::cout << "Stack not empty!" << std::endl;
				break;
			case 5:
				clear(&stack);
				clear(&stack2);
				std::cout << "Clear Stack!" << std::endl;
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
	return 0;
}
