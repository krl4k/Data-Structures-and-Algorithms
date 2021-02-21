#include "dynamic_list.h"

int is_valid_input(const char *s)
{
	int i;

	i = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
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
	std::string s;
	std::cin >> s;
	const char *num = s.c_str();
	if(is_valid_input(num))
	{
		char *n = strdup(num);
		return n;
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
	std::string str;
	std::cout << "----------------------" << std::endl;
	std::cout << "|Push  			:  1|" << std::endl;
	std::cout << "|Pop  			:  2|" << std::endl;
	std::cout << "|Print List 		:  3|" << std::endl;
	std::cout << "|Print Stack 		:  4|" << std::endl;
	std::cout << "|Get  elem 		:  5|" << std::endl;
	std::cout << "|Exit       		:  6|" << std::endl;
	std::cout << "|Enter a 	:  ";
	std::cin >> str;
	std::cout << "|--------------------|" << std::endl;

	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}



int push_menu()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "|PushBefore 	:  1|" << std::endl;
	std::cout << "|PushAfter  	:  2|" << std::endl;
	std::cout << "|PushBack  	:  3|" << std::endl;
	std::cout << "|PushFront  	:  4|" << std::endl;
	std::cout << "|Enter a 	:  ";
	std::string str;
	std::cin >> str;
	std::cout << "----------------------" << std::endl;
	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}

int 				push(t_list *list)
{
	int op;
	char *s_num;
	std::string s1;
	std::string s2;

	while (1)
	{
		op = push_menu();
		switch (op)
		{
			case 1:
				std::cout << "Enter the element BEFORE which to push : " << std::endl;
				std::cin >> s1;
				std::cout << "Enter the element to push: ";
				std::cin >> s2;
				push_before(list, s1.c_str(), new_node(s2.c_str()));
				return (0);
			case 2:
				std::cout << "Enter the element AFTER which to push" << std::endl;
				std::cin >> s1;
				std::cout << "Enter the element to push: ";
				std::cin >> s2;
				push_after(list, s1.c_str(), new_node(s2.c_str()));
				return (0);
			case 3:
				std::cout << "Enter the element to push back: ";
				std::cin >> s1;
				push_back(list, new_node(s1.c_str()));
				return (0);
			case 4:
				std::cout << "Enter the element to push front: ";
				std::cin >> s1;
				push_front(list, new_node(s1.c_str()));
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
	return (0);
}

int pop_menu()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "|PopBack  	:  1|" << std::endl;
	std::cout << "|PopFront  	:  2|" << std::endl;
	std::cout << "|Pop elem  	:  3|" << std::endl;
	std::cout << "|Enter a 	:  ";
	std::string str;
	std::cin >> str;
	std::cout << "----------------------" << std::endl;
	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}

void pop_to_stack(t_list *list, t_list *stack)
{
	if (!list || !stack || !list->head || !stack->head)
		return;
	int op = pop_menu();
	while (1)
	{
		switch (op)
		{
			case 1:
				pop_back_to_stack(list, stack);
				return;
			case 2:
				pop_front_to_stack(list, stack);
				return;
			case 3:
				return;
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
}


int main(void)
{
	t_list *list;
	t_list *stack;
	init(list);
	init(stack);
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	int op_num;
	std::string str;
	char *num;
	int n;
	int index;
	while (1)
	{
		op_num = menu();
		switch (op_num)
		{
			case (1):
				push(list);
				break;
			case 2:
				pop_to_stack(list, stack);
//				pop(list);
				break;
			case 3:
				list_print(list);
				break;
			case 4:
				list_print(stack);
				break;
			case 5:
				std::cout << "Enter an element for find its index : " << std::endl;
				std::cin >> str;
				if ((index = get_index(list, str.c_str())) != -1)
					std::cout << "Elem " << str << " has index " << index << std::endl;
				else
					std::cout << "Elem not found!" << std::endl;
				break;
			case 6:
				clear(&list);
				clear(&stack);
				std::cout << "Clear List!" << std::endl;
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
}
